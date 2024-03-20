#include "GameEnvironment.hpp"
#include "globals.h"
#include "spdlog/spdlog.h"
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

// needed because SDL does not create stdout and stderr anymore...
// FILE * my_stdout = freopen ("my_stdout.txt", "wb" /*or "wt"*/, stdout);
// FILE * my_stderr = freopen ("my_stderr.txt", "wb" /*or "wt"*/, stderr);

Uint32 menu_timecounter;
bool QuitProgram;
bool QuitFromMenu;
bool QuitToMenu;
Config_Type Config;

void init();  // Starts up SDL and creates window
void close(); // Frees media and shuts down SDL
void iniSetup();

// ##############################################
// ##############################################
// ##############################################

void mainloop()
{
  if(!QuitProgram) {
    Options_Save(); // SAVE OPTIONS TO FILE
    close(); // Free resources and close SDL
    #ifdef __EMSCRIPTEN__
    emscripten_cancel_main_loop();  /* this should "kill" the app. */
    #else
    exit(0);
    #endif
  }
  QuitFromMenu = false;
  QuitToMenu = true;
  menu_timecounter=SDL_GetTicks();
  GV.Mode = MODE_MENU;
  Menu.MenuEntriesMainMenu = 10;
  Menu.ActiveMainMenu = 0;

  SYSTEM_SetResolution(GV.Resolution);

  while(!QuitProgram)
  {
    getInput();
    INPUT_General();


    Menu.Active = Menu.ActiveMainMenu;
    Menu.MenuEntries = Menu.MenuEntriesMainMenu;

    if(Key_RIGHT_pressed || Joy_RIGHT_pressed)
    {
      Menu.ActiveMainMenu += 1;
      if(Menu.ActiveMainMenu > Menu.MenuEntriesMainMenu-1){Menu.ActiveMainMenu = Menu.MenuEntriesMainMenu-1;}
      Audio::playSound(Audio::AudioTypeEnum::AUDIO_CLICK);
    }

    if(Key_LEFT_pressed || Joy_LEFT_pressed)
    {
      Menu.ActiveMainMenu -= 1;
      if(Menu.ActiveMainMenu < 0){Menu.ActiveMainMenu = 0;}
      Audio::playSound(Audio::AudioTypeEnum::AUDIO_CLICK);
    }

    if(Key_DOWN_pressed || Joy_DOWN_pressed)
    {
      if(Menu.ActiveMainMenu < Menu.MenuEntriesMainMenu-Menu.Cols){Menu.ActiveMainMenu = Menu.ActiveMainMenu + Menu.Cols;}
      Audio::playSound(Audio::AudioTypeEnum::AUDIO_CLICK);
    }

    if(Key_UP_pressed || Joy_UP_pressed)
    {
      if(Menu.ActiveMainMenu > Menu.Cols-1){Menu.ActiveMainMenu = Menu.ActiveMainMenu - Menu.Cols;}
      Audio::playSound(Audio::AudioTypeEnum::AUDIO_CLICK);
    }


    if(Key_ESCAPE_pressed || Joy_ESCAPE_pressed)                     {QuitProgram = true;}

    //if(Key_F1_pressed) {GV.GameType = TYPE_C64;     GAMETYPE_Load();}
    //if(Key_F2_pressed) {GV.GameType = TYPE_OPENGGS; GAMETYPE_Load();}
    //if(Key_F3_pressed) {GV.GameType = TYPE_AMIGA;   GAMETYPE_Load();}


    if(!Key_LALT)
    {
      if((Key_ENTER_pressed || Joy_OK_pressed) && Menu.ActiveMainMenu == 0) {LOOP_Gameloop_Standard();}
      if((Key_ENTER_pressed || Joy_OK_pressed) && Menu.ActiveMainMenu == 1) {GV.GameType = TYPE_C64; GAMETYPE_Load();}
      if((Key_ENTER_pressed || Joy_OK_pressed) && Menu.ActiveMainMenu == 2) {GV.GameType = TYPE_AMIGA; GAMETYPE_Load();}
      //if((Key_ENTER_pressed || Joy_OK_pressed) && Menu.ActiveMainMenu == 3) {GV.GameType = TYPE_OPENGGS; GAMETYPE_Load();}
      if((Key_ENTER_pressed || Joy_OK_pressed) && Menu.ActiveMainMenu == 4) {LOOP_Editor_Stages();}
      if((Key_ENTER_pressed || Joy_OK_pressed) && Menu.ActiveMainMenu == 5) {LOOP_Options();}
      if((Key_ENTER_pressed || Joy_OK_pressed) && Menu.ActiveMainMenu == 6) {LOOP_Story();}
      if((Key_ENTER_pressed || Joy_OK_pressed) && Menu.ActiveMainMenu == 7) {LOOP_Stagefile_Load();}
      if((Key_ENTER_pressed || Joy_OK_pressed) && Menu.ActiveMainMenu == 8) {LOOP_Credits();}
      if((Key_ENTER_pressed || Joy_OK_pressed) && Menu.ActiveMainMenu == 9) {QuitProgram = true;}



      if(Key_F1_pressed){SYSTEM_SetResolution(RESOLUTION_640x480);}
      if(Key_F2_pressed){SYSTEM_SetResolution(RESOLUTION_800x600);}
      if(Key_F3_pressed){SYSTEM_SetResolution(RESOLUTION_1280x720);}

    }
    if(QuitToMenu)
    {
      QuitToMenu = false;
      Audio::playMusic(Audio::MusicTypeEnum::MUSIC_MENU);
    }
    Update_Screen();  // draw the scene
  }
  Options_Save(); // SAVE OPTIONS TO FILE
}

int main(int argc, char *args[]) {

  // spdlog::info("started openggs..");
  auto defined = GameEnvironment::define();

  GAME_ENVIRONMENT_Define();

  init();            // Start up SDL and create window
  srand(time(NULL)); // initialize random seed
  defineAngles();

  Option_GameType_Load();
  GAMETYPE_Load(); // Content load, audio define

  QuitProgram = false;

    #ifdef __EMSCRIPTEN__
    emscripten_set_main_loop(mainloop, 0, 1);
    #else
    while (1) { mainloop(); }
    #endif
}

// ##############################################
// ##############################################
// ##############################################

void close() {

  // Destroy window
  SDL_DestroyRenderer(gRenderer);
  SDL_DestroyWindow(gWindow);
  // SDL_JoystickClose( GameController );
  //  GameController = NULL;

  gWindow = NULL;
  gRenderer = NULL;
  // Quit SDL subsystems
  IMG_Quit();
  SDL_Quit();
}

// ##############################################
// ##############################################
// ##############################################

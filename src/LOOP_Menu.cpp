#include "globals.h"
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

Menu_Def Menu;

// ##############################################
// ##############################################
// ##############################################

void LOOP_Menu()
{
}

// ##############################################
// ##############################################
// ##############################################

void LOOP_Menu_Draw()
{
  int x;
  int Colour = 0;
  SDL_Rect SrcRect;
  SDL_Rect DstRect;
  SrcRect.x = 0;
  SrcRect.y = 208;
  SrcRect.w = 128;
  SrcRect.h = 96;
  DstRect.w = SrcRect.w;
  DstRect.h = SrcRect.h;


  for(x=0;x<Menu.MenuEntries;x++)
  {
    DstRect.x = Menu.x[x];
    DstRect.y = Menu.y[x];
    SDL_RenderCopyEx(gRenderer, InterfaceTexture, &SrcRect, &DstRect, 0, NULL, SDL_FLIP_NONE );
  }

  SrcRect.x = 128;
  DstRect.x = Menu.x[Menu.Active];
  DstRect.y = Menu.y[Menu.Active];
  SDL_RenderCopyEx(gRenderer, InterfaceTexture, &SrcRect, &DstRect, 0, NULL, SDL_FLIP_NONE );


  Colour = 0;
  SrcRect.x = 256;
  SrcRect.y = 240;
  SrcRect.w = 32;
  SrcRect.h = 32;
  DstRect.w = SrcRect.w;
  DstRect.h = SrcRect.h;
  DstRect.x = Menu.x[0]+86;
  DstRect.y = Menu.y[0]+56;
  SDL_RenderCopyEx(gRenderer, InterfaceTexture, &SrcRect, &DstRect, 0, NULL, SDL_FLIP_NONE );
  Print(Menu.x[0]+10, Menu.y[0]+10, Colour, 0, "Start /");
  Print(Menu.x[0]+10, Menu.y[0]+22, Colour, 0, "Resume");

  Colour = 2;
  if(GV.DirAmigaExists || GV.DirDefaultExists)
  {
  if(GV.GameType == TYPE_C64){Colour = 3;}
  Print(Menu.x[1]+10, Menu.y[1]+10, Colour, 0, "Load");
  Print(Menu.x[1]+10, Menu.y[1]+22, Colour, 0, "C64-Version");
  }

  Colour = 2;
  if(GV.DirAmigaExists)
  {
  if(GV.GameType == TYPE_AMIGA){Colour = 3;}
  Print(Menu.x[2]+10, Menu.y[2]+10, Colour, 0, "Load");
  Print(Menu.x[2]+10, Menu.y[2]+22, Colour, 0, "Amiga-");
  Print(Menu.x[2]+10, Menu.y[2]+34, Colour, 0, "Version");
  }

  Colour = 2;
  if(GV.DirDefaultExists)
  {
    if(GV.GameType == TYPE_OPENGGS){Colour = 3;}
    Print(Menu.x[3]+10, Menu.y[3]+10, Colour, 0, "Load");
    Print(Menu.x[3]+10, Menu.y[3]+22, Colour, 0, "OpenGGS-");
    Print(Menu.x[3]+10, Menu.y[3]+34, Colour, 0, "Version");
  }

  Colour = 0;
  SrcRect.x = 288;
  SrcRect.y = 272;
  SrcRect.w = 32;
  SrcRect.h = 32;
  DstRect.w = SrcRect.w;
  DstRect.h = SrcRect.h;
  DstRect.x = Menu.x[4]+86;
  DstRect.y = Menu.y[4]+56;
  SDL_RenderCopyEx(gRenderer, InterfaceTexture, &SrcRect, &DstRect, 0, NULL, SDL_FLIP_NONE );
  Print(Menu.x[4]+10, Menu.y[4]+10, Colour, 0, "Stage");
  Print(Menu.x[4]+10, Menu.y[4]+22, Colour, 0, "Editor");

  SrcRect.x = 288;
  SrcRect.y = 208;
  SrcRect.w = 32;
  SrcRect.h = 32;
  DstRect.w = SrcRect.w;
  DstRect.h = SrcRect.h;
  DstRect.x = Menu.x[5]+86;
  DstRect.y = Menu.y[5]+56;
  SDL_RenderCopyEx(gRenderer, InterfaceTexture, &SrcRect, &DstRect, 0, NULL, SDL_FLIP_NONE );
  Print(Menu.x[5]+10, Menu.y[5]+10, Colour, 0, "Options");

  SrcRect.x = 256;
  SrcRect.y = 272;
  SrcRect.w = 32;
  SrcRect.h = 32;
  DstRect.w = SrcRect.w;
  DstRect.h = SrcRect.h;
  DstRect.x = Menu.x[6]+86;
  DstRect.y = Menu.y[6]+56;
  SDL_RenderCopyEx(gRenderer, InterfaceTexture, &SrcRect, &DstRect, 0, NULL, SDL_FLIP_NONE );
  Print(Menu.x[6]+10, Menu.y[6]+10, Colour, 0, "Story");

  Colour = 0;
  SrcRect.x = 256;
  SrcRect.y = 208;
  SrcRect.w = 32;
  SrcRect.h = 32;
  DstRect.w = SrcRect.w;
  DstRect.h = SrcRect.h;
  DstRect.x = Menu.x[7]+86;
  DstRect.y = Menu.y[7]+56;
  SDL_RenderCopyEx(gRenderer, InterfaceTexture, &SrcRect, &DstRect, 0, NULL, SDL_FLIP_NONE );
  Print(Menu.x[7]+10, Menu.y[7]+10, Colour, 0, "Load");
  Print(Menu.x[7]+10, Menu.y[7]+22, Colour, 0, "Stagefile");


  Colour = 0;
  SrcRect.x = 320;
  SrcRect.y = 208;
  SrcRect.w = 32;
  SrcRect.h = 32;
  DstRect.w = SrcRect.w;
  DstRect.h = SrcRect.h;
  DstRect.x = Menu.x[8]+86;
  DstRect.y = Menu.y[8]+56;
  SDL_RenderCopyEx(gRenderer, InterfaceTexture, &SrcRect, &DstRect, 0, NULL, SDL_FLIP_NONE );
  Print(Menu.x[8]+10, Menu.y[8]+10, Colour, 0, "Credits");

  Colour = 0;
  SrcRect.x = 288;
  SrcRect.y = 240;
  SrcRect.w = 32;
  SrcRect.h = 32;
  DstRect.w = SrcRect.w;
  DstRect.h = SrcRect.h;
  DstRect.x = Menu.x[9]+86;
  DstRect.y = Menu.y[9]+56;
  SDL_RenderCopyEx(gRenderer, InterfaceTexture, &SrcRect, &DstRect, 0, NULL, SDL_FLIP_NONE );
  Print(Menu.x[9]+10, Menu.y[9]+10, Colour, 0, "Quit");

  //Print(400, 48, 2, 0, FileName.Stage[0]);
  Print(20, GV.Screen_Height-12, 0, 0, "PAGEUP/DOWN - Volume");

/*
  Print(MenuPosX+400, MenuPosY, 2, 0, "Controls");
  Print(MenuPosX+400, MenuPosY+12, 0, 0, "Arrows - Walk, Jump");
  Print(MenuPosX+400, MenuPosY+24, 0, 0, "CTRL - Shoot");
*/

  // DRAW TITLESCREEN

  SrcRect.x = 0;
  SrcRect.y = 1000;
  SrcRect.w = 320;
  SrcRect.h = 200;
  DstRect.w = SrcRect.w;
  DstRect.h = SrcRect.h;
  DstRect.x = Menu.x[10];
  DstRect.y = Menu.y[10];
  SDL_RenderCopyEx(gRenderer, TilesTexture, &SrcRect, &DstRect, 0, NULL, SDL_FLIP_NONE );

  Print(20, 10, 0, 0, "OpenGGS 2.0 (OpenGGS Maker)");
}

// ##############################################
// ##############################################
// ##############################################

void LOOP_Menu_Define_Positions(int Cols)
{
  Menu.Cols = Cols;
  int MenuStartPosX = 20;
  int MenuStartPosY = 40;

  if(Menu.Cols == 5)
  {
    Menu.x[0] = MenuStartPosX;
    Menu.y[0] = MenuStartPosY;
    Menu.x[1] = Menu.x[0]+138;
    Menu.y[1] = Menu.y[0];
    Menu.x[2] = Menu.x[1]+138;
    Menu.y[2] = Menu.y[0];
    Menu.x[3] = Menu.x[2]+138;
    Menu.y[3] = Menu.y[0];
    Menu.x[4] = Menu.x[3]+138;
    Menu.y[4] = Menu.y[0];

    Menu.x[5] = MenuStartPosX;
    Menu.y[5] = Menu.y[0]+106;
    Menu.x[6] = Menu.x[5]+138;
    Menu.y[6] = Menu.y[5];
    Menu.x[7] = Menu.x[6]+138;
    Menu.y[7] = Menu.y[5];
    Menu.x[8] = Menu.x[7]+138;
    Menu.y[8] = Menu.y[5];
    Menu.x[9] = Menu.x[8]+138;
    Menu.y[9] = Menu.y[5];

    Menu.x[10] = MenuStartPosX;
    Menu.y[10] = Menu.y[5]+106;
    Menu.x[11] = Menu.x[10]+138;
    Menu.y[11] = Menu.y[10];
    Menu.x[12] = Menu.x[11]+138;
    Menu.y[12] = Menu.y[10];
    Menu.x[13] = Menu.x[12]+138;
    Menu.y[13] = Menu.y[10];
    Menu.x[14] = Menu.x[13]+138;
    Menu.y[14] = Menu.y[10];

    Menu.x[15] = MenuStartPosX;
    Menu.y[15] = Menu.y[10]+106;
  }

  if(Menu.Cols == 4)
  {
    Menu.x[0] = MenuStartPosX;
    Menu.y[0] = MenuStartPosY;
    Menu.x[1] = Menu.x[0]+138;
    Menu.y[1] = Menu.y[0];
    Menu.x[2] = Menu.x[1]+138;
    Menu.y[2] = Menu.y[0];
    Menu.x[3] = Menu.x[2]+138;
    Menu.y[3] = Menu.y[0];
    Menu.x[4] = MenuStartPosX;
    Menu.y[4] = Menu.y[0]+106;
    Menu.x[5] = Menu.x[4]+138;
    Menu.y[5] = Menu.y[4];
    Menu.x[6] = Menu.x[5]+138;
    Menu.y[6] = Menu.y[4];
    Menu.x[7] = Menu.x[6]+138;
    Menu.y[7] = Menu.y[4];
    Menu.x[8] = MenuStartPosX;
    Menu.y[8] = Menu.y[4]+106;
    Menu.x[9] = Menu.x[8]+138;
    Menu.y[9] = Menu.y[8];
    Menu.x[10] = Menu.x[9]+138;
    Menu.y[10] = Menu.y[8];
    Menu.x[11] = Menu.x[10]+138;
    Menu.y[11] = Menu.y[8];

    Menu.x[12] = MenuStartPosX;
    Menu.y[12] = Menu.y[8]+106;
    Menu.x[13] = Menu.x[12]+138;
    Menu.y[13] = Menu.y[12];
    Menu.x[14] = Menu.x[13]+138;
    Menu.y[14] = Menu.y[12];
    Menu.x[15] = Menu.x[14]+138;
    Menu.y[15] = Menu.y[12];

  }

  if(Menu.Cols == 3)
  {
    Menu.x[0] = MenuStartPosX;
    Menu.y[0] = MenuStartPosY;
    Menu.x[1] = Menu.x[0]+138;
    Menu.y[1] = Menu.y[0];
    Menu.x[2] = Menu.x[1]+138;
    Menu.y[2] = Menu.y[0];
    Menu.x[3] = MenuStartPosX;
    Menu.y[3] = Menu.y[0]+106;
    Menu.x[4] = Menu.x[3]+138;
    Menu.y[4] = Menu.y[3];
    Menu.x[5] = Menu.x[4]+138;
    Menu.y[5] = Menu.y[3];
    Menu.x[6] = MenuStartPosX;
    Menu.y[6] = Menu.y[3]+106;
    Menu.x[7] = Menu.x[6]+138;
    Menu.y[7] = Menu.y[6];
    Menu.x[8] = Menu.x[7]+138;
    Menu.y[8] = Menu.y[6];
    Menu.x[9] = MenuStartPosX;
    Menu.y[9] = Menu.y[6]+106;
    Menu.x[10] = Menu.x[9]+138;
    Menu.y[10] = Menu.y[9];
    Menu.x[11] = Menu.x[10]+138;
    Menu.y[11] = Menu.y[9];
    Menu.x[12] = MenuStartPosX;
    Menu.y[12] = Menu.y[9]+106;
    Menu.x[13] = Menu.x[12]+138;
    Menu.y[13] = Menu.y[12];
    Menu.x[14] = Menu.x[13]+138;
    Menu.y[14] = Menu.y[12];
    Menu.x[15] = MenuStartPosX;
    Menu.y[15] = Menu.y[12]+106;
  }
}

// ##############################################
// ##############################################
// ##############################################

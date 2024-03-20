# Emscripten

## Build

```
mkdir build && cd build
emcmake cmake ..
emmake make -j2
```

## Link

```
em++ -flto -fno-rtti -O3 ./CMakeFiles/openggs.dir/src/*.o -o index.html -sUSE_LIBPNG=1 -sUSE_SDL=2 -sUSE_SDL_IMAGE=2 -sSDL2_IMAGE_FORMATS='png' -sUSE_SDL_MIXER=2 -sSDL2_MIXER_FORMATS='wav' -sWASM=2 -sENVIRONMENT=web --preload-file base -Wl,-u,fileno -sASYNCIFY -sASYNCIFY_ONLY=["main","mainloop","GLES2_RenderPresent","Emscripten_GLES_SwapWindow","SDL_Delay","dynCall_v"] -sASYNCIFY_IGNORE_INDIRECT
```
cmake_minimum_required(VERSION 3.15)

find_program(CCACHE_PROGRAM ccache)
if(CCACHE_PROGRAM)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_PROGRAM}")
endif()


project(openggs VERSION 0.1)

message("${CMAKE_PROJECT_NAME} version ${CMAKE_PROJECT_VERSION}")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

if( ${CMAKE_SYSTEM_NAME} MATCHES "Emscripten")
    set(USE_FLAGS "-fno-rtti -O3 -sUSE_LIBPNG=1 -sUSE_SDL=2 -sUSE_SDL_IMAGE=2  -sSDL2_IMAGE_FORMATS='png' -sUSE_SDL_MIXER=2 -sSDL2_MIXER_FORMATS='wav' ")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${USE_FLAGS}")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${USE_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${USE_FLAGS}" -flto -Wl,-u,fileno -Wl,-u,_emscripten_run_callback_on_thread -sWASM=2 )
    set(CMAKE_EXECUTABLE_SUFFIX .html)
	include_directories(
		${EMSCRIPTEN_ROOT_PATH}/system
		${CMAKE_SOURCE_DIR}/include
		${SDL2_INCLUDE_DIRS}
		${SDL2_IMAGE_INCLUDE_DIRS}
		${SDL2_MIXER_INCLUDE_DIRS}
		/mnt/d/Development/emsdk/upstream/emscripten/cache/sysroot/include/spdlog/
	)
else()
	find_package(SDL2 REQUIRED)
	find_package(SDL2_image REQUIRED)
	find_package(SDL2_mixer REQUIRED)
endif()

include(FetchContent)

FetchContent_Declare(spdlog 
    GIT_REPOSITORY https://github.com/gabime/spdlog
    GIT_SHALLOW ON 
)

set(SPDLOG_BUILD_SHARED ON)
set(BUILD_SHARED_LIBS ON)

FetchContent_MakeAvailable(spdlog)

#find_package(spdlog)

set(CMAKE_CXX_STANDARD 17)
add_executable(${PROJECT_NAME} )
target_include_directories( ${PROJECT_NAME}
                    PRIVATE
                    ${SDL2_INCLUDE_DIR} 
                    ${SDL2_IMAGE_INCLUDE_DIR}
                    ${SDL2_MIXER_INCLUDE_DIR})


add_subdirectory(src)
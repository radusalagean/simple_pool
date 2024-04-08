cmake_minimum_required(VERSION 3.22.1)

project(SimplePool)

set(SOURCES
    "${CMAKE_SOURCE_DIR}/../../platform/PSP/main.cpp"
    "${CMAKE_SOURCE_DIR}/../../src/exception.cpp"
    "${CMAKE_SOURCE_DIR}/../../src/mainwindow.cpp"
    "${CMAKE_SOURCE_DIR}/../../src/texture.cpp"
    "${CMAKE_SOURCE_DIR}/../../src/font.cpp"
    "${CMAKE_SOURCE_DIR}/../../src/music.cpp"
    "${CMAKE_SOURCE_DIR}/../../src/gamestate.cpp"
    "${CMAKE_SOURCE_DIR}/../../src/intro.cpp"
    "${CMAKE_SOURCE_DIR}/../../src/level.cpp"
    "${CMAKE_SOURCE_DIR}/../../src/table.cpp"
    "${CMAKE_SOURCE_DIR}/../../src/subject.cpp"
    "${CMAKE_SOURCE_DIR}/../../src/observer.cpp"
    "${CMAKE_SOURCE_DIR}/../../src/rect.cpp"
    "${CMAKE_SOURCE_DIR}/../../src/ball.cpp"
    "${CMAKE_SOURCE_DIR}/../../src/collisionobserver.cpp"
    "${CMAKE_SOURCE_DIR}/../../src/audioobserver.cpp"
    "${CMAKE_SOURCE_DIR}/../../src/cue.cpp"
)


add_executable(${PROJECT_NAME} ${SOURCES})

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)

target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_INCLUDE_DIRS})
target_include_directories(${PROJECT_NAME} PRIVATE /usr/local/pspdev/psp/sdk/include/)

target_link_libraries(${PROJECT_NAME} PRIVATE
    ${SDL2_LIBRARIES} 
    ${SDL2_LIBRARY}
    ${SDL2_IMAGE_LIBRARIES}
    ${SDL2_TTF_LIBRARIES}
    ${SDL2_MIXER_LIBRARIES}
    SDL2_image SDL2_ttf SDL2_mixer vorbis jpeg png16 z pspdebug freetype ogg vorbisfile xmp bz2
)

if(PSP)
    create_pbp_file(
        TARGET ${PROJECT_NAME}
        ICON_PATH NULL
        BACKGROUND_PATH NULL
        PREVIEW_PATH NULL
        TITLE ${PROJECT_NAME}
    )
endif()
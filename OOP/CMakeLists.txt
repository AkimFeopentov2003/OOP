cmake_minimum_required(VERSION 3.23)
project(untitled2)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(untitled2 main.cpp Map/Field.cpp Map/Field.h Map/Cell.cpp Map/Cell.h Map/CellView.cpp Map/CellView.h Map/FieldView.cpp Map/FieldView.h Player/Player.cpp Player/Player.h Read/CommandReader.cpp Read/CommandReader.h Controller.cpp Controller.h Game/Game.cpp Game/Game.h Events/Event.cpp Events/Event.h)

target_link_libraries(untitled2 sfml-graphics sfml-audio)

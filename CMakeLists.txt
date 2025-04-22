cmake_minimum_required(VERSION 4.0)
project(ImpossibleBattleBoss)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SRC src/*)
file(GLOB_RECURSE HEADERS include/*)

add_executable(ImpossibleBattleBoss ${LIB_HEADERS} ${HEADERS} ${SRC})

target_link_directories(ImpossibleBattleBoss PUBLIC .)
target_include_directories(ImpossibleBattleBoss PUBLIC include)

target_link_libraries(ImpossibleBattleBoss GL)
target_link_libraries(ImpossibleBattleBoss stdc++fs)
target_link_libraries(ImpossibleBattleBoss png)
target_link_libraries(ImpossibleBattleBoss pthread)
target_link_libraries(ImpossibleBattleBoss X11)

project(tdd)
set (CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-lncurses")
add_executable(main
    console.cpp
    game_state.cpp
    main.cpp
    tiles.cpp
)

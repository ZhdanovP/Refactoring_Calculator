project(Chess)

set(BASE_DIR ${CMAKE_SOURCE_DIR})


set(SRC
    main.cpp
    ChessFigure.cpp
)

add_executable(${PROJECT_NAME}
    ${SRC}
)

# Declare the library
add_library(lib${PROJECT_NAME} STATIC
    ${SRC}
)

include_directories (
    ${CMAKE_SOURCE_DIR}/include
)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)


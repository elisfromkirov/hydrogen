add_library(freeride)

file(GLOB_RECURSE FREERIDE_INCLUDE *.hpp)
file(GLOB_RECURSE FREERIDE_SOURCE *.cpp)

target_include_directories(freeride
    PUBLIC
        .
    )

target_sources(freeride
    PUBLIC
        ${FREERIDE_INCLUDE}
    PRIVATE
        ${FREERIDE_SOURCE}
    )
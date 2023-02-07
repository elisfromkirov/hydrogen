add_library(hydrogen)

file(GLOB_RECURSE HYDROGEN_INCLUDE *.hpp)
file(GLOB_RECURSE HYDROGEN_SOURCE *.cpp)
file(GLOB_RECURSE HYDROGEN_ASSEMBLY *.s)

target_include_directories(hydrogen
    PUBLIC
        .
    )

target_sources(hydrogen
    PUBLIC
        ${HYDROGEN_INCLUDE}
    PRIVATE
        ${HYDROGEN_SOURCE}
        ${HYDROGEN_ASSEMBLY}
    )

target_link_libraries(hydrogen
    PUBLIC
        crutch
    )
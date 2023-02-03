add_library(light)

file(GLOB_RECURSE LIGHT_INCLUDE *.hpp)
file(GLOB_RECURSE LIGHT_SOURCE *.cpp)
file(GLOB_RECURSE LIGHT_ASSEMBLY *.s)

target_include_directories(light
    PUBLIC
        .
    )

target_sources(light
    PUBLIC
        ${LIGHT_INCLUDE}
    PRIVATE
        ${LIGHT_SOURCE}
        ${LIGHT_ASSEMBLY}
    )
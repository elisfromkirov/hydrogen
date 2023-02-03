add_executable(light_test)

file(GLOB_RECURSE LIGHT_TESTS_INCLUDE *.hpp)
file(GLOB_RECURSE LIGHT_TESTS_SOURCE *.cpp)

target_sources(light_test
    PUBLIC
        ${LIGHT_TESTS_INCLUDE}
    PRIVATE
        ${LIGHT_TESTS_SOURCE}
    )

target_link_libraries(light_test
    PUBLIC
        light
    )
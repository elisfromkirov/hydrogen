add_executable(hydrogen_tests)

file(GLOB_RECURSE HYDROGEN_TESTS_INCLUDE *.hpp)
file(GLOB_RECURSE HYDROGEN_TESTS_SOURCE *.cpp)

target_sources(hydrogen_tests
    PUBLIC
        ${HYDROGEN_TESTS_INCLUDE}
    PRIVATE
        ${HYDROGEN_TESTS_SOURCE}
    )

target_link_libraries(hydrogen_tests
    PUBLIC
        hydrogen
    )
add_executable(freeride_test)

file(GLOB_RECURSE FREERIDE_TESTS_INCLUDE *.hpp)
file(GLOB_RECURSE FREERIDE_TESTS_SOURCE *.cpp)

target_sources(freeride_test
    PUBLIC
        ${FREERIDE_TESTS_INCLUDE}
    PRIVATE
        ${FREERIDE_TESTS_SOURCE}
    )

target_link_libraries(freeride_test
    PUBLIC
        freeride
    )
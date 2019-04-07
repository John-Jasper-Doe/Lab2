cmake_minimum_required(VERSION 3.2)

# Project name.
# Check if there is an environment variable.
if ($ENV{TRAVIS_BUILD_NUMBER})
  project(ip_filter VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else ($ENV{TRAVIS_BUILD_NUMBER})
  project(ip_filter VERSION 0.0.1)
endif ($ENV{TRAVIS_BUILD_NUMBER})

# Search for the "boost" library to enable unit tests.
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

# Generate executable file.
add_executable(${PROJECT_NAME}
  "ip_filter.cpp" "io.cpp" "utils.cpp" "filter.cpp")

# Generate executable tests.
#add_executable(test_version test_version.cpp)


set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)

#set_target_properties(test_version PROPERTIES
#    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
#    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
#)


#target_link_libraries(test_version
#    ${Boost_LIBRARIES}
#    lib${PROJECT_NAME}
#)

#install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

#set(CPACK_GENERATOR DEB)

#set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
#set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
#set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

#set(CPACK_PACKAGE_CONTACT john.jasper.doe@gmail.com)
#set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

#include(CPack)

#enable_testing()

#add_test(test_version test_version)


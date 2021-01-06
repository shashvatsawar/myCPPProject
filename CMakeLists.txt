cmake_minimum_required(VERSION 3.0.0)
project(myProject VERSION 0.1.0)

include(CTest)
enable_testing()
file(GLOB my_algorithms CONFIGURE_DEPENDS "my_algorithms/*.cpp" "data_structures/*.tpp" "utilities/*.cpp" "header_files/*.h")
add_executable(myProject main.cpp ${my_algorithms})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

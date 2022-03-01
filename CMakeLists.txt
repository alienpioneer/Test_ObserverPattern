# CMakeList.txt : CMake project for Test_ObserverPattern, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Test_ObserverPattern")

# Add source to this project's executable.
add_executable (Test_ObserverPattern "Observer.cpp" "Observer.h" "main.cpp" "Clients.cpp" "Clients.h")

# TODO: Add tests and install targets if needed.

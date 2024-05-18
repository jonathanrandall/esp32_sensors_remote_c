cmake_minimum_required(VERSION 3.10)
project(SSLClient)

# Add the source file
add_executable(ssl_client esp32_comms.cpp)

# Link against the required libraries
target_link_libraries(ssl_client PRIVATE ssl crypto)

#mkdir build
#cd build
#cmake ..
#make
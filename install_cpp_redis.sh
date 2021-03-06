#!/bin/bash

apt-get update -y && apt-get install build-essential cmake redis -y

# Change to home directory
cd ~
# Clone the project
git clone https://github.com/cpp-redis/cpp_redis.git
# Go inside the project directory
cd cpp_redis
# Get tacopie submodule
git submodule init && git submodule update
# Create a build directory and move into it
mkdir build && cd build
# Generate the Makefile using CMake
cmake .. -DCMAKE_BUILD_TYPE=Release
# Build the library
make
# Install the library
make install

# Install tacopie 
cd ~/cpp_redis/tacopie
pwd
cmake .
make
make install

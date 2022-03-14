#!/bin/bash

./build_scenes.py scenes > src/scenes.c
mkdir -p build && cd build && cmake .. && make && cd .. && ./build/manager-go

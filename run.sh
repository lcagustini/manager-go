#!/bin/bash

./build_scenes.py scenes > src/built_scenes.c
mkdir -p build && cd build && cmake .. && make && cd .. && ./build/manager-go

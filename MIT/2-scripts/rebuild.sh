#!/usr/bin/bash

while true; do
    inotifywait -e close_write ./main.cpp
    g++ ./main.cpp -o main
done

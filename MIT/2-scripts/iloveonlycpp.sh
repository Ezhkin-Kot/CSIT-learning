#!/usr/bin/bash

find . -mindepth 1 ! -iname "*.cpp" -exec rm -rf {} +

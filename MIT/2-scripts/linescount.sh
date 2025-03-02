#!/usr/bin/bash

find . -type f \( -iname "*.cpp" -o -iname "*.h" \) -exec cat {} \; | wc -l


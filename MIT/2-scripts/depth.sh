#!/usr/bin/bash

find . -type f -iname "how_far_are_you.txt" -exec echo {} \; | grep -o "/" | wc -l


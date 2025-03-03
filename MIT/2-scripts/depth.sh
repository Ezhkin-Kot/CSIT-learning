#!/bin/bash

find . -type f -iname "how_far_are_you.txt" -exec echo {} \; | sed 's/.\///1' | grep -o "/" | wc -l


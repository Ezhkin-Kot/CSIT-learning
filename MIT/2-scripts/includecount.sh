#!/usr/bin/bash

if [[ "$1" != *.cpp && "$1" != *.h ]]; then
    echo "Error: file must be .cpp or .h"
    exit 1
fi

grep -c "#include\|# include" "$1"

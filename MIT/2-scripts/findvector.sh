#!/usr/bin/bash

grep -rl --include="*.cpp" "#include <vector>\|#include<vector>" .


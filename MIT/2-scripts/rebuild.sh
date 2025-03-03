#!/bin/bash

find . -name main.cpp | entr g++ main.cpp -o main


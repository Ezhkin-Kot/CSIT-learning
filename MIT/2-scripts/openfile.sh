#!/bin/bash

vim "$(find "$HOME" -type f | fzf)"

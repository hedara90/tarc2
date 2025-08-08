#! /bin/bash

if git submodule status | grep --quiet '^-'; then
    git submodule update --init --recursive --remote
fi
exit 0

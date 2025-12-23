#!/usr/bin/bash

if [[ $# -eq 0 ]]; then
    echo "Input error" >&2
    exit 1

elif [[ -f $1.c ]]; then
    gcc -Wall -Wextra -Wpedantic -O2 -std=gnu23 -o "$1" "$1".c

elif [[ -f $1.cpp ]]; then
    g++ -Wall -Wextra -Wpedantic -O2 -std=c++23 -o "$1" "$1".cpp

elif [[ ! -f $1.c ]] && [[ ! -f $1.cpp ]]; then
    echo "Arquivo nao encontrado" >&2
    exit 1

fi

exit 0

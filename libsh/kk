#!/usr/bin/bash

if [[ $# -eq 0 ]]; then
    echo "Missing parameters" >&2
    exit 1
fi

if [[ $# -gt 1 ]]; then
    gcc -Wall -Wextra -Wpedantic -O2 -std=gnu23 -o "$1" "$1".c "$2".c && ./"$1"
    exit

elif [[ -f $1.c ]]; then
    gcc -Wall -Wextra -Wpedantic -O2 -std=gnu23 -o "$1" "$1.c" && ./"$1"
    exit 

elif [[ -f $1.cpp ]]; then
    g++ -Wall -Wextra -Wpedantic -O2 -std=c++23 -o "$1" "$1.cpp" && ./"$1"
    exit

elif [[ -f $1.rs ]]; then
    rustc "$1.rs" && ./"$1"
    exit

elif [[ ! -f $1.c ]] && [[ ! -f $1.cpp ]]; then
    echo "Arquivos nao encontrados" >&2
    exit 1

fi

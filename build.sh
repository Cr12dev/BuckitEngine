#!/bin/bash

defines="-DENGINE"
libs="-luser32 -lopengl32 -lgdi32"
warnings="-Wno-writable-strings -Wno-format-security"
includes="-Iincludes"

timestamp=$(date +%s)

out="build"

mkdir -p "$out"

echo "Creando biblioteca dinamica"
"C:\Program Files\LLVM\bin\clang++.exe" \
    -g src/main.cpp \
    $includes \
    -shared \
    -o "$out/game_$timestamp.dll" \
    $warnings $defines

cp "$out/game_$timestamp.dll" "$out/game.dll"

echo "Construyendo lo principal"
"C:\Program Files\LLVM\bin\clang++.exe" \
    -g src/main.cpp \
    $includes \
    -o "$out/3dengine.exe" \
    $libs $warnings $defines
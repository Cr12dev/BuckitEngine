#!/bin/bash

defines="-DENGINE"
#todo: add all directx11 lib
libs="-luser32 -lopengl32 -lgdi32 -ld3d11 -ldxgi -ld3dcompiler"
warnings="-Wno-writable-strings -Wno-format-security"
includes="-Iinclude"

timestamp=$(date +%s)

out="build"
mkdir -p "$out"

echo "Creando biblioteca dinamica"
"C:\Program Files\LLVM\bin\clang++.exe" \
    -g src/main.cpp \
    $includes \
    -shared \
    -o "$out/game_$timestamp.dll" \
    $libs $warnings $defines

cp "$out/game_$timestamp.dll" "$out/game.dll"

echo "Construyendo lo principal"
"C:\Program Files\LLVM\bin\clang++.exe" \
    -g src/main.cpp \
    $includes \
    -o "$out/3dengine.exe" \
    $libs $warnings $defines
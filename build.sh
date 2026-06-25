#!/bin/bash

defines="-DENGINE"

includes="
-Iinclude
-Ithirdparty/glfw/include
-Ithirdparty/glad/include
"

libs="
-lopengl32
-lgdi32
-luser32
-lshell32
"

warnings="
-Wno-writable-strings
-Wno-format-security
"

out="build"
mkdir -p "$out"

echo "Compilando GLAD..."

"C:\Program Files\LLVM\bin\clang.exe" \
    -c thirdparty/glad/src/glad.c \
    $includes \
    -o "$out/glad.obj"

echo "Construyendo motor..."

"C:\Program Files\LLVM\bin\clang++.exe" \
    -g \
    src/main.cpp \
    "$out/glad.obj" \
    "thirdparty/glfw/lib/glfw3.lib" \
    $includes \
    $libs \
    $warnings \
    $defines \
    -fuse-ld=lld \
    -o "$out/3dengine.exe"
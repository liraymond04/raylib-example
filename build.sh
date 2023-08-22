#!/bin/bash

target_flag=''

while getopts ':t:' flag; do
  case "${flag}" in
    t) target_flag="$OPTARG" ;;
    *) exit 1 ;;
  esac
done


if [[ $target_flag == "web" ]]
then
  echo $target_flag
  [ ! -d "build/" ] && mkdir build
  cd build
  emcmake cmake .. -DPLATFORM=Web -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXE_LINKER_FLAGS="-s USE_GLFW=3" -DCMAKE_EXECUTABLE_SUFFIX=".html"
  emmake make
  cd ..
else
  cmake -B build
  cmake --build build
fi

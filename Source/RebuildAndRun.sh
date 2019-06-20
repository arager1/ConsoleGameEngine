#!/bin/bash

source_dir=$(dirname "$0")
build_dir=$source_dir/../Build
exe_path=$build_dir/bin/ConsoleGame

flag=${1:-d}

cd $build_dir

case $flag in
	-c|--clean) 
		echo "Cleaning build"
		make clean;;
	-d|--delta);; # Do nothing
esac

echo "Running CMake"
cmake $source_dir

cmake_retval=$?

if (( $cmake_retval == 0 )); then
	echo "Building source"
	make 
else
	echo "CMake failure"
fi

make_retval=$?

cd $source_dir

if (( $make_retval == 0 )); then
	echo "Executing binary"
	./$exe_path
else
	echo "Build failure"
fi

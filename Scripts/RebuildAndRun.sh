#!/bin/bash

root_dir=$(dirname "$0")
cmake_source_dir=$root_dir
build_dir=$root_dir/Build
exe_path=$build_dir/bin
exe_name=Game

echo "$0"

echo $cmake_source_dir
# buildTypeFlag=${1:-d}
# verboseFlag=${2:-q}

# cd $build_dir

# case $buildTypeFlag in
# 	-c|--clean) 
# 		echo "[$BASH_SOURCE] Cleaning build"
# 		make clean;;
# 	-d|--delta)
# 		echo "[$BASH_SOURCE] Delta build";;
# esac

# echo "[$BASH_SOURCE] Running CMake"
# echo $cmake_source_dir
# cmake $cmake_source_dir -DENGINE_ONLY_MODE:BOOL=True

# cmake_retval=$?

# if (( $cmake_retval == 0 )); then
# 	echo "[$BASH_SOURCE] Building source"
# 	case $verboseFlag in
# 		-v|--verbose)
# 			echo "[$BASH_SOURCE] Verbose build"
# 			make VERBOSE=1;;
# 		-q|--quiet)
# 			echo "[$BASH_SOURCE] Quiet build"
# 			make;;
# 	esac
# else
# 	echo "[$BASH_SOURCE] CMake failure"
# fi

# make_retval=$?

# cd $cmake_source_dir

# if (( $make_retval == 0 )); then
# 	echo "[$BASH_SOURCE] Executing binary"
# 	echo "[$BASH_SOURCE] $exe_path/$exe_name"
# 	$exe_path/$exe_name
# else
# 	echo "[$BASH_SOURCE] Build failure"
# fi

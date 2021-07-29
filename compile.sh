#!/bin/bash

gcc src/*.c -o release/csh && valgrind --leak-check=full ./release/csh

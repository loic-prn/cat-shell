#!/bin/bash

gcc *.c -o ../csh/prog && valgrind --leak-check=full ./../csh/prog

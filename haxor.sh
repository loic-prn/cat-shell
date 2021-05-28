#!/bin/bash

gcc *.c -o bin/prog && valgrind --leak-check=full ./bin/prog

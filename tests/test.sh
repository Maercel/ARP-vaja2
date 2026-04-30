#!/bin/bash

g++ main.cpp -o program

./program tests/test1_input.txt

diff primer_izhoda tests/test1_expected.txt

if [ $? -ne 0 ]; then
  echo "TEST FAILED"
  exit 1
else
  echo "TEST PASSED"
fi
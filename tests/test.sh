#!/bin/bash

g++ vaja2.cpp -o vaja2

./vaja2 tests/test1_expected.txt

diff primer_izhoda tests/test1_expected.txt

if [ $? -ne 0 ]; then
  echo "TEST FAILED"
  exit 1
else
  echo "TEST PASSED"
fi
#!/usr/bin/env bash

echo "Calling make..."


if ! make > /dev/null
 then
  echo 'Make failed....' >&2
  exit 1
fi

echo "Running tests"

if [ -n "$1" ]
 then
	./bin/run_tests -g $1 ./data
 else
	./bin/run_tests ./data
 fi

if [ $? = 0 ]
 then
   echo "Test(s) successful."
 else
   echo "Test(s) unsuccessful."
 fi

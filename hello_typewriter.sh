#!/bin/bash

string="Hello World!"

for (( i=0; i<${#string}; i++ )); do
    echo -n "${string:$i:1}"
    sleep 0.1
done

echo


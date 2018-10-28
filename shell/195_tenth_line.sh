#!/usr/bin/env bash

test $(wc -l file.txt | awk '{print $1}') -ge 10  && head -n 10 file.txt | tail -1

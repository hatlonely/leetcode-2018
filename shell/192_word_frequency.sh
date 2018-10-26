#!/usr/bin/env bash
cat words.txt | sed -E $'s/ +/\\\n/g' | sort | uniq -c | sort -k1nr | awk '{if($2!="")print $2,$1}'
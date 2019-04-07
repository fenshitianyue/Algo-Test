#!/bin/bash

# filename: file.txt 
# content: 
# 981-123-1234 # matched
# 123 789 891
# (123) 456-7890 # matched

grep -P '^(\(\d{3}\) |\d{3}-)\d{3}-\d{4}$' file.txt
# else
# grep '^\(([0-9]\{3\}) \|[0-9]\{3\}-\)[0-9]\{3\}-\{4\}$' file.txt

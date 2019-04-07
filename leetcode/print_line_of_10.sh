#!/bin/bash

# print line 10 of the file

# The first method
n=1
while read line 
do 
  if [ $n -eq 10 ] 
  then
    echo ${line}
    break
  else
    n=`expr $n + 1` 
  fi
done <file.txt

# The second method
tail -n+10 file.txt | head -1
# The third method
sed -n 10p file.txt
# The four method
awk 'NR == 10' file.txt

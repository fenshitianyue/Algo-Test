#!/bin/bash 

# Word frequency statistics

# filename:words.txt 
# content:
# the day is sunny the the 
# the sunny is is

# input:
# the 4 
# is 3 
# sunny 2
# day 1


awk '{for(i=1;i<=NF;i++){res[$i]+=1}}END{for(k in res){print k" "res[k]}}' words.txt | sort -nrk2

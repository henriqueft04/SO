#!/bin/bash 
#This script does a very simple test for checking disk space. 
space=$(df -h | awk '{print $5}' | grep % | grep -v Use | sort -n | tail -1 | cut -d "%" -f1 -)

space2=$(df -h | awk 'NR>1 {print $2, $1}' | sort -k1 -h | tail -1 -)
echo "largest occupied space = $space%"
echo "most space = $space2"

case $space in
    [0-6][0-9])    # espaço < 70%
    Message="All OK."
    ;; 
    [7-8][0-9])    # 70% <= espaço < 90%
    Message="Cleaning out. One partition is $space % full."
    ;; 
    [9][0-8])    # 90% <= espaço < 99%
    Message="Better buy a new disk.  One partition is $space % full."
    ;; 
    [99] )    # espaço = 99%
    Message="I'm drowning here!  There's a partition at $space %!"
    ;; 
    * ) 
    Message="I seem to be running with a non-existent disk..."
    ;; 
esac

echo $Message

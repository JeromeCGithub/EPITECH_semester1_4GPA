#!/bin/bash

if [[ $# -eq "0" ]] ; then 
    wc -l 
elif [ $# = 1 ]
then
    cut -d\; -f 3 | grep -c -i $1
fi

#!/bin/bash

cut -d\: -f 1 | rev | sed -n 'n;p' | sort -r | sed -n "${MY_LINE1},${MY_LINE2}p" | tr "\n" "," | sed -e 's/,/, /g' | sed -e 's/, $/./'


echo

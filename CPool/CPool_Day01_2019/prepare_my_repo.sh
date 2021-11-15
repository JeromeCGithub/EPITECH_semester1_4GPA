#!/bin/bash

blih -u jerome.collet@epitech.eu repository create $1
blih -u jerome.collet@epitech.eu repository setacl $1 ramassage-tek r
blih -u jerome.collet@epitech.eu repository getacl $1

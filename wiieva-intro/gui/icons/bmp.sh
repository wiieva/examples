#!/bin/sh

find *.png | sed "s/\.png//" | xargs -n1 -Ixxx convert xxx.png -background white -alpha remove xxx.bmp
find {back.png,wifi*.png,batt*.png,menu*.png} | sed "s/\.png//" | xargs -n1 -Ixxx convert xxx.png -background '#e6e6e6' -alpha remove xxx.bmp

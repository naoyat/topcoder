#!/bin/sh
EXE=./3a

rm -f png/*.png
# for s in 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 ; do
for s in 1 2 3 4 5 6 7 8 9 10 ; do
  java -jar Visualizer.jar -exec "$EXE" -seed $s -vis "png/seed$s"
done
open png/seed*.png


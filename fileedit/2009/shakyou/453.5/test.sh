#!/bin/sh

if [ x$1 = x ]; then
  NAME=naoya_t
else
  NAME=$1
fi

if [ x$2 = x ]; then
  LEVEL=250
else
  LEVEL=$2
fi

MERGED=${NAME}_${LEVEL}_temp

cat ${NAME}_${LEVEL}.cc ${LEVEL}test.cc > ${MERGED}.cc

g++ -O3 -o ${MERGED} ${MERGED}.cc

./${MERGED}


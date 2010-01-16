#!/bin/sh
./test.sh $1 $2 2>&1 | awk 'BEGIN {
 FS = "[() ]"
}
{
 print $5
}'

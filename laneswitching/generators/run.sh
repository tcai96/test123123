#!/bin/bash

for FILE in *.in ; do
    OUT=`echo $FILE | sed -e 's/.in/.ans/'`
    echo $FILE $OUT
    ../submissions/accepted/lanes-hc < "$FILE" > "$OUT"
done

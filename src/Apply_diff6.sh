#!/bin/sh

for i in *.diff6
do
  SIMPLE_BACKUP_SUFFIX=.orig6  patch  -b < $i
done


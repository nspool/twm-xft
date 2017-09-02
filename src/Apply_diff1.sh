#!/bin/sh

for i in *.diff1
do
  SIMPLE_BACKUP_SUFFIX=.orig1  patch  -b < $i
done


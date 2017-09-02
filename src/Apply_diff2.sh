#!/bin/sh

for i in *.diff2
do
  SIMPLE_BACKUP_SUFFIX=.orig2  patch  -b < $i
done


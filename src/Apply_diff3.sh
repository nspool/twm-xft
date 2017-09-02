#!/bin/sh

for i in *.diff3
do
  SIMPLE_BACKUP_SUFFIX=.orig3  patch  -b < $i
done


#!/bin/sh

for i in *.diff4
do
  SIMPLE_BACKUP_SUFFIX=.orig4  patch  -b < $i
done


#!/bin/sh

for i in *.diff7
do
  SIMPLE_BACKUP_SUFFIX=.orig7  patch  -b < $i
done


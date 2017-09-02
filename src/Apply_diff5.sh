#!/bin/sh

for i in *.diff5
do
  SIMPLE_BACKUP_SUFFIX=.orig5  patch  -b < $i
done


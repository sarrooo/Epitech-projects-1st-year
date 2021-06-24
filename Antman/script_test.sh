#!/bin/bash
./compress $1 1 > pack_files
./uncompress pack_files 1 > unpack_files

size_1=$(stat -c%s pack_files)
size_2=$(stat -c%s $1)
result=$(diff -y -W 72 $1 unpack_files)

if [ $? -eq 0 ]
then
        echo "Compression OK"
        echo "Taille original -> "$size_2" octets"
        echo "Taille compréssé -> "$size_1" octets"
        echo "$((100-"$size_1"*100/"$size_2"))% économisé"
else
        echo "Difference Fichier"
fi

rm unpack_files
rm pack_files
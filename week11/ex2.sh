#!/bin/bash

Temp=lofsdisk

echo Artur > $Temp/file1
echo Eremov > $Temp/file2
chmod 777 $Temp/

mkdir -p $Temp/{bin,lib64,lib}
mkdir -p $Temp/lib/x86_64-linux-gnu
cp /bin/{bash,cat,echo,ls} $Temp/bin

list="$(ldd /bin/bash | egrep -o '/lib.*\.[0-9]')"
for i in $list; do sudo cp "$i" "${Temp}${i}"; done

list="$(ldd /bin/cat | egrep -o '/lib.*\.[0-9]')"
for i in $list; do sudo cp "$i" "${Temp}${i}"; done

list="$(ldd /bin/echo | egrep -o '/lib.*\.[0-9]')"
for i in $list; do sudo cp "$i" "${Temp}${i}"; done

list="$(ldd /bin/ls | egrep -o '/lib.*\.[0-9]')"
for i in $list; do sudo cp "$i" "${Temp}${i}"; done

gcc -o ex2.out ex2.c
chmod +x ex2.out
cp ./ex2.out $Temp/
chmod +x $Temp/ex2.out

chroot $Temp ./ex2.out > ex2.txt
echo '' >> ex2.txt
./ex2.out >> ex2.txt

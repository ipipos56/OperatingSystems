#!/bin/bash

sudo fallocate -l 50M lofs.img
sudo losetup -f lofs.img

tempA=$(losetup -a | grep 'lofs.img' | awk '{print $1}' | cut -d ':' -f 1)

sudo mkfs.ext4 $tempA

mkdir lofsdisk
sudo mount $tempA ./lofsdisk

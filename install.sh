#!/bin/bash

########################################
##### Installing paru (AUR Helper) #####
########################################
if ! command -v paru &> /dev/null
then
    printf "\n"
    printf "########################################\n"
    printf "##### Installing paru (AUR Helper) #####\n"
    printf "########################################\n\n"
    git clone https://aur.archlinux.org/paru-bin.git
    cd paru-bin
    makepkg -si
else
    printf "\n"
    printf "#######################################\n"
    printf "###### paru is already installed ######\n"
    printf "#######################################\n"
fi

printf "\n"
printf "#########################################\n"
printf "##### Installing suckless utilities #####\n"
printf "#########################################\n\n"
git clone https://github.com/alokshandilya/suckless.git
cd suckless/dwm
sudo make clean install
cd ../dwmblocks
sudo make clean install
cd ../st
sudo make clean install
cp -r ../.dwm ~/
cd

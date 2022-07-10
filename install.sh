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

printf "\n"
printf "#########################################\n"
printf "##### Installing fonts and packages #####\n"
printf "#########################################\n\n"
paru -S libxft-bgra nerd-fonts-jetbrains-mono ttf-fira-code nerd-fonts-fira-code wget bat dash

printf "\n"
printf "##############################\n"
printf "##### Installing lightdm #####\n"
printf "##############################\n\n"
paru -S lxappearance numlockx copyq conky feh bpytop ranger rofi nitrogen kvantum-qt5 kvantum-theme-materia qt5ct dunst thunar lightdm lightdm-webkit2-greeter lightdm-gtk-greeter
sudo systemctl enable lightdm

# polkit
paru -S gnome-keyring lxsession

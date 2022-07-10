#!/bin/bash

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

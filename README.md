# My Personal DWM build 🌟

## About dwm 🐧

dwm is an extremely fast, small and dynamic window manager for X.

## Requirements ✏️

- `script` will grab dependencies (assuming you run `Arch Linux` or it's derivatives) and make, install suckless utilities.
- In order to build dwm you need the _Xlib header files_.
- [***libxft-bgra***](https://aur.archlinux.org/packages/libxft-bgra-git) for coloured emojis in suckless utilities.
  - comment `iscol` in **drw.c**

## Installation 🎙️

``` sh
git clone https://github.com/alokshandilya/suckless.git
cd suckless
./install.sh
```

- `git clone` this repo and run `install.sh` ...
> assuming you are on **Arch linux** or it's derivative

## Patches 🧰

- status2d
- systray
- xrdb
- status2d-xrdb
- cool-autostart
- switchtotag
- vanitygaps
- cfacts
- pertag
- alwayscenter
- cyclelayouts
- ~~fancybar~~ awesomebar
- winicon
- movestack
- scratchpad
- actualfullscreen
- alttagsdecoration
- restartsig
- keychord
- statuspadding
- ***maybe more I don't remember exactly...***

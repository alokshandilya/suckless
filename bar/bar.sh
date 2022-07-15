#!/bin/dash

# ^c$var^ = fg color
# ^b$var^ = bg color

interval=0

# load colors
. ~/Documents/suckless/bar/gruvchad

up_time() {
  printf "^c$pink^ ﮮ "
  upt="$(uptime --pretty | sed -e 's/up //g' -e 's/ days/d/g' -e 's/ day/d/g' -e 's/ hours/h/g' -e 's/ hour/h/g' -e 's/ minutes/m/g' -e 's/, / /g')"
  echo "^c$white^$upt "
}

pkg_updates() {
  # updates=$(doas xbps-install -un | wc -l) # void
  updates=$(checkupdates | wc -l)   # arch
  # updates=$(aptitude search '~U' | wc -l)  # apt (ubuntu,debian etc)

  if [ -z "$updates" ]; then
    printf "^c$orange^ ^c$white^0" # padding
  else
    printf "^c$orange^ ^c$white^$updates" # padding
  fi
}

brightness() {
  printf "^c$blue^  "
  printf "^c$white^%.0f\n" $(cat /sys/class/backlight/*/brightness)
}

cpu() {
  cpu_val=$(top -bn1 | grep "Cpu(s)" | sed "s/.*, *\([0-9.]*\)%* id.*/\1/" | awk '{print 100 - $1}')
  printf "^c$green^  "
  echo "^c$white^$cpu_val%"
}

mem() {
  printf "^c$pink^ 瑱 "
  mem="$(free -h | awk '/^Mem:/ {print $3 "/" $2}')"
  printf "^c$white^$mem"
}

battery() {
  get_capacity="$(cat /sys/class/power_supply/BAT1/capacity)"
  echo "^c$orange^   ^c$white^$get_capacity%"
}

volume() {
  vol="$(amixer get Master | tail -n1 | sed -r 's/.*\[(.*)%\].*/\1/')"
  printf "^c$blue^  "
  echo "^c$white^$vol%"
}

clock() {
  printf "^c$red^  "
  dte="$(date +"%a, %B %d %l:%M%p"| sed 's/  / /g')"
  printf "^c$white^$dte"
}

while true; do

  [ $interval = 0 ] || [ $(($interval % 3600)) = 0 ] && updates=$(pkg_updates)
  interval=$((interval + 1))

  sleep 1 && xsetroot -name "$(up_time) $(pkg_updates) $(brightness) $(cpu) $(mem) $(battery) $(volume) $(clock)"
done

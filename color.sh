#!/bin/bash
esc="\033["
echo "      40      41      42      43      44      45      46      47"
for fore in 30 31 32 33 34 35 36 37; do
line1="$fore "
line2=" "
line3=" "
for back in 40 41 42 43 44 45 46 47 ; do
line1="${line1}${esc}${back};${fore}m Normal ${esc}0m"
line2="${line2}${esc}${back};${fore};1m  Bold  ${esc}0m"
line3="${line3}${esc}${back};${fore};2m  Thin  ${esc}0m"
done
echo "$line1\n  $line2\n  $line3"
done

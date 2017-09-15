#!/bin/bash
esc="\033["
cols=$( tput cols)
rows=$( tput lines)
txt=15

print_title () {
	local title=$1
	local lenght=${#title}
	local half=$(( $lenght / 2 ))
	local mid=$(( ($cols / 2) - $half ))
	tput cup $( tput lines ) $mid
	echo $title
	tput cup $( tput lines ) 0
}

print_standard () {
	print_title 'Standard colors'
	for bit in {0..7}
	do
		line="${line}${esc}48;5;${bit}m${esc}38;5;15m ${bit} ${esc}0m "
	done
	echo $line"\n"
}

print_high () {
	print_title 'High-intensity colors'
	for hi in {8..9}
	do
		line1="${line1}${esc}48;5;${hi}m${esc}38;5;0m ${hi} ${esc}0m "
	done
	for hi in {10..15}
	do
		line1="${line1}${esc}48;5;${hi}m${esc}38;5;0m ${hi}${esc}0m "
	done
	echo $line1"\n"
}


print_216 () {
	print_title '216 colors'
	for color in {16..231}
	do
		if [ $color -lt 100 ]
		then
			line2="${line2}${esc}48;5;${color}m${esc}38;5;${txt}m ${color}${esc}0m "
		else
			line2="${line2}${esc}48;5;${color}m${esc}38;5;${txt}m${color}${esc}0m "
		fi
		(( color++ ))
		if (( ($color - 16) % 36 == 0 ))
		then
			line2="${line2}\n"
		fi
		if  (( ($color -16) % 36 <= 17))
		then
			txt=15
		else
			txt=0
		fi
	done
echo $line2"\n"
}

print_grayscale () {
	print_title "Grayscale colors"
	for gray in {232..255}
	do
		if [ $gray -lt 244 ]
		then
			line3="${line3}${esc}48;5;${gray}m${esc}38;5;15m${gray}${esc}0m "
		else
			line3="${line3}${esc}48;5;${gray}m${esc}38;5;0m${gray}${esc}0m "
		fi
		(( gray++ ))
	done
	echo $line3
}

print_standard
print_high
print_216
print_grayscale

#!/bin/bash

# Please enter the complete path of the directory where u have you lem-in
LEM_IN_DIR='../'
TOTAL_OK=0
EMPTY=1
FULL=2
#

get_max_len()
{
	len=0
	list=`ls -1R map | grep ".map"`
	for name in $list
	do
		if [ ${#name} -gt $len ]
		then
			len=${#name}
		fi
	done
	return $len
}

# $1 -> le nom du fichier en train d'etre check
print_space()
{
	word_len=${#1}
	while [ $word_len -lt $MAX_LEN ]
	do
		echo -e " \c"
		let "word_len++"
	done
}

intro()
{
	echo -e "\033[31mTests could not have only one interpretation,\nthink and make your own if you don't agree with one test"
	echo -e "If you use it to correct someone, be careful and be open minded. \033[0m"
}

end()
{
	# echo -e "\nTEST WITH SUCESS : \033[32m $TOTAL_OK \033[0m"
	echo -e "\nPlease report any bug to mressier@student.42.fr"
}

compile_lem_in()
{
	make -C $LEM_IN_DIR && return 1
	return 0
}

print_title()
{
	echo -e "\033[34m***************************************************************\033[0m\n"
	echo -e "\033[34m \t\t\t$1\t \033[0m\n"
}

test_big_fail()
{
	ret=0
	if [ -n "$content" ]
	then
		ret=1
		segfault=`cat map/error_file | grep -i "Segmentation fault"`
		bus_error=`cat map/error_file | grep -i "bus error"`
		abort=`cat map/error_file | grep -i "abort"`
		echo -e "\033[36m\c"
		if [ -n "$segfault" ]
		then
			echo -e "\t[  SEG  ]\033[0m"
		elif [ -n "$bus_error" ]
		then
			echo -e "\t[  BUS  ]\033[0m"
		elif [ -n "$abort" ]
		then
			echo -e "\t[  ABRT  ]\033[0m"
		else
			ret=0
		fi
	fi
	echo -e "\033[0m\c"
	return $ret
}

# $1 => 1 : verifier si error_file est vide ; 2 : verifier si error_file est ecrit
test_fichier()
{
	content=`cat map/error_file`
	test_big_fail
	if [ $? -eq 1 ]
	then
		return
	fi
 	if [ $1 -eq $EMPTY ] && [ -n "$content" ]
 	then
		echo -e "\t[ \033[31m FAIL \033[0m ]"
	elif [ $1 -eq $FULL ] && [ -z "$content" ]
	then
		echo -e "\t[ \033[31m FAIL \033[0m ]"
	else
		echo -e "\t[ \033[32m OK \033[0m ]\c"
		if [ "$pb" -ne 0 ] && [ $1 -eq 1 ]
		then
			echo -e " Error exit status : check this test"
		else
			echo -e ""
		fi
	fi
}

# $1 => variable contenant les fichiers
# $2 => variable contenant le nom du dossier contenant les fichiers
# $3 => 1 : verifier si error_file est vide ; 2 : verifier si error_file est ecrit

test_parsing_map()
{
	for one_map in $1
	do
		$LEM_IN_DIR/lem-in $2/$one_map 2>map/error_file 1>map/valid_file
		pb=$?
		echo -e "$one_map" ": \c"
		print_space $one_map
		test_fichier $3
	done
}

# $1 : contient le dossier dans lequel recuperer les noms de fichier

get_all_files()
{
	files=$(ls $1 | grep \.map)
	if [ -z "$files" ]
	then
		return 0
	fi
	files=$(echo -e $files | sort -)
	files=$(echo -e $files | tr " " "\n")
	return 1
}

# $1 is the dir where to find maps
# $2 contain "empty" or "full"
# $3 is the title of the sequence
new_test()
{
	print_title "$3"
	map_dir=$1
	echo -e "\033[35mPATH : " $map_dir "\033[0m"
	get_all_files $map_dir
	if [ $? -eq 1 ]
	then
		test_parsing_map "$files" "$map_dir" $2
	fi
}

#
# MAIN
#

mode=$1
compile_lem_in
get_max_len
MAX_LEN=$?
# intro
if [ $? ]
then
	echo -e "\n"

	new_test "map/valid_map" $EMPTY "VALID TEST"
	new_test "map/unvalid_map" $FULL "UNVALID TEST"
	new_test "map/ant_error" $FULL "UNVALID ANT TEST"
	new_test "map/room_error" $FULL "UNVALID ROOM TEST"
	new_test "map/tube_error" $FULL "UNVALID TUBE TEST"
	new_test "map/command_map_error" $FULL "UNVALID COMMAND TEST"
	new_test "map/valid_comment_map" $EMPTY "VALID COMMENT MAP"
	new_test "map/valid_command_map" $EMPTY "VALID COMMAND MAP"
	new_test "map/valid_tube_map" $EMPTY "VALID TUBE MAP"
	new_test "map/valid_form_map" $EMPTY "VALID FORM MAP"
	new_test "map/uncomplete_valid_map" $EMPTY "UNCOMPLETE VALID MAP"
fi
rm map/valid_file map/error_file
end

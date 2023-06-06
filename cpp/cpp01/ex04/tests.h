/*
	Copy instructions into terminal.

 	##	Non existing filename ##
	./replace NON_EXISTING_FILE ARG1 ARG2

	##	Invalid number of arguments ##
	./replace
	./replace 1 2 3 4
	./replace 1
	./replace "1 2 3 " "4 5 6" "7 8 9" "0"

	##	Empty arguments ##
	./replace main.cpp "" ""
	./replace main.cpp "" "abc"
	./replace main.cpp "include" ""

 	## Normal input ##
 	./replace main.cpp "1" "1"
 	./replace main.cpp "1" "THERE USED TO BE A 1 HERE"
 	./replace main.cpp "NOTHING WILL CHANGE" "IF THE FIRST STRING DOESNT OCCUR IN THE FILE"
 */

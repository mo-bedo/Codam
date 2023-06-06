echo "Non existing filename:"
echo "Running: ./replace NON_EXISTING_FILE ARG1 ARG2"
./replace NON_EXISTING_FILE ARG1 ARG2

echo "\nInvalid number of arguments:"
echo "Running: ./replace"
	./replace
echo "Running: ./replace 1 2 3 4 "
	./replace 1 2 3 4
echo "Running: ./replace 1"
	./replace 1
echo "Running: ./replace \"1 2 3 \" \"4 5 6\" \"7 8 9\" \"0\""
	./replace "1 2 3 " "4 5 6" "7 8 9" "0"

echo "\nValid input:"
echo "Running: ./replace StringReplace.cpp \"\" \"\" "
	./replace StringReplace.cpp "" ""
echo "Running: ./replace NewFile.cpp \"\" \"abc\""
	./replace NewFile.cpp "" "abc"
echo "Running: ./replace InputFile.cpp \"include\" \"\""
	./replace InputFile.cpp "include" ""
echo "Running: ./replace main.cpp \"a\" \"###a WAS HERE###\""
 	./replace main.cpp "a" "###a WAS HERE###"
echo "Running	./replace InputFile.hpp \"NOTHING WILL CHANGE\" \"IF THE FIRST STRING DOESNT OCCUR IN THE FILE\""
 	./replace InputFile.hpp "NOTHING WILL CHANGE" "IF THE FIRST STRING DOESNT OCCUR IN THE FILE"

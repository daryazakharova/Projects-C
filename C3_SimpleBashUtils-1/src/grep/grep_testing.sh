#!/ bin / bash

echo "Testing non-existent file, except -f -l"
SUCCESS=0
FAIL=0
VERDICT=""
pattern=Muggles

for flag in -e -i -v -c -n -h -s
do
	./s21_grep $flag $pattern non_existent_file.txt > s21_grep.txt
	grep $flag $pattern non_existent_file.txt > grep.txt
	VERDICT="$(diff -s s21_grep.txt grep.txt)"
	if [ "$VERDICT" == "Files s21_grep.txt and grep.txt are identical" ]
	  then
	    (( SUCCESS++ ))
	  else
	    echo "flag $flag not passed"
	    (( FAIL++))
	fi
	rm s21_grep.txt grep.txt
done
echo "Passed successfully: $SUCCESS tests"
echo "Failed: $FAIL tests"
printf "\n"
# 
echo "Testing option stands at the end, except -f -l"
SUCCESS=0
FAIL=0
VERDICT=""
pattern=Muggles

for flag in -e -i -v -c -n -h -s
do
	./s21_grep  test.txt $flag $pattern> s21_grep.txt
	grep  test.txt $flag $pattern> grep.txt
	VERDICT="$(diff -s s21_grep.txt grep.txt)"
	if [ "$VERDICT" == "Files s21_grep.txt and grep.txt are identical" ]
	  then
	    (( SUCCESS++ ))
	  else
	    echo "flag $flag not passed"
	    (( FAIL++))
	fi
	rm s21_grep.txt grep.txt
done
echo "Passed successfully: $SUCCESS tests"
echo "Failed: $FAIL tests"
printf "\n"
# 
echo "Testing with 1 option, except -f -l"
SUCCESS=0
FAIL=0
VERDICT=""
pattern=Muggles
file=test2.txt

for flag in -e -i -v -c -n -h -s
do
	./s21_grep $flag $pattern test.txt > s21_grep.txt
	grep $flag $pattern test.txt > grep.txt
	VERDICT="$(diff -s s21_grep.txt grep.txt)"
	if [ "$VERDICT" == "Files s21_grep.txt and grep.txt are identical" ]
	  then
	    (( SUCCESS++ ))
	  else
	    echo "flag $flag not passed"
	    (( FAIL++))
	fi
	rm s21_grep.txt grep.txt
done
echo "Passed successfully: $SUCCESS tests"
echo "Failed: $FAIL tests"
printf "\n"
# 
echo "Dual option testing, except -f -l"
SUCCESS=0
FAIL=0
VERDICT=""
pattern=Muggles

for flag in -e -i -v -c -n -h -s
do
	for flag2 in e i v c n h s
	do
		if [ $flag != $flag2 ]
		then
		  ./s21_grep $flag$flag2 $pattern test.txt > s21_grep.txt
		  grep $flag$flag2 $pattern test.txt > grep.txt
		  VERDICT="$(diff -s s21_grep.txt grep.txt)"
		  if [ "$VERDICT" == "Files s21_grep.txt and grep.txt are identical" ]
		    then
		      (( SUCCESS++ ))
		    else
		      echo "flags $flag and $flag2 not passed"
		      (( FAIL++ ))
		 fi
		rm s21_grep.txt grep.txt
	     fi
	done
done
echo "Passed successfully: $SUCCESS tests"
echo "Failed: $FAIL tests"
printf "\n"
# 
echo "Testing -f"
SUCCESS=0
FAIL=0
VERDICT=""
file=test2.txt

for flag in -f
do
	./s21_grep $flag $file test.txt > s21_grep.txt
	grep $flag $file test.txt > grep.txt
	VERDICT="$(diff -s s21_grep.txt grep.txt)"
	if [ "$VERDICT" == "Files s21_grep.txt and grep.txt are identical" ]
	  then
	    (( SUCCESS++ ))
	  else
	    echo "flag $flag not passed"
	    (( FAIL++))
	fi
	rm s21_grep.txt grep.txt
done
echo "Passed successfully: $SUCCESS tests"
echo "Failed: $FAIL tests"
printf "\n"
# 
echo "Testing non-existent file -f"
SUCCESS=0
FAIL=0
VERDICT=""
file=test2.txt
for flag in -f
do
	./s21_grep $flag $file non_existent_file.txt > s21_grep.txt
	grep $flag $file non_existent_file.txt > grep.txt
	VERDICT="$(diff -s s21_grep.txt grep.txt)"
	if [ "$VERDICT" == "Files s21_grep.txt and grep.txt are identical" ]
	  then
	    (( SUCCESS++ ))
	  else
	    echo "flag $flag not passed"
	    (( FAIL++))
	fi
	rm s21_grep.txt grep.txt
done
echo "Passed successfully: $SUCCESS tests"
echo "Failed: $FAIL tests"
printf "\n"
# 
echo "Testing non-existent file/pattern -f"
SUCCESS=0
FAIL=0
VERDICT=""

for flag in -f
do
	./s21_grep $flag non_existent_file.txt test.txt> s21_grep.txt
	grep $flag non_existent_file.txt test.txt> grep.txt
	VERDICT="$(diff -s s21_grep.txt grep.txt)"
	if [ "$VERDICT" == "Files s21_grep.txt and grep.txt are identical" ]
	  then
	    (( SUCCESS++ ))
	  else
	    echo "flag $flag not passed"
	    (( FAIL++))
	fi
	rm s21_grep.txt grep.txt
done
echo "Passed successfully: $SUCCESS tests"
echo "Failed: $FAIL tests"
printf "\n"
# 
echo "Dual option testing -f"
SUCCESS=0
FAIL=0
VERDICT=""
pattern=Muggles
file=test2.txt

for flag in -f
do
	for flag2 in e i v c n h s
	do
		if [ $flag != $flag2 ]
		then
		  ./s21_grep $flag$flag2 $file test.txt > s21_grep.txt
		  grep $flag$flag2 $file test.txt > grep.txt
		  VERDICT="$(diff -s s21_grep.txt grep.txt)"
		  if [ "$VERDICT" == "Files s21_grep.txt and grep.txt are identical" ]
		    then
		      (( SUCCESS++ ))
		    else
		      echo "flags $flag and $flag2 not passed"
		      (( FAIL++ ))
		 fi
		rm s21_grep.txt grep.txt
	     fi
	done
done
echo "Passed successfully: $SUCCESS tests"
echo "Failed: $FAIL tests"
printf "\n"
# 
echo "Testing -l option"
SUCCESS=0
FAIL=0
VERDICT=""
pattern=Muggles
file=test3.txt

for flag in -l
do
	./s21_grep $flag $pattern test.txt $file> s21_grep.txt
	grep $flag $pattern test.txt $file> grep.txt
	VERDICT="$(diff -s s21_grep.txt grep.txt)"
	if [ "$VERDICT" == "Files s21_grep.txt and grep.txt are identical" ]
	  then
	    (( SUCCESS++ ))
	  else
	    echo "flag $flag not passed"
	    (( FAIL++))
	fi
	rm s21_grep.txt grep.txt
done
echo "Passed successfully: $SUCCESS tests"
echo "Failed: $FAIL tests"
printf "\n"
# 
echo "Testing non-existent file -l option"
SUCCESS=0
FAIL=0
VERDICT=""
pattern=Muggles
file=test3.txt

for flag in -l
do
	./s21_grep $flag $pattern non_existent_file.txt $file> s21_grep.txt
	grep $flag $pattern non_existent_file.txt $file > grep.txt
	VERDICT="$(diff -s s21_grep.txt grep.txt)"
	if [ "$VERDICT" == "Files s21_grep.txt and grep.txt are identical" ]
	  then
	    (( SUCCESS++ ))
	  else
	    echo "flag $flag not passed"
	    (( FAIL++))
	fi
	rm s21_grep.txt grep.txt
done
echo "Passed successfully: $SUCCESS tests"
echo "Failed: $FAIL tests"
printf "\n"
# 
echo "Testing non-existent 2file -l option"
SUCCESS=0
FAIL=0
VERDICT=""
pattern=Muggles
file=test3.txt

for flag in -l
do
	./s21_grep $flag $pattern test.txt non_existent_file.txt > s21_grep.txt
	grep $flag $pattern test.txt non_existent_file.txt > grep.txt
	VERDICT="$(diff -s s21_grep.txt grep.txt)"
	if [ "$VERDICT" == "Files s21_grep.txt and grep.txt are identical" ]
	  then
	    (( SUCCESS++ ))
	  else
	    echo "flag $flag not passed"
	    (( FAIL++))
	fi
	rm s21_grep.txt grep.txt
done
echo "Passed successfully: $SUCCESS tests"
echo "Failed: $FAIL tests"
printf "\n"
# 
echo "Dual option testing -l"
SUCCESS=0
FAIL=0
VERDICT=""
pattern=Muggles
file=test3.txt

for flag in -l
do
	for flag2 in e i v c n h s
	do
		if [ $flag != $flag2 ]
		then
		  ./s21_grep $flag$flag2 $pattern $file test.txt > s21_grep.txt
		  grep $flag$flag2 $pattern $file test.txt > grep.txt
		  VERDICT="$(diff -s s21_grep.txt grep.txt)"
		  if [ "$VERDICT" == "Files s21_grep.txt and grep.txt are identical" ]
		    then
		      (( SUCCESS++ ))
		    else
		      echo "flags $flag and $flag2 not passed"
		      (( FAIL++ ))
		 fi
		rm s21_grep.txt grep.txt
	     fi
	done
done
echo "Passed successfully: $SUCCESS tests"
echo "Failed: $FAIL tests"
printf "\n"
#
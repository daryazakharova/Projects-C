#!/ bin / bash

echo "Testing non-existent file"
SUCCESS=0
FAIL=0
VERDICT=""
for flag in -b -n -e -s -t -v
do
	./s21_cat $flag non_existent_file.txt > s21_cat.txt
	cat $flag non_existent_file.txt > cat.txt
	VERDICT="$(diff -s s21_cat.txt cat.txt)"
	if [ "$VERDICT" == "Files s21_cat.txt and cat.txt are identical" ]
	  then
	    (( SUCCESS++ ))
	  else
	    echo "flag $flag not passed"
	    (( FAIL++))
	fi
	rm s21_cat.txt cat.txt
done
echo "Passed successfully: $SUCCESS tests"
echo "Failed: $FAIL tests"
printf "\n"
# 
echo "Testing option stands at the end"
SUCCESS=0
FAIL=0
VERDICT=""
for flag in -b -n -e -s -t -v
do
	./s21_cat  test.txt $flag> s21_cat.txt
	cat  test.txt $flag> cat.txt
	VERDICT="$(diff -s s21_cat.txt cat.txt)"
	if [ "$VERDICT" == "Files s21_cat.txt and cat.txt are identical" ]
	  then
	    (( SUCCESS++ ))
	  else
	    echo "flag $flag not passed"
	    (( FAIL++))
	fi
	rm s21_cat.txt cat.txt
done
echo "Passed successfully: $SUCCESS tests"
echo "Failed: $FAIL tests"
printf "\n"
# 
echo "Testing with 1 option"
SUCCESS=0
FAIL=0
VERDICT=""
for flag in -b -n -e -s -t -v -bnestv
do
	./s21_cat $flag test.txt > s21_cat.txt
	cat $flag test.txt > cat.txt
	VERDICT="$(diff -s s21_cat.txt cat.txt)"
	if [ "$VERDICT" == "Files s21_cat.txt and cat.txt are identical" ]
	  then
	    (( SUCCESS++ ))
	  else
	    echo "flag $flag not passed"
	    (( FAIL++))
	fi
	rm s21_cat.txt cat.txt
done
echo "Passed successfully: $SUCCESS tests"
echo "Failed: $FAIL tests"
printf "\n"
# 
echo "Testing with 2 options"
SUCCESS=0
FAIL=0
VERDICT=""
for flag in -b -n -e -s -t -v 
do
	for flag2 in -b -n -e -s -t -v
	do
		if [ $flag != $flag2 ]
		then
		  ./s21_cat $flag $flag2 test.txt > s21_cat.txt
		  cat $flag $flag2 test.txt > cat.txt
		  VERDICT="$(diff -s s21_cat.txt cat.txt)"
		  if [ "$VERDICT" == "Files s21_cat.txt and cat.txt are identical" ]
		    then
		      (( SUCCESS++ ))
		    else
		      echo "flags $flag and $flag2 not passed"
		      (( FAIL++ ))
		  fi
		rm s21_cat.txt cat.txt
	        fi
	done
done
echo "Passed successfully: $SUCCESS tests"
echo "Failed: $FAIL tests"
printf "\n"
# 
echo "Testing with 3 options"
SUCCESS=0
FAIL=0
VERDICT=""
for flag in -b -n -e -s -t -v
do
  for flag2 in -b -n -e -s -t -v
  do
    for flag3 in -b -n -e -s -t -v
    do
      if [ $flag != $flag2 ] && [ $flag != $flag3 ] && [ $flag2 != $flag3 ]
      then
        ./s21_cat $flag $flag2 $flag3 test.txt > s21_cat.txt
        cat $flag $flag2 $flag3 test.txt > cat.txt
        VERDICT="$(diff -s s21_cat.txt cat.txt)"
	if [ "$VERDICT" == "Files s21_cat.txt and cat.txt are identical" ]
          then
            (( SUCCESS++ ))
          else
            echo "flags $flag, $flag2 and $flag3 not passed"
            (( FAIL++ ))
        fi
        rm s21_cat.txt cat.txt
      fi
    done
  done
done
echo "Passed successfully: $SUCCESS tests"
echo "Failed: $FAIL tests"
printf "\n"
# 
echo "Testing with 4 options"
SUCCESS=0
FAIL=0
VERDICT=""
for flag in -b -n -e -s -t -v
do
  for flag2 in -b -n -e -s -t -v
  do
    for flag3 in -b -n -e -s -t -v
    do
      for flag4 in -b -n -e -s -t -v
      do
        if [ $flag != $flag2 ] && [ $flag != $flag3 ] && [ $flag != $flag4 ] && [ $flag2 != $flag3 ] && [ $flag2 != $flag4 ] && [ $flag3 != $flag4 ]
        then
          ./s21_cat $flag $flag2 $flag3 $flag4 test.txt > s21_cat.txt
          cat $flag $flag2 $flag3 $flag4 test.txt > cat.txt
          VERDICT="$(diff -s s21_cat.txt cat.txt)"
          if [ "$VERDICT" == "Files s21_cat.txt and cat.txt are identical" ]
            then
	      (( SUCCESS++ ))
            else
              (( FAIL ++ ))
              echo "flags $flag, $flag2, $flag3 and $flag4 not passed"
          fi
          rm cat.txt s21_cat.txt
        fi
      done
    done
  done
done
echo "Passed successfully: $SUCCESS tests"
echo "Failed: $FAIL tests"
printf "\n"
# 
echo "Dual option testing"
SUCCESS=0
FAIL=0
VERDICT=""
for flag in -b -n -e -s -t -v 
do
	for flag2 in b n e s t v
	do
		if [ $flag != $flag2 ]
		then
		  ./s21_cat $flag$flag2 test.txt > s21_cat.txt
		  cat $flag$flag2 test.txt > cat.txt
		  VERDICT="$(diff -s s21_cat.txt cat.txt)"
		  if [ "$VERDICT" == "Files s21_cat.txt and cat.txt are identical" ]
		    then
		      (( SUCCESS++ ))
		    else
		      echo "flags $flag and $flag2 not passed"
		      (( FAIL++ ))
		 fi
		rm s21_cat.txt cat.txt
	     fi
	done
done
echo "Passed successfully: $SUCCESS tests"
echo "Failed: $FAIL tests"
printf "\n"
# 
echo "Testing GNU options"
SUCCESS=0
FAIL=0
VERDICT=""
for flag in -T -E --number --number-nonblank --squeeze-blank
do
	./s21_cat $flag test.txt > s21_cat.txt
	cat $flag test.txt > cat.txt
	VERDICT="$(diff -s s21_cat.txt cat.txt)"
	if [ "$VERDICT" == "Files s21_cat.txt and cat.txt are identical" ]
	  then
	    (( SUCCESS++ ))
	  else
	    echo "flag $flag not passed"
	    (( FAIL++))
	fi
	rm s21_cat.txt cat.txt
done
echo "Passed successfully: $SUCCESS tests"
echo "Failed: $FAIL tests"
printf "\n"
#!/ bin / bash

EXIT_SUCCESS=0 
EXIT_FAILURE=0
DIFF_RES=""

for var in -e -v -c -l -n -h -i -s -o
do 
    TEST1="$var cat test.txt"
    ./s21_grep $TEST1 > s21_grep.txt
    grep $TEST1 > grep.txt
    DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
    if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
        then
            (( EXIT_SUCCESS++ ))
        else
            echo "$TEST1" >> log.txt
            (( EXIT_FAILURE++ ))
            echo $TEST1
        fi
    rm s21_grep.txt grep.txt
done

for var in -f
do 
    TEST1="$var ftest.txt test.txt"
    ./s21_grep $TEST1 > s21_grep.txt
    grep $TEST1 > grep.txt
    DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
    if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
        then
            (( EXIT_SUCCESS++ ))
        else
            echo "$TEST1" >> log.txt
            (( EXIT_FAILURE++ ))
            echo $TEST1
        fi
    rm s21_grep.txt grep.txt
done


for var in -e -i -v -c -l -n -h -s 
do 
    TEST2="$var cat test.txt text.txt"
    ./s21_grep $TEST2 > s21_grep.txt
    grep $TEST2 > grep.txt
    DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
    if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
        then
            (( EXIT_SUCCESS++ ))
        else
            echo "$TEST2" >> log.txt
            (( EXIT_FAILURE++ ))
            echo $TEST2
        fi
    rm s21_grep.txt grep.txt
done


for var in -e -i -v -c -l -n -h -s
do 
    TEST3="$var ^cat test.txt"
    ./s21_grep $TEST3 > s21_grep.txt
    grep $TEST3 > grep.txt
    DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
    if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
        then
            (( EXIT_SUCCESS++ ))
        else
            echo "$TEST3" >> log.txt
            (( EXIT_FAILURE++ ))
            echo $TEST3
        fi
    rm s21_grep.txt grep.txt
done


for var in -e -i -v -c -l -n -h -s
do 
    TEST4="$var ^cat test.txt text.txt"
    ./s21_grep $TEST4 > s21_grep.txt
    grep $TEST4 > grep.txt
    DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
    if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
        then
            (( EXIT_SUCCESS++ ))
        else
            echo "$TEST4" >> log.txt
            (( EXIT_FAILURE++ ))
            echo $TEST4
        fi
    rm s21_grep.txt grep.txt
done


for var in  -i -v -c -l -n -h -s -o
do 
    TEST5="-e cat $var test.txt"
    ./s21_grep $TEST5 > s21_grep.txt
   
    grep $TEST5 > grep.txt
    DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
    if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
        then
            (( EXIT_SUCCESS++ ))
        else
            echo "$TEST5" >> log.txt
            (( EXIT_FAILURE++ ))
            echo $TEST5
        fi
    rm s21_grep.txt grep.txt    
done

for var in  -i -v -c -l -n -h -s
do 
    TEST6="-e cat $var test.txt text.txt"
    ./s21_grep $TEST6 > s21_grep.txt
   
    grep $TEST6 > grep.txt
    DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
    if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
        then
            (( EXIT_SUCCESS++ ))
        else
            echo "$TEST6" >> log.txt
            (( EXIT_FAILURE++ ))
            echo $TEST6
        fi
    rm s21_grep.txt grep.txt   
done

for var1 in   -i -v -c -l -n -h -s
do 
    for var2 in  -i -v -c -l -n -h -s
    do
        if [ $var1 != $var2 ]
        then
            TEST8="-e cat $var1 $var2 test.txt "
            ./s21_grep $TEST8 > s21_grep.txt
            grep $TEST8 > grep.txt
            DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
            if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
                then
                    (( EXIT_SUCCESS++ ))
                else
                    echo "$TEST8" >> log.txt
                    (( EXIT_FAILURE++ ))
                    echo $TEST8
                fi
            rm s21_grep.txt grep.txt
        fi
    done
done


for var1 in   -i -v -c -l -n -h -s
do 
    for var2 in  -i -v -c -l -n -h -s
    do
        for var3 in  -i -v -c -l -n -h -s
        do
            if [ $var1 != $var2 ] && [ $var3 != $var2 ] && [ $var1 != $var3 ]
            then
                TEST9="-e cat $var1 $var2 $var3 test.txt"
                ./s21_grep $TEST9 > s21_grep.txt
                grep $TEST9 > grep.txt
                DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
                if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
                    then
                        (( EXIT_SUCCESS++ ))
                    else
                        echo "$TEST9" >> log.txt
                        (( EXIT_FAILURE++ ))
                        echo $TEST9
                    fi
                rm s21_grep.txt grep.txt
            fi
        done 
    done
done

for var1 in   -i -v -c -l -n -h  -s
do 
    for var2 in  -i -v -c -l -n -h -s
    do
        if [ $var1 != $var2 ]
        then
            TEST10="-e cat $var1 $var2 test.txt text.txt"
            ./s21_grep $TEST10 > s21_grep.txt
            grep $TEST10 > grep.txt
            DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
            if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
                then
                    (( EXIT_SUCCESS++ ))
                else
                    echo "$TEST10" >> log.txt
                    (( EXIT_FAILURE++ ))
                    echo $TEST10
                fi
            rm s21_grep.txt grep.txt
        fi
    done
done




for var1 in   i v c l n h s
do 
    for var2 in  i v c l n h s
    do
        if [ $var1 != $var2 ]
        then
            TEST10="-e cat -$var1$var2 test.txt"
            ./s21_grep $TEST10 > s21_grep.txt
            grep $TEST10 > grep.txt
            DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
            if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
                then
                    (( EXIT_SUCCESS++ ))
                else
                    echo "$TEST10" >> log.txt
                    (( EXIT_FAILURE++ ))
                    echo $TEST10
                fi
            rm s21_grep.txt grep.txt
        fi
    done
done


for var1 in   i v c l n h 
do 
    for var2 in  i v c l n h
    do
        for var3 in  i v c l n h 
        do
            if [ $var1 != $var2 ] && [ $var3 != $var2 ] && [ $var1 != $var3 ]
            then
                TEST9="-e cat -$var1$var2$var3 test.txt text.txt" 
                ./s21_grep $TEST9 > s21_grep.txt
                grep $TEST9 > grep.txt
                DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
                if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
                    then
                        (( EXIT_SUCCESS++ ))
                    else
                        echo "$TEST9" >> log.txt
                        (( EXIT_FAILURE++ ))
                        echo $TEST9
                    fi
                rm s21_grep.txt grep.txt
            fi
        done 
    done
done


echo "SUCCESS: $EXIT_SUCCESS"
echo "FAIL: $EXIT_FAILURE"
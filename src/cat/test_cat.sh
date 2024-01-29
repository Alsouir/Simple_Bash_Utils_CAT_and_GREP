#!/ bin / bash

EXIT_SUCCESS=0 
EXIT_FAILURE=0
DIFF_RES=""


for var in -b -n -s -e -t
do 
    TEST1="$var test.txt"
    ./s21_cat $TEST1 > s21_cat.txt
    cat $TEST1 > cat.txt
    DIFF_RES="$(diff -s s21_cat.txt cat.txt)"
    if [ "$DIFF_RES" == "Files s21_cat.txt and cat.txt are identical" ]
        then
            (( EXIT_SUCCESS++ ))
        else
            echo "$TEST1" >> log.txt
            (( EXIT_FAILURE++ ))
        fi
    rm s21_cat.txt cat.txt
done

for var in -e -t
do  
    TEST2="$var -v test.txt"
    ./s21_cat $TEST2 > s21_cat.txt
    cat $TEST2 > cat.txt
    DIFF_RES="$(diff -s s21_cat.txt cat.txt)"
    if [ "$DIFF_RES" == "Files s21_cat.txt and cat.txt are identical" ]
        then
            (( EXIT_SUCCESS++ ))
        else
            echo "$TEST2" >> log.txt
            (( EXIT_FAILURE++ ))
        fi
    rm s21_cat.txt cat.txt
done

for var1 in -b -s -e -t -v -n
do 
    for var2 in -b -s -e -t -v -n
    do
        if [ $var1 != $var2 ]
        then
            TEST1="$var1 $var2 test.txt"
            ./s21_cat $TEST1 > s21_cat.txt
            cat $TEST1 > cat.txt
            DIFF_RES="$(diff -s s21_cat.txt cat.txt)"
            if [ "$DIFF_RES" == "Files s21_cat.txt and cat.txt are identical" ]
                then
                    (( EXIT_SUCCESS++ ))
                else
                    echo $(diff -u s21_cat.txt cat.txt)
                    echo "$TEST1" >> log.txt
                    (( EXIT_FAILURE++ ))
                    echo $var1 $var2 
                fi
            rm s21_cat.txt cat.txt
        fi
    done
done

for var1 in -b -s -e -t -v -n
do 
    for var2 in -b -s -e -t -v -n
    do
        for var3 in -b -s -e -t -v -n
        do
            if [ $var1 != $var2 ] && [ $var3 != $var2 ] && [ $var1 != $var3 ]
            then
                TEST1="$var1 $var2 $var3  test.txt"
                ./s21_cat $TEST1 > s21_cat.txt
                cat $TEST1 > cat.txt
                DIFF_RES="$(diff -s s21_cat.txt cat.txt)"
                if [ "$DIFF_RES" == "Files s21_cat.txt and cat.txt are identical" ]
                    then
                        (( EXIT_SUCCESS++ ))
                    else
                        echo $(diff -u s21_cat.txt cat.txt)
                        echo "$TEST1" >> log.txt
                        (( EXIT_FAILURE++ ))
                        echo $var1 $var2 $var3 
                    fi
                rm s21_cat.txt cat.txt
            fi
        done
    done
done

for var1 in -b -s -e -t -v -n
do 
    for var2 in -b -s -e -t -v -n
    do
        for var3 in -b -s -e -t -v -n
        do
            for var4 in -b -s -e -t -v -n
            do
                if [ $var1 != $var2 ] && [ $var1 != $var2 ] && [ $var1 != $var3 ] && [ $var1 != $var4 ] && [ $var2 != $var3 ]&& [ $var2 != $var4 ] && [ $var3 != $var4 ]
                then
                    TEST1="$var1 $var2 $var3  test.txt"
                    ./s21_cat $TEST1 > s21_cat.txt
                    cat $TEST1 > cat.txt
                    DIFF_RES="$(diff -s s21_cat.txt cat.txt)"
                
                    if [ "$DIFF_RES" == "Files s21_cat.txt and cat.txt are identical" ]
                        then
                            (( EXIT_SUCCESS++ ))
                        else
                            echo $(diff -u s21_cat.txt cat.txt)
                            echo "$TEST1" >> log.txt
                            (( EXIT_FAILURE++ ))
                            echo $var1 $var2 $var3 
                        fi
                    rm s21_cat.txt cat.txt
                fi
            done
        done
    done
done



echo "SUCCESS: $EXIT_SUCCESS"
echo "FAIL: $EXIT_FAILURE"
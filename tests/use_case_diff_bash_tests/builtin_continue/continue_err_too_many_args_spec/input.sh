echo "start"
for i in aa bb
do
    echo before $i
    for num in 11 22
    do
        echo before $num
        continue 3 3
        echo after $num
    done
    echo after $i
done
echo for status $?
echo "end"

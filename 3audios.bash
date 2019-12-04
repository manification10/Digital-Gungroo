tail -fn0 /dev/cu.SLAB_USBtoUART | \
while read line ; do
        echo "$line" | grep "1"
        if [ $? = 0 ]
        then
                mpg123 Ghungroo_1.mp3.mp3
        fi
        echo "$line" | grep "2"
        if [ $? = 0 ]
        then
                mpg123 Ghungroo_2.mp3
        fi
        echo "$line" | grep "3"
        if [ $? = 0 ]
        then
                mpg123 Ghungroo_3.mp3
        fi
done

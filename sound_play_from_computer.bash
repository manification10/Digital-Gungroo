tail -fn0 /dev/cu.SLAB_USBtoUART | \
while read line ; do
        echo $line
        if echo $line | grep -q "1"; then
		mpg123 Ghungroo_1.mp3
        fi
        if echo $line | grep -q "2"; then
        	mpg123 Ghungroo_2.mp3
        fi
        if echo $line | grep -q "3"; then
                mpg123 Ghungroo_3.mp3
        fi
done

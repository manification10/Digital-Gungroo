tail -fn0 aud.txt | \
while read line ; do
        echo "$line" | grep "mpg123"
        if [ $? = 0 ]
        then
                mpg123 ghungroo-audio.mp3
        fi
done

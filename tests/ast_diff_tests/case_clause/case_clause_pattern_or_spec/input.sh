space=a
case $space in
aa |bb| cc)
    Message="I am 1"
    ;;
[1-6]*)
    Message="All is quiet."
    ;;
[7-8]*)
    Message="Start thinking about cleaning out some stuff.  There's a partition that is $space % full."
    ;;
9[1-8])
    Message="Better hurry with that new disk...  One partition is $space % full."
    ;;
99)
    Message="I'm drowning here!  There's a partition at $space %!"
    ;;
*)
    Message="I seem to be running with an nonexistent amount of disk space..."
    ;;
esac
echo $Message

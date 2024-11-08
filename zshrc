man() {
    if [ "$1" = "print42" ]; then
        less ~/print42.txt
    else
        command man "$@"
    fi
}

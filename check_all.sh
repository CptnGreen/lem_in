#!/bin/bash

print_headline()
{
    if [[ "$1" == "flow-one" ]]; then
        echo -e "\n====One ant to one path=========\n"
    elif [[ "$1" == "flow-ten" ]]; then
        echo -e "\n====Ten ants to one path========\n"
    elif [[ "$1" == "flow-thousand" ]]; then
        echo -e "\n====Thousand ants to one path===\n"
    elif [[ "$1" == "big" ]]; then
        echo -e "\n====Big (~4K rooms) map=========\n"
    elif [[ "$1" == "big-superposition" ]]; then
        echo -e "\n====Complex big map=============\n"
    else
        echo -e "WRONG OPTION PASSED TO FARM GENERATOR"
        exit 1
    fi
}

check_time()
{
    echo -e "Time:"
    time ./lem-in < input > temp
    echo -e ""
}

check_leaks()
{
    echo -e "Leaks:"
    valgrind --log-file=leaks_log ./lem-in < input > /dev/null
    awk -F"==     " ' /in use at exit/{ print $2 } ' < leaks_log
    echo -e ""
}

check_lines()
{
    grep '#Here' < temp | uniq | awk -F": " ' { printf "Lines required: %s\nLines received: ", $2 } '
    grep -c '^L[0-9]' < temp
}

main()
{
    for option in flow-one flow-ten flow-thousand big big-superposition; do
        print_headline "$option"
        ./lemin-gen --"$option" > input
        check_time
        check_leaks
        check_lines
    done
    echo -e "\n================================"
    rm -f temp input leaks_log
}

main

#!/bin/bash

declare -i time_limit=14
declare -i num_runs=1
declare leaks_flag="no"

while getopts "t:n:lh" opt; do
    case $opt in
        t)
            if (( "${OPTARG}" > 0 )); then
                time_limit="${OPTARG}"
            else
                echo -e "TIME LIMIT TOO SMALL!"
                exit 1
            fi
            ;;
        n)
            if (( "${OPTARG}" > 0 && "${OPTARG}" < 100 )); then
                num_runs="${OPTARG}"
            else
                echo -e "NUMBER OF TESTS IS BAD!"
                exit 1
            fi
            ;;
        l)
            leaks_flag="yes"
            ;;
        h)
            echo -e "This script utilizes given farm generator to check lem-in\nUsage: check_all [-l] [-n N] [-t T]\n\t-l adds check for leaks (using valgrind)\n\t-n specifies number of test-cycles\n\t-t assigns time limit (in seconds) for a single test"
            exit 0
            ;;
        *)
            exit 1
            ;;
    esac
done

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
        echo -e "WRONG OPTION WAS PASSED TO FARM GENERATOR"
        exit 1
    fi
}

check_time()
{
    echo -e "Time:"
    { time ./lem-in < input > temp ; } 2>time_log
    cat time_log
    echo -e ""
    if (( $(awk ' /real/{ print $2 } ' < time_log | cut -dm -f2 | cut -d. -f1) >= time_limit )); then
        printf "Real time exceeds limit (%d sec) -- TOO SLOW!\n\n" "$time_limit"
        exit 1
    fi
}

check_leaks()
{
    echo -e "Leaks:"
    valgrind --log-file=leaks_log ./lem-in < input > /dev/null
    leaks=$(awk -F"==     " ' /in use at exit/{ print $2 } ' < leaks_log)
    echo "$leaks"
    echo -e ""
    if ! [[ "$leaks" =~ "0 bytes in 0 blocks" ]]; then
        printf "FOUND LEAKS!\n\n"
        exit 1
    fi
}

check_lines()
{
    declare req
    declare rec
    req=$(grep '#Here' < temp | uniq | awk -F": " ' { print $2 } ')
    rec=$(grep -c '^L[0-9]' < temp)
    printf "Lines required: %s\nLines received: %s\n" "$req" "$rec"
    if (( rec - req > 3 )); then
        printf "\nTOO MANY LINES RECEIVED!\n"
        exit 1
    fi
}

main()
{
    for (( i=0; i<num_runs; ++i)); do
        for option in flow-one flow-ten flow-thousand big big-superposition; do
            print_headline "$option"
            ./lemin-gen --"$option" > input
            check_time
            [[ "$leaks_flag" == "yes" ]] && check_leaks
            check_lines
        done
        rm -f temp input time_log leaks_log
    done
    echo -e "\n================================\n"
}

main

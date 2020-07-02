#!/bin/bash

echo -e "\n====One ant to one path=========\n"
./lemin-gen --flow-one > input
echo -e "Time:"
time ./lem-in < input > temp
echo -e ""
echo -e "Leaks:"
valgrind --log-file=leaks_log ./lem-in < input > /dev/null
awk -F"==     " ' /in use at exit/{ print $2 } ' < leaks_log
echo -e ""
grep '#Here' < temp | uniq | awk -F": " ' { printf "Lines required: %s\nLines received: ", $2 } '
grep -c '^L[0-9]' < temp


echo -e "\n====Ten ants to one path========\n"
lemin-gen --flow-ten > input
echo -e "Time:"
time ./lem-in < input > temp
echo -e ""
echo -e "Leaks:"
valgrind --log-file=leaks_log ./lem-in < input > /dev/null
awk -F"==     " ' /in use at exit/{ print $2 } ' < leaks_log
echo -e ""
grep '#Here' < temp | uniq | awk -F": " ' { printf "Lines required: %s\nLines received: ", $2 } '
grep -c '^L[0-9]' < temp


echo -e "\n====Thousand ants to one path===\n"
lemin-gen --flow-thousand > input
echo -e "Time:"
time ./lem-in < input > temp
echo -e ""
echo -e "Leaks:"
valgrind --log-file=leaks_log ./lem-in < input > /dev/null
awk -F"==     " ' /in use at exit/{ print $2 } ' < leaks_log
echo -e ""
grep '#Here' < temp | uniq | awk -F": " ' { printf "Lines required: %s\nLines received: ", $2 } '
grep -c '^L[0-9]' < temp


echo -e "\n====Big (~4K rooms) map=========\n"
lemin-gen --big > input
echo -e "Time:"
time ./lem-in < input > temp
echo -e ""
echo -e "Leaks:"
valgrind --log-file=leaks_log ./lem-in < input > /dev/null
awk -F"==     " ' /in use at exit/{ print $2 } ' < leaks_log
echo -e ""
grep '#Here' < temp | uniq | awk -F": " ' { printf "Lines required: %s\nLines received: ", $2 } '
grep -c '^L[0-9]' < temp


echo -e "\n====Complex big map=============\n"
lemin-gen --big-superposition > input
echo -e "Time:"
time ./lem-in < input > temp
echo -e ""
echo -e "Leaks:"
valgrind --log-file=leaks_log ./lem-in < input > /dev/null
awk -F"==     " ' /in use at exit/{ print $2 } ' < leaks_log
echo -e ""
grep '#Here' < temp | uniq | awk -F": " ' { printf "Lines required: %s\nLines received: ", $2 } '
grep -c '^L[0-9]' < temp


echo -e "\n================================"
rm -f temp input leaks_log

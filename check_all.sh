#!/bin/bash

echo -e "\n====One ant to one path=========\n"
lemin-gen --flow-one > input
echo -e "Time:"
time ./lem-in < input > temp
echo -e ""
cat temp | grep '#Here' | uniq | awk -F": " ' { printf "Lines required: %s\nLines received: ", $2 } '
cat temp | grep -c '^L[0-9]'


echo -e "\n====Ten ants to one path========\n"
lemin-gen --flow-ten > input
echo -e "Time:"
time ./lem-in < input > temp
echo -e ""
cat temp | grep '#Here' | uniq | awk -F": " ' { printf "Lines required: %s\nLines received: ", $2 } '
cat temp | grep -c '^L[0-9]'


echo -e "\n====Thousand ants to one path===\n"
lemin-gen --flow-thousand > input
echo -e "Time:"
time ./lem-in < input > temp
echo -e ""
cat temp | grep '#Here' | uniq | awk -F": " ' { printf "Lines required: %s\nLines received: ", $2 } '
cat temp | grep -c '^L[0-9]'


echo -e "\n====Big (~4K rooms) map=========\n"
lemin-gen --big > input
echo -e "Time:"
time ./lem-in < input > temp
echo -e ""
cat temp | grep '#Here' | uniq | awk -F": " ' { printf "Lines required: %s\nLines received: ", $2 } '
cat temp | grep -c '^L[0-9]'


echo -e "\n====Complex big map=============\n"
lemin-gen --big-superposition > input
echo -e "Time:"
time ./lem-in < input > temp
echo -e ""
cat temp | grep '#Here' | uniq | awk -F": " ' { printf "Lines required: %s\nLines received: ", $2 } '
cat temp | grep -c '^L[0-9]'


echo -e "\n================================"
rm -f temp input

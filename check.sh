#!/bin/zsh

SUCCES_COUNT=0
FAIL_COUNT=0
COUNT=0

while IFS= read -r -d '' file; do
	line_cont=0
	printf "\n\e[35m--------------- %s ---------------\e[00m\n" "$(basename "${file}")"
	if [[ ${str} =~ "ERROR" ]]; then
		printf "%s\n" "${str}"
	else
		while read -r str; do
			if [[ ${str} =~ "#" ]]; then
				num_need=${str//[^0-9]/}
				printf "Required lines: %d\n" ${num_need}
			elif [[ ${str} =~ "^L" ]]; then
				line_cont=$(( line_cont + 1 ))
			fi
			# printf "%s\n" "${str}"
		done < <(./lem-in <"${file}" | grep "required\|ERROR\|L" | uniq)
		printf "Received lines: %d\n" ${line_cont}
	fi
	COUNT=$((COUNT + 1))
	dif=$(( line_cont - num_need ))
	if [[ dif -gt 0 ]]; then
		printf "\e[31m -- Fail [%d] --\e[00m\n" ${dif}
		FAIL_COUNT=$((FAIL_COUNT + 1))
	else
		SUCCES_COUNT=$((SUCCES_COUNT + 1))
		printf "\e[32m -- Success [%d] --\e[00m\n" ${dif}
	fi
done < <(find maps_examples/* -type f -name "map*" -print0)

printf "\n\n\e[32mResults for: %d tests\n" COUNT
if [ "$FAIL_COUNT" -ne "0" ]; then
	printf "\n -- \e[32m[%d]\e[00m -- \e[31m[%d]\e[00m --\n" ${SUCCES_COUNT} ${FAIL_COUNT}
else
	printf "\n \e[32m---== SUCCESS ==---\e[00m\n"
fi

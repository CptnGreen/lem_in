GREEN="\033[32m";
RED="\033[31m";
DEFAULT="\033[37m";
CYAN="\x1b[36m";

USER="Result/";
DIR="Maps/"
USER2="Bfs_one_path/"
DIFF="Diff/"
P="./lem-in";
rm -dR Result;
mkdir Result;
# rm -dR Diff;
# mkdir Diff;
nm -u ./lem-in;
# norminette -RCheckForbiddenSourceHeader;
# cat -e author
C="cat";
C2="diff";

FILE="1.map";
FILE1="9_path_depth_4_ants.map";
FILE2="2.map";
FILE3="5.map";
FILE4="10K.map";
FILE6="err_link_to_unknown_room.map";
FILE7="10_lots_of_comments.map";
FILE8="20.map";
FILE9="err_3_coordinates.map";
FILE10="err_duplicate.map";
FILE11="err_no_ants2.map";
FILE12="err_no_ants.map";
FILE13="err_too_few_ants.map";
FILE14="err_no_links.map";
FILE15="err_empty.map";
FILE16="err_no_ants3.map";
FILE17="err_no_rooms.map";
FILE18="err_letter_in_coordinate.map";
FILE19="err_no_path.map";
FILE20="9_path_depth_2_ants.map";
FILE21="9_path_depth_8_ants.map";
FILE22="9_path_depth_9_ants.map";
FILE23="9_path_depth_10_ants.map";
FILE24="err_no_end2.map";
FILE25="err_no_start2.map";
FILE26="err_start_end_same.map";
FILE27="err_too_many_ants.map";
FILE28="err_no_start.map";
FILE29="err_no_ants3.map";
FILE30="err_no_rooms.map";
FILE31="err_letter_in_coordinate.map";
FILE32="err_no_end.map";
FILE33="9_path_depth_1_ants.map";

# echo -e "\n\n\033[32m$FILE\n\033[37m"
# $C $DIR$FILE | $P > $USER$FILE
# echo -e "\x1b[36mOutput: cat $USER$FILE\n"

# echo -e "\n\n\033[32m$FILE1\n\033[37m"
# $C $DIR$FILE1 | $P > $USER$FILE1;
# echo -e "\x1b[36mOutput: cat $USER$FILE1\n"

# echo -e "\n\n\033[32m$FILE20\n\033[37m"
# $C $DIR$FILE20 | $P > $USER$FILE20;
# echo -e "\x1b[36mOutput: cat $USER$FILE20\n"

# echo -e "\n\n\033[32m$FILE21\n\033[37m"
# $C $DIR$FILE21 | $P > $USER$FILE21;
# echo -e "\x1b[36mOutput: cat $USER$FILE20\n"

# echo -e "\n\n\033[32m$FILE22\n\033[37m"
# $C $DIR$FILE22 | $P > $USER$FILE22;
# echo -e "\x1b[36mOutput: cat $USER$FILE22\n"

# echo -e "\n\n\033[32m$FILE23\n\033[37m"
# $C $DIR$FILE23 | $P > $USER$FILE23;
# echo -e "\x1b[36mOutput: cat $USER$FILE23\n"

# echo -e "\n\n\033[32m$FILE2\n\033[37m"
# $C $DIR$FILE2 | $P > $USER$FILE2;
# echo -e "\x1b[36mOutput: cat $USER$FILE2\n"

# echo -e "\n\n\033[32m$FILE3\n\033[37m"
# $C $DIR$FILE3 | $P > $USER$FILE3;
# echo -e "\x1b[36mOutput: cat $USER$FILE3\n"

# echo -e "\n\n\033[32m$FILE4\n\033[37m"
# $C $DIR$FILE4 | $P > $USER$FILE4;
# echo -e "\x1b[36mOutput: cat $USER$FILE4\n"

# echo -e "\n\n\033[32m$FILE7\n\033[37m"
# $C $DIR$FILE7 | $P > $USER$FILE7;
# echo -e "\x1b[36mOutput: cat $USER$FILE7\n"

# echo -e "\n\n\033[32m$FILE8\n\033[37m"
# $C $DIR$FILE8 | $P > $USER$FILE8;
# echo -e "\x1b[36mOutput: cat $USER$FILE8\n"

# echo -e "\n\n\033[32m$FILE24\n\033[37m"
# $C $DIR$FILE24 | $P > $USER$FILE24;

# echo -e "\n\n\033[32m$FILE33\n\033[37m"
# $C $DIR$FILE33 | $P > $USER$FILE33;

# echo -e "\n\n\033[32m$FILE9\n\033[37m"
# $C $DIR$FILE9 | $P > $USER$FILE9;

# echo -e "\n\n\033[32m$FILE10\n\033[37m"
# $C $DIR$FILE10 | $P > $USER$FILE10;

# echo -e "\n\n\033[32m$FILE11\n\033[37m"
# $C $DIR$FILE11 | $P > $USER$FILE11;

# echo -e "\n\n\033[32m$FILE12\n\033[37m"
# $C $DIR$FILE12 | $P > $USER$FILE12;

# echo -e "\n\n\033[32m$FILE13\n\033[37m"
# $C $DIR$FILE13 | $P > $USER$FILE13;

# echo -e "\n\n\033[32m$FILE14\n\033[37m"
# $C $DIR$FILE14 | $P > $USER$FILE14;

# echo -e "\n\n\033[32m$FILE15\n\033[37m"
# $C $DIR$FILE15 | $P > $USER$FILE15;

# echo -e "\n\n\033[32m$FILE16\n\033[37m"
# $C $DIR$FILE16 | $P > $USER$FILE16;

# echo -e "\n\n\033[32m$FILE17\n\033[37m"
# $C $DIR$FILE17 | $P > $USER$FILE17;

# echo -e "\n\n\033[32m$FILE18\n\033[37m"
# $C $DIR$FILE18 | $P > $USER$FILE18;

# echo -e "\n\n\033[32m$FILE19\n\033[37m"
# $C $DIR$FILE19 | $P > $USER$FILE19;

# echo -e "\n\n\033[32m$FILE6\n\033[37m"
# $C $DIR$FILE6 | $P > $USER$FILE6;

# echo -e "\n\n\033[32m$FILE24\n\033[37m"
# $C $DIR$FILE24 | $P > $USER$FILE24;

# echo -e "\n\n\033[32m$FILE25\n\033[37m"
# $C $DIR$FILE25 | $P > $USER$FILE25;

# echo -e "\n\n\033[32m$FILE26\n\033[37m"
# $C $DIR$FILE26 | $P > $USER$FILE26;

# echo -e "\n\n\033[32m$FILE27\n\033[37m"
# $C $DIR$FILE27 | $P > $USER$FILE27;

# echo -e "\n\n\033[32m$FILE28\n\033[37m"
# $C $DIR$FILE28 | $P > $USER$FILE28;

# echo -e "\n\n\033[32m$FILE29\n\033[37m"
# $C $DIR$FILE29 | $P > $USER$FILE29;

# echo -e "\n\n\033[32m$FILE30\n\033[37m"
# $C $DIR$FILE30 | $P > $USER$FILE30;

# echo -e "\n\n\033[32m$FILE31\n\033[37m"
# $C $DIR$FILE31 | $P > $USER$FILE31;

# echo -e "\n\n\033[32m$FILE32\n\033[37m"
# $C $DIR$FILE32 | $P > $USER$FILE32;

echo -e "\n\n\033[32m/dev/urandom/\033[37m"
$C /dev/urandom | $P > $USER-dev-urandom;

# echo -e "\n\n\033[32m/dev/null/\033[37m"
# $C /dev/null | $P > $USER-dev-null;

# echo -e "\n\n\033[32m/dev/zero/\033[37m"
# $C /dev/zero | $P > $USER-dev-zero;

# echo -e "\n\n\033[32mNothing\033[37m"
# echo -e "" | $P > $USER-Nothing;

echo -e "\n\n\033[32mOutput Difference:\033[37m"
diff -r $DIR$USER2 $USER > output_difference.txt
echo -e "\x1b[36mOutput: cat output_difference.txt\n"

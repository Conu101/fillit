# fillit

3rd project in C of Hive Helsinki (42 network).

The goal of this project is to code a variant of the famous game Tetris: a list of teriminos (4 blocks arranged in various shapes similarly to those found 
in Tetris (is provided in a text file, as successive shapes drawn with '#' and '.'.
The goal is to find the smallest possible square within which all blocks can be placed, with each block at their most top-left possible position. There can be 
between 1 and 26 tetriminos, separated by a newline in the text file.

The result must be displayed in the standard output, with the first tetrimino represented by the letter A, the second by B, and so on.

If a faulty file is entered as an argument, the program displays "error" and quits. If no file or more than 1 file is entered as argument, the program
displays the usage and quits.

Example: text file including 3 tetriminos <trial.txt>

...#
...#
...#
...#

....
#...
#...
##..

...#
...#
..##
....


Command:

./fillit trial.txt


Result on stdout:

AB..
AB.C
ABBC
A.CC


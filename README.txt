James Holt and Shawn Tran

to output to txt without changing cout's or opening the output file in every cpp file: https://www.quora.com/How-do-I-output-all-my-cout-s-to-a-text-file-in-C

this website helped us figure out how to do weighted values for randomly populating the board with items: https://stackoverflow.com/questions/1761626/weighted-random-numbers

this website helped us understand how to return an array, because we built the level class first, we had to make the function that made the board return an array so we could store that in a single dimension array within the world class. Essentially making a 3-d array with more steps (it was the better progressional way to do it) : https://www.digitalocean.com/community/tutorials/return-array-in-c-plus-plus-function

to compile the program: g++ *.cpp
to execute: ./a.out > output-spec.txt
(this allowed us to keep all our cout statements without having to go back and open the file in each class to write to it)
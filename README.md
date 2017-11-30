Language Detection
 

Michael White
Sodiq Wilson-Agbaje

PROBLEMS TO SOLVE

-read from a file
-handle file error exeptions
-compute the trigram frequencies of a language
-properly order the trigram frequencies
-compute the similarity between two languages
-handle command line errors if present


LANGUAGE CLASS

Constructed with two vectors, One for the trigrams and one for the frequencies, and a string name.

The Libraries this class will need are

<vector>
<string>
<iostream>
<fstream>
<math>

The private instance variables will be 

vector of trigrams
vector of trigram frequencies
string name


LANGUAGE CLASS FUNCTIONS

setTrigrams(file)
#a void function that will take a file as its parameter set the trigram, the trigram frequencies and the name of the language

setTrigramFreq(trigram)
#a function that takes a string that is a trigram and puts that trigram into the correct index in the frequency vector

getTrigram()
#a function that will return a vector of trigrams

getTrigramFreq()
#a function that will return a vector of ints

getName()
#a function that will return a string that is the name of the language

getSimilarity(language, language)
#a function that will take 2 languages as its parameters and return a double that corresponds to the similarity between those two languages


OTHER FUNCTIONS

readFile()


FILES

main.cpp
languages.h
languages.cpp
compile


MILESTONE 1 MAIN DESIGN

-first check that there is only one command line arg
-if there is then continue or else throw an error
-return the trigram frequency vector seperated by spaces (use a for loop)

Libaries Needed
"languages.h"
<vector>
<string>


MILESTONE 2 MAIN DESIGN

-get the frequency of each inputted language
-compare the similarity of each language to test
-output the name of the language that is most similar to the test

Libaries Needed
"languages.h"
<vector>
<string>
<iostream>
<fstream>


COMPILE SCRIPT

files needed to compile
main.cpp
languages.cpp



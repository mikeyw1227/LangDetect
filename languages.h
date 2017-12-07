#ifndef _dna_h
#define _dna_h

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>

/*
A class to represent a language. A language object has three private
instance variables, a vector of trigrams, a vector of trigram
frequencies, and a name. A trigram cannot contain a newline character.
The trigram vector and the trigram frequency vector are in the same
order by a base-27 encoding.
*/

class languages {

public:

  //Default Constructor
  languages();

  /*
  Constructor that takes a string that is the languages name
  */
  languages(std::string langName, std::string lang);

  /*
  Constructor that takes a string that is a language
  */
  languages(std::string lang);

  /*
  Constructor that takes an input filestream that is expected to be
  an example of a language.
  */
  languages(std::ifstream &infile);

  /*
  A void function that takes a trigram and sets the puts the trigram
  in the proper order in the trigram array. If that trigram is already
  in the array the trigram frequency vector will change accordingly
  */
  void setTrigramFreq(std::string trigram);

  //returns the similarity between two vectors as a double
  double setSimilarity(std::vector<int> triFreq1, std::vector<int> triFreq2);

  //funciton to set the name of a triFreq
  void setName(std::string nm);


  //Getter Functions
  std::vector<int> getTrigramFreq();
  std::string getName();

private:

  //instance variables
  std::vector<int> trigramFreq;
  std::string name;
};

#endif

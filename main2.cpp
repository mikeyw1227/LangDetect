#include "languages.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

int main(int argc, char* argv){
  if(argc < 2){
    return 1; exit(EXIT_FAILURE);
  }
  //use if statement to do for the lowest comparision
  //get name for each language
  //return the name of a language
  for (int i = 1; i < argc - 1; i++){
    languages lang1 =  languages(agrv[i]);
    languages test = languages(argv[-1]);
    double comparision = setSimilarity(lang1, test);
  }
  return 0;
}

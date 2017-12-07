#include "languages.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

int main(int argc, char *argv[]){
  if(argc < 2){
    return 1; exit(EXIT_FAILURE);
  }
double comp = 0;
std::string name;
double similar;
for (size_t i = 1; i < argc - 2; i++){
  //language to be tested
  languages lang = languages(argv[i]);
  lang.setName(argv[i]);
  //setting the languages trigramfreq
  std::vector<int> langtf = lang.getTrigramFreq();

  //test language
  languages test = languages(argv[-1]);
  std::vector<int> testtf = test.getTrigramFreq();
  similar = setSimilarity(langtf, testtf);
  //seeing which lang is most similar
  if(similar > comp){
    comp = similar;
    name = lang.getName();
  }
}
  std::cout << name << std::endl;
  return 0;
}

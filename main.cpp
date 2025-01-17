#include "languages.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

int main(int argc, char *argv[]){
  if(argc <= 2){
    return 1; exit(EXIT_FAILURE);
  }

double comp = 0;
std::string name;
languages similar;
for (int i = 1; i < argc; i++){
  std::ifstream my_file(argv[i]);
if (my_file.good()){continue;}
else{return 1; exit(EXIT_FAILURE);}
}

for (int i = 1; i < argc - 2; i++){
  //language to be tested
  languages lang = languages(argv[i]);
  lang.setName(argv[i]);
  std::vector<int> langtf = lang.getTrigramFreq();

  //test language
  languages test = languages(argv[argc-1]);
  std::vector<int> testtf = test.getTrigramFreq();
  double sim = similar.setSimilarity(langtf, testtf);
  //seeing which lang is most similar
  if(sim > comp){
    comp = sim;
    name = lang.getName();
  }
}
  std::cout << name << std::endl;
  return 0;
}

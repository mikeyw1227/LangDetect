#include "languages.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

int main(int argc, char* argv){
  if(argc < 2){
    return 1; exit(EXIT_FAILURE);
  }

double similar;
for (int i = 1; i < argc - 1; i++){
  languages lang1 =  languages(agrv[i]);
  languages test = languages(argv[-1]);
  double comparision = setSimilarity(lang1, test);
  if (comparision[i] < comparision[i+1] && similar < comparision[i]){
    similar = comparision[i];}
  else{
    continue;}
}
  std::cout<<similar
  return 0;
}

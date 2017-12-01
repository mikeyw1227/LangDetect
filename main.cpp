#include "languages.h"
#include <vector>
#include <string>
#include <cstdlib>
#include <math.h>

int main(int argc, char *argv[]){
  //making sure there's only one comand lind argument
  if(argc != 2){
    return 1; exit(EXIT_FAILURE);
  }
  std::string lang = argv[1];
  languages l1 = languages::languages(lang);
  std::vector<int> triFreq = lang.getTrigramFreq();
  //outputting the trigram frequency vector
  for(int i = 0; i < triFreq.size(); i++){
    std::cout << triFreq[i] < std::endl;
  }
  return 0;
}

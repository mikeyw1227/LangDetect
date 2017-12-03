#include "languages.h"
#include <vector>
#include <string>
#include <cstdlib>


int main(int argc, char *argv[]){
  //making sure there's only one comand lind argument
  if(argc != 2){
    return 1; exit(EXIT_FAILURE);
  }
  std::string lang = argv[1];
  languages l1 = languages(lang);
  std::vector<int> triFreq = l1.getTrigramFreq();
  //outputting the trigram frequency vector
  for(size_t i = 0; i < triFreq.size(); i++){
    std::cout << triFreq[i] << std::endl;
  }
  return 0;
}

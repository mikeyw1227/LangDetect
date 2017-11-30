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
  language l1 = language(lang);
  std::vector<int> triFreq = getTrigramFreq();
  //outputting the trigram frequency vector
  for(int i = 0; i < triFreq.size(); i++){
    std::cout << triFreq[i] < std::endl;
  }
  return 0;
}

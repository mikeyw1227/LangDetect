#include "languages.h"
#include <vector>
#include <iostream>
#include <string>
#include <cmath>

languages::languages(){
  trigramFreq.resize(pow(27,3));
  name = "";
}

languages::languages(std::string lang){
  trigramFreq = getTrigramFreq();
  name = lang;
}

void setTrigramFreq(std::string language){
  std::string curStr;
  size_t index;
  int x;
  //loop through language to get frequencies
  for(int i = 0; i < language.length(); i++){
    curStr = language.substr(i, 3);
    for(int j = 0; j < curStr.length(); j++){
      x = curStr[j];
      if(x == 32){
        x = 0;
      }
      else{
        if(j == 0){
          index = index + ((x - 96) * pow(27,2));
        }
        if(j == 1){
          index = index + ((x - 96) * 27);
        }
        if(j == 2){
          index = index + (x - 96);
        }
      }
    }
    trigramFreq[index] += 1;
  }
}

languages::languages(std::ifstream &infile){
  for (std::string line; std::getline(infile, line); ){
    for (i = ; i <line.size(); i++){
      trigramFreq.push_back(setTrigramFreq(line[i]));
      }
    }
  }
std::vector<int> getTrigramFreq(){
  return trigramFreq;
}

std::string getName(){
  return name;
}

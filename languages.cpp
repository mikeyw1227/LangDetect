#include "languages.h"
#include <vector>
#include <iostream>
#include <string>
#include <cmath>

languages::languages(){
  trigramFreq.resize(pow(27,3));
  name = "";
}

languages::languages(std::string langName, std::string lang){
  setTrigramFreq(lang);
  trigramFreq = getTrigramFreq();
  name = langName;
}

languages::languages(std::string lang){
  setTrigramFreq(lang);
  trigramFreq = getTrigramFreq();
  name = "";
}

languages::languages(std::ifstream &infile){
  name = "";
  std::string line;
  std::vector<std::string> temp;
  std::string str;
  if(!infile.fail()){
    while(getline(infile, line)){
      temp.push_back(line);
    }
    for(size_t i = 0; i < temp.size(); i++){
      str.append(temp[i]);
    }
    setTrigramFreq(str);
    trigramFreq = getTrigramFreq();
  }
  else{
    throw std::runtime_error("Invalid File");
  }
  }

void languages::setTrigramFreq(std::string language){
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

std::vector<int> languages::getTrigramFreq(){
  return trigramFreq;
}

std::string languages::getName(){
  return name;
}

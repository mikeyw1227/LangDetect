#include "languages.h"
#include <vector>
#include <iostream>
#include <string>
#include <cmath>

languages::languages(){
  trigramFreq = std::vector<int>(pow(27,3),0);
  name = "";
}

languages::languages(std::string langName, std::string lang){
  trigramFreq=std::vector<int>(pow(27,3),0);
  setTrigramFreq(lang);
  trigramFreq = getTrigramFreq();
  name = langName;
}

languages::languages(std::string lang){
  trigramFreq = std::vector<int>(pow(27,3),0);
  setTrigramFreq(lang);
  trigramFreq = getTrigramFreq();
  name = "";
}

languages::languages(std::ifstream &infile){
  trigramFreq = std::vector<int>(pow(27,3),0);
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
  int index;
  int x;
  //loop through language to get trigrams
  for(int i = 0; i < (int)language.length()-2; i++){
    index = 0;
    curStr = language.substr(i, 3);
    //loop through substring to get frequencies
    for(int j = 0; j < (int)curStr.length(); j++){
      x = (int)curStr[j];
      //if there char is a space set it to 0
      if(x == 32){
        x = 0;
      }
      else{
        if(j == 0){
          int firstTerm = ((x - 96) * pow(27,2));
          index = index + firstTerm;
          //std::cout << "first: "<< firstTerm<<std::endl;
        }
        if(j == 1){
          int secondTerm = ((x - 96) * 27);
          index = index + secondTerm;
          //std::cout << "second: "<< secondTerm<<std::endl;
        }
        if(j == 2){
          int thirdTerm =  (x - 96);
          index = index +thirdTerm;
          //std::cout << "third: "<< thirdTerm<<std::endl;
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

double languages::setSimilarity(std::vector<int> triFreq1, std::vector<int> triFreq2){
  double similarity;
  int top = 0;
  int botA, botB;
  for(int i = 0; i < (int)triFreq1.size(); i++){
    top += (triFreq1[i] * triFreq2[i]);
    botA += pow(triFreq1[i], 2);
    botB += pow(triFreq2[i], 2);
  }

  return (top)/(sqrt(botA) * sqrt(botB));
}

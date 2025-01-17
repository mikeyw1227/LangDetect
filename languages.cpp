#include "languages.h"
#include <vector>
#include <iostream>
#include <string>
#include <cmath>


languages::languages(){
  trigramFreq = std::vector<int>(pow(27,3),0);
  name = "";
}
void languages::setName(std::string nm){
  name = nm;
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

/*
Function that takes a language as a parameter and sets the trigram
frequency of the language. The trigram frequency is a vector of
integers
*/
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
      //if the char is a space set its value to 0
      if(x == 32){
        x = 0;
      }
      else{
        //getting the value of the char in the 1st spot of the trigram
        if(j == 0){
          int firstTerm = ((x - 96) * pow(27,2));
          index = index + firstTerm;
        }
        //getting the value of the char in the 2nd spot of the trigram
        if(j == 1){
          int secondTerm = ((x - 96) * 27);
          index = index + secondTerm;
        }
        //getting the value of the char in the 3rd spot of the trigram
        if(j == 2){
          int thirdTerm =  (x - 96);
          index = index +thirdTerm;
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
  int top = 0;
  int botA = 0;
  int botB = 0;
  for(int i = 0; i < (int)triFreq1.size(); i++){
    top += (triFreq1[i] * triFreq2[i]);
    botA += pow(triFreq1[i], 2);
    botB += pow(triFreq2[i], 2);
  }

  return (top)/(sqrt(botA) * sqrt(botB));
}

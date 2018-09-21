#include <iostream>
#include <string>
#include "passagetokenizer.h"
using namespace std;

SectionToken::SectionToken(string str, type_t type) {
  sectionText = str;
  sectionType = type;
}

string SectionToken::getText() const {
  return sectionText;
}

void SectionToken::setType(type_t type){
  sectionType = type;
}

type_t SectionToken::getType() const {
  return sectionType;
}

PassageTokenizer::PassageTokenizer(string str){
  passageTextSource = str;
}

bool PassageTokenizer::hasNextSection(){
  if(passageTextSource.find("(set:", pLocation) != string::npos){
    return true;
  }
  else if(passageTextSource.find("(go-to:", pLocation) != string::npos){
    return true;
  }
  else if(passageTextSource.find("(if:", pLocation) != string::npos){
    return true;
  }
  else if(passageTextSource.find("(else-if:", pLocation) != string::npos){
    return true;
  }
  else if(passageTextSource.find("(else:", pLocation) != string::npos){
    return true;
  }
  else{
    return false;
  }
}

int PassageTokenizer::getLocation() const{
   return pLocation;
}

SectionToken PassageTokenizer::nextSection(){
  int sectionBeginning;
  type_t tempType;

  if(passageTextSource.find("(", pLocation) != string::npos || passageTextSource.find("[", pLocation) != string::npos){
      if((passageTextSource.find("(", pLocation) < passageTextSource.find("[", pLocation)) || (passageTextSource.find("[", pLocation) == string::npos)){
         pLocation = passageTextSource.find("(", pLocation);
      }
      else{
         pLocation = passageTextSource.find("[", pLocation);
      }
  }
  if(passageTextSource.substr(pLocation, 5) == "(set:"){
    tempType = SET;
    sectionBeginning = passageTextSource.find("(set:", pLocation);
    pLocation = passageTextSource.find(")", sectionBeginning) + 1;
  }
  else if(passageTextSource.substr(pLocation, 7) == "(go-to:"){
    tempType = GOTO;
    sectionBeginning = passageTextSource.find("(go-to:", pLocation);
    pLocation = passageTextSource.find(")", sectionBeginning) + 1;
  }
  else if(passageTextSource.substr(pLocation, 4) == "(if:"){
    tempType = IF;
    sectionBeginning = passageTextSource.find("(if:", pLocation);
    pLocation = passageTextSource.find(")", sectionBeginning) + 1;
  }
  else if(passageTextSource.substr(pLocation, 9) == "(else-if:"){
    tempType = ELSEIF;
    sectionBeginning = passageTextSource.find("(else-if:", pLocation);
    pLocation = passageTextSource.find(")", sectionBeginning) + 1;
  }
  else if(passageTextSource.substr(pLocation, 6) == "(else:"){
    tempType = ELSE;
    sectionBeginning = passageTextSource.find("(else:", pLocation);
    pLocation = passageTextSource.find(")", sectionBeginning) + 1;
  }
  else if(passageTextSource.substr(pLocation, 2) == "[["){
    tempType = LINK;
    sectionBeginning = passageTextSource.find("[[", pLocation);
    pLocation = passageTextSource.find("]]", sectionBeginning) + 2;
  }

  SectionToken stok(passageTextSource.substr(sectionBeginning, pLocation - sectionBeginning), tempType);
  return stok;
}

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

type_t SectionToken::getType() const {
  return sectionType;
}

PassageTokenizer::PassageTokenizer(string str){
  passageTextSource = str;
}

bool PassageTokenizer::hasNextSection(){
  return false;
}

SectionToken PassageTokenizer::nextSection(){
  SectionToken stok("", LINK);
  return stok;
}

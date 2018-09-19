#include <iostream>
#include <string>
using namespace std;

SectionToken::SectionToken(string str, type_t type) {
  sectionText = str;
  sectionType = type;
}

string SectionToken::getText() const {
  return sectionText;
}

string SectionToken::getType() const {
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

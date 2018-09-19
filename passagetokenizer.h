#ifndef PASSAGETOKENIZER_H
#define PASSAGETOKENIZER_H

#include <string>
using namespace std;

enum type_t = {LINK, GOTO, SET, IF, ELSEIF, ELSE, BLOCK, TEXT};

class SectionToken() {
	public:
		SectionToken(string str, type_t type);
		string getText() const;
		type_t getType() const;
	private:
		string sectionText;
		sectionType sectionType;
}

class PassageTokenizer() {
	public:
		PassageTokenizer(string str);
		bool hasNextSection();
		SectionToken nextSection();
	private:
		string passageTextSource;
		int location;
}

#endif PASSAGETOKENIZER_H

#ifndef PASSAGETOKENIZER_H
#define PASSAGETOKENIZER_H

#include <string>
using namespace std;

enum sectionType = {LINK, GOTO, SET, IF, ELSEIF, ELSE, BLOCK, TEXT};

class SectionToken() {
	public:
		SectionToken(string str);
		string getText();
		sectionType getType();
	private:
		string text;
		sectionType type;
}

class PassageTokenizer() {
	public:
		PassageTokenizer(string str);
		bool hasNextSection();
		SectionToken nextSection();
}

#endif PASSAGETOKENIZER_H

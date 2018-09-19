#ifndef STORYTOKENIZER_H
#define STORYTOKENIZER_H

#include "passagetokenizer.h"
#include <string>
using namespace std;

class PassageToken {
	public:
		PassageToken(string str);
		string getText() const;
	private:
		string passageText;
};

class StoryTokenizer {
	public:
		StoryTokenizer(string str);
		bool hasNextPassage();
		PassageToken nextPassage();
	private:
		string storyTextSource;
		int location = 0;
};

#endif

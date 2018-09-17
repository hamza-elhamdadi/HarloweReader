#ifndef STORYTOKENIZER_H
#define STORYTOKENIZER_H

#include "passagetokenizer.h"
#include <string>
using namespace std;

class PassageToken() {
	public:
		PassageToken(string str);
		string getText();
	private:
		string passageText;
}

class StoryTokenizer() {
	public:
		StoryTokenizer(string str);
		bool hasNextPassage();
		PassageToken nextPassage();
	private:
		string storyText;
		int location;
}

#endif

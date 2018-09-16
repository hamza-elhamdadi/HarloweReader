#ifndef STORYTOKENIZER_H
#define STORYTOKENIZER_H

#include "passagetokenizer.h"
using namespace std;

class PassageToken() {
	public:
		PassageToken();
		string getText();
	private:

}

class StoryTokenizer() {
	public:
		StoryTokenizer(string str);
		bool hasNextPassage();
		PassageToken nextPassage();
}

#endif

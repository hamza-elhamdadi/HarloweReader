#include "storytokenizer.h"
#include <iostream>
using namespace std;

PassageToken::PassageToken(string str) {
	passageText = str;
}

string PassageToken::getText() const{
	return passageText;
}

StoryTokenizer::StoryTokenizer(string str) {
	storyTextSource = str;
}

bool StoryTokenizer::hasNextPassage() {
	if (storyTextSource.find("<tw-passagedata ", location) != string::npos) {
		return true;
	}
	else {
		return false;
	}
}

PassageToken StoryTokenizer::nextPassage() {
	int passageBeginning;

	passageBeginning = storyTextSource.find("<tw-passagedata ", location);
	location = storyTextSource.find("</tw-passagedata>", passageBeginning) + 17;

	PassageToken ptok(storyTextSource.substr(passageBeginning, location - passageBeginning));

	return ptok;
}

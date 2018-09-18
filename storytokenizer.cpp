#include <iostream>
using namespace std;

PassageToken::PassageToken(string str) {
	passageText = str;
}

PassageToken::getText() {
	return passageText;
}

StoryTokenizer::StoryTokenizer(string str) {
	storyText = str;
}

bool StoryTokenizer::hasNextPassage() {
	if (passageText.find("<tw-passagedata ") != -1) {
		return true;
	}
	else {
		return false;
	}
}

PassageToken StoryTokenizer::nextPassage) {
	int passageBeginning;

	passageBeginning = storyText.find("<tw-passagedata ", location);
	location = storyText.find("</tw-passagedata>", passageBeginning) + 17;

	PassageToken ptok(passageText.substr(passageBeginning, location - passageBeginning));

	return ptok;
}


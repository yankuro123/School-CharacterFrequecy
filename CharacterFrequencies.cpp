#include "CharacterFrequencies.h"
CharacterFrequencies::CharacterFrequencies() {}
CharacterFrequencies::CharacterFrequencies(string line) {
	readString(line);
}

void CharacterFrequencies::readString(string line) {
	for (int i = 0; i < line.size(); i++) {
		char c = line.at(i);
		int charIndex = getCharacterIndex(c);

		// Check if this character is already present in the vector. If so,
		// then increment the frequency. If not, then add the character to the
		// end of the vector with frequency 1.
		if (charIndex == -1)
			frequencies.push_back(make_pair(c, 1));
		else
			frequencies.at(charIndex).second++;
	}
}

void CharacterFrequencies::reset() {
	frequencies.clear();
}

int CharacterFrequencies::getFrequency(char c) {
	int charIndex = getCharacterIndex(c);

	if (charIndex == -1)
		return 0;	// Not found so frequency is 0
	else
		return frequencies.at(charIndex).second;
}

int CharacterFrequencies::getCharacterIndex(char c) {
	for (int i = 0; i < frequencies.size(); i++) {
		if (frequencies.at(i).first == c)
			return i;
	}

	// Not found
	return -1;
}

void CharacterFrequencies::printFrequencies() {
	for (int i = 0; i < frequencies.size(); i++) {
		cout << frequencies.at(i).first << ": " << frequencies.at(i).second
			<< endl;
	}
}
int main(){
	string line2 = "AACEEECFCFABACCDBDEECFCEACCDBDEECF.";
	cout << line2 << endl;
	CharacterFrequencies line2CharFreq(line2);
	line2CharFreq.printFrequencies();
	line2CharFreq.readString(line2);
	line2CharFreq.printFrequencies();
}
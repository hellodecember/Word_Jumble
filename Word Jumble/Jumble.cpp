/*
* Name: Autumn Arnold
* Date: 1/16/2017
* Modified: 5/3/2020
*
* Classic word jumble game
*/

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <thread>

using namespace std;

int main() {
	enum fields {WORD, HINT, NUM_FIELDS};
	const int NUM_WORDS = 5;
	const string WORDS[NUM_WORDS][NUM_FIELDS] = {
		{ "wall", "Do you feel you’re banging your head against something?" },
		{ "glasses", "These might help you see the answer." },
		{ "labored", "Going slowly, is it?" },
		{ "persistent", "Keep at it." },
		{ "jumble", "It’s what the game is all about." }
	};

	srand(static_cast<unsigned int>(time(0)));
	int choice = (rand() % NUM_WORDS);
	string theWord = WORDS[choice][WORD];	//word to guess
	string theHint = WORDS[choice][HINT];	//corresponding hint

	string jumble = theWord;
	int length = jumble.size();
	for (int i = 0; i < length; i++) {
		int index1 = (rand() % length);
		int index2 = (rand() % length);

		char temp = jumble[index1];
		jumble[index1] = jumble[index2];
		jumble[index2] = temp;
	}

	cout << "Welcome to Word Jumble!\n" << endl;
	cout << "Unscramble the letters to make a word. \n" << endl;
	cout << "Enter 'hint' for a hint\n";
	cout << "Enter 'quit' to quit the game.\n" << endl;
	cout << "The word is: " << jumble << endl;
	
	string guess;
	cout << "Your guess is: ";
	cin >> guess;

	while (guess != "quit") {
		if (guess == "hint") {
			cout << theHint;
		}
		else if (guess == theWord) {
			cout << "\nThat's right! You guessed it!\n";
			break;
		}
		else {
			cout << "Sorry that isn't it. \n";
		}

		cout << "\nYour guess: ";
		cin >> guess;
	}

	std::chrono::seconds dura(2);
	std::this_thread::sleep_for(dura);

	cout << "\nThanks for playing!\n";

	std::this_thread::sleep_for(dura);

	return 0;
}
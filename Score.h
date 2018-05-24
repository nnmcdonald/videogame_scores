#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// This is a Score class that keeps track of a player name and a score.
// For simplicity it is here in the main file, but you might put it into
// its own header and implementation file.
class Score
{
private:
	string name;
	int score;
public:
	Score();
	Score(string newName, int newScore);
	string getName();
	int getScore();
};
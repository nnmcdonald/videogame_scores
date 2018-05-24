#include "Score.h"
#include <vector>
using namespace std;

// This is the main function that reads in a name/value pair of high
// scores for a game from a file until the end of file is reached.
// It then lets the user input a name and outputs the high score and number of times
// the game is played.

int main()
{
	ifstream scoresFile;
	vector<Score> scoreList;

	cout << "Reading in game scores..." << endl;
	scoresFile.open("scores.txt");
	while (!scoresFile.eof())
	{
		string name;
		scoresFile >> name;
		if (!scoresFile.eof())
		{
			int score;
			scoresFile >> score;
			scoreList.push_back(Score(name, score));
		}
	}
	cout << "Scores read." << endl;
	scoresFile.close();

	// This part reads in a name and outputs some info about the
	// scores for the player
	cout << endl;
	cout << "Enter a name to look up scores, blank line to exit." << endl;
	string name;
	getline(cin, name);
	while (name.length() > 0)
	{
		int timesPlayed = 0;
		int highscore = -1;
		for (int i = 0; i < scoreList.size(); i++)
		{
			if (scoreList[i].getName() == name)
			{
				timesPlayed++;
				if (highscore < scoreList[i].getScore())
					highscore = scoreList[i].getScore();
			}
		}
		if (timesPlayed > 0)
		{
			cout << name << " has a high score of " << highscore <<
				" and has played " << timesPlayed << " times." << endl;
		}
		else
		{
			cout << name << " has no recorded scores." << endl;
		}
		getline(cin, name); // Read next name
	}

	return 0;
}

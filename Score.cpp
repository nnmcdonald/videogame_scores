#include "Score.h"

Score::Score() : name(""), score(0)
{ }
Score::Score(string newName, int newScore) : name(newName), score(newScore)
{ }
string Score::getName()
{
	return name;
}
int Score::getScore()
{
	return score;
}

#ifndef NOTNOTGAME_H
#define NOTNOTGAME_H

#include <iostream>
#include <conio.h>
#include <vector>
#include <string>
#include <set>

using namespace std;

class NovicePlayer;

struct ques_ans {
	string question;
	set<int> answer;
};

class NotNotGame
{
private:
	vector<bool> said;
	int question_num;
	const int exp = 15;
	double time_limit = 2.00;
	int revival_times = 1;
	vector<ques_ans> source;
	void initializeQuestion();
	void setCursor(int x, int y);
public:
	NotNotGame(int num);
	bool run(vector<NovicePlayer*> player_list);

};

#endif
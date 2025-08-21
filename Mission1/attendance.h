#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

namespace {
	const string USER_INPUT = "attendance_weekday_500.txt";
	const string GOLD = "GOLD";
	const string SILVER = "SILVER";
	const string NORMAL = "NORMAL";
	const string WEDNESDAY = "wednesday";
	const string SATURDAY = "saturday";
	const string SUNDAY = "sunday";

	const int BONUS_POINTS = 10;
	const int TRAININGDAY_POINTS = 3;
	const int WEEKEND_POINTS = 2;
	const int NORMAL_POINTS = 1;
	const int GOLD_POINTS = 50;
	const int SILVER_POINTS = 30;
	const int TEN_ATTEND = 10;

	const int INPUT_SIZE = 500;
}

class UserInfo {
public:
	string name;
	int points;
	string grade;
	int days;
	int trainingDay;
	int weekend;

	UserInfo(string userName) {
		name = userName;
		points = days = trainingDay = weekend = 0;
		grade = NORMAL;
	}
};

struct Input {
	string userName;
	string week;
};

extern Input tokenizeInput(ifstream& fin);
extern void calculatePoint(Input input);
extern int getUserId(const string userName);
extern int calculateBonusPoint(UserInfo* userInfo);
extern string decideGrade(UserInfo* userInfo);
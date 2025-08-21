#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "user_info.h"

using namespace std;

namespace {
	const string USER_INPUT = "attendance_weekday_500.txt";
	const string GOLD = "GOLD";
	const string SILVER = "SILVER";
	const string NORMAL = "NORMAL";
	const string MONDAY = "monday";
	const string WEDNESDAY = "wednesday";
	const string SATURDAY = "saturday";
	const string SUNDAY = "sunday";

	const int BONUS_POINTS = 10;
	const int TRAININGDAY_POINTS = 3;
	const int WEEKEND_POINTS = 2;
	const int NORMAL_POINTS = 1;
	const int TEN_ATTEND = 10;
}

class AttendManager {
private:
	ifstream fin;
public:
	map<string, int> idMap;
	map<int, UserInfo*> userMap;
	vector <string> removedPlayer;
	int id_cnt = 0;

	void runAttendManger(void);
	void tokenizeInput();
	void getUserInfo(string name, string week);
	int getUserId(const string userName);
	int calculateBonusPoint(UserInfo* userInfo);
	Grade* decideGrade(UserInfo* userInfo);
	void printPlayerInfo(UserInfo* userInfo);
	void printRemovedPlayer(void);

	AttendManager(string inputFile) {
		fin.open(inputFile);
	}

	~AttendManager() {
		fin.close();
	}
};
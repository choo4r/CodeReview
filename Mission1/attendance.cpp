#include "attendance.h"
#include "attendance_print.h"

map<string, int> idMap;
map<int, UserInfo*> userMap;
int id_cnt = 0;

void attendanceManger() {

	ifstream fin{ USER_INPUT };
	for (int i = 0; i < INPUT_SIZE; i++) {
		calculatePoint(tokenizeInput(fin));
	}

	for (int userId = 1; userId <= id_cnt; userId++) {
		UserInfo* userInfo = userMap[userId];
		userInfo->points += calculateBonusPoint(userInfo);
		userInfo->grade = decideGrade(userInfo);
		printPlayerInfo(userInfo);
	}

	printRemovedPlayer();
}

Input tokenizeInput(ifstream& fin) {
	Input info;
	fin >> info.userName >> info.week;
	return info;
}

void calculatePoint(Input input) {

	int userId = getUserId(input.userName);
	UserInfo* userInfo = userMap[userId];

	if (input.week == WEDNESDAY) {
		userInfo->trainingDay++;
		userInfo->points += TRAININGDAY_POINTS;
	}
	else if (input.week == SATURDAY || input.week == SUNDAY) {
		userInfo->weekend++;
		userInfo->points += WEEKEND_POINTS;
	}
	else {
		userInfo->points += NORMAL_POINTS;
	}

}

int getUserId(const string userName) {
	if (idMap.count(userName) == 0) {
		idMap.insert({ userName, ++id_cnt });
		userMap.insert({ id_cnt, new UserInfo(userName) });
	}

	return idMap[userName];
}

int calculateBonusPoint(UserInfo* userInfo) {
	int bonus = 0;

	if (userInfo->trainingDay >= TEN_ATTEND)
		bonus += BONUS_POINTS;

	if (userInfo->weekend >= TEN_ATTEND)
		bonus += BONUS_POINTS;

	return bonus;
}

string decideGrade(UserInfo* userInfo) {
	string grade = NORMAL;

	if (userInfo->points >= GOLD_POINTS) {
		grade = GOLD;
	}
	else if (userInfo->points >= SILVER_POINTS) {
		grade = SILVER;
	}

	return grade;
}

int main() {
	attendanceManger();
}
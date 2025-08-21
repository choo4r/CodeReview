#include "attend_manager.h"
#include "grade.h"
#include "policy.h"

void AttendManager::runAttendManger() {

	tokenizeInput();

	for (int userId = 1; userId <= id_cnt; userId++) {
		UserInfo* userInfo = userMap[userId];
		userInfo->points += calculateBonusPoint(userInfo);
		userInfo->grade = decideGrade(userInfo);
		printPlayerInfo(userInfo);
	}

	printRemovedPlayer();
}

void AttendManager::tokenizeInput() {
	string userName;
	string week;
	string line;

	while (!fin.eof()) {
		fin >> userName >> week;
		getUserInfo(userName, week);
	}
}

void AttendManager::getUserInfo(string name, string week) {
	int userId = getUserId(name);
	UserInfo* userInfo = userMap[userId];

	Policy* policy = policyFactory(week);

	if (week == WEDNESDAY) {
		userInfo->trainingDay++;
	}
	else if (week == SATURDAY || week == SUNDAY) {
		userInfo->weekend++;
	}
	userInfo->points += policy->weekPoint();
}

int AttendManager::getUserId(const string userName) {
	if (idMap.count(userName) == 0) {
		idMap.insert({ userName, ++id_cnt });
		userMap.insert({ id_cnt, new UserInfo(userName) });
	}

	return idMap[userName];
}

int AttendManager::calculateBonusPoint(UserInfo* userInfo) {
	int bonus = 0;

	if (userInfo->trainingDay >= TEN_ATTEND)
		bonus += BONUS_POINTS;

	if (userInfo->weekend >= TEN_ATTEND)
		bonus += BONUS_POINTS;

	return bonus;
}

Grade* AttendManager::decideGrade(UserInfo* userInfo) {

	Grade* grade = gradeFactory(userInfo->points);
	return grade;
}

void AttendManager::printPlayerInfo(UserInfo* userInfo) {
	cout << "NAME : " << userInfo->name << ", ";
	cout << "POINT : " << userInfo->points << ", ";
	cout << "GRADE : " << userInfo->grade->gradeType << "\n";
}

void AttendManager::printRemovedPlayer() {
	std::cout << std::endl;
	std::cout << "Removed player" << std::endl;
	std::cout << "==============" << std::endl;

	for (int userId = 1; userId <= id_cnt; userId++) {
		UserInfo* userInfo = userMap[userId];

		if (userInfo->grade->gradeType != NORMAL)
			continue;

		if (userInfo->trainingDay != 0 || userInfo->weekend != 0)
			continue;

		std::cout << userInfo->name << std::endl;
		removedPlayer.push_back(userInfo->name);
	}
}
#pragma once
#include <string>
#include "grade.h"
using namespace std;

class UserInfo {
public:
	string name;
	int points;
	Grade* grade;
	int days;
	int trainingDay;
	int weekend;

	UserInfo(string userName) {
		name = userName;
		points = days = trainingDay = weekend = 0;
		grade = NULL;
	}
};

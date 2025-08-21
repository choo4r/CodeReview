#pragma once
#include <string>

using namespace std;

namespace {
	const int GOLD_POINTS = 50;
	const int SILVER_POINTS = 30;
};

class Grade {
public:
	string gradeType;
};
class GradeGolde : public Grade {
public:
	GradeGolde() {
		gradeType = "GOLD";
	}
};
class GradeSilver : public Grade {
public:
	GradeSilver() {
		gradeType = "SILVER";
	}
};
class GradeNormal : public Grade {
public:
	GradeNormal() {
		gradeType = "NORMAL";
	}
};

extern Grade* gradeFactory(int point);
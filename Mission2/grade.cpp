#include "grade.h"

Grade* gradeFactory(int point) {
	if (point >= GOLD_POINTS)
		return new GradeGolde();
	else if (point >= SILVER_POINTS)
		return new GradeSilver();

	return new GradeNormal();
}
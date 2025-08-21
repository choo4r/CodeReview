#include "gmock/gmock.h"
#include "attend_manager.h"

using namespace testing;
class AttendManagerFixture : public Test {

protected:
	void SetUp() {
		//AttendManager manager("attendance_weekday_500.txt");
		manager = new AttendManager("C:/Users/User/source/repos/AttendManager/Mission2/gtest_input.txt");
	}

public:
	AttendManager *manager;
};

TEST_F(AttendManagerFixture, GET_USER_ID) {
	EXPECT_EQ(1, manager->getUserId("CHOO"));
	EXPECT_EQ(1, manager->getUserId("CHOO"));
	EXPECT_EQ(2, manager->getUserId("KIM"));
}

TEST_F(AttendManagerFixture, GET_USER_INFO) {

	manager->getUserInfo("CHOO", MONDAY);
	manager->getUserInfo("CHOO", WEDNESDAY);
	manager->getUserInfo("CHOO", SUNDAY);
	manager->getUserInfo("KIM", SATURDAY);
	manager->getUserInfo("PARK", WEDNESDAY);


	UserInfo *user = manager->userMap[manager->getUserId("CHOO")];
	EXPECT_EQ(6, user->points);

	user = manager->userMap[manager->getUserId("KIM")];
	EXPECT_EQ(2, user->points);

	user = manager->userMap[manager->getUserId("PARK")];
	EXPECT_EQ(3, user->points);
}

TEST_F(AttendManagerFixture, TOKENIZE_INPUT) {
	manager->tokenizeInput();
	UserInfo* user = manager->userMap[manager->getUserId("choo")];
	EXPECT_EQ(60, user->points);

	user = manager->userMap[manager->getUserId("kim")];
	EXPECT_EQ(40, user->points);

	user = manager->userMap[manager->getUserId("park")];
	EXPECT_EQ(45, user->points);

	user = manager->userMap[manager->getUserId("oh")];
	EXPECT_EQ(5, user->points);

	user = manager->userMap[manager->getUserId("cherry")];
	EXPECT_EQ(23, user->points);
}

TEST_F(AttendManagerFixture, CAL_BONUS_POINT) {
	manager->tokenizeInput();
	UserInfo* user = manager->userMap[manager->getUserId("choo")];
	EXPECT_EQ(20, manager->calculateBonusPoint(user));

	user = manager->userMap[manager->getUserId("kim")];
	EXPECT_EQ(10, manager->calculateBonusPoint(user));

	user = manager->userMap[manager->getUserId("park")];
	EXPECT_EQ(10, manager->calculateBonusPoint(user));

	user = manager->userMap[manager->getUserId("oh")];
	EXPECT_EQ(0, manager->calculateBonusPoint(user));

	user = manager->userMap[manager->getUserId("cherry")];
	EXPECT_EQ(10, manager->calculateBonusPoint(user));
}

TEST_F(AttendManagerFixture, DECIDE_GRADE) {
	manager->tokenizeInput();
	UserInfo* user = manager->userMap[manager->getUserId("choo")];
	user->points += manager->calculateBonusPoint(user);
	string gradeType = (manager->decideGrade(user))->gradeType;
	EXPECT_EQ("GOLD", gradeType);

	user = manager->userMap[manager->getUserId("cherry")];
	user->points += manager->calculateBonusPoint(user);
	gradeType = (manager->decideGrade(user))->gradeType;
	EXPECT_EQ("SILVER", gradeType);

	user = manager->userMap[manager->getUserId("oh")];
	user->points += manager->calculateBonusPoint(user);
	gradeType = (manager->decideGrade(user))->gradeType;
	EXPECT_EQ("NORMAL", gradeType);
}

TEST_F(AttendManagerFixture, RUN_ATTEND_MANAGER) {
	manager->runAttendManger();
	EXPECT_EQ("oh", manager->removedPlayer[0]);
}
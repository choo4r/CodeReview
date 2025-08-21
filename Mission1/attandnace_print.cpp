#include "attendance_print.h"

void printPlayerInfo(UserInfo* userInfo) {
	cout << "NAME : " << userInfo->name << ", ";
	cout << "POINT : " << userInfo->points << ", ";
	cout << "GRADE : " << userInfo->grade << "\n";
}

void printRemovedPlayer() {
	std::cout << std::endl;
	std::cout << "Removed player" << std::endl;
	std::cout << "==============" << std::endl;

	for (int userId = 1; userId <= id_cnt; userId++) {
		UserInfo* userInfo = userMap[userId];

		if (userInfo->grade != NORMAL)
			continue;

		if (userInfo->trainingDay != 0 || userInfo->weekend != 0)
			continue;

		std::cout << userInfo->name << std::endl;
	}
}
#ifdef _DEBUG
#include "gmock/gmock.h"

int main(void) {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}
#else

#include "attend_manager.h"
int main() {
	AttendManager manager(USER_INPUT);
	manager.runAttendManger();
}
#endif
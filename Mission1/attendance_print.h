#pragma once
#include "attendance.h"

extern map<string, int> idMap;
extern map<int, UserInfo*> userMap;
extern int id_cnt;

extern void printPlayerInfo(UserInfo* userInfo);
extern void printRemovedPlayer();

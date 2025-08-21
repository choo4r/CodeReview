#pragma once
#include <string>

using namespace std;

class Policy {
public:
	string week;
	virtual int weekPoint() = 0;
};

class NormalPolicy : public  Policy {
public:
	int weekPoint() override;
};

class TraniningPolicy : public  Policy {
public:
	int weekPoint() override;
};

class WeekendPolicy : public  Policy {
public:
	int weekPoint() override;
};

extern Policy* policyFactory(string week);
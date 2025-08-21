#include "policy.h"
#include "attend_manager.h"

int NormalPolicy::weekPoint() {
	return NORMAL_POINTS;
}

int TraniningPolicy::weekPoint() {
	return TRAININGDAY_POINTS;
}

int WeekendPolicy::weekPoint() {
	return WEEKEND_POINTS;
}

Policy* policyFactory(string week) {
	if (week == WEDNESDAY)
		return new TraniningPolicy();
	else if (week == SATURDAY || week == SUNDAY)
		return new WeekendPolicy();
	return new NormalPolicy();
}
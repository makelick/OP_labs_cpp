#include "Header.h"

int getMonthsBetweenDates(Date& date1, Date& date2) {
	return ((date1.year - date2.year) * 12) + date1.month - date2.month;
}
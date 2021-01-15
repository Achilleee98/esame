#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <stdbool.h>

typedef struct {
    unsigned short day;
    unsigned short month;
    unsigned short year;
} sDate;

bool isLeapYear(const unsigned short year);
bool isValidDate(const sDate date, const char *dayEndString, const char *monthEndString, const char *yearEndString);
sDate acquireDate();

#endif // DATE_H_INCLUDED

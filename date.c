#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "date.h"
#include "constants.h"

bool isLeapYear(const unsigned short year)
{
    return (((year % 400 == 0) || (year % 100 != 0)) && (year % 4 == 0));
}

bool isValidDate(const sDate date, const char *dayEndString, const char *monthEndString, const char *yearEndString)
{
    if (dayEndString == NULL || monthEndString == NULL || yearEndString == NULL)
        return false;

    if (strcmp(dayEndString, "") != 0 || strcmp(monthEndString, "") != 0 || strcmp(yearEndString, "") != 0)
        return false;

    if (date.month > 12)
        return false;

    const int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (date.day == 0)
        return false;

    if (date.year < MIN_YEAR_RANGE_VALUE)
        return false;

    if (date.year > MAX_YEAR_RANGE_VALUE)
        return false;

    if (isLeapYear(date.year) && date.month == 2)
    {
        if (date.day > (monthDays[date.month - 1] + 1))
            return false;
    }
    else
    {
        if (date.day > monthDays[date.month - 1])
            return false;
    }

    return true;
}

sDate acquireDate()
{
    sDate date = {0, 0, 0};

    char dayString[MAX_STRING_LENGHT] = {0};
    char monthString[MAX_STRING_LENGHT] = {0};
    char yearString[MAX_STRING_LENGHT] = {0};

    char *dayEndString = NULL;
    char *monthEndString = NULL;
    char *yearEndString = NULL;

    do
    {
        printf("Inserisci la data di ascolto separando con uno spazio (gg mm year):\n");
        scanf("%s %s %s", dayString, monthString, yearString);
        fflush(stdin);

        date.day = (unsigned short)strtol(dayString, &dayEndString, 0);
        date.month = (unsigned short)strtol(monthString, &monthEndString, 0);
        date.year = (unsigned short)strtol(yearString, &yearEndString, 0);
    } while (!isValidDate(date, dayEndString, monthEndString, yearEndString));

    return date;
}

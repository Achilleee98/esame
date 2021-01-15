#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "listen.h"
#include "constants.h"

float calculateAverageDuration(const float total, const float sum)
{
    float result = 0.0;

    if (sum > 0)
        result = sum / total;

    return result;
}

unsigned short acquireListenDuration()
{
    unsigned short tempDuration = 0;
    char tempStringDuration[MAX_STRING_LENGHT] = "";

    do
    {
        printf("Inserisci la durata dell'ascolto:\n");
        scanf("%s", tempStringDuration);
        fflush(stdin);
        tempDuration = (unsigned short)atoi(tempStringDuration);
    } while (!isValidListenDuration(tempDuration));

    return tempDuration;
}

bool isValidListenData(const sListen currListenData)
{
    if (!isValidListenDuration(currListenData.duration))
        return false;

    if (!isValidDate(currListenData.date, "", "", ""))
        return false;

    return true;
}

bool isValidListenDuration(const unsigned short duration)
{
    if (duration < MIN_LISTEN_DURATION_RANGE_VALUE)
        return false;

    if (duration > MAX_LISTEN_DURATION_RANGE_VALUE)
        return false;

    return true;
}


/*
void setListenDataDuration(sListen *listenData, const unsigned short duration)
{
    listenData->duration = duration;
}

void setListenDataDate(sListen *listenData, const sDate date)
{
    listenData->date = date;
}
*/

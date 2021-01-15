#ifndef LISTEN_H_INCLUDED
#define LISTEN_H_INCLUDED

#include "date.h"

typedef struct {
    unsigned short duration;
    sDate date;
} sListen;


float calculateAverageDuration(const float total, const float sum);

unsigned short acquireListenDuration();

bool isValidListenData(const sListen currListenData);
bool isValidListenDuration(const unsigned short duration);


#endif // LISTEN_H_INCLUDED

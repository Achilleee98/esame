#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include "artist.h"
#include "date.h"

void testing()
{
    printf("Fase di testing:\n");

    assert(isValidListenDuration(100) == true);                // Durata corretta
    assert(isValidListenDuration(50) == true);                // Durata corretta
    assert(isValidListenDuration(0) == false);                // Durata non corretta (fuori dal range)
    assert(isValidListenDuration(4) == false);               // Durata non corretta (fuori dal range)
    assert(isValidListenDuration(750) == false);               // Durata non corretta (fuori dal range)

    sDate date = {1, 2, 2000};
    assert(isValidDate(date, "", "", "") == true);    // Data corretta

    sDate date_correct = {29, 2, 2016};
    assert(isValidDate(date_correct, "", "", "") == true);    // Data corretta (bisestile)

    sDate date_not_correct_day = {32, 1, 2020};
    assert(isValidDate(date_not_correct_day, NULL, NULL, NULL) == false);    // Data non corretta

    sDate date_not_correct_month = {31, 13, 2020};
    assert(isValidDate(date_not_correct_month, NULL, NULL, NULL) == false);    // Data non corretta

    sDate date_not_correct_year = {31, 1, 2050};
    assert(isValidDate(date_not_correct_year, NULL, NULL, NULL) == false);    // Data non corretta

    sDate date_not_correct_string = {31, 1, 2020};
    assert(isValidDate(date_not_correct_string, "qq", "qq", NULL) == false);    // Data non corretta


    printf("Testing eseguito con successo.\n");
}

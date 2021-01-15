#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "artist.h"

void managePrintArtistArchive(sArtistData *artistsArchive, const int countArtists)
{
    int i;
    for (i = 0; i < countArtists; i++)
    {
        sArtistData *currArtistData = &artistsArchive[i];
        printf("Artista numero: %d\n", i+1);

        printf("%10s\t\t", "Nome artista:");
        printf("%s\n", getArtistDataName(currArtistData));

        printf("%10s\t\t", "Genere artista:");
        printf("%s\n", getArtistDataGenre(currArtistData));

        printf("%10s\t\t", "Durata ascolto:");
        printf("%hu\n", getArtistListenDataDuration(currArtistData));

        printf("%10s\t\t", "Giorno ascolto:");
        printf("%hu\n", getArtistListenDataDate(currArtistData).day);

        printf("%10s\t\t", "Mese ascolto:");
        printf("%hu\n", getArtistListenDataDate(currArtistData).month);

        printf("%10s\t\t", "Anno ascolto:");
        printf("%hu\n", getArtistListenDataDate(currArtistData).year);

        printf("\n");
    }

    printf("\n");
}

void manageInsertNewArtistArchive(sArtistData *artistsArchive, int *countArtists)
{
    sArtistData newArtist;
    acquireInputArtist(&newArtist);

    newArtist.listen.duration = acquireListenDuration();
    newArtist.listen.date = acquireDate();

    if (isInsertNewArtist(artistsArchive, newArtist, countArtists))
    {
        printf("Artista inserito con successo.\n");
        (*countArtists)++;
    }
    else
    {
        printf("Non è stato possibile inserire l'artista.\n");
    }

    printf("\n");
}

void manageCalculateAverageArtistDuration(sArtistData *artistsArchive, const int countArtists)
{
    char nameArtist[MAX_ARTIST_NAME_LENGHT] = "";
    acquireNameArtist(nameArtist);

    if (!isFindArtistName(artistsArchive, nameArtist, countArtists))
    {
        printf("Non è stato trovato nessun artista con questo nome.\n");
    }
    else
    {
        float average = calculateAverageArtistDuration(artistsArchive, nameArtist, countArtists);
        printf("%f\n", average);
    }

    printf("\n");
}

bool isFindArtistName(sArtistData *artistsArchive, const char *nameArtist, const int countArtists)
{
    bool bFind = false;     // Variabile sentinella

    int i;
    for (i = 0; i < countArtists; i++)
    {
        sArtistData *currArtistData = &artistsArchive[i];    // Variabile che corrisponde all'attuale artista nell'archivio
        if (strcmp(getArtistDataName(currArtistData), nameArtist) == 0) // Se l'artista attule ha lo stesso nome la variabile sentinella viene impostata su true ed esce dal ciclo
        {
            bFind = true;
            i = countArtists;
        }
    }

    return bFind;
}

int calculateAverageArtistDuration(sArtistData *artistsArchive, const char *nameArtist, const int countArtists)
{
    int sum = 0;
    int total = 0;

    int i;
    for (i = 0; i < countArtists; i++)
    {
        sArtistData *currArtist = &artistsArchive[i];
        if (strcmp(getArtistDataName(currArtist), nameArtist) == 0)
        {
            sum += getArtistListenDataDuration(currArtist);
            total++;
        }
    }

    return calculateAverageDuration((float)total, (float)sum);
}

bool isInsertNewArtist(sArtistData *artistsArchive, const sArtistData newArtist, int *countArtists)
{
    if (*countArtists >= MAX_ARTIST_ARCHIVE_SIZE - 1)   // -1 poichè countArtists include anche lo 0 come primo elemento
        return false;

    sArtistData *currArtistData = &artistsArchive[*countArtists];   // Variabile che corrisponde all'ultima posizione nell'archivio

    setArtistDataName(currArtistData, newArtist.nameArtist);
    setArtistDataGenre(currArtistData, newArtist.nameGenre);

    setArtistListenDataDuration(currArtistData, newArtist.listen.duration);
    setArtistListenDataDate(currArtistData, newArtist.listen.date);

    return true;
}

void acquireInputArtist(sArtistData *newArtist)
{
    printf("Inserisci i dati del nuovo artista da inserire:\n");

    char nameArtist[MAX_ARTIST_NAME_LENGHT] = "";
    acquireNameArtist(nameArtist);

    char nameGenre[MAX_ARTIST_GENRE_LENGHT] = "";
    acquireNameGenre(nameGenre);

    setArtistDataName(newArtist, nameArtist);
    setArtistDataGenre(newArtist, nameGenre);
}

void acquireNameArtist(char *name)
{
    char tempName[MAX_STRING_LENGHT] = "";
    do
    {
        printf("Inserisci il nome dell'artista:\n");
        scanf("%s", tempName);
        fflush(stdin);
    } while (!isValidNameArtistString(tempName));

    strcpy(name, tempName);
}

void acquireNameGenre(char *genre)
{
    char tempGenre[MAX_STRING_LENGHT] = "";
    do
    {
        printf("Inserisci il genere dell'artista:\n");
        scanf("%s", tempGenre);
        fflush(stdin);
    } while (!isValidGenreString(tempGenre));

    strcpy(genre, tempGenre);
}



bool isValidArtistData(const sArtistData currArtistData)
{
    if (!isValidNameArtistString(currArtistData.nameArtist))
        return false;

    if (!isValidGenreString(currArtistData.nameGenre))
        return false;

    if (!isValidListenData(currArtistData.listen))
        return false;

    return true;
}

bool isValidNameArtistString(const char *name)
{
    int lenght = strlen(name);

    if (lenght < MIN_ARTIST_NAME_LENGHT)
        return false;

    if (lenght > MAX_ARTIST_NAME_LENGHT)
        return false;

    int i;
    for (i = 0; i < lenght; i++)
    {
        if (!isalnum(name[i]))          // Se è presente almeno un carattere speciale, la stringa non è valida
            return false;
    }

    return true;
}


bool isValidGenreString(const char *genre)
{
    int lenght = strlen(genre);

    if (lenght < MIN_ARTIST_GENRE_LENGHT)
        return false;

    if (lenght > MAX_ARTIST_GENRE_LENGHT)
        return false;

    return true;
}







void setArtistDataName(sArtistData *artistData, const char *name)
{
    strcpy(artistData->nameArtist, name);
}

void setArtistDataGenre(sArtistData *artistData, const char *genre)
{
    strcpy(artistData->nameGenre, genre);
}


void setArtistListenDataDuration(sArtistData *artistData, const unsigned short duration)
{
    artistData->listen.duration = duration;
}

void setArtistListenDataDate(sArtistData *artistData, const sDate date)
{
    artistData->listen.date = date;
}


const char *getArtistDataName(sArtistData *artistData)
{
    return artistData->nameArtist;
}

const char *getArtistDataGenre(sArtistData *artistData)
{
    return artistData->nameGenre;
}

unsigned short getArtistListenDataDuration(sArtistData *artistData)
{
    return artistData->listen.duration;
}

sDate getArtistListenDataDate(sArtistData *artistData)
{
    return artistData->listen.date;
}

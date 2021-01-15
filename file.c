#include <stdio.h>
#include "file.h"

/** @file file.c
 *
 *  Synthetic description. Implementazione delle funzioni presentate in file.h. Le funzioni svolgono le operazioni
 *                         principali per la gestione (lettura e scrittura) di dati su file.
 *
 *  @version 1.0
 *  @date 10/06/2020
 *  @author Alessandro Daniele
 */


void manageInitArtistArchive(FILE *file, sArtistData *artistsArchive, int *countArtists)
{
    int countReadFile = initLoadArtistArchive(file, artistsArchive, *countArtists);
    if (countReadFile > 0)
    {
        printf("Archivio caricato da file con successo.\n");
        *countArtists = countReadFile;
    }
    else
    {
        printf("Non è stato possibile caricare l'archivio da file.\n");
    }

    printf("\n");
}


/**
 *  Funzione che si occupa di acquisire i dati da file ed inserirli nell'archivio.
 *  Acquisisce tutti i dati presenti all'interno del file.
 *  Inolte nel caso i dati acquisiti non siano validi, vengono ignorati.
 *  @pre L'archivio degli artisti deve essere vuoto, non inizializzato
 *  @post L'archivio degli artisti conterrà i dati acquisiti dal file
 *
 */
int initLoadArtistArchive(FILE *file, sArtistData *artistsArchive, const int countArtists)
{
    int i = 0;

    if (countArtists > 0)
        return i;

    // Legge dal file fin quando non si raggiunge la fine, o la dimensione dell'archivio termina
    while (!feof(file) && i < MAX_ARTIST_ARCHIVE_SIZE)
    {
        sArtistData newArtistData;
        int line = fscanf(file, "%s\t%s\t%hu\t%hu\t%hu\t%hu\t", newArtistData.nameArtist, newArtistData.nameGenre,
                          &newArtistData.listen.duration,
                          &newArtistData.listen.date.day,
                          &newArtistData.listen.date.month,
                          &newArtistData.listen.date.year);

        // Controlla che ci sia corrispondenza con i dati richiesti e che questi siano validi
        if (line > 0 && (isValidArtistData(newArtistData) == true))
        {
            sArtistData *currArtistData = &artistsArchive[i];    // Variabile che corrisponde all'attuale utente nell'archivio

            setArtistDataName(currArtistData, newArtistData.nameArtist);
            setArtistDataGenre(currArtistData, newArtistData.nameGenre);

            setArtistListenDataDuration(currArtistData, newArtistData.listen.duration);
            setArtistListenDataDate(currArtistData, newArtistData.listen.date);

            i++;
        }
        else
            printf("failed\n");
    }

    return i;
}

/**
 *  Funzione che si occupa di salvare i dati presenti nell'archivio su file.
 *  @pre L'archivio degli artisti deve essere inizializzato
 *  @post Il file conterrà l'archivio degli artisti presente nella struttura
 *
 */
void saveArtistArchiveToFile(FILE *file, sArtistData *artistsArchive, const int countArtists)
{
    int i;
    for (i = 0; i < countArtists; i++)
    {
        sArtistData *currArtistData = &artistsArchive[i];    // Variabile che corrisponde all'attuale utente nell'archivio
        fprintf(file, "%s\t%s\t%hu\t%hu\t%hu\t%hu\t\n",
                getArtistDataName(currArtistData),
                getArtistDataGenre(currArtistData),
                getArtistListenDataDuration(currArtistData),
                getArtistListenDataDate(currArtistData).day,
                getArtistListenDataDate(currArtistData).month,
                getArtistListenDataDate(currArtistData).year);
    }
}

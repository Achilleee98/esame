#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

#include "artist.h"

/** @file file.h
 *
 *  Synthetic description. Header file contenente i prototipi per le funzioni richiamate e utilizzate che riguardano unicamente
 *                         la gestione dei files.
 *  @version 1.0
 *  @date 10/06/2020
 *  @author Alessandro Daniele
 */

void manageInitArtistArchive(FILE *file, sArtistData *artistsArchive, int *countArtists);

/** @brief Acquisisce i nuovi dati dello studente tramite file e li salva all'interno dell'archivio
 *
 * @param file FILE* File contente i dati
 * @param artistsArchive sArtistData* Archivio contente gli studenti
 * @return int
 *
 */
int initLoadArtistArchive(FILE *file, sArtistData *artistsArchive, const int countArtists);


/** @brief Salva i dati presenti nell'archivio su file
 *
 * @param file FILE* File dove salvare i dati
 * @param artistsArchive sArtistData* Archivio contente gli studenti
 * @return void
 *
 */
void saveArtistArchiveToFile(FILE *file, sArtistData *artistsArchive, const int countArtists);

#endif // FILE_H_INCLUDED

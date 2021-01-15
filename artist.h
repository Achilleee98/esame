#ifndef ARTIST_H_INCLUDED
#define ARTIST_H_INCLUDED

#include "constants.h"
#include "listen.h"

typedef struct {
    char nameArtist[MAX_ARTIST_NAME_LENGHT];
    char nameGenre[MAX_ARTIST_GENRE_LENGHT];
    sListen listen;
} sArtistData;

/** @brief Gestisce la visualizzazione in output gli artisti
 *
 * @param artistsArchive sArtistData* Archivio contente gli artisti
 * @return void
 *
 */
void managePrintArtistArchive(sArtistData *artistsArchive, const int countArtists);

/** @brief Gestisce l'inserimento di un nuovo artista
 *
 * @param artistsArchive sArtistData* Archivio contente gli artisti
 * @param countArtists const int Numero degli artisti presneti nell'archivio
 * @return void
 *
 */
void manageInsertNewArtistArchive(sArtistData *artistsArchive, int *countArtists);

/** @brief Funzione che controlla se un'artista è stato inserito con successo nell'archivio
 *
 * @param artistsArchive sArtistData* Archivio contente gli artisti
 * @param newArtist const sArtistData Struttura contente i nuovi dati
 * @param countArtists const int Numero degli artisti presneti nell'archivio
 * @return bool True se è stato inserito con successo, False se non è stato inserito
 *
 */
bool isInsertNewArtist(sArtistData *artistsArchive, const sArtistData newArtist, int *countArtists);

/** @brief Gestisce la visualizzazione in output la media degli ascolti dell'artista
 *
 * @param artistsArchive sArtistData* Archivio contente gli artisti
 * @param countArtists const int Numero degli artisti presneti nell'archivio
 * @return void
 *
 */
void manageCalculateAverageArtistDuration(sArtistData *artistsArchive, const int countArtists);

/** @brief Funzione che controlla se esiste un artista con un determinato nome
 *
 * @param artistsArchive sArtistData* Archivio contente gli artisti
 * @param nameArtist const char* Nome da verificare
 * @param countArtists const int Numero degli artisti presneti nell'archivio
 * @return bool True se è stato trovato un artista con un dato nome, False se non è stato trovato
 *
 */
bool isFindArtistName(sArtistData *artistsArchive, const char *nameArtist, const int countArtists);

/** @brief Calcola la media delle durate dell'artista
 *
 * @param artistsArchive sArtistData* Archivio contente gli artisti
 * @param nameArtist const char* Nome dell'artista
 * @param countArtists const int Numero degli artisti presneti nell'archivio
 * @return int Media artista
 *
 */
int calculateAverageArtistDuration(sArtistData *artistsArchive, const char *nameArtist, const int countArtists);


/** @brief Acquisisce i nuovi dati dell'artista e li salva su una struttura (d'appoggio)
 *
 * @param newArtist sArtistData*
 * @return void
 *
 */
void acquireInputArtist(sArtistData *newArtist);

/** @brief Acquisisce i nuovi dati degli ascolti del musicista e li salva su una struttura (d'appoggio)
 *
 * @param newArtist sArtistData*
 * @return void
 *
 */
void acquireInputListen(sArtistData *newArtist);

/** @brief Acquiscisce tramite input da tastiera il nome
 *
 * @param name char* Stringa dove viene sovrascritto il nome acquisito
 * @return void
 *
 */
void acquireNameArtist(char *name);

/** @brief Acquiscisce tramite input da tastiera il genere
 *
 * @param genre char* Stringa dove viene sovrascritto il genere acquisito
 * @return void
 *
 */
void acquireNameGenre(char *genre);


/** @brief Insieme di istruzioni che hanno lo scopo di verificare se i dati di un'artista sono corretti
 *
 * @param currArtistData const sArtistData Artistra cui verificare i dati
 * @return bool True se i dati sono validi, False se non lo sono
 *
 */
bool isValidArtistData(const sArtistData currArtistData);


/** @brief Funzione di controllo che verifica se il nome di un'artista è corretto
 *
 * @param name const char* Nome da verificare
 * @return bool True se il nome è valido, False se non lo è
 *
 */
bool isValidNameArtistString(const char *name);

/** @brief Funzione di controllo che verifica se il genere di un'artista è corretto
 *
 * @param genre const char* Genere da verificare
 * @return bool True se il nome è valido, False se non lo è
 *
 */
bool isValidGenreString(const char *genre);


void setArtistDataName(sArtistData *artistData, const char *name);
void setArtistDataGenre(sArtistData *artistData, const char *genre);
void setArtistListenDataDuration(sArtistData *artistData, const unsigned short duration);
void setArtistListenDataDate(sArtistData *artistData, const sDate date);


const char *getArtistDataName(sArtistData *artistData);
const char *getArtistDataGenre(sArtistData *artistData);
unsigned short getArtistListenDataDuration(sArtistData *artistData);
sDate getArtistListenDataDate(sArtistData *artistData);

#endif // ARTIST_H_INCLUDED

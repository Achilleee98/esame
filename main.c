#include <stdio.h>
#include <stdbool.h>
#include "menu.h"
#include "constants.h"
#include "artist.h"
#include "file.h"
#include "test.h"

/** @file main.c
 *
 *  Synthetic description. Il file contiene le funzionalita' principali (di dominio) per l'implementazione di questo programma.
 *                         Le funzionalita' di dominio richiamate dal main sono utili alla lettura degli studenti da file,
                            all'inserimento di un ascolto, a calcolare la durata media degli ascolti
                            di un artista (digitato in input), ed ad effettuare il testing del programma.
 *
 *  @version 1.0
 *  @date 10/06/2020
 *  @author Alessandro Daniele
 */


int main()
{
    bool bEsc = false;              // Variabile sentinella utilizzata per il controllo sull'uscita dal menu.
    sArtistData artistsArchive[MAX_ARTIST_ARCHIVE_SIZE];     // Archivio contente gli artisti.
    int countArtists = 0;          // Variabile che memorizza il numero di artisti presenti nell'archivio

    FILE *file;
    file = fopen(FILE_NAME, "r");

    while (bEsc == false)
    {
        int choice = selectMenu();  // Gestione del menu tramite scelta dell'utente.
        switch (choice)
        {
        case 1:
            manageInitArtistArchive(file, artistsArchive, &countArtists);
            fclose(file);       // Chiude il file poichè la lettura è stata effettuata, quindi il file non serve più.
            break;
        case 2:
            managePrintArtistArchive(artistsArchive, countArtists);
            break;
        case 3:
            manageInsertNewArtistArchive(artistsArchive, &countArtists);

            // Procede con il salvataggio su file
            file = fopen(FILE_NAME, "w");
            saveArtistArchiveToFile(file, artistsArchive, countArtists);
            fclose(file);

            break;
        case 4:
            manageCalculateAverageArtistDuration(artistsArchive, countArtists);
            break;
        case 5:
            testing();
            break;
        case 6:
            bEsc = true;
            break;
        default:		// Nel caso l'utente digitasse un input valido (numero valido) ma non corrisponde a nessuna scelta del menu, notifica l'utente.
            printf("Scelta errata. Riprova.\n\n");
            break;
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "constants.h"

/** @file menu.c
 *
 *  Synthetic description. Implementazione delle funzioni presentate in menu.h. Le funzioni svolgono le operazioni
 *                         principali per la gestione del menu.
 *
 *  @version 1.0
 *  @date 10/06/2020
 *  @author Alessandro Daniele
 */


/**
 *  È una funzione che descrive all'utente quali sono le scelte del menu che può effettuare.
 *  Successivamente acquisisce la scelta dell'utente, e la restituisce dopo aver controllato sia una scelta valida.
 *  @post L'intero restituito è un numero valido e maggiore di 0
 *
 */
int selectMenu()
{
    char choice[MAX_STRING_LENGHT];
    int value = 0;
    do
    {
        printf("Inserisci la scelta che vuoi effettuare.\n");
        printf("1- Leggi i dati da file.\n");
        printf("1- Visualizza i dati presenti nell'archivio.\n");
        printf("3- Aggiungi un nuovo ascolto.\n");
        printf("4- Calcolare la durata media degli ascolti dato voto.\n");
        printf("5- Testing.\n");
        printf("6- Esci.\n");

        scanf("%s", choice);
        fflush(stdin);

        value = atoi(choice);

    } while (value == 0);

    return value;
}

//
// Created by Marvin on 12.10.2023.
//

#include "header.h"

void start(){
    printf("Willkommen, bitte waehle folgenden Option.\n"
           "Neu anmelden  : 1 \n"
           "LogIn         : 2 ");
    int auswahl;
    scanf("%i", &auswahl);

    switch (auswahl) {
        case 1:
            neu_anmelden();
        case 2:
//            login();
        default:
            return;
    }

}

void neu_anmelden(){
    char benutzer_name[MAX_SIZE];
    char benutzer_PW[MAX_SIZE];
    char file_path[255] = "01_benutzer/";                      // wurde lokal angelegt fuer die Uebersicht


    FILE * benutzer;

    printf("Bitte gebe deinen Benutzer_Namen ein. \n");                         // Benutzer_Name erstellen
    scanf("%s", benutzer_name);

    printf("Bitte gebe deinen Benutzer_Password ein. \n");                      // Benutzer_PW erstellen
    scanf("%s", benutzer_PW);                               // BEACHTE

    strcat(file_path, benutzer_name);
    benutzer= fopen(strcat(file_path, ".txt"), "w");


// fehlerabfrage
    if(benutzer == NULL) {
        printf("FEHLER");
    }

// Benutzer_Name in datei speichern
    fprintf(benutzer, "Name : BN");
    fprintf(benutzer, benutzer_name );
    fprintf(benutzer, "\n");

// Benutzer_PW wird in die Datei gespeichert
    fprintf(benutzer, "Password: PW");
    fprintf(benutzer, benutzer_PW );
    fprintf(benutzer, "\n");


    fclose(benutzer);

}


void login(){

}

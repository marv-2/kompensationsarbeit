
#ifndef INC_02_RPG_TEXTBASIERT_HEADER_H
#define INC_02_RPG_TEXTBASIERT_HEADER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 255

////////////// STRUCT   ////////////

typedef struct player_s{
    int ID;
    char name[50];
    int level;
    int HP;
}player_t;



//////////////   FUNKTIONESPROTOTYPEN   ////////////////////

void start();
void neu_anmelden();
struct player_s *erstelle_spieler(char benutzer_name[]);


void login();
void spielstart(struct player_s *user_a);

void geschichte_01();
void geschichte_02();
void geschichte_03();

void frage_01(struct player_s *user_a);
void frage_02(struct player_s *user_a);
void frage_03(struct player_s *user_a);
void frage_04(struct player_s *user_a);
void frage_05(struct player_s *user_a);
void frage_06(struct player_s *user_a);
void frage_07(struct player_s *user_a);
void frage_08(struct player_s *user_a);

void antwort_01();
void antwort_02();
void antwort_03();
void antwort_04();
void antwort_05();
void antwort_06();
void antwort_07();
void antwort_08();




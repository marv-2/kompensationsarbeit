
//#ifndef INC_02_RPG_TEXTBASIERT_HEADER_H
#define INC_02_RPG_TEXTBASIERT_HEADER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_SIZE 255

///////////// STACK   //////////////////////////////

struct list_element_s *erstelle_elem(struct list_element_s *elem);

struct list_header_s *befuelle(struct list_header_s *kopf);
struct list_header_s *erstellen(struct list_header_s *kopf);

void easter_egg_frage_03();


////////////// BAUM   //////////////////////////////////

typedef struct knoten_s{
    int daten ;
    int counter;
    struct knoten_s *left ;         // fuer die linke Adresse
    struct knoten_s *right;         // fuer die rechte Adresse
}knoten_t ;
struct knoten_s * neuer_knoten(int daten);      // easter_egg in frage 9
void easter_egg_frage_07();

/////////////   LISTE   ////////////////////////////////

typedef struct list_element_s{
    int val ;

    struct list_item * naechstes_element;
    struct list_item * vorheriges_element;
}list_element_t;
typedef struct list_header_s{
    int groesse ;
    struct list_item_s * start ;
    struct list_item_s * end ;
}list_header_t ;


void easter_egg_frage_05();

//////////////   FUNKTIONESPROTOTYPEN   ////////////////////

typedef struct player_s{
    int ID;
    char name[50];
    int level;
    int HP;
}player_t;

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




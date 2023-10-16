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
            login();
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


    fprintf(benutzer, "Level : LV1");
    fprintf(benutzer, "\n");




//    *ptr_address = (int) user_a;

//    printf("%p", ptr_address);

    fclose(benutzer);



}


struct player_s *erstelle_spieler(char benutzer_name[]){
    struct player_s * user_a ;
    user_a = (struct player_s*) malloc(sizeof(struct player_s));
    if(user_a == NULL){
        printf("kein speicher");
    }

    strcpy(user_a->name,benutzer_name);
    user_a->level = 1 ;
    user_a->HP = 100 ;


    return user_a ;
}


void login(){

    char benutzer_name[MAX_SIZE];
    char benutzer_PW[MAX_SIZE];
    char file_path[255] = "01_benutzer/";

    char benutzer_PW_check[MAX_SIZE];

    int a;
    int counter_00 = 0 ;
    int counter_01 = 0 ;
    int counter_02 = 0 ;
//    int counter_03 = 0 ;

    int file_content_int01 = 0 ;
    int file_content_int02 = 0 ;
//    int file_content_int03 = 0 ;


    FILE * benutzer ;

    printf("LogIn Abfrage \n");
    printf("Benutzer_Name eingeben: \n");
    scanf("%s", benutzer_name);

    strcat(file_path, benutzer_name);
    strcat(file_path, ".txt");

    benutzer= fopen(file_path, "r");                                            // Datei zum lesen oeffnen
// fehlerabfrage
    if(benutzer == NULL){
        printf("FEHLER\nKeine Datei vorhanden");
    }

    printf("Bitte gebe deinen Benutzer_Password ein. \n");                      // Benutzer_PW abfragen
    getchar();
    counter_00 = 0 ;
    a = 0 ;                                                                     // 'a' hat sonst noch das 'enter' von oben
    while ( a != 10)                                                            // solange kein 'Enter' eingegeben wird
    {
        a = getchar();
        benutzer_PW[counter_00] = a ;

        counter_00++;                                                           // counter fuer die Gr. des neues ARRAY (Benutzer_Password_Resized)
    }


//PW wird aus der Datei geholt und in benutzer_PW_check gespeichert
    a = 0 ;
    while(counter_02 < MAX_SIZE && (a != 10) ){
        file_content_int01 = fgetc(benutzer);
        if(file_content_int01 == 'P') {                                     // pruefen ob pointer in der Datei bei 'P' ist
            file_content_int02 = fgetc(benutzer);                       // und pruefen ob Zweite stelle in 'W'
            if (file_content_int02 == 'W') {
                                                                            // hier wird das PW aus der Datei gespeichert
                for (int i = 0; a != 10 ; ++i) {                            // die darauf folgenden buchstaben bis zum '\0' speichern
                    a = fgetc(benutzer);                                // '10' steht fuer den INTEGER-Wert des 'ENTER'
                    benutzer_PW_check[i] = a;
                    counter_01++;                                           // counter fuer die Gr. des neues ARRAY (Benutzer_Password__Check_Resized)
                }
            }
        }
        counter_02++;                                                       // um die Schleife zu verlassen (sicherung)
    }

// Umwandlung beim EINGEGEBEN PASSWORT des (alten Gr.) Arrays in die ANGEPASSTE (ideale Gr.)
    char benutzer_PW_Resized[counter_00] ;                                  // fuer die Spaetere abfrage muss auch die Gr. gleich sein
    strcpy(benutzer_PW_Resized, benutzer_PW );                  // siehe: PW vergleich
    printf("Echtes_Benutzer_Password : %s\n", benutzer_PW_Resized);

// Umwandlung beim HINTERLEGTEN PASSWORT des (alten Gr.) Arrays in die angepasste (ideale Gr.)
    char benutzer_PW_Ceck_Resized[counter_01] ;                                 // fuer die Spaetere abfrage muss auch die Gr. gleich sein
    strcpy(benutzer_PW_Ceck_Resized, benutzer_PW_check );           // siehe: PW vergleich
    printf("Echtes_Benutzer_Password_Check : %s\n", benutzer_PW_Ceck_Resized);


    struct player_s *user_a;
    user_a =  erstelle_spieler(benutzer_name);


// Abfrage, ob PW korrekt
    if(strcmp(benutzer_PW_Resized, benutzer_PW_Ceck_Resized) == 0 ){                           // PW vergleichen
        printf("Sie haben Zugang \n");
        spielstart(user_a );
    } else
        printf("Ihre daten sind falsch. Aus Sicherheitsgruenden wird das Programm "
               "geschlossen. ");
//    return;

}


void spielstart(struct player_s *user_a){
    printf("Du bist im spiel!");
    geschichte_01();
    frage_01(user_a);
    frage_02(user_a);
    frage_03(user_a);
    geschichte_02();
    frage_04(user_a);
    frage_05(user_a);
    frage_06(user_a);
    frage_07(user_a);
    frage_08(user_a);
    geschichte_03();

}


////////////   Geschichte   ///////////////////////

void geschichte_01(){
    printf("\n\nDas Schicksal von Eldoria\n"
           "\n"
           "In einer fernen Welt, weit entfernt von unserer Realitaet, \n"
           "existiert ein mystisches Koenigreich namens Eldoria.\n"
           " Dieses Land ist von einer zauberhaften Aura umgeben, \n"
           "die seit Jahrhunderten die Aufmerksamkeit von Abenteurern, \n"
           "Magiern und Helden auf sich zieht. Eldoria ist beruehmt für seine atemberaubenden Landschaften, \n"
           "die von ueppigen Waeldern ueber majestaetische Gebirge bis hin zu endlosen Meeren reichen.\n"
           "\n"
           "Jedoch, wie es oft der Fall ist, selbst in den schoensten Orten, \n"
           "lauert das Boese im Schatten. Vor vielen Jahren wurde Eldoria von einer \n"
           "dunklen Macht heimgesucht, die das Koenigreich in ewige Dunkelheit stuerzen wollte. \n"
           "Die Bewohner von Eldoria wandten sich verzweifelt an die Helden ihrer Legenden, \n"
           "um Hilfe zu erbitten.\n"
           "\n"
           "Du stehst heute am Rande des Abenteuers deines Lebens. \n"
           "Als tapferer Krieger oder maechtiger Magier, der fuer die Rettung von Eldoria auserwaehlt wurde, \n"
           "wirst du in diese mystische Welt gezogen. Deine Mission ist klar: Finde und rette die gefangene \n"
           "Seele des Koenigreichs, Prinzessin Elara, die von der Dunkelheit gefangen gehalten wird.\n"
           "\n"
           "Mit einem Schwert in der Hand oder Zaubersprüchen auf den Lippen begibst du dich auf \n"
           "eine gefaehrliche Reise, die voller Geheimnisse, Herausforderungen und unerwarteter \n"
           "Verbündeter sein wird. Die Zeit draengt, und das Schicksal von Eldoria liegt in deinen Haenden. \n"
           "Wirst du mutig genug sein, die Dunkelheit zu besiegen und die Prinzessin zu befreien?\n"
           "\n"
           "Deine Reise beginnt jetzt, in einer Welt, in der Abenteuer und Magie eins sind. \n"
           "Dein Schicksal und das von Eldoria sind untrennbar miteinander verknüpft. Moege das \n"
           "Licht deiner Entschlossenheit die Dunkelheit durchdringen und das Königreich erlösen.\n"
           "\n"
           "Von diesem Punkt aus koennen die Spieler in dein textbasiertes RPG eintauchen und die \n"
           "Geschichte entfalten lassen, waehrend sie die verschiedenen Aspekte von Eldoria erkunden \n"
           "und ihre Mission vorantreiben.\n\n");
}

void geschichte_02(){
    printf("Waehrend deiner Reise durch Eldoria, hast du bereits viele Hindernisse ueberwunden. "
           "Dunkle Waelder, die von geisterhaften Kreaturen bewohnt sind, \n"
           "hast du durchquert. Bergpaesse, in denen der eisige Atem des Nordwinds durch die Luft zischte, "
           "hast du bezwungen. Dabei hast du Raetsel gelöst, \n"
           "gefaehrliche Kreaturen besiegt und wertvolle Schaetze entdeckt.\n"
           "\n"
           "Die Bewohner von Eldoria sind voller Hoffnung und danken dir für deine unermüuedlichen Anstrengungen. "
           "Dein Name wird in Liedern besungen \n"
           "und in den Geschichten der Tavernen erzaehlt. Doch du weißt, dass der schwerste Teil "
           "deiner Reise noch vor dir liegt.\n"
           "\n"
           "Du folgst den Hinweisen und Prophezeiungen, die dich zu einem verborgenen Tempel fuehren. "
           "Dieser Tempel, tief im Herzen des \n"
           "verzauberten Waldes von Lysandra, ist der Schluessel zur Rettung von Prinzessin Elara. "
           "Hier, heißt es, muss der Auserwaehlte sein letztes Abenteuer bestehen, \n"
           "um die Dunkelheit zu besiegen.\n"
           "\n"
           "Als du die Pforten des Tempels erreichst, spuerst du die bedrueckende Aura der Dunkelheit, "
           "die von innen herausstroemt. Der Boden ist \n"
           "mit uralten Symbolen bedeckt, und Kerzen flackern im fahlen Licht. "
           "Dein Herzschlag beschleunigt sich, denn du weißt, dass dies der Ort ist, \n"
           "an dem alles entschieden wird.\n"
           "\n"
           "Du trittst entschlossen ein und findest dich in einem riesigen Saal wieder, "
           "in dem ein schwebendes Buch auf einem steinernen Podest thront. \n"
           "Es ist das Buch der Pruefungen, das nur der Auserwaehlte beruehren kann. "
           "Als du es sanft in die Hand nimmst, spuerst du eine Welle von Energie, \n"
           "die durch deinen Koerper fließt.\n"
           "\n"
           "Die Seiten des Buches beginnen zu leuchten, und es offenbart eine Reihe von letzten Pruefungen, "
           "die du bestehen musst, \n"
           "um die Dunkelheit zu besiegen und Prinzessin Elara zu befreien. "
           "Jede Pruefung stellt dich auf die Probe, erfordert deinen Verstand, \n"
           "deine Staerke und deine Magie.\n"
           "\n"
           "Mit Entschlossenheit und Mut stellst du dich den Herausforderungen. "
           "Du entschluesselst geheimnisvolle Raetsel, kaempfst gegen maechtige \n"
           "Schattenkreaturen und ueberwindest gefaehrliche Fallen. "
           "Mit jeder bestandenen Pruefung spuerst du, wie die Dunkelheit um dich herum nachlaesst.\n"
           "\n"
           "Schließlich, nachdem du die letzten Pruefungen gemeistert hast, kehrst du zum schwebenden Buch zurueck. "
           "Mit einem letzten Blick \n"
           "auf die glaenzenden Seiten, die nun ruhig liegen, spuerst du, "
           "wie eine Welle der Erleichterung durch deinen Koerper stroemt.\n"
           "\n"
           "Du hast es geschafft. Du hast die Dunkelheit besiegt.\n\n");
}

void geschichte_03(){
    printf("\n\nDer Triumph des Auserwaehlten\n"
           "\n"
           "Nachdem du das Verbindungstor geoeffnet hast, beginnt eine neue Aera für Eldoria. "
           "Die Verbindung mit anderen Reichen eroeffnet den Bewohnern \n"
           "unzaehlige neue Moeglichkeiten des Handels, des Wissensaustauschs und der Zusammenarbeit.\n"
           "\n"
           "Die Nachricht von deinem tapferen Abenteuer verbreitet sich wie ein Lauffeuer. "
           "Du wirst als Held gefeiert, dessen Mut und Weisheit das \n"
           "Schicksal von Eldoria und der umliegenden Reiche für immer veraendert hat.\n"
           "\n"
           "Prinzessin Elara, befreit aus der Dunkelheit, kehrt in ihr Koenigreich zurueck. "
           "Ihr Blick voller Dankbarkeit trifft deinen, und du weißt, \n"
           "dass deine Reise nicht umsonst war. Das Koenigreich blueht auf, "
           "und die Menschen leben in Frieden und Harmonie.\n"
           "\n"
           "Der Phoenix, der dich begleitet hat, bleibt an deiner Seite. "
           "Seine Anwesenheit ist ein Symbol der staendigen Erneuerung und der \n"
           "unzerstoerbaren Kraft der Hoffnung.\n"
           "\n"
           "Deine Abenteuer in Eldoria sind jedoch noch nicht vorbei. "
           "Du wirst zu einem Ratgeber des Koenigreichs ernannt, ein weiser Mentor, \n"
           "der mit Rat und Tat zur Seite steht.\n"
           "\n"
           "Die Geschichten ueber deine Heldentaten werden von Generation zu Generation weitererzaehlt. "
           "Du wirst zur Legende, \n"
           "dessen Name in den Annalen der Geschichte von Eldoria verewigt ist.\n"
           "\n"
           "Und so endet deine Reise, nicht in Ruhm und Glanz, sondern in der Erfuellung deines Schicksals. "
           "Du hast eine Welt gerettet, \n"
           "Verbindungen geschaffen und das Gleichgewicht wiederhergestellt.\n"
           "\n"
           "Die Welt von Eldoria wird immer in deinem Herzen leben, und deine Abenteuer werden als Inspiration "
           "fuer kommende Helden dienen.\n"
           "\n"
           "Das ist der Triumph des Auserwaehlten, der die Dunkelheit besiegt hat und das Licht zurueckgebracht hat. "
           "Moege deine Geschichte \n"
           "in den Winden der Zeit weiterleben und Generationen von Abenteurern inspirieren, ihren eigenen Weg zu finden.\n"
           "\n"
           "Und so lebten sie glücklich bis ans Ende ihrer Tage...");
}

///////////   Frage - Antworten   /////////////////////////

void frage_01(struct player_s *user_a){

    int a = 0 ;
    printf("Welcher mythische Vogel ist für seine regenerativen Faehigkeiten bekannt?\n"
           " 1) Phoenix\n"
           " 2) Harpyie\n"
           " 3) Greif\n"
           " 4) Ziz");

    scanf("%i", &a);

    switch (a) {
        case 1:
            printf("Diese antwort ist korrekt\n"
                   "########################################################################\n"
                   );
            user_a->level++;
            antwort_01();

        default:
            printf("Diese Antwort ist falsch\n"
                   "!!!!!Du verlierst 10 Lebenspunkte!!!\n");
            user_a->HP -= 10 ;
            printf("Deine neuen HP sind %i\n", user_a->HP );
    }

}

void antwort_01(){
    printf("Die Flamme des Wiederauferstehens"
           "\n\"\n"
           "In einer Welt, in der Legenden lebendig werden, begibst du dich als tapferer Abenteurer auf eine Reise, "
           "\n"
           "die dich zu den entlegensten Ecken des Landes fuehren wird. Dein Ruf als mutiger Held hat "
           "dich zu einem uralten Tempel gefuehrt, \n"
           "der in den Bergen von Eldoria verborgen liegt. Es ist gesagt, dass hier eine uralte Macht ruht, "
           "die demjenigen, der sie erweckt, \n"
           "die Faehigkeit verleiht, selbst durch den Tod hindurchzugehen.\n"
           "Als du den Tempel betrittst, umgibt dich eine unheimliche Stille. Die Luft ist schwer von "
           "Jahrhunderten des Schweigens. \n"
           "In der Mitte des Tempels siehst du einen verzierten Altar, auf dem eine vergessene "
           "Schriftrolle liegt. Als du sie entrollst, \n"
           "offenbart sie die Legende des maechtigen Phoenix."
           "\n\n"
           "Der Phoenix, ein Wesen der ewigen Wiedergeburt, ist in einem uralten Kristallgefaengnis gefangen, "
           "das sich tief in den Höhlen unterhalb des Tempels befindet. \n"
           "Es wird gesagt, dass seine Freilassung die Dunkelheit vertreiben und das Land erneuern wird."
           "\n\n"
           "\"Deine erste Aufgabe ist klar: Du musst die Hoehlen betreten, die von gefaehrlichen Kreaturen "
           "bewacht werden, und den Kristall finden, \n"
           "der den Phoenix gefangen haelt. Dort angekommen, musst du ein uraltes Raetsel loesen, "
           "um den Kristall zu befreien"
           "\n\n"
           "Als du tiefer in die Hoehlen vordringst, spuerst du die Hitze der unterirdischen Flammen. "
           "Schliesslich erreichst du den Kristallraum, \n"
           "in dem der maechtige Phoenix in einem schimmernden Kaefig gefangen ist. "
           "Vor dir liegt ein Raetsel aus leuchtenden Symbolen, die den Weg zur Freiheit weisen."
           "\n\n"
           "Nach sorgfaeltigem ueberlegen und entschlossenem Handeln gelingt es dir, das Raetsel zu loesen. "
           "Der Kristall zerbricht, und ein gleissendes Licht strahlt hervor."
           "Der Phoenix erhebt sich majestaetisch und sein Gesang erfuellt die Hoehlen.\\"
           "\n\n"
           "Mit einem letzten kraftvollen Fluegelschlag durchbricht der Phoenix die Hoehlenwand und "
           "steigt zum Himmel empor. Seine Fluegel leuchten in allen Farben des Feuers,\n"
           "und sein Ruf verkuendet die Geburt einer neuen Aera."
           "\n\n"
           "Du kehrst zum Tempel zurueck, erfuellt von einer tiefen Zufriedenheit und der Gewissheit, "
           "dass du einen maechtigen Verbuendeten gewonnen hast. \n"
           "Der Phoenix wird an deiner Seite stehen, bereit, dir bei deinem weiteren Abenteuer zu helfen.\n"
           "\n\n"
           "Die Flamme des Wiederauferstehens brennt nun in deinem Herzen, und du weißt, dass noch "
           "viele Abenteuer vor dir liegen. "
           "Doch mit dem Phoenix an deiner Seite und der \n"
           "Macht der ewigen Wiedergeburt in deinen Haenden, gibt es nichts, was du nicht erreichen kannst."
           "\n"
           "Das Abenteuer hat gerade erst begonnen."
           "\n\n");
}

////////////////////////////////////

void frage_02(struct player_s *user_a){

    int a = 0 ;
    printf("Welcher Planet ist der vierte in unserem Sonnensystem?\n"
           "1) Mars\n"
           "2) Jupiter\n"
           "3) Venus\n"
           "4) Saturn");

    scanf("%i", &a);

    switch (a) {
        case 1:
            printf("Diese antwort ist korrekt\n"
                   "########################################################################\n"
            );
            user_a->level++;
            antwort_02();
            break;

        default:
            printf("Diese Antwort ist falsch\n"
                   "!!!!!Du verlierst 10 Lebenspunkte!!!\n");
            user_a->HP -= 10 ;
            printf("Deine neuen HP sind %i\n", user_a->HP );
    }

}

void antwort_02(){
    printf("Das Geheimnis des Verbindungstors"
           "\n\n"
           "In Eldoria, einem Koenigreich voller Wunder und Magie, verbirgt sich ein uraltes Geheimnis, "
           "das die Welt mit anderen Reichen verbindet. \n"
           "Dieses Geheimnis wird von den Aeltesten nur in Legenden erwaehnt - ein Verbindungstor, "
           "das einst die Grenzen zwischen den Welten ueberbrueckte.\n"
           "Als du dich weiter auf deinem Abenteuer durch Eldoria begibst, "
           "hoerst du Geruechte über das verschollene Verbindungstor. Die Legenden besagen, \n"
           "dass es an einem heiligen Ort verborgen liegt, tief im Herzen des Diamantengebirges."
           "\n\n"
           "Nach wochenlanger Suche und gefahrvoller Reisen durch unerforschte Gebiete, "
           "stehst du schließlich vor dem majestaetischen Diamantengebirge. \n"
           "In den schimmernden Hoehlen und den glitzernden Fluessen, die das Gebirge durchziehen, "
           "spuerst du die Anwesenheit von etwas Uraltem."
           "\n\n"
           "Nach vielen Pruefungen und Begegnungen mit den gefaehrlichen Bewohnern des Gebirges, "
           "findest du den heiligen Ort. Hier, in einem gewaltigen Saal \n"
           "aus funkelndem Kristall, erhebt sich das Verbindungstor."
           "\n\n"
           "In deinem Inneren spuerst du, dass die Antwort von großer Bedeutung ist. "
           "Deine Entscheidung wird nicht nur dein Schicksal bestimmen, sondern auch die Verbindung \n"
           "zwischen Eldoria und den anderen Reichen beeinflussen."
           "\n\n"
           "Nachdem du deine Wahl getroffen hast, erfuellt sich die Kammer mit einem blendenden Licht. "
           "Das Tor beginnt zu gluehen, und ein Sog erfasst dich, \n"
           "als ob die Maechte der Welten selbst dich durch die Pforte tragen."
           "\n\n"
           "Ploetzlich stehst du an einem anderen Ort, in einer anderen Welt. "
           "Du hast das Verbindungstor geoffnet, und Eldoria ist nun mit einem neuen Reich verbunden. \n"
           "Dein Mut und deine Weisheit haben nicht nur dein eigenes Abenteuer vorangetrieben, "
           "sondern auch das Schicksal von Eldoria und die Verbindung zwischen den \n"
           "Welten für immer veraendert."
           "\n\n"
           "Die Legende des Auserwaehlten, der die Welten vereinte, wird nun fuer alle Zeit in Eldoria weiterleben.\n\n\n");
}

////////////////////////////////////

void frage_03(struct player_s *user_a){

    int a = 0 ;
    printf("Welcher Fluss ist der längste der Welt??\n"
           "A) Nil\n"
           "B) Amazonas\n"
           "C) Mississippi\n"
           "D) Jangtse\n");

    scanf("%i", &a);

    switch (a) {
        case 1:
            printf("Diese antwort ist korrekt\n"
                   "########################################################################\n"
            );
            user_a->level++;
            antwort_03();
            break;

        default:
            printf("Diese Antwort ist falsch\n"
                   "!!!!!Du verlierst 10 Lebenspunkte!!!\n");
            user_a->HP -= 10 ;
            printf("Deine neuen HP sind %i\n", user_a->HP );
    }

}

void antwort_03(){
    printf("\nDer Silberstrom\n"
           "\n"
           "Der Silberstrom ist ein majestaetischer Fluss, der sich durch die idyllischen "
           "Landschaften von Eldoria schlaengelt. Sein Wasser schimmert in einem sanften Silberton, \n"
           "als wuerde es das Mondlicht einfangen und in seinen Wellen tragen. "
           "Umgeben von ueppigen Waeldern, die sich bis zum Ufer erstrecken, "
           "strahlt der Silberstrom eine Aura \n"
           "von Ruhe und Frieden aus.\n"
           "\n"
           "Die Ufer des Flusses sind mit einer Vielzahl von Blumen geschmueckt, "
           "von denen einige nirgendwo sonst in Eldoria zu finden sind. Ihre leuchtenden \n"
           "Farben spiegeln sich im klaren Wasser des Silberstroms wider und "
           "schaffen ein atemberaubendes Schauspiel aus Naturschoenheit.\n"
           "\n"
           "Entlang des Ufers finden sich geheimnisvolle Steinformationen, "
           "die von den alten Bewohnern von Eldoria geschaffen wurden. "
           "Sie erzaehlen Geschichten \n"
           "aus laengst vergangenen Zeiten und fuegen eine zusaetzliche Dimension der Magie hinzu, "
           "die den Silberstrom umgibt.\n"
           "\n"
           "Vor vielen Generationen, als Eldoria von einem dunklen Schatten bedroht wurde, "
           "kam eine mutige Kriegerin namens Lysandra zum Silberstrom. Sie glaubte fest daran, \n"
           "dass der Fluss eine besondere Kraft barg, die in der Lage war, das Böse zu vertreiben.\n"
           "\n"
           "Lysandra verbrachte Monate am Ufer des Silberstroms und fand schließlich eine geheime "
           "Hoehle hinter einem Wasserfall, die als Heiligtum der Wasserweisen bekannt war. \n"
           "Dort entdeckte sie eine uralte Reliquie, den Silberkelch, der als Schluessel zur "
           "Befreiung der verlorenen Magie von Eldoria galt.\n"
           "\n"
           "Mit dem Silberkelch in ihren Haenden kehrte Lysandra zurueck und fuehrte das Volk "
           "von Eldoria in die Schlacht gegen die Dunkelheit. Der Glanz des Silberstroms \n"
           "begleitete sie, und die Legende besagt, dass der Fluss selbst in den Augen der "
           "Kriegerin leuchtete, als sie die Maechte des Boesen besiegte.\n"
           "\n"
           "Seitdem wird der Silberstrom als Symbol der Hoffnung und des Sieges ueber "
           "die Dunkelheit verehrt. Viele Pilger stroemen an seine Ufer, um Ruhe und \n"
           "Inspiration zu finden, und die Geschichten von Lysandras mutigem Kampf leben "
           "in den Liedern und Legenden von Eldoria weiter. Der Silberstrom bleibt \n"
           "ein Ort von tiefer Bedeutung und eine Quelle unendlicher Schoenheit im Herzen des Koenigreichs\n\n");
}

////////////////////////////////////

void frage_04(struct player_s *user_a){

    int a = 0 ;
    printf("\nWelches Element hat das chemische Symbol H ?\n"

           "1) Wasserstoff\n"
           "2) Helium\n"
           "3) Kohlenstoff\n"
           "4) Sauerstoff\n");

    scanf("%i", &a);

    switch (a) {
        case 1:
            printf("Diese antwort ist korrekt\n"
                   "########################################################################\n"
            );
            user_a->level++;
            antwort_04();
            break;

        default:
            printf("Diese Antwort ist falsch\n"
                   "!!!!!Du verlierst 10 Lebenspunkte!!!\n");
            user_a->HP -= 10 ;
            printf("Deine neuen HP sind %i\n", user_a->HP );
    }

}


void antwort_04(){
    printf("Der Koenig des Dschungels\n"
           "\n"
           "Einst, in den unendlichen Tiefen von Eldoria, thronte ein majestaetischer Koenig des Dschungels. "
           "Er hieß Arion und war ein maechtiger Loewe von beeindruckender \n"
           "Groeße und koeniglicher Anmut. Sein Fell glaenzte golden im Sonnenlicht, "
           "und seine Augen leuchteten wie die Sterne am Nachthimmel.\n"
           "\n"
           "Arion war nicht nur ein Koenig, sondern auch ein Beschuetzer der "
           "gesamten Wildnis von Eldoria. Unter seinem maechtigen Gebruell erzitterten die Waelder, und seine \n"
           "Anwesenheit verbreitete Respekt und Ehrfurcht unter den Tieren.\n"
           "\n"
           "Jedoch eines Tages, als ein großes Unheil ueber das Land kam, "
           "entschied Arion, dass er mehr tun musste. Eine dunkle Macht aus den tiefsten Schatten \n"
           "hatte sich erhoben und bedrohte die Harmonie von Eldoria.\n"
           "\n"
           "Arion begab sich auf eine gefaehrliche Reise, um das Boese zu besiegen. "
           "Durch dichte Waelder, gefaehrliche Suempfe und reißende Fluesse kaempfte er gegen die Dunkelheit. \n"
           "Seine Tapferkeit und Entschlossenheit waren seine staerksten Waffen.\n"
           "\n"
           "Nach vielen Kaempfen und Opfern, erreichte Arion schließlich den Ort, "
           "an dem die Dunkelheit geboren wurde. Dort traf er auf ein uraltes Fabelwesen \n"
           "namens Morvax, ein Schattenwaechter von beaengstigender Macht.\n"
           "\n"
           "Der Kampf zwischen Arion und Morvax war episch, ein Duell von Licht und Dunkelheit, "
           "von Tapferkeit und Verzweiflung. \n"
           "Die Schlacht tobte tagelang, und der Himmel erzitterte vor der Wucht ihrer Kraefte.\n"
           "\n"
           "Schliesslich, in einem letzten verzweifelten Angriff, opferte Arion seine eigene Kraft, "
           "um Morvax zu besiegen. Die Energie des Aufeinandertreffens war so gewaltig, \n"
           "dass sie eine Explosion ausloeste, die das Land erzittern liess.\n"
           "\n"
           "Als der Staub sich legte, war von Arion nichts mehr zu sehen. "
           "Doch an seiner Stelle stand ein neues Wesen, halb Loewe, halb Fabelwesen. \n"
           "Seine Maehne glaenzte nun mit schillernden Farben, und seine Augen leuchteten "
           "mit einer noch tieferen Weisheit.\n"
           "\n"
           "Arion war nicht mehr nur ein Koenig des Dschungels, sondern auch ein Beschuetzer von "
           "Eldoria in einer neuen, maechtigeren Form. Sein Opfer hatte die Dunkelheit \n"
           "besiegt und das Land gerettet.\n"
           "\n"
           "Von diesem Tag an wurde er als Arion, der Fabelkoenig verehrt. "
           "Seine Legende wurde von Generation zu Generation weitergegeben, und sein Name war \n"
           "ein Symbol der Hoffnung und des Mutes.\n"
           "\n"
           "Und so lebte Arion weiter, nicht nur als Kaenig des Dschungels, "
           "sondern als lebende Legende, die Eldoria für immer beschuetzte.\n\n");
}

////////////////////////////////////

void frage_05(struct player_s *user_a){

    int a = 0 ;
    printf("\nWelcher berühmte Künstler malte die Mona Lisa?\n"
           "1) Leonardo da Vinci\n"
           "2) Vincent van Gogh\n"
           "3) Pablo Picasso\n"
           "4) Michelangel");

    scanf("%i", &a);

    switch (a) {
        case 1:
            printf("Diese antwort ist korrekt\n"
                   "########################################################################\n"
            );
            user_a->level++;
            antwort_05();
            break;

        default:
            printf("Diese Antwort ist falsch\n"
                   "!!!!!Du verlierst 10 Lebenspunkte!!!\n");
            user_a->HP -= 10 ;
            printf("Deine neuen HP sind %i\n", user_a->HP );
    }

}


void antwort_05(){
    printf("\"Die Magie der Malerei\n"
           "\n"
           "In Eldoria, einem Koenigreich, in dem Magie und Kreativitaet ineinander verschmelzen, "
           "gab es eine besondere Tradition, \n"
           "die die Herzen der Bewohner erfuellte - die Kunst der lebendigen Malerei.\n"
           "\n"
           "In der malerischen Stadt Farbenfroh, die von bunten Blumen und duftenden Gaerten umgeben war, "
           "lebte ein begabter Kuenstler namens Elyan. \n"
           "Seine Leinwände waren Fenster zu einer Welt voller Magie, "
           "in denen die Farben zum Leben erwachten.\n"
           "\n"
           "Eines Tages erhielt Elyan eine mysterioese Einladung von der geheimnisvollen Koenigin Isolde, "
           "die in einem Schloss voller schimmernder \n"
           "Gaerten und glaenzender Wasserspiele residierte. Die Koenigin hatte von Elyans "
           "aussergewoehnlichem Talent gehoert und wuenschte sich ein Gemaelde, das die Pracht ihres \n"
           "Koenigreichs einfangen sollte.\n"
           "\n"
           "Elyan nahm die Einladung mit Freude an und begab sich zum Schloss. "
           "Als er die schimmernden Tore passierte, offenbarte sich ihm eine Welt, \n"
           "die noch zauberhafter war, als er es sich je vorgestellt hatte. "
           "Voegel mit schillernden Federn flogen zwischen den Baeumen, und die Blumen tanzten im Wind.\n"
           "\n"
           "Im Herzen des Schlosses traf Elyan die Königin Isolde, "
           "eine Frau von grosser Anmut und Weisheit. Sie fuehrte ihn "
           "durch die Gaerten und zeigte ihm die verborgenen Orte, \n"
           "die sie in seinem Gemaelde verewigt sehen wollte.\n"
           "\n"
           "In den folgenden Wochen widmete sich Elyan mit ganzem Herzen seinem Werk. "
           "Jeden Morgen, wenn die ersten Sonnenstrahlen die Blaetter der Baeume kuessten, \n"
           "setzte er sich an seine Leinwand und liess die Magie fliessen. "
           "Die Farben tanzten auf der Leinwand und die Landschaft nahm Gestalt an.\n"
           "\n"
           "Als das Gemaelde vollendet war, strahlte es mit der Lebendigkeit von Eldoria selbst. "
           "Koenigin Isolde betrachtete das Werk mit glaenzenden \n"
           "Augen und dankte Elyan von Herzen. Sie wusste, dass dieses Gemaelde nicht nur ein "
           "Abbild ihrer Welt war, sondern auch ein Geschenk an die Bewohner von Eldoria.\n"
           "\n"
           "Die Nachricht von Elyans Meisterwerk verbreitete sich durch das Koenigreich, "
           "und bald kamen Menschen von weit her, um seine Kunst zu bestaunen. \n"
           "Die lebendigen Gemaelde wurden zu einem Teil der Kultur von Eldoria, "
           "und Elyan wurde als Meister der lebendigen Malerei verehrt.\n"
           "\n"
           "Seine Werke erzählten Geschichten, vermittelten Emotionen und verbanden die "
           "Menschen mit der Magie der Natur. Durch seine Kunst konnte man die \n"
           "Seele von Eldoria spüren.\n"
           "\n"
           "Und so lebte Elyan, der Kuenstler mit dem Zauber in seinen Haenden, "
           "in der Stadt Farbenfroh, wo die Leinwaende atmeten und die Farben fluesterten \n\n");
}

////////////////////////////////////

void frage_06(struct player_s *user_a){

    int a = 0 ;
    printf("\nWelches mystische Artefakt schützt die Stadt Farbenfroh vor bösen Mächten?\n"
           "1) Der Prismenanhänger\n"
           "2) Der Leuchtkristall\n"
           "3) Die Regenbogenstatue\n"
           "4) Das Farbenamulett");

    scanf("%i", &a);

    switch (a) {
        case 1:
            printf("Diese antwort ist korrekt\n"
                   "########################################################################\n"
            );
            user_a->level++;
            antwort_06();
            break;

        default:
            printf("Diese Antwort ist falsch\n"
                   "!!!!!Du verlierst 10 Lebenspunkte!!!\n");
            user_a->HP -= 10 ;
            printf("Deine neuen HP sind %i\n", user_a->HP );
    }

}

void antwort_06(){
    printf("Der Leuchtkristall\n"
           "\n"
           "Vor langer Zeit, als die Dunkelheit drohte, die Stadt Farbenfroh zu verschlingen, "
           "erschien ein geheimnisvolles Wesen namens Elara. \n"
           "Sie trug einen Kristall, der in allen Farben des Regenbogens schimmerte. "
           "Dieser Kristall, der als Leuchtkristall bekannt wurde, war ein Geschenk der Natur selbst.\n"
           "\n"
           "Elara brachte den Leuchtkristall in die Mitte der Stadt und platzierte "
           "ihn auf einem altaraehnlichen Stein. Sofort erstrahlte der \n"
           "Kristall in einem blendenden Licht, das die Dunkelheit zurueckdraengte.\n"
           "\n"
           "Seitdem wird der Leuchtkristall als ein heiliges Artefakt verehrt, "
           "das Farbenfroh vor bösen Mächten schützt. Er ist das Herz der Stadt und ein \n"
           "Symbol für die Verbindung zwischen Magie und Natur in Eldoria. \n\n");
}

////////////////////////////////////

void frage_07(struct player_s *user_a){

    int a = 0 ;
    printf("\nWelche magische Blume blüht nur einmal im Jahr im geheimen Garten von Eldoria?\n"
           "1) Die Sternenblüte\n"
           "2) Die Silberrose\n"
           "3) Die Morgentauorchidee\n"
           "4) Die Mondscheinlilie");

    scanf("%i", &a);

    switch (a) {
        case 1:
            printf("Diese antwort ist korrekt\n"
                   "########################################################################\n"
            );
            user_a->level++;
            antwort_07();
            break;

        default:
            printf("Diese Antwort ist falsch\n"
                   "!!!!!Du verlierst 10 Lebenspunkte!!!\n");
            user_a->HP -= 10 ;
            printf("Deine neuen HP sind %i\n", user_a->HP );
    }

}

void antwort_07(){
    printf("\nDie Sternenblüte\n"
           "\n"
           "In einem verborgenen Garten, der von den Aeltesten von Eldoria gehuetet wird, "
           "blueht eine Blume von beispielloser Schoenheit - die Sternenbluete. \n"
           "Diese Blume erhebt sich nur einmal im Jahr, wenn die Sterne am hellsten "
           "leuchten und die Magie in der Luft liegt.\n"
           "\n"
           "Die Sternenbluete hat die Fehigkeit, Traeume wahr werden zu lassen. "
           "Legenden besagen, dass wer in der Nacht der Sternenbluete einen Wunsch ausspricht, \n"
           "von der Magie der Blume erhoert wird.\n"
           "\n"
           "Viele Abenteurer haben versucht, den geheimen Garten zu finden, "
           "doch nur diejenigen von reinem Herzen und wahrer Absicht dürfen die Sternenbluete sehen. \n"
           "Sie ist ein Schatz von unschaetzbarem Wert und ein Zeichen der engen Verbindung zwischen "
           "Eldoria und der Magie, die das Koenigreich durchdringt.\n\n");
}

////////////////////////////////////

void frage_08(struct player_s *user_a){

    int a = 0 ;
    printf("\nWelches mythische Tier wird als Bote der Träume und Hoffnung in Eldoria verehrt?\n"
           "1) Der Traumfalke\n"
           "2) Der Glücksphönix\n"
           "3) Der Silberwolf\n"
           "4) Die Sterneneule");

    scanf("%i", &a);

    switch (a) {
        case 1:
            printf("Diese antwort ist korrekt\n"
                   "########################################################################\n"
            );
            user_a->level++;
            antwort_08();
            break;

        default:
            printf("Diese Antwort ist falsch\n"
                   "!!!!!Du verlierst 10 Lebenspunkte!!!\n");
            user_a->HP -= 10 ;
            printf("Deine neuen HP sind %i\n", user_a->HP );
    }

}


void antwort_08(){
    printf("Der Traumfalke\n"
           "\n"
           "In den sanften Huegeln von Eldoria gibt es einen geheimnisvollen Wald, "
           "der als das Heim der Traumfalken bekannt ist. \n"
           "Diese majestaetischen Voegel sind von strahlendem Weiss, "
           "mit Augen, die leuchten wie die Sterne am Nachthimmel.\n"
           "\n"
           "Die Bewohner von Eldoria glauben, dass die Traumfalken Boten aus einer anderen Welt sind, "
           "die Traeume und Hoffnung zu den Menschen tragen. \n"
           "Es wird gesagt, dass in den Naechten, in denen die Sterne besonders hell leuchten, "
           "die Traumfalken aufsteigen und Botschaften der Inspiration und \n"
           "Ermutigung verbreiten.\n"
           "\n"
           "Viele Menschen in Eldoria haben berichtet, von einem Traumfalken in ihren Traeumen "
           "besucht worden zu sein. Diese Begegnungen haben den Menschen Mut gegeben, \n"
           "in schwierigen Zeiten nicht aufzugeben und weiter für ihre Traeume zu kaempfen.\n"
           "\n"
           "Die Traumfalken sind ein Symbol der Verbindung zwischen den Welten und der staendigen Ermutigung, "
           "die in Eldoria zu finden ist. \n"
           "Sie werden verehrt und geschützt, denn sie repraesentieren die Kraft der Traeume "
           "und die Hoffnung, die niemals verloren geht. \n\n");
}

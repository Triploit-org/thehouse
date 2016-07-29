#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//#include "thsys.h"

#ifndef TOHAUS_HPP
#include "tohaus.hpp"
#endif

void schlaf();
void wach();
void nachgucken();
void polizei_r();

int indorf()
{
	if (obj.isinhaus == true)
	{
		obj.isinhaus = false;
		inhaus();
	}
  print("Du gehst nun also zum Dorf.");
  if (obj.matsch == true)
  {
    print("Ganz durchmottert wie du bist... Baehh das stinkt!");
    print("Ja hast ja recht, ich komm zurueck zur Story...");
  }
  print("Nun gehst du zum erstbesten Haus.");
  print("*Klopf* *Klopf*");
  print("Die Tuer oeffnet sich, es steht eine");
  print("Frau darin: \"Guten Abend!");
  testfor(obj.matsch, "Mensch, sie sehen ja aus!");
  print("Was kann ich fuer sie tun?\"");
  print_me("Ich suche ein Zimmer fuer die Nacht.");
  print("Die Frau sieht dich an, aber bittet dich herein.");
  testfor(obj.matsch, "Sie schaut dich noch einmal an: \"Gehen sie erst einmal baden, ich zeige ihnen das Bad.\nSie zeigt dir das Bad und du waescht dich.\"");
  testfor(obj.matsch, "Also du fertig bist gehst du wieder runter.");
  obj.matsch = false;
  print_me("Ich danke ihnen!");
  print("Die Frau meinte: \"Nichts zu danken!");
  print("und nun gehen sie erst einmal schlafen, morgen");
  print("sehen wir dann weiter...\"");
  gleich();
  print(" 1) Du gehst Schlafen...");
  print(" 2) Du bleibst wach");
  gleich();
  obj.ans = getans();

  if (obj.ans == 1){schlaf();}else{wach();}

}

void schlaf()
{
	if (obj.kreisch)
	{

	}
	else
	{
			  print("Du gehst also schlafen und ruhst dich aus.");
	}
  inhaus();
}

void wach()
{
  print("Nun bleibst du wach und schaust dich etwas um in deinem Zimmer.");
  print("Aufeinmal hoerst du etwas, aus dem Nebenzimmer...");
  print_me("Ein rufen? Ein kreischen? Was passiert hier!?");

  gleich();
  print(" 1) Du gehst schlafen");
  print(" 2) Du schaust nach was da los ist");
  print(" 3) Du gehst nach unten und rufst die Polizei");
  gleich();

  obj.ans = getans();

  if (obj.ans == 1) {schlaf();} else if (obj.ans==2) {nachgucken();} else {polizei_r();}

}

void nachgucken()
{
  testfor(obj.wahl, "Du hast keine andere Wahl, du schaust nach....");
  obj.wahl = false;
  print("Vor der Tuer des naechstem Zimmers haelst du an.");
  print_me("Was da wohl los ist...");
  print("Du oeffnest die Tuer... und....");
  print_me("Nichts?! Aber es war doch was zu hoeren!");
  print("\"Was machen sie hier? Gehen sie bitte\"");
  print("Zurueck in das Gaestezimmer!\", sagte die");
  print("Frau die aus dem nichts erschien...");
  print_me("Haben sie das nicht auch gehoert? Das gekreische?!");
  print("Die Frau darauf: \"Nein, es war nichts zu hoeren");
  print("und jetzt zurueck mit ihnen!\"");
  print("Auf deinem Zimmer angekommen wunderst du dich.");
  print_me("Aber das kann man doch nicht ueberhoert haben....");
  print("*Geraeusch* *Kraechts* *Kreisch*");
  print("Du legst dich nun unter dem Laerm schlafen...");
  obj.kreisch = true;
	schlaf();
}

void polizei_r()
{
  print("Du gehst aus deinem Zimmer und suchst das");
  print("naechste Telefon.");
  print_me("Da ist es!");
  print("Denkst du dir und nimmst den Hoerer ab.");
  print("Du faengst an zu waehlen...");
  print_me("1...1...0...");
  print_me("Mist! Keine Verbindung!");
  obj.wahl = true;
  nachgucken();
}

#include <iostream>
using namespace std;

#ifndef THSYS__H
#define THSYS__H
#include "thsys.h"
#endif

void gotop(string pos)
{
  if (pos == "Schrank" && (obj.aktPos == "Zimmer" || obj.aktPos == "Zimmer-Tuer" || obj.aktPos == "Uhr"))
  {
    obj.aktPos = "Zimmer-Schrank";
    print("Du stehst nun am Schrank");
    if (obj.posZettel == obj.aktPos)
      print("und siehst einen Zettel darauf liegen.");
  }
  else if (pos == "Tuer" && (obj.aktPos == "Zimmer-Schrank" || obj.aktPos == "Zimmer" || obj.aktPos == "Zimmer-Uhr"))
  {
    obj.aktPos = "Zimmer-Tuer";
    print("Nun befindest du dich vor der Zimmertuer.");
  }
  else if (pos == "Uhr" && (obj.aktPos == "Zimmer-Schrank" || obj.aktPos == "Zimmer" || obj.aktPos == "Zimmer-Tuer"))
  {
    obj.aktPos = "Zimmer-Uhr";
    print("Du stehst vor der Uhr.");
    print_me("Es ist immer noch 12 Uhr, genau zwoelf.\nEntweder geht die Uhr nicht oder die Zeit ist stehen geblieben...");
  }
  else if (pos == "Zimmer" && obj.aktPos == "Flur")
  {
    obj.aktPos = "Zimmer-Tuer";
    print("Du befindest dich wieder im Zimmer.");
  }
  else if ((pos == "Flur" || pos == "Zimmer-Tuer" || pos == "Gaestezimmer") && obj.aktPos == "Flur-Mitte")
  {
    obj.aktPos = "Flur";
    print("Du befindest dich wieder neben deiner Zimmer-Tuer");
  }
  else if (obj.aktPos == "Flur")
  {
    if (pos == "geradeaus")
    {
      obj.aktPos = "Flur-Mitte";
      print("Du befindest dich nun in der Mitte des Flurs.");
    }
    else if (pos == "Zimmer")
    {
      obj.aktPos = "Zimmer-Tuer";
      print("Du befindest dich wieder in deinem Zimmer.");
    }
    else
    {
      print("Du musst \"geradeaus\" gehen um weiterzukommen!");
    }
  }
  else if (obj.aktPos == "Flur-Mitte")
  {
    if (pos == "Nebenzimmer" || pos == "Zimmer" || pos == "Tuer" || pos == "Nachbarzimmer")
    {
      if (obj.Item == obj.sls)
      {
        obj.NebenTuer = "true";
        obj.aktPos = "Nebenzimmer";
        print("Du betrittst das Nebenzimmer...");
      }
      else if (obj.Item != obj.sls && obj.NebenTuer != "true")
      {
        print_me("Mist, sie hat die Tuer zugeschlossen!");
        print_me("Ich muss einen Schluessel finden, vielleicht ist er irgendwo ja im unteren Stockwerk?");
      }
    }
    else if (pos == "Treppe")
    {
      print("Gehe Treppe runter...");
      obj.treppe = 0;
      obj.aktPos = "Unten";
      if (obj.wUnten == "false")
      {
        print("Dir steigt ein uebler Geruch in die Nase...");
        print_me("Riecht es hier nach Verwesung?!");
        obj.wUnten = "true";
      }
    }
    else
    {
      print("Position leider nicht verfuegbar!");
    }
  }
  else if (obj.aktPos == "Unten")
  {
    if (pos == "Treppe")
    {
      obj.treppe = 0;
      obj.aktPos = "Flur-Mitte";
      print("Du bist nun in der Mitte des oberen Flures.");
    }
    else if (pos == "Kueche")
    {
      obj.aktPos = "Unten-Kueche";
      print("Du befindest dich nun in der Kueche!");
    }
    else if (pos == "Wohnzimmer" || pos == "Stube" || pos == "Wohnung")
    {
      obj.aktPos = "Unten-Wohnzimmer";
      print("Du befindest dich nun im Wohnzimmer!");
    }
    else if (pos == "Badezimmer" || pos == "Bad")
    {
      obj.aktPos = "Unten-Badezimmer";
      print("Du bist nun im Bad!");
    }
    else
    {
      print("Position leider nicht verfuegbar!");
    }
  }
  else if (obj.aktPos == "Unten-Kueche" || obj.aktPos == "Kueche-Herd" || obj.aktPos == "Kueche-Schrank" || obj.aktPos == "Kueche-Tisch")
  {
    if (pos == "Flur")
    {
      print("Die Kueche hast du verlassen,\nnun befindest du dich wieder im Flur des Untergeschosses.");
      obj.aktPos = "Unten";
    }
    else if(pos == "Tisch" || pos == "Person")
    {
      print("Du stehst nun vor dem Tisch...");
      obj.aktPos = "Kueche-Tisch";
    }
    else if (pos == "Schrank")
    {
      print("Nun befindest du dich bei dem Schrank.");
      obj.aktPos = "Kueche-Schrank";
    }
    else if(pos == "Herd" || pos == "Kochzeug")
    {
      print("Du befindest dich vor dem Herd, der noch an ist.");
      obj.aktPos = "Kueche-Herd";
    }
    else
    {
      print("Position leider nicht verfuegbar!");
    }
  }
  else if (obj.aktPos == "Unten-Wohnzimmer" || obj.aktPos == "Wohnzimmer-TV" || obj.aktPos == "Wohnzimmer-Couch")
  {
    if (pos == "Flur")
    {
      print("Du befindest dich wieder im Flur des Untergeschosses.");
      obj.aktPos = "Unten";
    }
    else if (pos == "Couch")
    {
      print("Du stehst nun vor der Couch.");
      obj.aktPos = "Wohnzimmer-Couch";
    }
    else if (pos == "Fernseher")
    {
      print("Du befindest dich nun vor dem Fernseher.");
      obj.aktPos = "Wohnzimmer-TV";
    }
    else
    {
      print("Position leider nicht verfuegbar!");
    }
  }
  else if (obj.aktPos == "Unten-Badezimmer" || obj.aktPos == "Bad-Waschbecken" || obj.aktPos == "Bad-Badewanne" || obj.aktPos == "Bad-Dusche")
  {
    if (pos == "Flur")
    {
      print("Du befindest dich wieder im Flur des Untergeschosses.");
      obj.aktPos = "Unten";
    }
    else if (pos == "Dusche")
    {
      print("Du stehst nun vor der Dusche.");
      obj.aktPos = "Bad-Dusche";
    }
    else if (pos == "Badewanne")
    {
      print("Du befindest dich nun vor der Badewanne.");
      obj.aktPos = "Bad-Badewanne";
    }
    else if (pos == "Waschbecken")
    {
      print("Du stehst nun vor dem Waschbecken.");
      obj.aktPos = "Bad-Waschbecken";
    }
    else
    {
      print("Position leider nicht verfuegbar!");
    }
  }
  else if (obj.aktPos == "Zimmer-Tuer" && pos == "Flur")
  {
    obj.aktPos = "Flur";
    print("Du befindest dich nun im Flur.");
  }
  else if (obj.aktPos == "Nebenzimmer")
  {
    if (pos == "Gang")
    {
      print("Gehe Gang runter...");
      obj.aktPos = "Gang";
    }
    else
    {
      print("Position leider nicht verfuegbar!");
    }
  }
  else if (obj.aktPos == "Gang")
  {
    if (pos == "Gang")
    {
      print("Gehe Gang hoch...");
      obj.aktPos = "Nebenzimmer";
    }
    else if (pos == "geradeaus")
    {
      print("Du gehst geradeaus.\nIn den naechsten Augenblicken erkennst du verhuellte Gestalten.");
      print_me("Sollte ich in den Raum gehen?");
      obj.aktPos = "Gang-VorRaum";
    }
    else if (pos == "Tuer")
    {
      print("Du befindest dich nun in einem Raum...");
      obj.aktPos = "Gang-Tuer";
    }
    else
    {
      print("Position leider nicht verfuegbar!");
    }
  }
  else if (obj.aktPos == "Gang-VorRaum")
  {
    if (pos == "geradeaus" || pos == "zurueck")
    {
      print("Du befindest dich wieder zurueck im Gang.");
      obj.aktPos = "Gang";
    }
    else if (pos == "Raum")
    {
      print("Du gehst in den Raum...");
      if (obj.Item != obj.Robe)
      {
        print("Gestalt: \"Hey! Was tust du hier? Schnappt ihn!\"");
        print("Am besten du verkleidest dich.\nDu bist wieder im Vorraum.");
      }
      else
      {
        print("Gestalt: \"Warum kommst du denn so spaet?\"");
        print("Andere Gestalt: \"Geh auf deine Position!\"");
        obj.aktPos = "Gang-Raum";
      }
    }
    else
    {
      print("Position leider nicht verfuegbar!");
    }
  }
  else if (obj.aktPos == "Gang-Tuer")
  {
    if (pos == "Gang")
    {
      print("Du befindest dich nun wieder im Gang.");
      obj.aktPos = "Gang";
    }
    else
    {
      print("Position leider nicht verfuegbar!");
    }
  }
  else if (obj.aktPos == "Gang-Raum")
  {
    if (pos == "Gang")
    {
      print("Du befindest dich nun wieder im Vorraum.");
      obj.aktPos = "Gang-VorRaum";
    }
    else if (pos == "Position")
    {
      print("Du befindest dich nun auf deiner Pos...");
      print("...");
      print("ition. Du stellst jedoch fest das du\nnicht mehr in dem großen Raum bist...\nSondern in einem kleinen Raum.");
      obj.aktPos = "Satan";
    }
    else
    {
      print("Position leider nicht verfuegbar!");
    }
  }
  else if (obj.aktPos == "Satan")
  {
    if(pos == "Tuer")
    {
      print("Du bist nun bei der Tuer.");
      obj.aktPos = "Satan-ZTuer";
    }
  }
  else if (obj.aktPos == "Satan-ZTuer")
  {
    if (pos == "Flur")
    {
        print("Du bist nun im Flur.");
        obj.aktPos = "Satan-OFlur";
    }
    else
    {
      print("Position leider nicht verfuegbar!");
    }
  }
  else if (obj.aktPos == "Satan-OFlur")
  {
    if(pos == "geradeaus")
    {
      print("Du befindest dich nun in der Mitte des Flures.");
      obj.aktPos = "Satan-OFlur-Mitte";
    }
    else if (pos == "Nebenraum" || pos == "Nebenzimmer")
    {
      if (obj.portal)
      {
        obj.aktPos = "Satan-PortalR";
        print("Du befindest dich im Nebenraum.");
      }
      else
      {
        print("Es scheint so als waere die Tuer verschlossen.\nJedoch besitzt sie kein Schluesselloch...");
      }
    }
    else if (pos == "Tuer" || pos == "Zimmer")
    {
      print("Die Tuer von dem Zimmer aus dem du kahmst\nist abgeschlossen...");
    }
    else
    {
      print("Position leider nicht verfuegbar!");
    }
  }
  else if (obj.aktPos == "Satan-OFlur-Mitte")
  {
    if (pos == "Treppe")
    {
      print("Du bist nun im Obergeschoss.");
      obj.aktPos = "SH-Flur";
    }
    else if (pos == "Tuer" || pos == "Zimmer" || pos == "Raum")
    {
      print("Du befindest dich nun im Zimmer.");
      obj.aktPos = "Satan-Artefakte";
    }
    else if (pos == "geradeaus")
    {
      print("Du stehst wieder am Anfang des Flur's.");
      obj.aktPos = "Satan-OFlur";
    }
    else
    {
      print("Position leider nicht verfuegbar!");
    }
  }
  else if (obj.aktPos == "Satan-Artefakte")
  {
    if (pos == "Flur")
    {
      print("Du befindest dich wieder im Flur.");
      obj.aktPos = "Satan-OFlur-Mitte";
    }
    else
      print("Du kannst dich hier leider nicht fortbewegen,\naber es ist moegliche dein Aktuelles Item\nzu platzieren. Beispiel:\n\tplatziere auf <Aufschrift-des-Altars>");
  }
  else if (obj.aktPos == "SH-Flur")
  {
    if (pos == "Kueche")
    {
      print("Du befindest dich nun in der Kueche.");
      obj.aktPos = "SH-Kueche";
    }
    else if (pos == "Bad" || pos == "Badezimmer")
    {
      print("Du befindest dich nun im Badezimmer.");
      obj.aktPos = "SH-Bad";
    }
    else if (pos == "Wohnzimmer")
    {
      print("Du stehst nun im Wohnzimmer.");
      obj.aktPos = "SH-Wohnzimmer";
    }
    else if (pos == "geradeaus" || pos == "Gang")
    {
      print("Du befindest dich nun in einem Gang.");
      obj.aktPos = "SH-Gang";
    }
    else if (pos == "Treppe")
    {
      print("Du befindest dich wieder unten im mittleren Flur.");
      obj.aktPos = "Satan-OFlur-Mitte";
    }
    else if (pos == "Raum")
    {
      print("Du befindest dich nun einem Raum.");
      obj.aktPos = "SH-Raum";
    }
    else
    {
      print("Position leider nicht verfuegbar!");
    }
  }
  else if (obj.aktPos == "SH-Bad")
  {
		if (pos == "Flur")
		{
			print("Du bist wieder im Flur");
			obj.aktPos = "SH-Flur";
		}
		else
		{
			print("Position leider nicht verfuegbar!");
		}
  }
  else if (obj.aktPos == "SH-Gang")
  {
		if (pos == "Flur")
		{
			print("Du bist wieder im Flur");
			obj.aktPos = "SH-Flur";
		}
		else if (pos == "geradeaus")
		{
			print("Du befindest dich nun in der Mitte des Gang's.");
			if (obj.gesIsDead == "false")
			{
				print("Jedoch bist du nicht alleine.");
				print("Gestalt:\"Was machst du hier?\"\nFragt sie und geht auf dich zu.\nSie versucht dich zu schlagen und du\nweichst aus.\nOb du sie attakieren solltest?");
			}
			obj.aktPos = "SH-Gang-Mitte";
		}
    else if (pos == "Schwerthalter")
    {
      print("Du musst dich dort nicht extra hinbegeben!");
    }
    else
		{
			print("Position leider nicht verfuegbar!");
		}
  }
  else if (obj.aktPos == "SH-Kueche")
  {
		if (pos == "Flur")
		{
			print("Du bist wieder im Flur");
			obj.aktPos = "SH-Flur";
		}
		else
		{
			print("Position leider nicht verfuegbar!");
		}
  }
  else if (obj.aktPos == "SH-Wohnzimmer")
  {
		if (pos == "Flur")
		{
			print("Du bist wieder im Flur");
			obj.aktPos = "SH-Flur";
		}
		else
		{
			print("Position leider nicht verfuegbar!");
		}
  }
  else if (obj.aktPos == "SH-Gang-Mitte")
  {
		if (pos == "geradeaus")
		{
			print("Du bist wieder am Anfang des Ganges");
			obj.aktPos = "SH-Gang";
		}
		else
		{
			print("Position leider nicht verfuegbar!");
		}
  }
  else if (obj.aktPos == "SH-Raum")
  {
    if (pos == "Flur")
    {
      print("Du bist wieder im Flur.");
      obj.aktPos = "SH-Flur";
    }
    else if (pos == "zurueck" || pos == "Tuer" || pos == "Raum" || pos == "Zimmer")
    {
      print("Du stehst nun in dem anderen Zimmer.");
      obj.aktPos = "SH-Raum-Raum";
    }
  }
  else if (obj.aktPos == "SH-Raum-Raum" || obj.aktPos == "SH-Raum-Raum-Zeichen")
  {
    if (pos == "zurueck" || pos == "Tuer" || pos == "Raum" || pos == "Zimmer")
    {
      print("Du befindest dich wieder in dem anderen Raum.");
      obj.aktPos = "SH-Raum";
    }
    else if (pos == "Zeichen")
    {
      print("Du stehst am Zeichen.");
      obj.aktPos = "SH-Raum-Raum-Zeichen";
    }
  }
  else if (obj.aktPos == "")
  {

  }
  else if (obj.aktPos == "")
  {

  }
  else if (obj.aktPos == "")
  {

  }
  else if (obj.aktPos == "")
  {

  }
  else if (obj.aktPos == "")
  {

  }
  else if (obj.aktPos == "")
  {

  }
  else
  {
    print("Position leider nicht verfuegbar!");
  }
}

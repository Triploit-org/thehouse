#include <iostream>
using namespace std;

#ifndef THSYS__H
#define THSYS__H
#include "thsys.h"
#endif

void umschauen(string args[])
{
  if (obj.aktPos == "Zimmer")
  {
    print("Du liegst auf dem Bett deines Gaestezimmers.");
    print("Rechts von dir steht ein Schrank.");
    print("Links von dir steht eine Uhr und auf dem Boden liegt ein Teppich.");
    print("Genau vor dem Bett auf dem du liegst, befindet sich die Tuer.");
  }
  else if (obj.aktPos == "Zimmer-Schrank")
  {
    print("Du stehst vor einem Schrank in deinem Gaestezimmer.");
    if (obj.posZettel == obj.aktPos && obj.posZettel != obj.hand)
    {
        print("Doch darauf liegt ein Zettel, solltest du ihn\ndir durchlesen?");
    }
  }
  else if (obj.aktPos == "Zimmer-Tuer")
  {
    print("Du stehst im Zimmer vor deiner Tuer.\nOb du in den Flur gehen solltest?");
  }
  else if (obj.aktPos == "Flur-Mitte")
  {
    print("Du stehst in der Mitte des Flures.\nNeben dir ist die Tuer des Zimmers aus dem die Schreie kamen.");
    print("Vor dir befindet sich eine Treppe die in das Untergeschoss fuehrt.");
  }
  else if (obj.aktPos == "Flur")
  {
    print("Du befindest dich im Flur des Hauses im oberen Stockwerk.");
    print("Hinter und rechts von dir sind eine Wand, links von dir ist deine Zimmertuer.");
    print("Links von dir sind auch noch andere Zimmertueren, darunter die,\naus der der Laerm kam, der aufgehoert hat.");

    //print("Hier hatt es auch schon leider sein Ende :(! Danke fuers Spielen :)!");
  }
  else if (obj.aktPos == "Unten")
  {
    print("Du bist im Flur des Untergeschosses.");
    print("Du stehst in einem kleinem Raum. Dieser Raum");
    print("hat drei Tueren, einmal zur Kueche,");
    print("zum Wohnzimmer und zum Badezimmer.");
  }
  else if (obj.aktPos == "Unten-Kueche")
  {
    print("Du stehst in der Kueche, hinter dir ist der Flur.");
    print("Vor dir kannst du einen Tisch entdecken.");
    print("Rechts von dir siehst du einen Schrank.");
    print("Links von dir siehst du einen Herd und alles moegliche von Kochzeug.");
    if (obj.wKueche == "false")
    {
      print("Auf dem Stuhl an dem Tisch sitzt eine Person,\ndu kannst sie im Dunkeln nicht genau erkennen.");
    }
    obj.wKueche = "true";
  }
  else if (obj.aktPos == "Unten-Badezimmer")
  {
    print("Du siehst vor dir eine Badewanne.\nRechts von dir ist eine Dusche,\nlinks von dir ein Waschbecken.");
  }
  else if (obj.aktPos == "Unten-Wohnzimmer")
  {
    print("Du befindest dich im Wohnzimmer.\nRechts von dir befindet sich ein Fernseher,\nlinks von dir eine Couch.");
  }
  else if (obj.aktPos == "Kueche-Schrank")
  {
    print("Eine Glasvitriene steht vor dir.");
    print("Dort sind Teller, Besteck und alles");
    print("moegliche von unbrauchbarem drin.");
  }
  else if (obj.aktPos == "Kueche-Tisch")
  {
    if (obj.wKueche == "true") { obj.matsch = true; }
    if (obj.matsch)
    {
      print("Du kannst die Person nun erkennen.");
      print("Es ist die Frau und sie ist Tot! \nBei genauerem hinsehen \nsiehst du das ihre Hand verbrannt ist und\nsie komische Zeichen auf dieser Handflaeche\nhat. Diese sehen au wie eine Art Keilschrift.");
      print_me("Gibt es hier etwa einen Moerder? Ich muss \nherausfinden was in dem oben Raum drine passiert ist!");
      obj.matsch = false;
    }
    else
    {
      print("Das hier hast du schon entdeckt!");
    }
  }
  else if (obj.aktPos == "Kueche-Herd")
  {
    print("Du siehst den Herd.");
    if (obj.posSls == obj.aktPos)
    {
      print("Auf dem Herd liegt ein Schluessel.");
    }
  }
  else if (obj.aktPos == "Bad-Dusche")
  {
    print("Du stehst nun vor der Dusche.\nSie ist aus und Trocken, aber die Waende innen und \ndie Tueren haben Risse....");
  }
  else if (obj.aktPos == "Bad-Badewanne")
  {
    print("Du stehst vor der Badewanne.\nDort drine befindet sich jedoch kein Wasser,\nsondern eine andere, dickfluessige und rote Fluessigkeit");
  }
  else if (obj.aktPos == "Bad-Waschbecken")
  {
    print("Vor dem Wasbecken liegt der Teppich,\n er hat rote Tropfen auf sich...");
  }
  else if (obj.aktPos == "Wohnzimmer-Couch")
  {
    print_me("Die Couch der Stube ist zerfleddert. Warum bloss?");
  }
  else if (obj.aktPos == "Wohnzimmer-TV")
  {
    print("Du befindest dich vor dem Fernseher des Wohnzimmers.\nDer Fernseher ist an. Man kann jedoch nur erkennen, dass\nkein Signal vorhanden ist.");
  }
  else if (obj.aktPos == "Nebenzimmer")
  {
    print("Das Zimmer ist komplett leer,\njedoch etwas gibt es dort drin, was\nvorher nicht dort war...\nDu siehst vor dir einen Gang, der nach unten fuehrt.");
    print_me("Ob ich den Gang runtergehen sollte? Ich weiss nicht....");
  }
  else if (obj.aktPos == "Gang")
  {
    print("Du befindest dich in einem Gang.\nEr scheint unterirdisch zu verlaufen und nicht nur im Haus....");
    print("Du kannst links von dir eine Tuer sehen.\nWenn du Geradeaus schaust, kannst du einen großen Raum entdecken.");
  }
  else if (obj.aktPos == "Gang-VorRaum")
  {
    print("Du stehst vor dem Eingang des großen Raumes.");
    print("In dem Raum sind verhuellte gestalten.\nVielleicht solltest du dich verkleiden.");
  }
  else if (obj.aktPos == "Gang-Raum")
  {
    print("Du stehst in einem großen Raum.");
    print("Es stehen verhuellte Gestalten auf einem Muster\nim Marmorboden.");
    print("Es scheint so als wuerden sie darauf warten,\ndass du auf deine Position gehst.");
  }
  else if (obj.aktPos == "Gang-Tuer")
  {
    print("Du stehst in einem sehr kleinem Raum.");
    print("Es koennte eine Garderobe sein, denn");
    print("es haengen ueberall Roben(Umhaenge).");
  }
  else if (obj.aktPos == "Satan")
  {
    print("Du befindest dich in einem dunklen Raum.\nVor dir befindet sich eine Tuer.");
    print("Befindest du dich ueberhaupt noch in dem Haus der Frau?");
    if (obj.Item == obj.Robe)
    {
      print("Du hast nun deine Robe ausgezogen...");
      obj.posRobe = obj.aktPos;
      obj.Item = "";
    }
  }
  else if (obj.aktPos == "Satan-OFlur")
  {
    print("Du stehst im Flur des Untergeschosses,\nwenn du richtig liegst.");
    print("Du siehst rechts von dir einen kleinen Nebenraum.");
    print("Wenn du geradeaus schaust siehst du eine Treppe und\nnoch eine Tuer");
  }
  else if (obj.aktPos == "Satan-ZTuer")
  {
    print("Du befindest dich vor der Zimmertuer.");
    print("Ob sie zu einem Flur fuehrt?");
  }
  else if (obj.aktPos == "Satan-PortalR")
  {
    print("Du kannst ein Pult erkennen,\nda kommt doch sicher etwas rauf?");
  }
  else if (obj.aktPos == "Satan-Artefakte")
  {
    print("Du bist in einem grossen Raum.");
    print("Du siehst Verschiedne saeulenartige Altartische aus Stein.\nAuf denen Steht, nach ihrer Position zu folge, etwas eingemeißelt: ");
    print("1. Leicht");
    print("2. Hart");
    print("3. Rot");
    print("4. Rundlich");
    print("5. Scharf");
    print("6. ??? [Unkenntlich] ???");
  }
  else if (obj.aktPos == "Satan-OFlur-Mitte")
  {
    print("Neben dir ist ein ein Raum, vor dir eine Treppe.\nDu bist in der Mitte des Flurs im Untergeschoss.");
  }
  else if (obj.aktPos == "SH-Flur")
  {
    /*print("Du kannst folgende Raeume erkennen:");
    print(" eine Kueche");
    print(" einen unbekannten Raum");
    print(" ein Bad");
    print(" ein Wohnzimmer");
    print(" ein Gang");
    print("und den Weg zurueck nach oben.");*/

		print("Du stehst in der Mitte eines groeßeren Flur's.");
		print("Du kannst eine Kueche, ein Bad, ein Wohnzimmer,\neinen weiteren Gang der geradeaus fuehrt und \neinen Unbekannten Raum entdecken.");
  }
  else if (obj.aktPos == "SH-Bad")
  {
		print("Dieser Raum wurde noch nicht ins Spiel integriert!");
		print("Fuer eine Geschaetzte Zeit der Entwicklung kontaktieren\nSie den Projektleiter.");
  }
  else if (obj.aktPos == "SH-Gang")
  {
		print("Du stehst in einem langen Gang.");
		print("DU siehst verschiedene Dinge, einen");
		print("Schwerthalter zum Beispiel.");
    if (obj.posSchwert == obj.aktPos)
      print("Dadrinne haengt sogar ein Schwert.");
  }
  else if (obj.aktPos == "SH-Kueche")
  {
		print("Dieser Raum wurde noch nicht ins Spiel integriert!");
		print("Fuer eine Geschaetzte Zeit der Entwicklung kontaktieren\nSie den Projektleiter.");
  }
  else if (obj.aktPos == "SH-Wohnzimmer")
  {
		print("Du erkennst verschiedene Sachen.\nEinen Schrank der neben einem Fernseher steht und\neiner Couch die sich auf der rechten Seite befindet\nund neben einer Zimmerpflanze steht.");
  }
  else if (obj.aktPos == "SH-Gang-Mitte")
  {
		print("Dieser Raum wurde noch nicht vollstaendig ins Spiel integriert!");
		print("Fuer eine Geschaetzte Zeit der Entwicklung kontaktieren\nSie den Projektleiter.");
  }
  else if (obj.aktPos == "Zimmer-Uhr")
  {
    print("Es ist 12 Uhr... Immer noch...");
  }
  else if (obj.aktPos == "SH-Raum")
  {
    print("Du siehst dich um und entdeckst eine Keilschrift\nan der Wand. Sie kommt dir bekannt vor.\nDie siehst vor dir noch eine Tuer die in ein\nanderes Zimmer fuehrt.");
  }
  else if (obj.aktPos == "SH-Raum-Raum")
  {
    if (obj.aktPos == "SH-Raum-Raum")
    {
      print("Du erkennst einen dunklen Raum. Es stehen Kerzen rum\nund du siehst ein komsiches Zeichen auf dem Boden.");
      //print("Auf dem Zeichen steht eine Figur.");
      print_me("Sind... sind das etwa Stimmen?");
      print("Du hoerst Stimmen, sie fluestern wirre Dinge.");
    }
  }
  else if (obj.aktPos == "SH-Raum-Raum-Zeichen")
  {
    print("Du kannst auf dem Boden ein Zeichen erkennen.");
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
    print("Du befindest dich an einem nicht existenten Ort!");
  }

  if (obj.aktPos == obj.posZettel)
  {
    print("Auf dem Boden liegt ein Blutverschmierter Zettel...");
  }

  if (obj.aktPos == obj.posRobe)
  {
    print("Auf dem Boden liegt eine Robe...");
  }

  if (obj.posSatan == obj.aktPos)
  {
    print("Außerdem erkennst du eine Teufelsfigur auf dem Boden.");
  }
}

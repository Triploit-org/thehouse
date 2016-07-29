#include <iostream>
using namespace std;

#ifndef THSYS__H
#define THSYS__H
#include "thsys.h"
#endif

void take(string c)
{
  if (obj.aktPos == "Zimmer-Schrank" && c == obj.Zettel)
  {
    if (obj.ZettelInHand != true)
    {
      obj.Item = obj.Zettel;
      print("Du haeltst nun den Zettel in der Hand. Er scheint\nblutig zu sein.... du solltest ihn dir durchlesen....");
      obj.ZettelInHand = true;
      obj.posZettel = obj.hand;
    }
    else
    {
      print("Du hast den Zettel in der Hand!");
    }
  }
  else if (obj.aktPos == obj.posZettel && c == obj.Zettel)
  {
    if (obj.ZettelInHand != true)
    {
      obj.Item = obj.Zettel;
      print("Du haeltst nun den Zettel in der Hand.");
      obj.ZettelInHand = true;
      obj.posZettel = obj.hand;
    }
    else
    {
      print("Du hast den Zettel in der Hand!");
    }
  }
  else if (obj.aktPos == "Gang-Tuer")
  {
    if (c == "Robe")
    {
      print("Du hast nun die Robe an.");
      if (obj.Item == obj.sls)
      {
        obj.posSls = obj.aktPos;
      }
      obj.Item = obj.Robe;
      obj.posRobe = obj.hand;
    }
  }
  else if (obj.aktPos == obj.posSls && c == "Schluessel")
  {
    if (obj.SlsInHand)
    {
      print("Du hast den Schluessel schon in der Hand!");
    }
    else
    {
      print("Du haeltst den Schluessel nun in der Hand!");
      obj.SlsInHand = true;
      obj.Item = obj.sls;
      obj.posSls = obj.hand;
    }
  }
  else if (obj.aktPos == "SH-Gang")
  {
		if (c == "Schwert")
		{
			if (obj.Item != "Schwert")
			{
				print("Du haeltst nun das scharfe Schwert in deiner Hand.");
				print("Beim Betrachten haettest du dich fast geschnitten.");
				obj.Item = "Schwert";
				obj.posSchwert = obj.hand;
			}
			else
			{
				print("Du hast das Schwert schon in der Hand!");
			}
		}
		else
		{
			print("Dieses Objekt ist hier nicht zu finden...");
		}
  }
  else if (obj.aktPos == "SH-Raum-Raum-Zeichen")
  {
    if ((c == "Figur" || c == "Teufel" || c == "Satan" || c == "Teufelsfigur") && obj.Item != "Figur")
    {
      print("Du hast nun die Figur in der Hand.");
      obj.Item = "Figur";
      obj.posSatan = obj.hand;
    }
    else if (obj.Item == "Figur")
    {
      print("Du hasst die Figru schon in der Hand!");
    }
    else
    {
      print("Objekt nicht gefunden!");
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
  else
  {
    print("Momentan nicht moeglich!");
  }
}

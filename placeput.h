#include <iostream>
using namespace std;

#ifndef THSYS__H
#define THSYS__H
#include "thsys.h"
#endif

void put(string s)
{
  if (/*s == obj.Zettel || */s == obj.Zettel && obj.ZettelInHand == true)
  {
    obj.posZettel = obj.aktPos;
    obj.Item = "";
    obj.ZettelInHand = false;
    print("Zettel weg gelegt!");
  }

  if (s == obj.Robe && obj.Item == obj.Robe)
  {
    obj.posRobe = obj.aktPos;
    obj.Item = "";
    print("Robe weggelegt!");
  }

  if (s == obj.sls && obj.Item == obj.sls)
  {
    obj.posSls = obj.aktPos;
    obj.Item = "";
    print("Schluessel weggelegt!");
  }

  if (s == "Schwert" && obj.Item == "Schwert")
  {
    obj.posSchwert = obj.aktPos;
    obj.Item = "";
    print("Schwert weggelegt!");
  }
}

void place(string pos)
{
  if (obj.aktPos == "Satan-Artefakte")
  {
    if(pos == "Leicht")
    {
      if (obj.Item == "Feder")
      {
        print("Objekt platziert!");
        obj.posFeder = "Leicht";
				obj.Item = "";
      }
      else
      {
        print("Ich denke, das ist der falsche Altar...");
      }
    }
    else if (pos == "Hart")
    {
      if (obj.Item == "Ziegenhorn")
      {
        print("Objekt platziert!");
        obj.posZiegenhorn = "Hart";
      }
      else
      {
        print("Ich denke, das ist der falsche Altar...");
      }
    }
    else if (pos == "Rundlich")
    {
      if (obj.Item == "Schaedel")
      {
        print("Objekt platziert!");
        obj.posSchaedel = "Rundlich";
      }
      else
      {
        print("Ich denke, das ist der falsche Altar...");
      }
    }
    else if (pos == "Scharf")
    {
      if (obj.Item == "Schwert")
      {
        print("Objekt platziert!");
        obj.posSchwert = "Scharf";
      }
      else
      {
        print("Ich denke, das ist der falsche Altar...");
      }
    }
    else if (pos == "Rot")
    {
      if (obj.Item == "Apfel")
      {
        print("Objekt platziert!");
        obj.posApfel = "Rot";
      }
      else
      {
        print("Ich denke, das ist der falsche Altar...");
      }
    }
    else if (pos == "???" || pos == "Unkenntlich")
    {
      if (obj.Item == "Stein")
      {
        print("Objekt platziert!");
        obj.posStein = "?";
      }
      else
      {
        print("Ich denke, das ist der falsche Altar oder\nder falsche Gegenstand.");
      }
    }
    else
    {
      print("Der Angegebene Altar steht nicht zur Verfuegung.");
    }
  }
  else
  {
    print("In dem Raum in dem du dich befindest kann man nichts Platzieren!");
  }

  if (obj.posFeder == "Leicht" && obj.posZiegenhorn == "Hart" && obj.posSchaedel == "Rundlich" && obj.posSchwert == "Scharf" && obj.posApfel == "Rot" && obj.posStein == "?")
  {
    obj.portal = true;
    print("Die Tuer zum Raum eines bestimmten Zimmers hat sich geoeffnet...");
  }
}

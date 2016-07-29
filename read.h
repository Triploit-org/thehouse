#include <iostream>
using namespace std;

#ifndef THSYS__H
#define THSYS__H
#include "thsys.h"
#endif

void reads(string c)
{
  if (c == obj.Zettel)
  {
    if (obj.Item == obj.Zettel)
    {
      print_me("Was steht denn hier... \"Wer auch immer das liest...\nGEH NICHT IN DAS ZIMMER NEBEN AN!!!\nVERSCHWINDE SCHNELL VON HIE..\"\nDie letzten Worte sind... blutverschmiert!?");
      print_me("Ich denke das sollte eine Warnung sein, aber ob ich ins Zimmer gehen sollte?");
    }
    else
    {
        print("Du hast keinen Zettel in der Hand, schon mal\n\"nimm Zettel\" versucht?");
    }
  }
}

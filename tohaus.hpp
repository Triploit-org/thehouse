#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//#include "save.h"
#include "parser.h"

using namespace std;

void inhaus()
{
    if (obj.aktPos == "") {
      obj.aktPos = "Zimmer";
    	print("Du wachst auf, mitten in der Nacht...");
      print("Du schaust auf die Uhr neben dir an der Wand.");
      print_me("Es ist ja schon 12 Uhr Mittags! Warum ist es denn so dunkel?");

      if (obj.kreisch == false)
      {
        print_me("Was ist das fuer ein Gekreisch hier?");
        print("Meinst du und haeltst dir bei dem Laerm die Ohren zu.");
      }
      else
      {
        print_me("Nicht schon wieder dieses gekreische...");
        print("Du haeltst dir die Ohren zu.");
        obj.kreisch = false;
      }

      print("Tipp:\n\tBenutze den Befehl \"help\" um \n\teine Liste von Befehlen zu erhalten.\nBenutze statt den Umlauten \"ae\",\"oe\" und \"ue\"!");
    }

    while (true)
    {
      string cmds[300];
      int i = 0;
      char c[256];
      obj.tmp = getans(c);
      cin.sync();
      stringstream ssin(obj.tmp);

      while (ssin.good() && i < 300)
      {
        ssin >> cmds[i];
        ++i;
      }
      cin.sync();
      parse(cmds, obj.tmp);
    }

}

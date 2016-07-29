#include <iostream>
#include "save.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int parse(string cmd[], string fcmd)
{

  if (cmd[0].find("help") == 0)
  {
    help();
  }
  else if (cmd[0].find("umschauen") == 0)
  {
    umschauen(cmd);
  }
  else if (cmd[0].find("gehe") == 0 || cmd[0].find("geh") == 0 || cmd[0].find("zu") == 0)
  {
    if (cmd[2].find("hoch") == 0||cmd[2].find("runter") == 0 || cmd[2].find("rauf") == 0 || cmd[2].find("herunter") == 0 || cmd[2].find("hinauf") == 0 || cmd[2].find("hinunter") == 0)
    {
      gotop(cmd[1]);
    }
    if (cmd[1].find("zu") == 0 || cmd[1].find("im") == 0 || cmd[1].find("zum") == 0 || cmd[1].find("zur") == 0 || cmd[1].find("in") == 0 || cmd[1].find("durch") == 0 || cmd[1].find("auf") == 0)
    {
      if (cmd[2].find("der") == 0 || cmd[2].find("die") == 0 || cmd[2].find("das") == 0 || cmd[2].find("den") == 0 || cmd[2].find("dem") == 0 || cmd[2].find("dessen") == 0 || cmd[2].find("ein") == 0 || cmd[2].find("eine") == 0 || cmd[2].find("einen") == 0)
      {
        gotop(cmd[3]);
      }
      else
      {
          gotop(cmd[2]);
      }
    }
    else if (cmd[1].find("geradeaus") == 0)
    {
      gotop("geradeaus");
    }
    else
    {
      //print("Das war etwas ungenau, versuch es mal anders zu formulieren.\nBeispiel: gehe zu [ABCD]");
    }
  }
  else if (cmd[0].find("nimm") == 0 || cmd[0].find("greif") == 0|| cmd[0].find("nehme") == 0)
  {
    take(cmd[1]);
  }
  else if (cmd[0].find("lies") == 0 || cmd[0].find("lese") == 0)
  {
    if (cmd[1].find("der") == 0 || cmd[1].find("die") == 0 || cmd[2].find("das") == 0 || cmd[1].find("den") == 0 || cmd[1].find("dem") == 0 || cmd[1].find("dessen") == 0 || cmd[1].find("ein") == 0 || cmd[1].find("eine") == 0 || cmd[1].find("einen") == 0)
    {
      reads(cmd[2]);
    }
    else
    {
        reads(cmd[1]);
    }
  }
  /*else if (cmd[0].find("oeffne") == 0)
  {
    open(cmd[1]);
  }*/
  else if (cmd[0].find("item") == 0)
  {
     if (cmd[1].find("set") == 0)
     {
       obj.Item = cmd[2];
     }
     print(obj.Item);
  }
  else if (cmd[0].find("lege") == 0)
  {
     if (cmd[2].find("weg") == 0 || cmd[2].find("auf") == 0 || cmd[2].find("ab") == 0)
     {
       put(cmd[1]);
     }
  }
  else if (cmd[0].find("exit") == 0 || cmd[0].find("quit") == 0)
  {
    print("Danke fuers Spielen!");
    exit(0);
  }
  else if (cmd[0].find("save") == 0)
  {
    save_game();
  }
  else if (cmd[0].find("stat") == 0)
  {
    cout << "Item: " << obj.Item << endl;
    cout << "Pos: " << obj.aktPos << endl;
    cout << "Name: " << obj.name << endl;
    cout << "Level: " << "inHaus();" << endl;
  }
  else if (cmd[0].find("trete") == 0)
  {
    print("Guter Versuch...");
  }
  else if (cmd[0].find("licht") == 0)
  {
    print("Nichts zum Licht steuern da!");
  }
  else if (cmd[0].find("schalte") == 0)
  {
    print("Kein Schalter in der Nähe!");
  }
  else if (cmd[0].find("ja") == 0)
  {
    print("Wenn du es so meinst.");
  }
  else if (cmd[0].find("nein") == 0)
  {
    print("Deine Entscheidung.");
  }
  else if (cmd[0].find("schaue") == 0)
  {
    umschauen(cmd);
  }
  else if (cmd[0].find("platziere") == 0)
  {
    place(cmd[2]);
  }
  else if (cmd[0].find("laden") == 0)
  {
    load_game("user.th");
  }
  else if (cmd[0].find("sag") == 0)
  {
    string msg = fcmd;
    replace(msg, "sag ", "");
    replace(msg, "\"", "");
    print_me(msg);
  }
  else if (cmd[0].find("schlage") == 0 || cmd[0].find("attakiere") == 0 || cmd[0].find("schlag") == 0 || cmd[0].find("hau") == 0 || cmd[0].find("haue") == 0 || cmd[0].find("toete") == 0 || cmd[0].find("attackiere") == 0)
  {
    if (obj.aktPos == "SH-Gang-Mitte")
    {
      if (cmd[1].find("die") == 0 || cmd[1].find("der") == 0 || cmd[1].find("das") == 0 || cmd[1].find("ein") == 0 || cmd[1].find("eine") == 0 || cmd[1].find("einer") == 0 || cmd[1].find("eines") == 0 || cmd[1].find("den") == 0 || cmd[1].find("dem") == 0)
      {
        if (cmd[3].find("mit") == 0)
        {
          if (cmd[4].find("die") == 0 || cmd[4].find("der") == 0 || cmd[4].find("das") == 0 || cmd[4].find("ein") == 0 || cmd[4].find("eine") == 0 || cmd[4].find("einer") == 0 || cmd[4].find("eines") == 0 || cmd[4].find("den") == 0 || cmd[4].find("dem") == 0)
          {
            attack(cmd[2], cmd[5]);
          }
          else
          {
            attack(cmd[2], cmd[4]);
          }
        }
        else
        {
          print("Pardon, wen soll ich mit was attackieren?");
        }
      }
      else
      {
        if (cmd[2].find("mit") == 0)
        {
          attack(cmd[1], cmd[3]);
        }
        else
        {
          print("Pardon, wen soll ich mit was attackieren?");
        }
      }
    }
    else
    {
      print("Ich glaube nicht, dass das hier hilft.");
    }
  }
  else if (cmd[0].find("kannst") == 0 && cmd[1].find("du") == 0)
  {
    print("Was kann ich?");
  }
  else if (cmd[0].find("zeit") == 0 || cmd[0].find("uhrzeit") == 0)
  {
    print("Es ist...");
    sleep(1);
    print("12 Uhr...");
  }
  else if (cmd[0].find("skript") == 0 || cmd[0].find("author") == 0 || cmd[0].find("info") == 0 || cmd[0].find("infos") == 0 || cmd[0].find("version") == 0)
  {
    print("Text und Story: Tristan Pieper");
    print("Leveldesign: Tristan Pieper, Simon Papke");
    print("Tester: Fabian Melching, P.B.(Anonym)");
    print("Programmierung: Tristan Pieper");
    print("Weitere Ideen: Fabian Melching, P.B.(Anonym), Simon Papke");
  }
  else if (cmd[0].find("gt") == 0)
  {
    obj.aktPos = cmd[1];
  }
  /*else if (cmd[0].find("") == 0)
  {

  }
  /*else if (cmd[0].find("") == 0)
  {

  }
  /*else if (cmd[0].find("") == 0)
  {

  }
  /*else if (cmd[0].find("") == 0)
  {

  }
  /*else if (cmd[0].find("") == 0)
  {

  }
  /*else if (cmd[0].find("") == 0)
  {

  }*/
  /*else if (cmd[0].find("unlock") == 0)
  {
    obj.NebenTuer = "true";
  }*/
  else
  {
    print("Das habe ich leider nicht verstanden.");
  }

}

#include <iostream>
#include "thsys.h"
using namespace std;

int generates();

void attack(string per, string w)
{
  int proz = generates();

  if (obj.gesIsDead != "true")
  {
    if (per == "Gestalt" || per == "Gegner")
    {
      if ((w == obj.Item || w == "Hand" || w == "Haende"))
      {
        if (proz == 1)
        {
          print("Attakiere die Gestalt...");
          print("Gestalt schlaegt zurueck!");
          print("Die Gestalt wurde mit dem Schwert getoetet.");
          print_me("Das war knapp! Aber ich hab nur ein paar Kratzer...");
          obj.gesIsDead = "true";
        }
        else
        {
          print("Du schlaegst zu...");
          print("Du hast verfehlt!");
        }
      }
      else
      {
        print("Mit dem Gegenstand kann nicht angegriffen werden!");
      }
    }
    else
    {
      print("Warum willst du diese Person attakieren?");
    }
  }
  else
    print("Person nicht gefunden!");
}


int generates()
{
  int num;
  srand (time(NULL));
  num = rand() % 2 + 1;
  return num;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <iostream>
#include <time.h>
#include <windows.h>

#ifndef CMD
#define CMD
#include "look.h"
#include "placeput.h"
#include "read.h"
#include "take.h"
#include "gotop.h"
#endif

using namespace std;

#ifndef THSYS_H
#define THSYS_H

bool StartsWith(const string& text,const string& token)
{
	if(text.length() < token.length())
		return false;
	return (text.compare(0, token.length(), token) == 0);
}
bool replace(string& str, const string& from, const string& to) { size_t start_pos = str.find(from); if(start_pos == string::npos) return false; str.replace(start_pos, from.length(), to); return true; }


/*
 * ======================== Objekte ========================
 */


struct objects {
  string name;
  string tmp;
  int ans;
  string befehl;

  bool isindorf;
  bool isinhaus;

  //1
  bool matsch = false;
  bool wahl;
  bool kreisch;

  //2
  string aktPos;
  string Item;
  string hand = "InHand";

  //2 Items
  string Zettel = "Zettel";
  string sls = "Schluessel";
  string Robe = "Robe";

  //2 Item Pos
  string posZettel = "Zimmer-Schrank";
  string posSls = "Kueche-Herd";
  string posRobe = "Gang-Tuer";

  //2 Items in Hand?
  bool SlsInHand;
  bool ZettelInHand;

  //2 Door open?
  bool ZimmerTuer;
  string NebenTuer = "false";

  //2 Where?
  string wUnten = "false";
  string wBadezimmer = "false";
  string wKueche = "false";
  string wWohnzimmer = "false";

  //3 Item Pos
  string posFeder = "SH-Kueche";
  string posSchwert = "SH-Gang";
  string posApfel = "SH-";
  string posSchaedel = "SH-Bad";
  string posZiegenhorn = "SH-";
  string posStein = "SH-";
	string posSatan = "SH-Raum-Raum-Zeichen";

	string gesIsDead = "false";
  bool portal;

  int treppe;
};

struct objects obj;

/*
 * ======================================================
 */

int gen()
{
  int num;
  srand (time(NULL));
  num = rand() % 40000 + 30000;
  return num;
}

 void print(string s)
 {
   //cout << s << endl;
   //usleep(200000);
   string::iterator i;
   for (i=s.begin(); i!=s.end(); i++)
   {
       cout << *i;
       usleep(gen());
       cin.sync();
   }
   cout << endl;
 }

bool find(string s, string sd)
{
	if (s.find(sd) == 0)
		return true;
	else
		return false;
}

void testfor(bool t, string s)
{
  if (t == true)
  {
    string::iterator i;
    for (i=s.begin(); i!=s.end(); i++)
    {
        cout << *i;
        usleep(gen());
        cin.sync();
    }
    cout << endl;
  }
}

void print_me(string s)
{
  cout << obj.name << ": \"";
  string::iterator i;
  for (i=s.begin(); i!=s.end(); i++)
  {
      cout << *i;

      usleep(gen());
      cin.sync();
  }
  cout << "\"" << endl;
}

void gleich()
{
  cout << "===============================" << endl;
}

int getans()
{
  int ans;
  cout << "> ";
  cin >> ans;
  sleep(1);
  return ans;
}

string getans(string ans)
{
	cout << "> ";
	getline(cin, ans);
  cin.sync();
	usleep(500000);
  string ans2 = ans;
	return ans2;
}

// Befehle
void help()
{
	print("Einige Kommandos:");
	print("\thelp - Zeigt diese Hilfeseite an.");
  print("\tumschauen - Sagt dir wo du dich befindest");
  print("\tgehe <zu/in/zur/zum/durch> <Ort>");
  print("\tsavegame - Um das Spiel in die Datei \"user.th\" zu speichern.");
  print("\tsave - Alias von \"savegame\"");
  print("Das reicht auch. Den Rest musst du");
  print("selber herausfinden.");
  print("Nach Tueren kommt ein Flur...");
  print("PS: Bitte zuerst immer die Verben\n(also den Befehle) und dann den Rest eingeben!\nBeispiel: \n\tgehe zum Nachbarn\n\tgehe Treppe runter/hoch");
  print("Die Beispiele sind nur Beispiele!\nSie funktionieren (noch) nicht!");
}

/*void open(string ob)
{
  if (ob == "Tuer")
  {
    if (obj.aktPos == "Zimmer-Tuer")
    {
      print("Tuer geoeffnet, du betrittst den Flur...");
      obj.aktPos = "Flur";
      obj.ZimmerTuer == true;
    }
    else
    {
      print("Du stehst nicht an einer Tuer!");
    }
  }
}*/

void item()
{
  print(obj.Item);
}

void clear()
{
  #ifdef __cplusplus__
    #include <cstdlib>
  #else
    #include <stdlib.h>
  #endif
  if (system("CLS")) system("clear");
}

#endif

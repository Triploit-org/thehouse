#include <algorithm>
#include <string>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>

#include "todorf.h"

using namespace std;
void part1();
int main(int argc, char* argv[]) {

    print("  _____ _            _   _");
    print(" |_   _| |__   ___  | | | | ___  _   _ ___  ___");
    print("   | | | '_ \\ / _ \\ | |_| |/ _ \\| | | / __|/ _ \\");
    print("   | | | | | |  __/ |  _  | (_) | |_| \\__ \\  __/");
    print("   |_| |_| |_|\\___| |_| |_|\\___/ \\__,_|___/\\___|");


  	//print("\tThE hOuSE");
    //print("\t=========");
  	z:
  	print("\nWenn du einen Spielstand laden moechtest, tippe \"laden\" ein.\n""Oder, wenn bereit zum Spielen, dann \"fertig\" schreiben und Enter...");
    //print("Laden von Spielstaenden nocht nicht vollstaendig unterstuetzt!");
    cin.sync();
    cout << "> ";
	  cin >> obj.tmp;

    clear();

  	string args[300];
  	int i = 0;
  	stringstream ssin(obj.tmp);

  	while (ssin.good() && i < 300)
  	{
  		ssin >> args[i];
  		++i;
  	}

 	  if (args[0].find("a-b-e") == 0)
  	{
  		print("Jaja, ist ja gut Meister Survari...\nHier hast ne Prompt:");
  		inhaus();
  	}
    else if (args[0].find("lade") == 0)
    {
      load_game("user.th");
      part1();
	}
	else if (args[0].find("fert") == 0)
	{
		part1();
  }
  else
  {
    print("Option steht nicht zur Verfuegung!");
    goto z;
  }
  cout << endl;
  return 0;
}

void part1() {
  cout << "Hi! Ich, der Erzaehler, werde dich durch" << endl;
  cout << "diese kleine Story fuehren..." << endl;
  cout << "Lass uns erstmal mit dir beginnen, wie heisst du?" << endl;
  cout << "Name: ";
  cin >> obj.name;

  cout << "Ok, hallo " << obj.name << "! Ich will mal" << endl;
  cout << "nicht so sein und mich auch vorstellen!" << endl;
  cout << "Mein Name ist Survari und ich bin der" << endl;
  cout << "Erzaehler dieser Geschichte. Aber nun Fangen wir an." << endl;

  cout << endl << obj.name << ", jetzt geht es los...\n" << endl;
  //cout << "Tipp: \n\tGib nur Zahlen ein, sonnst stuertzt das \n\tSpiel ab und der Spielstand \n\tgeht verloren!" << endl;
    cout << "\nDu Stehst auf einer Strasse, es ist fast Dunkel.\nDu brauchst einen Unterschlupf!\nRechts von dir liegen Felder, so weit das Auge reicht.\nLinks siehst du ein Dorf, vielleicht einen Kilometer weit weg.\nDa du nun seelenverlassen dort stehst und nicht vom Fleck kommst musst\ndu dich nun entscheiden.\nWaehle aus:" << endl;
    gleich();
    cout << " 1) Uebers Feld gehen" << endl;
    cout << " 2) Zum Dorf wandern" << endl;
    cout << " 3) Auf Mitfahrgelegenheit warten" << endl;
    gleich();

    obj.ans = getans();

    if (obj.ans == 1)
    {
        print("Du machst dich nun auf dem Weg zum Feld...");
        print("Ueberquerst es ganz vorsichtig um nicht im Matsch auszurutschen..");
        print("*PLATSCH*");
        print("Und schon liegst du im Matsch!");
        print("und nicht nur das, du hast dir als du");
        print("hingefallen bist auch noch den Kopf aufgeschlagen....");
        obj.matsch = true;
        indorf();
    }
    else if (obj.ans == 2)
    {
      indorf();
    }
    else if (obj.ans == 883)
    {
      inhaus();
    }
    else
    {
        print("Du siehst da schon ein Auto, also hast du dich");
        print("entschlossen zu warten und stellst dich in den Weg des Autos,");
        print("aber das Auto haelt nicht an, es wird sogar");
        print("schneller! Du versuchst auszuweichen...");
        gleich();
        print("\tDEAD");
        gleich();
    }
}

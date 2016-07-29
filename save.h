#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fstream>

#include "attack.h"

void inhaus();
int indorf();

void load_game(string file)
{
  string src;
  ifstream f;
	int is = 0;
	int line = 0;

  f.open(file.c_str());
  while (std::getline(f, src))
  {
  	line++;
    if(StartsWith(src, "name"))
    {
      string nam = src;
      replace(nam, "name ", "");
      obj.name = nam;
      //cout << "Name: " << nam << endl;
			//print("Hallo Spieler!");
			is++;
    }
    else if (StartsWith(src, "inHaus"))
    {
			if (is == 19)
			{
				print("Spielstand geladen!");
			}
			else
			{
				print("Spielstand geladen, jedoch\nist die Speicherdatei defekt!");
				cout << is << endl;
			}
      //print("Letzte Funktion geladen!");
      inhaus();
    }
    else if (StartsWith(src, "inDorf"))
    {
      //print("Letzte Funktion geladen!");
      indorf();
    }
    else if (StartsWith(src, "item"))
    {
			string item = src;
      replace(item, "item ", "");
      obj.Item = item;
			//cout << "Item: " << item << endl;
			//print("Items geladen!");
			is++;
    }
    else if (StartsWith(src, "posF"))
    {
			string position = src;
			replace(position, "posF ", "");
			obj.aktPos = position;
      //cout << "Position: " << position << endl;
			//print("Spielerposition geladen!");
			is++;
    }
    else if (StartsWith(src, "wunten"))
    {
			string position = src;
			replace(position, "wunten ", "");
			obj.wUnten = position;
      //cout << "wUnten: " << position << endl;
			//print("Position \"WU\" geladen!");
			is++;
    }
    else if (StartsWith(src, "wbadezimmer"))
    {
			string position = src;
			replace(position, "wbadezimmer ", "");
			obj.wBadezimmer = position;
			//cout << "WBad: " << position << endl;
			//print("Position \"WB\" geladen!");
			is++;
    }
    else if (StartsWith(src, "wkueche"))
    {
			string position = src;
			replace(position, "wkueche ", "");
			obj.wKueche = position;
			//cout << "WKueche: " << position << endl;
			//print("Position \"WK\" geladen!");
			is++;
    }
    else if (StartsWith(src, "wwohnzimmer"))
    {
			string position = src;
			replace(position, "wwohnzimmer ", "");
			obj.wWohnzimmer = position;
			//cout << "WWohnzimmer: " << position << endl;
			//print("Position \"WW\" geladen!");
			is++;
    }
    else if (StartsWith(src, "poszettel"))
    {
			string position = src;
			replace(position, "poszettel ", "");
			obj.posZettel = position;
			//cout << "pZ: " << position << endl;
			//print("Position \"Z\" geladen!");
			is++;
    }
		else if (StartsWith(src, "possls"))
    {
			string position = src;
			replace(position, "possls ", "");
			obj.posSls = position;
			//cout << "pS: " << position << endl;
			//print("Position \"S\" geladen!");
			is++;
    }
		else if (StartsWith(src, "posrobe"))
    {
			string position = src;
			replace(position, "posrobe ", "");
			obj.posRobe = position;
			//cout << "pR: " << position << endl;
			//print("Position \"R\" geladen!");
			is++;
    }
		else if (StartsWith(src, "posfeder"))
    {
			string position = src;
			replace(position, "posfeder ", "");
			obj.posFeder = position;
			is++;
    }
		else if (StartsWith(src, "posschaedl"))
    {
			string position = src;
			replace(position, "posschaedl ", "");
			obj.posSchaedel = position;
			is++;
    }
		else if (StartsWith(src, "posstein"))
    {
			string position = src;
			replace(position, "posstein ", "");
			obj.posStein = position;
			is++;
    }
		else if (StartsWith(src, "posziege"))
    {
			string position = src;
			replace(position, "posziege ", "");
			obj.posZiegenhorn = position;
			is++;
    }
		else if (StartsWith(src, "posschwert"))
    {
			string position = src;
			replace(position, "posschwert ", "");
			obj.posSchwert = position;
			is++;
    }
		else if (StartsWith(src, "posapfel"))
    {
			string position = src;
			replace(position, "posapfel ", "");
			obj.posApfel = position;
			is++;
    }
		else if (StartsWith(src, "possat"))
    {
			string position = src;
			replace(position, "possat ", "");
			obj.posSatan = position;
			is++;
    }
		else if (StartsWith(src, "gid"))
    {
			string position = src;
			replace(position, "gid ", "");
			obj.gesIsDead = position;
			is++;
    }
		else if (StartsWith(src, "tuer"))
    {
			string position = src;
			replace(position, "tuer ", "");
			obj.NebenTuer = position;
			//cout << "Tuer: " << position << endl;
			//print("TA geladen!");
			is++;
    }
    else if (StartsWith(src, "#"))
    {
      // Wenn die Zeile mit einem # beginnt, ist dies ein Kommentar
    }
    else
    {
    	cout << "USERTH: Da ist ein Error in Zeile " << line << endl;
	  }
  }

}

void save_game()
{
	if (remove("user.th") != 0)
	{
		print("Es konnte nicht gespeichert werden\nda die Datei \"user.th\" nicht geloescht werden konnte! \nBitte tun sie dies manuell!");
	}
	ofstream datei("user.th", ios::app);
	if(!datei.fail())
	{
			print("Speichern...");
			datei << "name " << obj.name << endl;
			//print("N");
			datei << "posF " << obj.aktPos << endl;
			//print("P");
			datei << "item " << obj.Item << endl;
			//print("I");
			datei << "wunten " << obj.wUnten << endl;
			//print("WU");
			datei << "wkueche " << obj.wKueche << endl;
			//print("WK");
			datei << "wbadezimmer " << obj.wBadezimmer << endl;
			//print("WB");
			datei << "wwohnzimmer " << obj.wWohnzimmer << endl;
			//print("PZ");
			datei << "poszettel " << obj.posZettel << endl;
			//print("PSLS");
			datei << "possls " << obj.posSls << endl;
			//print("PR");
			datei << "posrobe " << obj.posRobe << endl;
			//print("PSC");
			datei << "posschwert " << obj.posSchwert << endl;
			//print("PS");
			datei << "posschaedl " << obj.posSchaedel << endl;
			//print("PST");
			datei << "posstein " << obj.posStein << endl;
			//print("PZI");
			datei << "posziege " << obj.posZiegenhorn << endl;
			//print("PA");
			datei << "posapfel " << obj.posApfel << endl;
			//print("PSA");
			datei << "possat " << obj.posSatan << endl;
			//print("PF");
			datei << "posfeder " << obj.posFeder << endl;
      //print("PAH");
			datei << "tuer " << obj.NebenTuer << endl;
      //print("GID");
			datei << "gid " << obj.gesIsDead << endl;
			//print("T");
			datei << "inHaus" << endl;
			//print("IH");
			print("Fertig!");

			datei.close();
	}
	else
	{
		print("Konnte keine neue Spiel-Datei erstellen!");
	}
}

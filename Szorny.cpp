#include "Szorny.h"

Szorny::Szorny(std::string nev, int hp, int dmg){
    this->nev = nev;
    this->maxhp = hp;
    this->hp = maxhp;
    this->dmg = dmg;
}

int Szorny::getDmg()const {
	return dmg;
}

int Szorny::getMaxHp()const {
	return hp;
}

int Szorny::getHp()const {
	return hp;
}

std::string Szorny::getName()const {
	return nev;
}

void Szorny::tamad(Szorny & a) {
	a.hp = a.hp - this->dmg;
	if (a.hp < 0) a.hp = 0;
}

Szorny Szorny::parseUnit(const std::string &fajlnev) {
    /*int hp, dmg, keyv;
    std::string name;
    std::string::size_type found;
    std::ifstream f(fajlnev);
    if (!f.good()) throw 56;

    std::string sor;
    std::string tmp;
    std::string::size_type i;

    while (!f.eof()) {
        getline(f, sor);
        keyv = 0;
        found = sor.find('"');
        if (found!=std::string::npos) {
            i = found+1;
            tmp = "";
            while (sor[i]!='"') {
                tmp = tmp+sor[i];
                i++;
            }

            if (tmp == "name") keyv = 1;
            if (tmp == "hp") keyv = 2;
            if (tmp == "dmg") keyv = 3;
        }

        found = sor.find(':');
        if (found!=std::string::npos) {
            i = found+1;
            tmp = "";
            while (sor[i]!=',' && i!=sor.size()) {
                if (sor[i]=='"' || sor[i]==' ') {
                    i++;
                } else {
                    tmp = tmp+sor[i];
                    i++;
                }
            }

            switch(keyv) {
                case 1: name = tmp;
                    break;
                case 2: hp = stoi(tmp);
                    break;
                case 3: dmg = stoi(tmp);
                    break;
                default: throw 57;
                    break;

            }
        }
    }
    f.close();

    return Szorny(name, hp, dmg);*/

    std::string tmpString, name = "";
    double health, damage = 0;
    std::string line = "" , searchTerm;
    std::size_t searchResult;
    std::ifstream file(fajlnev);
    int linecounter = 0;

    if(!file.is_open()){
        throw "The file is missing";
    }

    while (std::getline(file,line))
    {
        searchTerm = "\"name\" : ";
        searchResult = line.find(searchTerm);
        if(searchResult != std::string::npos){
        tmpString = line.substr((searchResult+searchTerm.size()+1));
        if(linecounter<=2){
        tmpString.resize(tmpString.size()-2);
        }
        else{
            tmpString.resize(tmpString.size()-1);
        }
        name = tmpString;
        }

        searchTerm ="\"dmg\" : ";
        searchResult = line.find(searchTerm);
        if(searchResult != std::string::npos){
            tmpString = line.substr(searchResult+searchTerm.size());
            damage = std::stod(tmpString);
        }
        searchTerm = "\"hp\" : ";
        searchResult = line.find(searchTerm);
        if(searchResult != std::string::npos){
            tmpString = line.substr(searchResult+searchTerm.size());
            health = std::stod(tmpString);
        }
        linecounter++;
    }
    return Szorny(name, health, damage);
}

Szorny& Szorny::operator=(const Szorny &szorny) {
    this->maxhp = szorny.getMaxHp();
    this->hp = szorny.getHp();
    this->dmg = szorny.getDmg();
    this->nev = szorny.getName();
    return *this;
}

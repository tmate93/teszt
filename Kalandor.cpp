#include "Kalandor.h"
#include <math.h>

#define XPTOLVL 100

Kalandor::Kalandor(std::string nev, int hp, int dmg) : Szorny(nev, hp, dmg) {
    lvl = 1;
    xp = 0;
}

Kalandor::Kalandor(Szorny sz)
	: Szorny(sz.getName(), sz.getHp(), sz.getDmg()), xp(0), lvl(1){}

int Kalandor::getXp()const {
	return xp;
}

int Kalandor::getLvl()const {
	return lvl;
}

void Kalandor::lvlUp(int xptoLvl) {
    xp = xp-xptoLvl;
    lvl++;
    maxhp = floor(maxhp*1.1);
    hp = maxhp;
    dmg = floor(dmg*1.1);
}

void Kalandor::xpGain() {
    xp += dmg;
    while (xp >= XPTOLVL) {
        lvlUp(XPTOLVL);
    }
}

void Kalandor::tamad(Szorny & a) {
	a.hp = a.hp - this->dmg;
	xpGain();
	if (a.hp < 0) a.hp = 0;
}

Kalandor Kalandor::parseUnit(std::string fajlnev) {
    int hp, dmg, keyv;
    std::string name;
    std::string::size_type found;
    std::ifstream f(fajlnev);
    if (!f.good()) throw 56;
    else {
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

        return Kalandor(name, hp, dmg);
    }
}

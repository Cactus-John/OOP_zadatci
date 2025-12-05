#include <iostream>
#include <string>
using namespace std;

class Zrno {
public:
    string boja;
    float promjer;
};

class Pijesak {
public:
    int kolicina;
    Zrno* zrno;
    Pijesak(int _kolicina) : kolicina(_kolicina) {
        // dinamički alocirajte polje 'zrno'
        zrno = new Zrno[kolicina];
    }

    ~Pijesak() {
        // ?
        delete[] zrno;
    }

    //kopirni konstruktor
    Pijesak(const Pijesak& p) {
        kolicina = p.kolicina;
        zrno = new Zrno[kolicina];
        for (int i = 0; i < kolicina; i++)
            zrno[i] = p.zrno[i]; 

        cout << endl << "\tKopirni konstruktor POZVAN" << endl;
    }

    //operator pridruzivanja (kopiranje)
    Pijesak& operator = (const Pijesak& p) {
        if (this != &p) {
            delete[] zrno;
            kolicina = p.kolicina;
            zrno = new Zrno[kolicina];
            for (int i = 0; i < kolicina; i++)
                zrno[i] = p.zrno[i];
        }

        cout << endl << "\tOperator kopiranja POZVAN" << endl;
        return *this;
    }

    //konstruktor prijenosa
    Pijesak(Pijesak&& p) {
        kolicina = p.kolicina;
        zrno = p.zrno;
        p.kolicina = 0;
        p.zrno = NULL;

        cout << endl << "\tKonstruktor prijenosa POZVAN" << endl;
    }

    //operator pridruzivanja (prijenos)
    Pijesak& operator = (Pijesak&& p) {
        delete[] zrno;
        kolicina = p.kolicina;
        zrno = p.zrno;
        p.kolicina = 0;
        p.zrno = NULL;
     
        cout << endl << "\tOperator prijenosa POZVAN" << endl;
        return *this;
    }
};

int main() 
{
    Pijesak igraliste(1000000);
    cout << "Na igralistu ima " << igraliste.kolicina << " zrna pijeska!\n" << endl;

    cout << "--- Demonstracija kopirnog konstruktora ---" << endl;
    Pijesak kopirni(igraliste); 

    cout << "\n--- Demonstracija konstruktora prijenosa ---" << endl;
    Pijesak prijenosni(move(igraliste));

    cout << "\n--- Demonstracija operatora kopiranja ---" << endl;
    Pijesak kopija2(1);
    kopija2 = kopirni;

    cout << "\n--- Demonstracija operatora prijenosa ---" << endl;
    Pijesak drugi(10);
    drugi = move(kopirni);

    return 0;
}
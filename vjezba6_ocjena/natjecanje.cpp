#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

// Klasa za iznimke
class NatjecanjeIznimka {
public:
    string opis() const {
        return "Broj natjecatelja je prevelik!";
    }
};

// Klasa Natjecatelj
class Natjecatelj {
private:
    string ime;
    int bodovi;

public:
    static int ukupnoBodova;
    static int brojNatjecatelja;

    Natjecatelj(string _ime = "", int _bodovi = 0) : ime(_ime), bodovi(_bodovi) {
        ukupnoBodova += bodovi;
        brojNatjecatelja++;
    }

    string getIme() const { return ime; }
    int getBodovi() const { return bodovi; }

    static double getProsjecnoBodova() {
        return (brojNatjecatelja == 0) ? 0.0 : double(ukupnoBodova) / brojNatjecatelja;
    }
};

int Natjecatelj::ukupnoBodova = 0;
int Natjecatelj::brojNatjecatelja = 0;

// Klasa Natjecanje
class Natjecanje {
private:
    string naziv;
    int maxNatjecatelja;
    vector<Natjecatelj> natjecatelji;

public:
    Natjecanje(string _naziv, int _maxNatjecatelja) : naziv(_naziv), maxNatjecatelja(_maxNatjecatelja) {}

    Natjecanje& operator+=(const Natjecatelj& n) {
        if (natjecatelji.size() >= maxNatjecatelja) {
            throw NatjecanjeIznimka();
        }
        natjecatelji.push_back(n);
        return *this;
    }

    operator double() const {
        if (natjecatelji.empty()) return 0.0;
        int ukupno = 0;
        for (int i = 0; i < natjecatelji.size(); i++) {
            ukupno += natjecatelji[i].getBodovi();
        }
        return double(ukupno) / natjecatelji.size();
    }

    friend ostream& operator<<(ostream& izlaz, const Natjecanje& n) {
        izlaz << "Natjecanje: " << n.naziv << endl;
        for (int i = 0; i < n.natjecatelji.size(); i++) {
            izlaz << i + 1 << ". " << n.natjecatelji[i].getIme() << " - Bodovi: " << n.natjecatelji[i].getBodovi() << endl;
        }
        return izlaz;
    }
};

int main() {
    Natjecanje streljastvo("Streljastvo", 2);
    try {
        Natjecatelj Ante("Ante", 6);
        Natjecatelj Ivana("Ivana", 8);

        streljastvo += Ante; // Dodavanje Ante
        streljastvo += Ivana; // Dodavanje Ivane

        streljastvo += Natjecatelj("Mario", 7); // Ovo baca iznimku
    }
    catch (const NatjecanjeIznimka& e) {
        cout << "Iznimka: " << e.opis() << endl;
    }

    // Jo  jedno natjecanje
    Natjecanje nogomet("Nogomet", 3);

    // Kreiranje natjecatelja za drugo natjecanje
    Natjecatelj Ivan("Ivan", 9);
    Natjecatelj Ana("Ana", 7);
    Natjecatelj Luka("Luka", 8);

    // Dodavanje natjecatelja u drugo natjecanje
    nogomet += Ivan;
    nogomet += Ana;
    nogomet += Luka;

    // Ispis podataka o natjecanjima
    cout << streljastvo;
    cout << "Prosjek bodova na natjecanju 'Streljastvo': " << double(streljastvo) << endl;

    cout << nogomet;
    cout << "Prosjek bodova na natjecanju 'Nogomet': " << double(nogomet) << endl;

    // Globalni prosjek bodova svih natjecatelja
    cout << "Globalni prosjek bodova svih natjecatelja: " << Natjecatelj::getProsjecnoBodova() << endl;

    return 0;
}

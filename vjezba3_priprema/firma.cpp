#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Zaposlenik {
private:
    string ime, prezime;
public:
    Zaposlenik(string i, string p) : ime(i), prezime(p) {
        cout << "Zaposlenik constructor called" << endl;
    }

    ~Zaposlenik() {
        cout << "Zaposlenik destructor called" << endl;
    }

    void setIme(string novoIme) { ime = novoIme; }
    void setPrezime(string novoPrezime) { prezime = novoPrezime; }

    string getIme() const { return ime; }
    string getPrezime() const { return prezime; }
};

class Firma {
private:
    string naziv, OIB, adresa;
public:
    vector<Zaposlenik> zaposlenici;
    void setAdresa(string novaAdresa) { adresa = novaAdresa; }

    void setNaziv(string noviNaziv) {
        if (noviNaziv.length() < 5) {
            cout << "Unesi barem 5 ili više znakova!!!" << endl;
            return;
        }
        naziv = noviNaziv;
    }

    void setOIB(string o) {
        if (o.size() != 11 || o.find_first_not_of("0123456789") != string::npos) {
            cout << "OIB mora imati tocno 11 znamenki!" << endl;
            return;
        }
        OIB = o;
    }
    
    string getNaziv() const { return naziv; }
    string getOIB() const { return OIB; }
    string getAdresa() const { return adresa; }

    void dodajZaposlenika1(Zaposlenik z) {
        zaposlenici.push_back(z);
    }
    void dodajZaposlenika2(Zaposlenik& z) {
        zaposlenici.push_back(z);
    }
    void dodajZaposlenika3(Zaposlenik* z) {
        zaposlenici.push_back(*z);
    }

    void ispisSvihZaposlenika(const vector<Zaposlenik>& zap) {
        for (int i = 0; i < zap.size(); i++) {
            cout << zap[i].getIme() << "\t" << zap[i].getPrezime() << endl;
        }
    }

    Zaposlenik nadjiZaposlenika1(string ime, string prezime) {
        for (int i = 0; i < zaposlenici.size(); i++) {
            if (zaposlenici[i].getIme() == ime && zaposlenici[i].getPrezime() == prezime)
                return zaposlenici[i];
        }
    }

    Zaposlenik* nadjiZaposlenika2(string ime, string prezime) {
        for (int i = 0; i < zaposlenici.size(); i++) {
            if (zaposlenici[i].getIme() == ime && zaposlenici[i].getPrezime() == prezime)
                return &zaposlenici[i];
        }
    }

    Zaposlenik& nadjiZaposlenika3(string ime, string prezime) {
        for (int i = 0; i < zaposlenici.size(); i++) {
            if (zaposlenici[i].getIme() == ime && zaposlenici[i].getPrezime() == prezime)
                return zaposlenici[i];
        }
    }
};

int main() 
{
    Firma firma;
    firma.setNaziv("Infobip");
    firma.setOIB("12341678901");
    firma.setAdresa("Istarska 157");

    Zaposlenik z1("Ivica", "Patrun");
    Zaposlenik z2("Ivan", "Bosnjak");
    Zaposlenik z3("Danijel", "Jurkovic");

    cout << "\nDodavanje zaposlenika" << endl;
    firma.dodajZaposlenika1(z1);     
    firma.dodajZaposlenika2(z2);     
    firma.dodajZaposlenika3(&z3);

    cout << "\nPopis svih zaposlenika" << endl;
    firma.ispisSvihZaposlenika(firma.zaposlenici);

    cout << "\n\t Pronalazenje i izmjena" << endl;

    Zaposlenik izmjena1 = firma.nadjiZaposlenika1("Ivica", "Patrun");
    izmjena1.setIme("Luka");
    izmjena1.setPrezime("Galunic"); //nece promjenit ime niti prezime
  
    Zaposlenik* izmjena2 = firma.nadjiZaposlenika2("Ivan", "Bosnjak");
    if (izmjena2 != nullptr) //sprjecava da se program ne srusi u slucaju da ivan bosnjak ne postoji u vektoru zaposlenici
        izmjena2->setPrezime("Kolic");      //promjenit ce prezime iz Bosnjak u Kolic

    Zaposlenik& izmjena3 = firma.nadjiZaposlenika3("Danijel", "Jurkovic"); //promjenit ce ime iz Danijel na Lovro
    izmjena3.setIme("Lovro");

    cout << "\nPopis nakon izmjena" << endl;
    firma.ispisSvihZaposlenika(firma.zaposlenici);

    cout << "\nKraj programa." << endl;
    return 0;
}


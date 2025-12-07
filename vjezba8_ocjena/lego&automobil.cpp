#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Proizvod {
protected:
	string naziv;
	double cijena = 0;

public:
	Proizvod(string _naziv, double _cijena) : naziv(_naziv), cijena(_cijena) {}

	virtual double getKoefKvalitete() const = 0;
	virtual void print() = 0;
};

class LegoIgracka : public Proizvod {
public:
	int brKomada = 0;
	LegoIgracka(string naziv, double cijena, int _brKomada) : Proizvod(naziv, cijena), brKomada(_brKomada) {}

	void print()  override {
		cout << "Lego igracka: " << naziv << ", Cijena: " << cijena << ", Broj komada: " << brKomada << endl;
	}

	double getKoefKvalitete() const override {
		return brKomada / cijena;
	}
};

class Automobil : public Proizvod {
public:
	int godProizvodnje;
	double maxBrzina = 0;

	Automobil(string naziv, double cijena, int _godProizvodnje, double _maxBrzina) :
		Proizvod(naziv, cijena), godProizvodnje(_godProizvodnje), maxBrzina(_maxBrzina) {
	}

	void print() override {
		cout << "Automobil: " << naziv << ", Cijena: " << cijena << ", Godina proizvodnje: " << godProizvodnje << ", Max brzina: " << maxBrzina << endl;
	}

	double getKoefKvalitete() const override {
		return 1.0 / (2015 - godProizvodnje) * maxBrzina / 100.0 * cijena / 100000.0;
	}
};

int main()
{
	vector<Proizvod*> proizvodi = {

		new LegoIgracka("Star Wars - Millenium Falcon", 2250.99, 756), //1. parametar = naziv, 2. parametar = cijena, 3. parametar = br. komada
		new Automobil("BMW", 51230, 2013, 207.34), //1. parametar = naziv, 2. parametar = cijena, 3. parametar = god. proizvodnje, 4. parametar = max brzina
		new LegoIgracka("Vlakic na upravljanje", 1750.99, 877),
		new Automobil("Yugo 45", 14500, 1988, 127.88),

	};

	for (int i = 0; i < 4; i++) 
		proizvodi[i]->print();
	
	double maxKoeficijent = -1.0;
	Proizvod* najkvalitetnijiProizvod = nullptr;

	for (int i = 0; i < proizvodi.size(); i++) {
		double koeficijent = proizvodi[i]->getKoefKvalitete();
		if (koeficijent > maxKoeficijent) {
			maxKoeficijent = koeficijent;
			najkvalitetnijiProizvod = proizvodi[i];
		}
	}
	cout << "\nProizvod s najvecim koeficijentom kvalitete:" << endl;
	najkvalitetnijiProizvod->print();
	cout << "Koeficijent kvalitete: " << maxKoeficijent << endl;

	for (int i = 0; i < proizvodi.size(); i++)
		delete proizvodi[i];

	return 0;
}

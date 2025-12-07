#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Cokolada {
public:
	string naziv;
	int tezina = 80;
	Cokolada(string _naziv) : naziv(_naziv) {}

	virtual double getCijena() = 0;
	virtual int getTezina() = 0;

	virtual ~Cokolada() {
		cout << "Destruktor Cokolada" << endl;
	}
};

class Mlijecna : public Cokolada {
public:
	int tezina = 200;
	double cijena = 6.5;
	Mlijecna(string naziv) : Cokolada(naziv){}
	
	double getCijena() override {
		return cijena;
	}

	int getTezina() override {
		return tezina;
	}

	~Mlijecna() {
		cout << "Destruktor Mlijecna" << endl;
	}
};

class Crna : public Cokolada {
public:
	double cijena = 7;
	int tezina = 100;
	Crna(string naziv) : Cokolada(naziv) {}

	double getCijena() override {
		return cijena;
	}

	int getTezina() override {
		return tezina;
	}

};

class CrnaBrusnica : public Crna {
public:
	double cijena = 8;
	int tezina = 80;
	CrnaBrusnica(string naziv) : Crna(naziv) {}

	double getCijena() override {
		return cijena;
	}

	int getTezina() override {
		return tezina;
	}

};

double ProsjecnaCijena(const vector<Cokolada*>& tvornica) {
	if (tvornica.empty()) 
		return 0.0;
  
	double ukupno = 0;
	for (int i = 0; i < tvornica.size(); i++)
		ukupno += tvornica[i]->getCijena();

	double prosjek = ukupno / tvornica.size();
	return prosjek;
}


int main() {

	Mlijecna jedan("Milka");
	Crna dva("Kinder");
	CrnaBrusnica tri("Brusn");

	cout << "Tezina Milka cokolade: " << jedan.getTezina() << endl;
	cout << "Tezina Kinder cokolade: " << dva.getTezina() << endl;
	cout << "Tezina Brusn cokolade: " << tri.getTezina() << endl;

	vector<Cokolada*> tvornica = { &jedan , &dva, &tri };

	cout << "Cijena Milka cokolade: " << jedan.getCijena() << endl;
	cout << "Cijena Kinder cokolade: " << dva.getCijena() << endl;
	cout << "Cijena Brusn cokolade: " << tri.getCijena() << endl;

	cout << "Prosjecna cijena cokolada: " << ProsjecnaCijena(tvornica) << endl;

	Cokolada* c = new Mlijecna("Dorina");
	delete c;

	return 0;
}

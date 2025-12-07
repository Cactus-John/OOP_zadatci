#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Fotografija {
public:
	string opis;
	double cijena;
	int brojFotografija;

	Fotografija() {}
	Fotografija(string _opis, double _cijena, int _brojFotografija) :
		opis(_opis), cijena(_cijena), brojFotografija(_brojFotografija) {
	}

	virtual ~Fotografija() {
		cout << "Destruktor Fotografija" << endl;
	}
};

class Fotograf {
public:
	string ime;

	Fotograf() {}
	Fotograf(string _ime) : ime(_ime) {}

	virtual double getCijena() = 0;

	void OpisFotografa() {
		cout << "fotograf" << endl;
	}
};

class FotografAgencije : public Fotograf, public Fotografija {
public:

	FotografAgencije(string ime) : Fotograf(ime) {}

	FotografAgencije(string opis, double cijena, int brojFotografija) :
		Fotografija(opis, cijena, brojFotografija) {
	}

	double getCijena() override {
		return (brojFotografija * cijena) * 0.75;
	}

	~FotografAgencije() {
		cout << "Destruktor FotografAgencije" << endl;
	}

	void OpisFotografa() {
		cout << "Ovo je fotograf agencije" << endl;
	}
};

class SamostalniFotograf : public Fotograf, public Fotografija {
public:

	SamostalniFotograf(string opis, double cijena, int brojFotografija) :
		Fotografija(opis, cijena, brojFotografija) {
	}

	double getCijena() override {
		return brojFotografija * cijena;
	}

	~SamostalniFotograf() {
		cout << "Destruktor SamostalniFotograf" << endl;
	}

	void OpisFotografa() {
		cout << "Ovo je samostalni fotograf " << endl;
	}
};

double ukupnaCijenaIzradjenihFotografija(vector<Fotograf*> fotografi) {
	double ukupno = 0;
	for (int i = 0; i < fotografi.size(); i++)
		ukupno += fotografi[i]->getCijena();

	return ukupno / fotografi.size();
}

int main()
{
	FotografAgencije fa("pejsaz", 1000, 4);
	SamostalniFotograf sf("portret", 1000, 4);

	vector<Fotograf*> fotografi = { &fa, &sf };
	cout << "Prosjecna cijena fotografija: " << ukupnaCijenaIzradjenihFotografija(fotografi) << endl;

	FotografAgencije f1("kip", 3000, 2);
	f1.OpisFotografa();
	sf.OpisFotografa();
	FotografAgencije p("Pero");
	return 0;
}

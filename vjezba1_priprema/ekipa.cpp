#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Igrac {
public:
	string ime, prezime;
	int broj, cijena;
	Igrac(string _ime, string _prezime) {
		ime = _ime;
		prezime = _prezime;
	}

	void ispisi() {
		cout << "Igrac: " << ime << " " << prezime << " " << broj << " " << " " << cijena << endl;
	}
};

bool usporedba(Igrac a, Igrac b) {
	return a.broj < b.broj;
}

class Ekipa {
public:
	string naziv;
	vector<Igrac> igraci;
	void dodajIgraca(Igrac igrac) {
		igraci.push_back(igrac);
	}

	void ispisi() {
		sort(igraci.begin(), igraci.end(), usporedba);
		cout << "Ekipa: " << naziv << endl;

		for (int i = 0; i < igraci.size(); i++) {
			cout << "Igrac: " << igraci[i].ime << " " << igraci[i].prezime << " Broj: " << igraci[i].broj << " Cijena: " << igraci[i].cijena << endl;
		}
	}
	Igrac dohvatiNajskupljeg() {
		Igrac najskuplji = igraci[0];
		for (int i = 0; i < igraci.size(); i++) {
			if (igraci[i].cijena > najskuplji.cijena)
				najskuplji = igraci[i];
		}
		return najskuplji;
	}

	int ukupnaCijena() {
		int ukupno = 0;
		for (int i = 0; i < igraci.size(); i++) {
			ukupno += igraci[i].cijena;
		}

		return ukupno;
	}

	double prosjecnaCijena() {
		double prosjecno = 0;
		int ukupno = 0;
		for (int i = 0; i < igraci.size(); i++) {
			ukupno += igraci[i].cijena;
		}

		prosjecno = ukupno / igraci.size();
		return prosjecno;
	}
};

int main()
{
	Ekipa ekipa;
	ekipa.naziv = "Tim raketa";
	Igrac i1("Luka", "Modric");
	i1.broj = 10;
	i1.cijena = 50000000;
	ekipa.dodajIgraca(i1);
	Igrac i2("Mario", "Mandzukic");
	i2.broj = 9;
	i2.cijena = 27000000;
	ekipa.dodajIgraca(i2);
	Igrac i3("Darijo", "Srna");
	i3.broj = 11;
	i3.cijena = 14500000;
	ekipa.dodajIgraca(i3);
	ekipa.ispisi();
	Igrac najskuplji = ekipa.dohvatiNajskupljeg();
	cout << "Najskuplji igrac: ";
	najskuplji.ispisi();
	cout << "Ukupna cijena svih igraca: " << ekipa.ukupnaCijena() << endl;
	cout << "Prosjecna cijena jednog igraca: " << ekipa.prosjecnaCijena() << endl;
}

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Nogomet {
protected:
	string ime;
	string prezime;
	double osnovica = 0;

public:
	Nogomet(string _ime, string _prezime, double _osnovica) : ime(_ime), prezime(_prezime), osnovica(_osnovica) {}

	virtual void ispis() = 0;
	virtual double izracunPlace() = 0;
};

class Igrac : public Nogomet {
public:
	int brojGolova = 0;
	int brojAsistencija = 0;

	Igrac(string ime, string prezime, double osnovica) : Nogomet(ime, prezime, osnovica) {}

	void dodajGolove(int n) {
		brojGolova += n;
	}

	void dodajAsistencije(int n) {
		brojAsistencija += n;
	}

	void ispis() override {
		cout << ime << " " << prezime << " - Golova: " << brojGolova << ", Asistencija: "
			<< brojAsistencija << endl;
	}

	double izracunPlace() override {
		return osnovica + (brojGolova / 10) * 0.1 * osnovica + (brojAsistencija / 5) * 0.1 * osnovica;
	}

	int getOsnovica() const {
		return osnovica;
	}
};

class Trener : public Nogomet {
public:
	int brojPobjeda = 0;
	int brojRemija = 0;
	int brojIzgubljenih = 0;

	Trener(string ime, string prezime, double osnovica) : Nogomet(ime, prezime, osnovica) {}

	void dodajPobjede(int n) {
		brojPobjeda += n;
	}

	void dodajRemi(int n) {
		brojRemija += n;
	}

	void dodajIzgubljene(int n) {
		brojIzgubljenih += n;
	}

	void ispis() override {
		cout << ime << " " << prezime << " Omjer (W/D/L): " << brojPobjeda << " / " << brojRemija << " / " << brojIzgubljenih << endl;
	}

	double izracunPlace() override {
		return osnovica + (brojPobjeda / 5) * 0.1 * osnovica + (brojRemija / 10) * 0.1 * osnovica - (brojIzgubljenih / 8) * 0.1 * osnovica;
	}
};

int main()
{
	Igrac i("Luka", "Modric", 100000); //Ime, prezime, osnovica plaće
	i.dodajGolove(7);
	i.dodajAsistencije(12);
	i.ispis(); //Luka Modric - golova: 7, asistencija: 12
	cout << "Placa: " << i.izracunPlace() << endl; //Placa: 120000
	cout << "Osnovica: " << i.getOsnovica() << endl;

	Igrac i2("C", "Ronaldo", 234505);
	i2.dodajGolove(57);
	i2.dodajAsistencije(32);
	i2.ispis(); //C Ronaldo - Golova : 57, Asistencije : 32.
	cout << "Placa: " << i2.izracunPlace() << endl; //Placa : 492461

	Trener t1("Hose", "Murinjo", 143009); //Ime, prezime, osnovica plaće
	t1.dodajPobjede(88); //Dodati broj pobjeda (W)
	t1.dodajRemi(12); //Dodati broj neriješenih utakmica (D)
	t1.dodajIzgubljene(0); //Dodati broj izgubljenih (L)
	t1.ispis(); //Hose Murinjo - Omjer (W/D/L): 88 / 12 / 0
	cout << "Placa: " << t1.izracunPlace() << endl; //Placa: 400425

	t1.dodajPobjede(11);
	t1.dodajIzgubljene(47);
	t1.ispis(); //Hose Murinjo - Omjer (W/D/L): 99 / 12 / 47
	cout << "Placa: " << t1.izracunPlace() << endl; //Placa: 357523
}

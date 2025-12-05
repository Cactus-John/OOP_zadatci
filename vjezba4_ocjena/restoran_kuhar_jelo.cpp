#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Jelo {
public:
	string imejela;
	double cijena;
};
namespace Kuhari {
	class GlavniKuhar {

	private:
		string ime;
		string prezime;
		int brojJela;

	public:
		void setIme(string _ime);

		string getIme() const;

		void setPrezime(string _prezime);

		string getPrezime() const;

	};

	void GlavniKuhar::setIme(string _ime) {
		int i = 0;
		_ime[i] = toupper(_ime[i]);
		for (int i = 1; i < _ime.size(); i++) {
			_ime[i] = tolower(_ime[i]);
		}
		ime = _ime;
	}

	string GlavniKuhar::getIme() const {
		return ime;
	}

	void GlavniKuhar::setPrezime(string _prezime) {
		int i = 0;
		_prezime[i] = toupper(_prezime[i]);
		for (int i = 1; i < _prezime.size(); i++) {
			_prezime[i] = tolower(_prezime[i]);
		}
		prezime = _prezime;
	}
}

string Kuhari::GlavniKuhar::getPrezime() const {
	return prezime;
}

class Restoran {
public:
	string naziv;
	string adresa;
	string glKuhar;
	vector<Jelo*> jela;

	Restoran() {}

	Restoran(string _naziv, string _adresa, string _glKuhar) : naziv(_naziv), adresa(_adresa),
		glKuhar(_glKuhar) {
	}

	Restoran(const Restoran& r) {
		for (int i = 0; i < r.jela.size(); i++) {
			jela.push_back(new Jelo);
			*jela[i] = *r.jela[i];
		}
	}

	Restoran& operator = (const Restoran& r) {
		if (this != &r) {
			for (int i = 0; i < jela.size(); i++) {
				delete jela[i];
				jela.clear();
			}

			for (int i = 0; i < r.jela.size(); i++) {
				jela.push_back(new Jelo);
				*jela[i] = *r.jela[i];
			}
		}
		return *this;
	}

	Restoran(Restoran&& r) {
		for (int i = 0; i < r.jela.size(); i++) {
			jela.push_back(r.jela[i]);
			r.jela[i] = NULL;
		}
	}

	Restoran& operator = (Restoran&& r) {
		for (int i = 0; i < jela.size(); i++)
			delete jela[i];
		jela.clear();
		for (int i = 0; i < r.jela.size(); i++) {
			jela.push_back(r.jela[i]);
			r.jela[i] = NULL;
		}
		return *this;
	}

	~Restoran() {
		for (int i = 0; i < jela.size(); i++) {
			delete jela[i];
		}
	}

	Restoran& dodajJelo(Jelo* novo_jelo) {
		jela.push_back(novo_jelo);
		return *this;
	}
};

int main() {
	using namespace Kuhari;
	GlavniKuhar GlavniKuhar;

	Restoran r1("Maestral", "Nova Cesta", "Hesenberg");
	Restoran r2(r1);
	Restoran r3 = move(r2);

	Jelo* j1 = new Jelo();
	j1->imejela = "burek";
	j1->cijena = 5.0;

	Jelo* j2 = new Jelo();
	j2->imejela = "cevapi";
	j2->cijena = 30.0;  

	Restoran r4;
	r4.dodajJelo(j1).dodajJelo(j2);
}

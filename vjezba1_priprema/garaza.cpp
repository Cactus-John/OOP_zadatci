#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Predmet {
public:
    string naziv;
    int vrijednost;
};

class Garaza {
public:
    double sirina, duzina;
    string lokacija;
    string automatska_vrata;
    vector<Predmet> predmeti;
};

int main()
{
    vector<Garaza> garaze;
    int N;
    cout << "Unesite broj garaza (N): ";
    cin >> N;
    cin.ignore();

    for (int i = 0; i < N; i++) {
        Garaza pom;
        cout << "Unesite velicinu, lokaciju i podatak o vratima za " << i + 1 << ". garazu:" << endl;
        cin >> pom.sirina >> pom.duzina;
        cin.ignore();
        getline(cin, pom.lokacija);
        cin >> pom.automatska_vrata;
        garaze.push_back(pom);
    }

    int M;
    cout << "Unesite broj predmeta (M): ";
    cin >> M;

    for (int i = 0; i < M; i++) {
        Predmet pom;
        int redni_broj;
        cout << "Unesite redni broj garaze u koju spada " << i + 1 << ". predmet: ";
        cin >> redni_broj;
        cout << "Unesite naziv i vrijednost predmeta: ";
        cin >> pom.naziv >> pom.vrijednost;

        if (redni_broj > 0 && redni_broj <= garaze.size()) {
            garaze[redni_broj - 1].predmeti.push_back(pom);
        }
        else {
            cout << "Neispravan broj garaze!" << endl;
        }
    }

    cout << "\nIspis garaza i predmeta:\n";
    for (int i = 0; i < N; i++) {
        cout << i + 1 << ". " << garaze[i].lokacija << " " << garaze[i].sirina << "x" << garaze[i].duzina << " - predmeti: ";

        if (garaze[i].predmeti.empty()) {
            cout << "";
        }
        else {
            for (int j = 0; j < garaze[i].predmeti.size(); j++) {
                cout << garaze[i].predmeti[j].naziv << " (" << garaze[i].predmeti[j].vrijednost << "kn)";
                if (j < garaze[i].predmeti.size() - 1)
                    cout << ", ";
            }
        }
        cout << endl;
    }

    return 0;
}

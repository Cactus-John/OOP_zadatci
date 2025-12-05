#include <iostream>
using namespace std;

class Slika {
public:
    double cijena;
    static double suma;
    static int kolicina;
    Slika(double _cijena) : cijena(_cijena) {
        suma += _cijena;
        kolicina++;
    }

    static double ProsjecnaCijena() {
        return suma / kolicina;
    }
};

double Slika::suma = 0;
int Slika::kolicina = 0;

int main()
{
    Slika Slika1(2000); // 2000 eura
    Slika Slika2(3000); // 3000 eura
    Slika Slika3(1800); // 1800 eura

    cout << Slika::ProsjecnaCijena() << " eura"; // 2266.67 eura
}

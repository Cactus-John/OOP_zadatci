#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Cigla {  
public:
    int a, b, c;
    vector<int> cigla;

    Cigla(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {
        cigla.push_back(a);
        cigla.push_back(b);
        cigla.push_back(c);
    }

    void ispisi() {
        for (int i = 0; i < 3; i++)
            cout << cigla[i] << " ";
        cout << endl;
    }

    Cigla& operator+=(const Cigla& druga) {
        vector<int> ploha;
        vector<int> brid1;
        vector<int> brid2;
        int i = 0;
        int j = 0;

        //prolaz kroz a(1,2,3) i b(2,3,4)
        while (i < 3 && j < 3) {
            if (cigla[i] == druga.cigla[j]) {
                ploha.push_back(cigla[i]);
                i++; j++;
            }
            else if (cigla[i] < druga.cigla[j]) {
                brid1.push_back(cigla[i]);
                i++;
            }
            else {
                brid2.push_back(druga.cigla[j]);
                j++;
            }
        }
       
        while (i < 3)
            brid1.push_back(cigla[i++]);
        while (j < 3)
            brid2.push_back(druga.cigla[j++]);
        
        //provjera
        if (ploha.size() == 2 && brid1.size() == 1 && brid2.size() == 1) {
            cigla[0] = ploha[0];
            cigla[1] = ploha[1];
            cigla[2] = brid1[0] + brid2[0];
            sort(cigla.begin(), cigla.end());
        }

        return *this;
    }

    Cigla operator--(int) {
        Cigla temp = *this;
        cigla[0]--;
        cigla[1]--;
        cigla[2]--;
        return temp;
    }
};

ostream& operator<<(ostream& izlaz, const Cigla& c) {
    izlaz << c.cigla[2] << " x " << c.cigla[0] << " x " << c.cigla[1] << endl;
    return izlaz;
}

int main()
{
    Cigla a(1, 2, 3); //1, 2 i 3 su duljine bridova cigle. Cigla je kvadar
    a.ispisi();
    Cigla b(2, 3, 4);
    b.ispisi();
    
    a += b; //Lijepimo ciglu b na plohu 2x3 (cigle se lijepe na plohu istih dimenzija), i dobivamo ukupno ciglu veličine 5x2x3

    cout << a; //5 x 2 x 3
    a += Cigla(3, 5, 1);
    cout << a; //5 3 3
    a += Cigla(3, 3, 2);
    cout << a; //7 x 3 x 3

    a--;
    a--;
    cout << a; // 5 x 1 x 1
    return 0;
}

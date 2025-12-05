// Definirajte potrebne dijelove da bi funkcija "main" radila kako je opisano.
// class Sortiranje i main() su vec napisani.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Sortiranje {
public:
    virtual void sortiraj(vector<int>* vec) final {
        for (int i = 0; i < vec->size() - 1; ++i)
            for (int j = i + 1; j < vec->size(); ++j)
                if (!usporedba((*vec)[i], (*vec)[j])) {
                    swap((*vec)[i], (*vec)[j]);
                }
    }

    virtual bool usporedba(int e1, int e2) = 0;
};

class SortVeciPremaManjem : public Sortiranje {
    virtual bool usporedba(int e1, int e2) {
        return e1 > e2;
    }
};

class SortManjiPremaVecem : public Sortiranje {
    virtual bool usporedba(int e1, int e2) {
        return e1 < e2;
    }
};

ostream& operator<<(ostream& izlaz, vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        izlaz << v[i] << " ";
    }
    cout << endl; 
    return izlaz;
}

int main() {
    vector<int> v = { 8, 17, 1, 14, 5, 2, 19, 3, 15, 11 };

    Sortiranje* sort1 = new SortVeciPremaManjem();
    sort1->sortiraj(&v);
    cout << v;        // ispisuje 19 17 15 14 11 8 5 3 2 1
    delete sort1;

    Sortiranje* sort2 = new SortManjiPremaVecem();
    sort2->sortiraj(&v);
    cout << v;        // ispisuje 1 2 3 5 8 11 14 15 17 19
    delete sort2;

    return 0;
}


#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Racunalo {
private:
    string os;

public:
    Racunalo(string _os) : os(_os) {}
    string getOS() const { return os; }

    virtual string getTip() const = 0;
};

class Tablet : public Racunalo {
public:
    Tablet(string os) : Racunalo(os) {}
    string getTip() const override { return "Tablet"; }
};

class Laptop : public Racunalo {
public:
    Laptop(string os) : Racunalo(os) {}
    string getTip() const override { return "Laptop"; }
};

void AnalizaUcionice(vector<Racunalo*> racunala, int* brojTableta, int* brojLaptopa, int* brojAndroida, int* brojWindowsa, int* brojLinuxa) {

    *brojTableta = 0;
    *brojLaptopa = 0;
    *brojAndroida = 0;
    *brojWindowsa = 0;
    *brojLinuxa = 0;

    for (int i = 0; i < racunala.size(); i++) {

        if (racunala[i]->getTip() == "Tablet") {
            (*brojTableta)++;
            if (racunala[i]->getOS() == "Android")
                (*brojAndroida)++;
            else
                (*brojWindowsa)++;
        }

        else if (racunala[i]->getTip() == "Laptop") {
            (*brojLaptopa)++;
            if (racunala[i]->getOS() == "Windows")
                (*brojWindowsa)++;
            else 
                (*brojLinuxa)++;
            
        }
    }

    cout << "U ucionici se nalazi " << racunala.size() << " racunala" << endl;
    cout << "Broj tablet racunala : " << *brojTableta << endl;
    cout << "Broj laptop racunala : " << *brojLaptopa << endl;
    cout << "Android OS : " << *brojAndroida << endl;
    cout << "Windows OS : " << *brojWindowsa << endl;
    cout << "Linux OS : " << *brojLinuxa << endl;
}

int main() {
    int brTableta, brLaptopa;
    int brAndroida, brWindowsa, brLinuxa;

    Tablet Acer("Android"), Prestigio("Windows");
    Laptop Dell("Linux"), IBM("Windows"), Toshiba("Windows");

    vector<Racunalo*> Ucionica1 = { &Acer, &Prestigio, &Dell, &IBM, &Toshiba };
    AnalizaUcionice(Ucionica1, &brTableta, &brLaptopa, &brAndroida, &brWindowsa, &brLinuxa);


    /* u nastavku ispisite dobivenu analizu ucionice u sljedecem obliku:

    U ucionici se nalazi 5 racunala
    Broj tablet racunala : 2
    Broj laptop racunala : 3
    Android OS : 1
    Windows OS : 3
    Linux OS : 1
    */
    return 0;
}

#include <iomanip>
#include <iostream>
#include <vector>
#include <iostream>
#ifndef MY_H
#define MY_H

using namespace std;

class Studentas {
public:
  // Konstruktorius
  Studentas() {}

  // Konstruktorius su vardu ir pavarde
  Studentas(string vardas, string pavarde) : vardas_(vardas), pavarde_(pavarde) {}


  // Kopijavimo konstruktorius
  Studentas(const Studentas& studentas) {
    vardas_ = studentas.vardas_;
    pavarde_ = studentas.pavarde_;
    nd_ = studentas.nd_;
    egz_ = studentas.egz_;
    galutinis_ = studentas.galutinis_;
    metodas_ = studentas.metodas_;
  }

  // Priskyrimo operatorius
  Studentas& operator=(const Studentas& studentas) {
    vardas_ = studentas.vardas_;
    pavarde_ = studentas.pavarde_;
    nd_ = studentas.nd_;
    egz_ = studentas.egz_;
    galutinis_ = studentas.galutinis_;
    metodas_ = studentas.metodas_;
    return *this;
  }

  // Destruktorius
  ~Studentas() {}

  // Duomenų įvedimo metodas
  void ivedimas() {
    cout << "Įveskite studento vardą: ";
    cin >> vardas_;
    cout << "Įveskite studento pavardę: ";
    cin >> pavarde_;
    
    // deklaruojame kintamajį `n` ir jo reikšmę įvedame iš vartotojo
    int n;
    cout << "Kiek namų darbų rezultatų norite įvesti? ";
    cin >> n;

    // vector konteineris namu darbu pažymiams 
    vector <int> nd(n);

    for (int i = 0; i < n; i++) {
      cout << "nd[" << i + 1 << "]: ";
      cin >> nd[i];
    }

    // egzaminimo pažymio įvedimas 
    cout << "Įveskite egzamino pažymį (10-balėje sistemoje): ";
    cin >> egz_;

    // 
    cout << "Pasirinkite galutinio pažymio skaičiavimo metodą:\n1. Pagal vidurkį\n2. Pagal medianą\n";
    cin >> metodas_;

    // priklausomai nuo galutinio pažymio skaičiavimo metodo apskaičiuojamas galutinis pažymys
    if (metodas_ == 1) {
      galutinis_ = (nd[0] + nd[1] + nd[2] + egz_) / (n+1);
    } else if (metodas_ == 2) {
      sort(nd.begin(), nd.end());
      galutinis_ = (nd[n / 2] + egz_) / 2 ;
    }

  }

  // Duomenų išvedimo metodas
  void isvedimas() {
    cout << "Studento vardas: " << vardas_ << endl;
    cout << "Studento pavardė: " << pavarde_ << endl;
    cout << "Galutinis pažymys: " << fixed << setprecision(2) << galutinis_ << endl;
    cout << "Egzamino pažymys: " << egz_ << endl;
    cout << "Galutinio pažymio skaičiavimo metodas: " << (metodas_ == 1 ? "Vidurkis" : "Mediana") << endl;
  }
  // Išvedame duomenis į ekraną
 void isvedimas2() {
    cout << left << setw(15) << "Pavardė" << setw(15) << "Vardas" << fixed << setprecision(2) << setw(10) << "Galutinis (Vid.)" << setw(10) << "Galutinis (Med.)" << endl;
    cout << left << setw(15) << pavarde_ << setw(15) << vardas_ << fixed << setprecision(2) << setw(10) << galutinis_ << " (";
    cout << (metodas_ == 1 ? "Vid." : "Med") << ")" << endl;
 }

private:
  string vardas_;
  string pavarde_;
  vector<int> nd_;
  int egz_;
  double galutinis_;
  int metodas_;
};

#endif 

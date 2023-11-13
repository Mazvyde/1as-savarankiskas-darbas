#include <iomanip>
#include <iostream>
#include <vector>
#include <iostream>

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
    cout << "Įveskite namų darbų rezultatus (10-balėje sistemoje): ";

    // deklaruojame kintamajį `n` ir jo reikšmę įvedame iš vartotojo
    int n;
    cout << "Kiek namų darbų rezultatų norite įvesti? ";
    cin >> n;

    // sukuriame naują `std::vector` objektą, kurio elementų tipas yra `int`
    vector<int> nd(n);

    // įvedame namų darbų rezultatus į `nd_` masyvą
    for (int i = 0; i < n; i++) {
      cout << "nd[" << i + 1 << "]: ";
      cin >> nd[i];
    }

    // įvedame egzamino pažymį
    cout << "Įveskite egzamino pažymį (10-balėje sistemoje): ";
    cin >> egz_;

    // įvedame galutinio pažymio skaičiavimo metodą
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

private:
  string vardas_;
  string pavarde_;
  vector<int> nd_;
  int egz_;
  double galutinis_;
  int metodas_;
};


int main() {
  // Sukuriame objektą
  Studentas studentas;

  // Ivedame duomenis
  studentas.ivedimas();

  // Išvedame duomenis
  studentas.isvedimas();

  return 0;
}


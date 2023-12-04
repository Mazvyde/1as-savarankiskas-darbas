#ifndef MY_H
#define MY_H
#include <iomanip>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Studentas {
public:
  // Konstruktorius
  Studentas() {}

  // Konstruktorius su vardu ir pavarde
  Studentas(string vardas, string pavarde)
      : vardas_(vardas), pavarde_(pavarde) {}

  // Konstruktorius nuskaitymui iš failo
  Studentas(string vardas, string pavarde, int nd1, int nd2, int nd3, int nd4,
            int nd5, int egzaminas)
      : vardas_(vardas), pavarde_(pavarde), egz_(egzaminas) {
    nd_.push_back(nd1);
    nd_.push_back(nd2);
    nd_.push_back(nd3);
    nd_.push_back(nd4);
    nd_.push_back(nd5);
  }

// Kopijavimo konstruktorius
  Studentas(const Studentas &studentas) {
    vardas_ = studentas.vardas_;
    pavarde_ = studentas.pavarde_;
    nd_ = studentas.nd_;
    egz_ = studentas.egz_;
    galutinis_ = studentas.galutinis_;
    metodas_ = studentas.metodas_;
  }

  // Priskyrimo operatorius
  Studentas &operator=(const Studentas &studentas) {
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

  // Duomenų įvedimas iš klaviatūros
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
    vector<int> nd;

    cout << "Ar norite generuoti galutinį pažymį pagal atsitiktinius balus? (1 - taip, 0 - ne): ";
    int pasirinkimas;
    cin >> pasirinkimas;

     if (pasirinkimas == 1) {
        generuotiAtsitiktiniusBalus(n);
    } else {
        // masyvas namu darbu pažymiams
        nd.resize(n);
        for (int i = 0; i < n; i++) {
            cout << "nd[" << i + 1 << "]: ";
            cin >> nd[i];
        }

        // egzaminimo pažymio įvedimas
        cout << "Įveskite egzamino pažymį (10-balėje sistemoje): ";
        cin >> egz_;
    }
  
    //
    cout << "Pasirinkite galutinio pažymio skaičiavimo metodą:\n1. Pagal "
            "vidurkį\n2. Pagal medianą\n";
    cin >> metodas_;

    // priklausomai nuo galutinio pažymio skaičiavimo metodo apskaičiuojamas galutinis pažymys
    if (metodas_ == 1) {
    double nd_total = 0.0;
    for (int i = 0; i < n; i++) {
        nd_total += nd[i];
    }
    // vidutinis nd 
    double nd_average = nd_total / n;
    galutinis_ = 0.4 * nd_average + 0.6 * egz_;
}
    else if (metodas_ == 2) {
    sort(nd.begin(), nd.end());
    galutinis_ = (nd[n / 2] + egz_) / 2;
  } else {
    cout << "Netinkamai pasirinktas galutinio pažymio skaičiavimo metodas: ";
    }
  }

// Duomenų išvedimo metodas i lentele
  void isvedimas2() const {
    cout << left << setw(15) << "Pavardė" << setw(15) << "Vardas" << fixed
         << setprecision(2) << setw(10) << "Galutinis (Vid.)" << setw(10)
         << "Galutinis (Med.)" << endl;
    cout << left << setw(15) << pavarde_ << setw(15) << vardas_ << fixed
         << setprecision(2) << setw(10) << galutinis_ << "(";
    cout << (metodas_ == 1 ? "Vid." : "Med") << ")" << endl;
  }

  //atsitiktiniu balu generavimui metodas 
  void generuotiAtsitiktiniusBalus(int n) {
    nd_.clear(); // Išvalome senus namų darbų rezultatus

    int minBalas, maxBalas;
    cout << "Įveskite minimalų ir maksimalų balų diapazoną (pvz., 1 10): ";
    cin >> minBalas >> maxBalas;

    // Sugeneruojame atsitiktinius namų darbų pažymius
    for (int i = 0; i < n; i++) {
        nd_.push_back(rand() % (maxBalas - minBalas + 1) + minBalas);
    }

    // Sugeneruojame atsitiktinį egzamino pažymį
    egz_ = rand() % (maxBalas - minBalas + 1) + minBalas;
}
  

private:
  string vardas_;
  string pavarde_;
  vector<int> nd_;
  int egz_;
  double galutinis_;
  int metodas_;
};


vector<Studentas> nuskaityti_is_failo(string kursiokai) {
    ifstream fd(kursiokai);
    vector<Studentas> studentai;

        if (fd.is_open()) {
        int n;
        fd >> n;

        for (int i = 0; i < n; i++) {
            string vardas, pavarde;
            int nd1, nd2, nd3, nd4, nd5, egzaminas;

            fd >> pavarde >> vardas >> nd1 >> nd2 >> nd3 >> nd4 >> nd5 >> egzaminas;

            // sukuria nauja studenta i vektoriu
            Studentas studentas(vardas, pavarde, nd1, nd2, nd3, nd4, nd5, egzaminas);
            studentai.push_back(studentas);
        }

        fd.close();
    } else {
        cout << "Negaliu atidaryti failo " << kursiokai << endl;
    }

    return studentai;
}

void isvesti_nuskaitytus_duomenis(const vector<Studentas>& studentai) {
    cout << "Nuskaityti duomenys:" << endl;
    for (const auto& studentas: studentai) {
        studentas.isvedimas2(); 
        cout << "-----------------------------------" << endl;
    }
}

#endif


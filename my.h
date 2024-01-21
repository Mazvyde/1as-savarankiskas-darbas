#ifndef MY_H
#define MY_H
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

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

  // move contruktorius ir move prieskyros operatorius. 

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

    cout << "Ar norite generuoti galutinį pažymį pagal atsitiktinius balus? (1 "
            "- taip, 0 - ne): ";
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

    // priklausomai nuo galutinio pažymio skaičiavimo metodo apskaičiuojamas
    // galutinis pažymys
    if (metodas_ == 1) {
      double nd_total = 0.0;
      for (int i = 0; i < n; i++) {
        nd_total += nd[i];
      }
      // vidutinis nd
      double nd_average = nd_total / n;
      galutinis_ = 0.4 * nd_average + 0.6 * egz_;
    } else if (metodas_ == 2) {
      sort(nd.begin(), nd.end());
      galutinis_ = (nd[n / 2] + egz_) / 2;
    } else {
      cout << "Netinkamai pasirinktas galutinio pažymio skaičiavimo metodas: ";
    }
  }

  // Duomenų išvedimo metodas i lentele
  void isvedimas2() const {
    cout << left << setw(15) << "Pavardė" << setw(15) << "Vardas" << fixed
         << setprecision(2) << setw(2) << "Galutinis (Vid.)" << setw(2)
         << "Galutinis (Med.)" << endl;
    cout << left << setw(15) << pavarde_ << setw(15) << vardas_ << fixed
         << setprecision(2) << setw(2) << galutinis_ << "(";
    cout << (metodas_ == 1 ? "Vid." : "Med") << ")" << endl;
  }

  // atsitiktiniu balu generavimui metodas
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

  string getVardas() const { return vardas_; }

  string getPavarde() const { return pavarde_; }

  const vector<int> &getNd() const {return nd_; }

  int getEgz() const {return egz_; }

  double getGalutinis() const { return galutinis_; }
  
  int getMetodas() const { return metodas_; }
  
  friend bool operator< (const Studentas &a, const Studentas &b)
  {
    return a.getGalutinis() < b.getGalutinis(); 
  } 


private:
  string vardas_;
  string pavarde_;
  vector<int> nd_;
  int egz_;
  double galutinis_;
  int metodas_;
};

bool vardasmaz (const Studentas &a, const Studentas &b)
  {
    return a.getVardas() < b.getVardas(); 
  } 

bool pavardmaz (const Studentas &a, const Studentas &b)
  {
    return a.getPavarde() < b.getPavarde(); 
  } 

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

void isvesti_nuskaitytus_duomenis(const vector<Studentas> &studentai) {
  cout << "Nuskaityti duomenys:" << endl;
  for (const auto &studentas : studentai) {
    studentas.isvedimas2();
    cout << "-----------------------------------" << endl;
  }
}

void generuotiIrIrasymasIFaila(int studentuSkaicius, const string &failoPavadinimas) {
  vector<Studentas> studentai;

  //atsitiktinių skaičių generavimui
  srand(static_cast<unsigned>(time(0))); 

  for (int i = 0; i < studentuSkaicius; ++i) {
    string vardas = "Vardas" + to_string(i + 1);
    string pavarde = "Pavarde" + to_string(i + 1);
    int nd1 = rand() % 10 + 1;
    int nd2 = rand() % 10 + 1;
    int nd3 = rand() % 10 + 1;
    int nd4 = rand() % 10 + 1;
    int nd5 = rand() % 10 + 1;
    int egzaminas = rand() % 10 + 1;

    Studentas naujasStudentas (vardas, pavarde, nd1, nd2, nd3, nd4, nd5, egzaminas);
    studentai.push_back(naujasStudentas);
  }

  ofstream fd(failoPavadinimas);

  if (fd.is_open()) {
    fd << studentuSkaicius << endl;

  for (const auto& studentas : studentai) {
        fd << studentas.getVardas() << " "
           << studentas.getPavarde() << " "
           << studentas.getNd()[0] << " "
           << studentas.getNd()[1] << " "
           << studentas.getNd()[2] << " "
           << studentas.getNd()[3] << " "
           << studentas.getNd()[4] << " "
           << studentas.getEgz() << endl;
    }

    fd.close();
    cout << "Failas " << failoPavadinimas << " sukurtas." << endl;
  } else {
    cout << "Negaliu atidaryti failo " << failoPavadinimas << endl;
  }
}

void generuotiFailus() {
    cout << "Ar norite sugeneruoti failus? (1 - taip, 0 - ne): ";
    int pasirinkimas;
    cin >> pasirinkimas;

    if (pasirinkimas == 1) {

        cout << "Failų generavimas..." << endl;
        generuotiIrIrasymasIFaila(1000, "failas_1000.txt");
        generuotiIrIrasymasIFaila(10000, "failas_10000.txt");
        generuotiIrIrasymasIFaila(100000, "failas_100000.txt");
        generuotiIrIrasymasIFaila(1000000, "failas_1000000.txt");
        generuotiIrIrasymasIFaila(10000000, "failas_10000000.txt");
        cout << "Failai sukurti" << endl;
    }
}

void skaiciuotiIrIsvestiGalutinius(const vector<Studentas>& studentai) {
    sort (studentai.begin(), studentai.end()); 
    sort (studentai.begin(), studentai.end(), pavardmaz);  

    cout << "Studentai ir jų galutiniai pažymiai:" << endl;
    cout << left << setw(15) << "Pavardė" << setw(15) << "Vardas" << fixed
         << setprecision(2) << setw(10) << "Galutinis (Vid.)" << setw(10)
         << "Galutinis (Med.)" << endl;

    for (const auto& studentas : studentai) {
        cout << left << setw(15) << studentas.getPavarde() << setw(15) << studentas.getVardas() << fixed<< setprecision(2) << setw(10) << studentas.getGalutinis() << "("
        << (studentas.getMetodas() == 1 ? "Vid." : "Med") << ")" << endl;
    }

    
}

#endif

#include  "my.h"
#include <iomanip>
#include <iostream>
#include <vector>
#include <iostream>
#include <fstream>


int main() {
    
    generuotiFailus();
    
    vector<Studentas> studentai;

    cout << "Pasirinkite kaip norite ivesti duomenis:\n"
            "1. Ranka\n"
            "2. Iš failo\n";

    int pasirinkimas;
    cin >> pasirinkimas;

    if (pasirinkimas == 1) {
        // kai pasirinko įvesti duomenis ranka
        int studentuSkaicius;
        cout << "Iveskite studentu skaiciu: ";
        cin >> studentuSkaicius;

        for (int i = 0; i < studentuSkaicius; i++) {
            Studentas naujasStudentas;
            naujasStudentas.ivedimas();
            studentai.push_back(naujasStudentas);
        }
    } else if (pasirinkimas == 2) {
        // kai pasirinko nuskaityti duomenis iš failo kursiokai
        studentai = nuskaityti_is_failo("kursiokai.txt"); 
        studentai = nuskaityti_is_failo("failas_1000.txt");
        isvesti_nuskaitytus_duomenis(studentai);
        // skaiciuotiIrIsvestiGalutinius(studentai);
    } else {
        cout << "Netinkamas pasirinkimas\n";
        return 1; // Baigiame programos darbą, nes pasirinkimas nebuvo tinkamas
    }




    return 0;
}

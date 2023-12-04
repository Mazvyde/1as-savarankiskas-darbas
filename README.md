# 1as-savarankiskas-darbas

Programa, nuskaito šiuos studentų duomenis:
- vardą ir pavardę
- n atliktų namų darbų (nd) rezultatus (10-balėje sistemoje), o taip pat egzamino (egz) rezultatą.
Tuomet iš šių duomenų, suskaičiuoja galutinį balą (galutinis). 
Programoje realizuoti reikalavimai versijai (v0.1): 
1.	nuskaito vartotojų įvedamus reikiamus duomenis ;
2.	duomenų talpinimui sukurta klasėje ir kartu su metodais skirtais tokių duomenų apdorojimui;
3.	realizuota "trejų metodų" taisyklė: 
- klasės duomenys:
•	studento vardas ir pavardė;
•	namų darbų ir egzamino rezultatas;
•	galutinis pažymys.
- klasės metodai: 
•	Konstruktorius Studentas() {}; 
•	Priskyrimo-kopijavimo operatorius Studentas &operator=(const Studentas &studentas)
•	Kopijavimo konstruktorius Studentas(const Studentas &studentas); 
•	Destruktorius ~Studentas() {};
•	Duomenų įvedimo metodas cin;
•	Duomenų išvedimo metodas cout;
4. Galutinio pažymio skaičiavimo metodas galimas pasirinktinai pagal medianą arbą vidurkį. 
5. Baigus duomenų įvedimą, programam suskaičiuoja galutį balą ir juos pateikia į ekraną. Programa veikia kai namų darbų skaičius (n) yra žinomas iš anksto, t.y. įvedimo metu vartotojas nurodo, kiek namų darbų bus įvesta.
7.	Namų darbų rezultatai saugomi į vector tipo konteineryje.
8.	Programoje veikia galimybė mokinio gautuosius balus už namų darbus ir egzaminą generuoti atsitiktinai.
9. Programa turi galimybę nuskiatyti duomenis iš failo kursiokai.txt.
10. Programa generuoja penkis atsitiktinius studentų sąrašų failus, sudarytus iš: 1 000, 10 000, 100 000, 1 000 000, 10 000 000 įrašų (Vardas2 Pavarde2, Vardas3 Pavarde3). 





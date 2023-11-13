# 1as-savarankiskas-darbas_

Programa, nuskaito šiuos studentų duomenis:
o	vardą ir pavardę
o	n atliktų namų darbų (nd) rezultatus (10-balėje sistemoje), o taip pat egzamino (egz) rezultatą.
Tuomet iš šių duomenų, suskaičiuoja galutinį balą (galutinis). 

Realizuoti reikalavimai versijai (v0.1): 
1.	nuskaito vartotojų įvedamus reikiamus duomenis ;
2.	duomenų talpinimui sukurta klasėje ir kartu su metodais skirtais tokių duomenų apdorojimui;
3.	realizuota "trejų metodų" taisyklė: 
  o	klasės duomenys:
  	-studento vardas ir pavardė;
  	-namų darbų ir egzamino rezultatas;
  	-galutinis pažymys.
  o	klasės metodai: 
  	-Konstruktorius Studentas() {}; 
  	-Priskyrimo-kopijavimo operatorius Studentas &operator=(const Studentas &studentas)
  	-Kopijavimo konstruktorius Studentas(const Studentas &studentas); 
  	-Destruktorius ~Studentas() {} 
  	-Duomenų įvedimo metodas cin
  	-Duomenų išvedimo metodas cout
	Galutinio pažymio skaičiavimo metodas pasirinktinai pagal medianą arbą vidurkį
4.	Baigus duomenų įvedimą, suskaičiuoja galutį balą ir juos pateikia į ekraną.
5.	Programa veikia kai namų darbų skaičius (n) yra žinomas iš anksto, t.y. tik įvedimo metu vartotojas nurodo, kiek namų darbų bus įvesta.
6.	Namų darbų rezultatai saugomi į vector tipo konteinerį.  



# Studentų pažymių skaičiavimo programa

## Projekto aprašymas

Programa skirta studentų pažymių apdorojimui. Ji leidžia įvesti arba nuskaityti studentų duomenis, apskaičiuoti galutinį balą pagal **vidurkį** arba **medianą**, rūšiuoti studentus pagal pasirinktą kriterijų bei išvesti rezultatus į ekraną arba failus.

Programa vystoma etapais naudojant **GitHub versijavimą (branches ir releases)**.

---

# Programos funkcionalumas

Programa leidžia:

* įvesti studentų duomenis ranka
* generuoti atsitiktinius pažymius
* generuoti studentų vardus, pavardes ir pažymius
* nuskaityti duomenis iš failo
* generuoti didelius studentų duomenų failus testavimui
* apskaičiuoti galutinį balą pagal:

  * vidurkį
  * medianą
* rūšiuoti studentus pagal:

  * vardą
  * pavardę
  * galutinį balą (vidurkį)
  * galutinį balą (medianą)
* padalinti studentus į dvi kategorijas:

  * **kietiakiai** (galutinis ≥ 5.0)
  * **vargšiukai** (galutinis < 5.0)
* išvesti rezultatus:

  * į terminalą
  * į vieną failą
  * į du atskirus failus pagal studentų kategoriją

---

# Projekto versijos

## v.pradinė

Realizuota bazinė programa:

* įvedami studento duomenys
* apskaičiuojamas galutinis balas
* galutinis balas gali būti skaičiuojamas pagal vidurkį arba medianą

---

## v0.1

Papildyta programa:

* sukurta **C masyvų versija**
* sukurta **std::vector versija**
* vartotojas gali pasirinkti programos veikimo būdą per meniu
* pažymiai gali būti generuojami atsitiktinai
* studentų ir namų darbų skaičius nėra žinomas iš anksto

---

## v0.2

Papildytas funkcionalumas:

* duomenys gali būti **nuskaitomi iš failo**
* studentai gali būti rūšiuojami pagal vartotojo pasirinktą kriterijų
* rezultatai gali būti išvedami į ekraną arba failą
* programa ištestuota naudojant pateiktus failus:

  * `Studentai10000.txt`
  * `Studentai100000.txt`
  * `Studentai1000000.txt`

---

## v0.3

Atliktas projekto **refactoring**:

* naudotos **struct struktūros**
* funkcijos ir struktūros perkeltos į **header (.h) failus**
* projektas padalintas į kelis `.cpp` ir `.h` failus
* realizuotas **klaidų valdymas (exception handling)**:

  * tikrinama ar egzistuoja failas
  * tikrinami vartotojo įvedami duomenys
* visi pranešimai vartotojui pateikiami **lietuvių kalba**

---

## v0.4

Papildytas funkcionalumas:

* sukurta **studentų failų generavimo funkcija**
* sugeneruoti testavimo failai su skirtingais įrašų kiekiais:

| Studentų skaičius |
| ----------------- |
| 1 000             |
| 10 000            |
| 100 000           |
| 1 000 000         |
| 10 000 000        |

Studentų vardai generuojami šabloniškai:

```
Vardas1 Pavarde1
Vardas2 Pavarde2
...
```

Programa:

1. nuskaito studentų duomenis
2. apskaičiuoja galutinį balą
3. padalina studentus į dvi kategorijas:

   * **kietiakiai**
   * **vargšiukai**
4. išveda rezultatus į du naujus failus

---

# Programos veikimo spartos tyrimas

Testavimas atliktas naudojant **Release build**.

Buvo atlikti **du tyrimai**.

---

# 1 tyrimas – failų generavimas

Tyrimo tikslas – išmatuoti laiką, reikalingą **failo sukūrimui ir uždarymui**.

Šio tyrimo metu:

* nenaudojami vektoriai
* duomenys generuojami ir iškart rašomi į failą
* matuojamas tik failo kūrimo procesas

Matavimo etapai:

* failo sukūrimas
* duomenų įrašymas
* failo uždarymas

---

# 2 tyrimas – duomenų apdorojimas

Šio tyrimo metu naudojami **anksčiau sugeneruoti failai**, siekiant užtikrinti tyrimo patikimumą.

Matuojami šie programos etapai:

1. **duomenų nuskaitymas iš failo**
2. **studentų padalijimas į dvi kategorijas**
3. **rezultatų išvedimas į du failus**
4. **bendras programos veikimo laikas**

---

# Testavimo rezultatai

Testavimo rezultatai pateikiami lentelėse ir saugomi kataloge:

```
testavimas/
```

CSV failuose pateikiami kelių testų **laikų vidurkiai**.

Rezultatų vizualizacijos ir programos veikimo nuotraukos pateikiamos kataloge:

```
testavimo nuotraukos/
```

---

# Projekto struktūra

```
.
├── v0.4/              # programos šaltinio kodas
├── studentInput/      # įvesties failai
├── vardai             # vardu generavimui
├── studentOutput/     # programos sugeneruoti rezultatai
├── testavimas/        # testavimo duomenys (csv)
├── photos/            # testavimo nuotraukos
└── README.md
```

---

# Naudotos technologijos

* C++
* STL (`std::vector`, `std::algorithm`, `std::fstream`)
* Git / GitHub

---
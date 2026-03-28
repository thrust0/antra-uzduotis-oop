# Studentų pažymių skaičiavimo programa v1.1

## Projekto aprašymas

Programa skirta studentų pažymių apdorojimui. Ji leidžia įvesti arba nuskaityti studentų duomenis,
apskaičiuoti galutinį balą pagal **vidurkį** arba **medianą**, rūšiuoti studentus pagal pasirinktą
kriterijų bei išvesti rezultatus į ekraną arba failus.

Ši versija yra ankstesnės versijos [v1.0](https://github.com/thrust0/pirma-uzduotis-oop) tęsinys,
kurioje `struct` struktūra pakeista į pilnavertę `class` klasę.

---

## v1.1 Pakeitimai

### Struktūros → Klasės perėjimas

Ankstesnėje versijoje naudota `struct Students` struktūra pakeista į `class Students` klasę.

**Pagrindiniai pakeitimai:**

* Visi laukai tapo `private` — tiesioginis prieiga prie duomenų išoriškai nebegalima
* Pridėti `get` metodai duomenims nuskaityti
* Pridėti `set` metodai duomenims įrašyti (naudojami rankinio įvedimo metu)
* `calc_result()` ir `calc_median()` tapo `private` klasės metodais
* Pridėtas numatytasis konstruktorius `Students()`
* Pridėtas konstruktorius iš srauto `Students(istream& is)` — naudojamas failo nuskaitymui
* Pridėtas `read_students(istream& is)` metodas — nuskaito studento duomenis iš srauto

### Kodų pakeitimai

* Visas kodas atnaujintas — tiesioginė prieiga prie laukų (pvz. `student.first_name`)
  pakeista į get metodus (pvz. `student.get_first_name()`)
* `file_input` funkcija atnaujinta — naudoja `Students(istream& is)` konstruktorių
* `manual_input` funkcija atnaujinta — naudoja `set` metodus

---

## Įdiegimo instrukcija

### Reikalavimai

* [G++ kompiliatorius (C++17)](https://gcc.gnu.org/)
* make (Mac/Linux)

### Įdiegimas

#### Mac / Linux

1. Įsitikinkite, kad turite g++ kompiliatorių:
```bash
g++ --version
```

2. Jei neturite, įdiekite per Homebrew (Mac):
```bash
brew install gcc
```

3. Sukompiliuokite programą:
```bash
make main
```

#### Windows

Windows sistemoje `make` nėra palaikomas pagal nutylėjimą. Rekomenduojama naudoti:

* [MinGW](https://www.mingw-w64.org/) — leidžia naudoti g++ ir make Windows sistemoje
* [WSL](https://learn.microsoft.com/en-us/windows/wsl/install) — Linux aplinka Windows sistemoje

Arba kompiliuoti rankiniu būdu:
```bash
g++ -std=c++17 -Wall -Wextra student.cpp io.cpp menu.cpp main.cpp -o main
```

---

## Naudojimosi instrukcija

### Programos paleidimas
```bash
./main
```

### Programos veikimas

1. Pasirinkite duomenų įvedimo būdą:
   * Ranka
   * Generuoti pažymius
   * Generuoti vardus ir pažymius
   * Nuskaityti iš failo
   * Sugeneruoti studentų failą
2. Pasirinkite rūšiavimo būdą (vardas, pavardė, vidurkis, mediana)
3. Pasirinkite skaidymo strategiją (1, 2 arba 3)
4. Pasirinkite išvedimo būdą (terminalas, failas, du atskiri failai)

## Testavimas
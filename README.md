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

Here's an updated installation section:

---

## Įdiegimo instrukcija

### Reikalavimai

* [G++ kompiliatorius (C++17)](https://gcc.gnu.org/) 
* make (Mac/Linux)

### Įdiegimas pagal operacinę sistemą

#### Mac / Linux

1. Įsitikinkite, kad turite g++ kompiliatorių:
```bash
g++ --version
```

2. Jei neturite, įdiekite per Homebrew (Mac):
```bash
brew install gcc
```

3. Eikite į norimą konteinerio aplanką ir sukompiliuokite:
```bash
# Vector versija
cd v1.0/vector
make main

# List versija
cd v1.0/list
make main

# Deque versija
cd v1.0/deque
make main
```

#### Windows

Windows sistemoje `make` nėra palaikomas pagal nutylėjimą. Rekomenduojama naudoti vieną iš šių sprendimų:

* [MinGW](https://www.mingw-w64.org/) — leidžia naudoti g++ ir make Windows sistemoje
* [WSL (Windows Subsystem for Linux)](https://learn.microsoft.com/en-us/windows/wsl/install) — Linux aplinka Windows sistemoje

Įdiegus MinGW arba WSL, kompiliavimas atliekamas taip pat kaip Mac/Linux.

Arba kompiliuoti rankiniu būdu:
```bash
g++ -std=c++17 -Wall -Wextra student.cpp io.cpp menu.cpp main.cpp -o main
```

### Paleidimas

```bash
./main
```

### Testavimo paleidimas

```bash
./test
```


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

## v1.0

Papildytas funkcionalumas:

* programa reimplementuota su trimis skirtingais konteineriais:
  * **std::vector**
  * **std::list**
  * **std::deque**
* realizuotos trys studentų skaidymo strategijos kiekvienam konteineriui
* atliktas konteinerių veikimo spartos tyrimas
* rezultatai palyginti ir aprašyti README faile

### Pakeitimai pereinant nuo vector prie list

* `std::sort` pakeistas į `list::sort()` — list nepalaiko atsitiktinės prieigos iteratorių
* `[]` indeksavimas pakeistas į `std::advance` su iteratoriais
* `std::partition` veikia lėčiau nei su vector dėl susieto sąrašo struktūros

### Pakeitimai pereinant nuo vector prie deque

* `std::sort`, `[]` indeksavimas ir visi algoritmai veikia taip pat kaip su vector
* pakeistas tik konteinerio tipas — `vector` → `deque`
* programos uždarymas su 10m įrašų užtrunka ilgiau dėl deque atminties atlaisvinimo mechanizmo
---

# v0.4 Programos veikimo spartos tyrimas

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
├── v1.0/
│   ├── vector/        # vector konteinerio versija
│   ├── list/          # list konteinerio versija
│   └── deque/         # deque konteinerio versija
├── studentInput/      # įvesties failai
├── vardai/            # vardų generavimui
├── studentOutput/     # programos sugeneruoti rezultatai
└── README.md
```

---

# Naudotos technologijos

* C++
* STL
* Visual Studio Code
* Git / GitHub

---
# v0.4 tyrimas


## v0.4 Testavimo rezultatai

Visi laikai milisekundėmis (ms).

### 1 tyrimas – Failo sugeneravimo laikas

|                  | 1k  | 10k  | 100k  | 1m    | 10m   |
|------------------|-----|------|-------|-------|-------|
| Testavimas nr. 1 | 2   | 25   | 201   | 1982  | 20648 |
| Testavimas nr. 2 | 2   | 27   | 189   | 1855  | 20223 |
| Testavimas nr. 3 | 2   | 37   | 203   | 1831  | 19736 |
| Testavimas nr. 4 | 2   | 28   | 184   | 1871  | 19394 |
| Testavimas nr. 5 | 6   | 30   | 206   | 1812  | 19495 |
| Vidurkis         | 2.8 | 29.4 | 196.6 | 1870  | 19899 |

### 2 tyrimas – Duomenų apdorojimas

#### Bendras laikas

|                  | 1k   | 10k  | 100k | 1m   | 10m   |
|------------------|------|------|------|------|-------|
| Testavimas nr. 1 | 18   | 68   | 564  | 5336 | 57888 |
| Testavimas nr. 2 | 24   | 65   | 540  | 5312 | 56940 |
| Testavimas nr. 3 | 19   | 63   | 527  | 5408 | 56814 |
| Testavimas nr. 4 | 22   | 61   | 530  | 5306 | 56727 |
| Testavimas nr. 5 | 21   | 62   | 530  | 5356 | 57201 |
| Vidurkis         | 20.8 | 63.8 | 538  | 5344 | 57114 |

#### Nuskaitymo laikas

|                  | 1k   | 10k | 100k  | 1m     | 10m   |
|------------------|------|-----|-------|--------|-------|
| Testavimas nr. 1 | 12   | 47  | 375   | 3424   | 35626 |
| Testavimas nr. 2 | 12   | 45  | 350   | 3398   | 35018 |
| Testavimas nr. 3 | 10   | 43  | 334   | 3451   | 34933 |
| Testavimas nr. 4 | 10   | 42  | 337   | 3428   | 35024 |
| Testavimas nr. 5 | 9    | 43  | 338   | 3448   | 35048 |
| Vidurkis         | 10.6 | 44  | 346.8 | 3429.8 | 35130 |

#### Rūšiavimo laikas

|                  | 1k | 10k | 100k | 1m  | 10m  |
|------------------|----|-----|------|-----|------|
| Testavimas nr. 1 | 0  | 2   | 24   | 268 | 3493 |
| Testavimas nr. 2 | 0  | 2   | 24   | 255 | 3282 |
| Testavimas nr. 3 | 0  | 2   | 23   | 256 | 3235 |
| Testavimas nr. 4 | 0  | 2   | 24   | 256 | 3291 |
| Testavimas nr. 5 | 0  | 2   | 25   | 259 | 3181 |
| Vidurkis         | 0  | 2   | 24   | 259 | 3296 |

#### Išvedimo laikas

|                  | 1k | 10k  | 100k  | 1m   | 10m   |
|------------------|----|------|-------|------|-------|
| Testavimas nr. 1 | 5  | 18   | 165   | 1643 | 18767 |
| Testavimas nr. 2 | 11 | 17   | 166   | 1657 | 18639 |
| Testavimas nr. 3 | 8  | 17   | 168   | 1699 | 18645 |
| Testavimas nr. 4 | 11 | 16   | 167   | 1621 | 18411 |
| Testavimas nr. 5 | 10 | 16   | 166   | 1648 | 18971 |
| Vidurkis         | 9  | 16.8 | 166.4 | 1657 | 18687 |


# v1.0 Tyrimas

## Vector - 1 Strategija

Visi laikai milisekundėmis (ms).

### Nuskaitymas

|          | 1k   | 10k | 100k | 1m   | 10m   |
|----------|------|-----|------|------|-------|
| Test 1   | 12   | 52  | 332  | 3414 | 36089 |
| Test 2   | 12   | 50  | 327  | 3405 | 34887 |
| Test 3   | 9.7  | 48  | 328  | 3421 | 34622 |
| Test 4   | 10   | 47  | 334  | 3432 | 34865 |
| Test 5   | 10   | 48  | 332  | 3417 | 34843 |
| Vidurkis | 10.7 | 49  | 331  | 3418 | 35061 |

### Rūšiavimas

|          | 1k   | 10k | 100k | 1m  | 10m  |
|----------|------|-----|------|-----|------|
| Test 1   | 0.78 | 2.6 | 21.6 | 220 | 2371 |
| Test 2   | 0.77 | 2.7 | 21.6 | 221 | 2282 |
| Test 3   | 0.7  | 2.6 | 21.7 | 220 | 2380 |
| Test 4   | 0.38 | 2.5 | 22.1 | 222 | 2238 |
| Test 5   | 0.76 | 2.6 | 22   | 223 | 2239 |
| Vidurkis | 0.67 | 2.6 | 21.8 | 221 | 2302 |

### Skaidymas

|          | 1k   | 10k  | 100k | 1m | 10m |
|----------|------|------|------|----|-----|
| Test 1   | 0.38 | 1.11 | 8.6  | 94 | 912 |
| Test 2   | 0.36 | 1.15 | 8.5  | 93 | 881 |
| Test 3   | 0.32 | 1.07 | 8.66 | 93 | 861 |
| Test 4   | 0.14 | 1.07 | 8.66 | 94 | 820 |
| Test 5   | 0.30 | 1.08 | 8.7  | 93 | 876 |
| Vidurkis | 0.30 | 1.09 | 8.6  | 93 | 870 |

### Bendras laikas

|          | 1k   | 10k | 100k | 1m   | 10m   |
|----------|------|-----|------|------|-------|
| Test 1   | 13.2 | 56  | 363  | 3728 | 39373 |
| Test 2   | 13.2 | 54  | 357  | 3720 | 38051 |
| Test 3   | 10.7 | 52  | 359  | 3735 | 37863 |
| Test 4   | 12.4 | 49  | 369  | 3731 | 37662 |
| Test 5   | 11.8 | 50  | 370  | 3812 | 38032 |
| Vidurkis | 12.2 | 52  | 364  | 3745 | 38196 |


---



## Vector - 2 Strategija (atnaujinta, 6 testai)

Visi laikai milisekundėmis (ms).

### Nuskaitymas

|          | 1k    | 10k   | 100k   | 1m      | 10m     |
|----------|-------|-------|--------|---------|---------|
| Test 1   | 12.08 | 49.42 | 327.47 | 3335.34 | 35857.6 |
| Test 2   | 10.68 | 47.22 | 325.83 | 3379.08 | 35245.0 |
| Test 3   | 9.22  | 46.52 | 332.59 | 3427.78 | 35195.5 |
| Test 4   | 9.60  | 46.79 | 333.95 | 3411.56 | 35097.9 |
| Test 5   | 12.57 | 49.64 | 327.03 | 3390.83 | 34781.7 |
| Test 6   | 9.13  | 46.44 | 332.10 | 3398.09 | 34757.3 |
| Vidurkis | 10.55 | 47.67 | 329.83 | 3390.45 | 35155.8 |

### Rūšiavimas

|          | 1k    | 10k   | 100k  | 1m     | 10m     |
|----------|-------|-------|-------|--------|---------|
| Test 1   | 0.893 | 2.694 | 21.75 | 222.55 | 2471.16 |
| Test 2   | 0.947 | 2.563 | 21.71 | 221.49 | 2443.88 |
| Test 3   | 0.603 | 2.540 | 22.30 | 221.56 | 2488.62 |
| Test 4   | 0.654 | 2.542 | 22.50 | 228.83 | 2464.65 |
| Test 5   | 1.035 | 2.654 | 21.52 | 223.37 | 2421.12 |
| Test 6   | 0.601 | 2.535 | 22.34 | 222.67 | 2448.98 |
| Vidurkis | 0.789 | 2.588 | 22.02 | 223.41 | 2456.40 |

### Skaidymas

|          | 1k    | 10k   | 100k  | 1m     | 10m     |
|----------|-------|-------|-------|--------|---------|
| Test 1   | 0.259 | 1.967 | 16.83 | 174.46 | 1958.13 |
| Test 2   | 0.332 | 1.914 | 17.12 | 175.50 | 2030.12 |
| Test 3   | 0.317 | 1.858 | 17.37 | 180.30 | 2014.83 |
| Test 4   | 0.339 | 1.910 | 17.49 | 181.10 | 2022.04 |
| Test 5   | 0.460 | 1.983 | 17.05 | 176.69 | 1922.71 |
| Test 6   | 0.317 | 1.891 | 17.91 | 178.45 | 2081.43 |
| Vidurkis | 0.337 | 1.921 | 17.30 | 177.75 | 2004.88 |

### Bendras laikas

|          | 1k    | 10k   | 100k   | 1m      | 10m     |
|----------|-------|-------|--------|---------|---------|
| Test 1   | 13.23 | 54.08 | 366.05 | 3732.35 | 40286.8 |
| Test 2   | 11.96 | 51.70 | 364.66 | 3776.07 | 39719.0 |
| Test 3   | 10.13 | 50.92 | 372.25 | 3829.65 | 39699.0 |
| Test 4   | 10.60 | 51.25 | 373.95 | 3821.49 | 39584.6 |
| Test 5   | 14.06 | 54.28 | 365.61 | 3790.89 | 39125.5 |
| Test 6   | 10.05 | 50.87 | 372.35 | 3799.22 | 39287.7 |
| Vidurkis | 11.67 | 52.18 | 369.15 | 3791.61 | 39617.1 |

---


## Vector - 3 Strategija

Visi laikai milisekundėmis (ms).

### Nuskaitymas

|          | 1k   | 10k   | 100k   | 1m      | 10m     |
|----------|------|-------|--------|---------|---------|
| Test 1   | 4.63 | 61.50 | 345.31 | 3448.09 | 34913.8 |
| Test 2   | 4.70 | 35.10 | 341.57 | 3436.54 | 34698.1 |
| Test 3   | 4.74 | 34.87 | 340.66 | 3441.69 | 34831.4 |
| Test 4   | 4.77 | 35.16 | 343.56 | 3456.15 | 34822.8 |
| Test 5   | 4.68 | 35.18 | 343.19 | 3430.78 | 34823.8 |
| Vidurkis | 4.70 | 40.36 | 342.86 | 3442.65 | 34818.0 |

### Rūšiavimas

|          | 1k    | 10k   | 100k  | 1m     | 10m    |
|----------|-------|-------|-------|--------|--------|
| Test 1   | 0.105 | 2.100 | 19.95 | 193.16 | 1925.15 |
| Test 2   | 0.117 | 2.098 | 19.82 | 193.03 | 1924.16 |
| Test 3   | 0.105 | 2.080 | 19.81 | 192.56 | 1910.28 |
| Test 4   | 0.103 | 2.090 | 19.77 | 193.33 | 1928.79 |
| Test 5   | 0.112 | 2.077 | 19.54 | 192.20 | 1907.34 |
| Vidurkis | 0.108 | 2.089 | 19.78 | 192.86 | 1919.14 |

### Skaidymas

|          | 1k    | 10k   | 100k | 1m    | 10m   |
|----------|-------|-------|------|-------|-------|
| Test 1   | 0.291 | 1.024 | 9.77 | 96.57 | 964.37 |
| Test 2   | 0.283 | 1.009 | 9.57 | 96.54 | 983.81 |
| Test 3   | 0.282 | 1.020 | 9.54 | 96.51 | 973.62 |
| Test 4   | 0.291 | 0.999 | 9.84 | 94.77 | 986.23 |
| Test 5   | 0.313 | 1.045 | 9.89 | 96.54 | 974.35 |
| Vidurkis | 0.292 | 1.019 | 9.72 | 96.19 | 976.48 |

### Bendras laikas

|          | 1k   | 10k   | 100k   | 1m      | 10m     |
|----------|------|-------|--------|---------|---------|
| Test 1   | 5.02 | 64.62 | 375.04 | 3737.82 | 37803.3 |
| Test 2   | 5.10 | 38.21 | 370.96 | 3726.10 | 37606.1 |
| Test 3   | 5.13 | 37.97 | 370.00 | 3730.76 | 37715.3 |
| Test 4   | 5.17 | 38.25 | 373.17 | 3744.25 | 37737.8 |
| Test 5   | 5.10 | 38.30 | 372.63 | 3719.52 | 37705.5 |
| Vidurkis | 5.10 | 43.47 | 372.36 | 3731.69 | 37713.6 |


## Deque - 1 Strategija

Visi laikai milisekundėmis (ms).

### Nuskaitymas

|          | 1k    | 10k   | 100k    | 1m      | 10m     |
|----------|-------|-------|---------|---------|---------|
| Test 1   | 13.31 | 50.70 | 366.14  | 4034.50 | 45090.7 |
| Test 2   | 13.53 | 51.43 | 371.70  | 3852.19 | 45551.7 |
| Test 3   | 10.39 | 49.24 | 370.44  | 3743.83 | 43963.2 |
| Test 4   | 4.12  | 44.28 | 365.92  | 4057.64 | 44664.0 |
| Test 5   | 10.85 | 50.60 | 375.72  | 3764.76 | 44187.3 |
| Vidurkis | 10.44 | 49.25 | 369.98  | 3890.58 | 44691.4 |

### Rūšiavimas

|          | 1k   | 10k  | 100k  | 1m     | 10m    |
|----------|------|------|-------|--------|--------|
| Test 1   | 2.29 | 5.77 | 49.06 | 554.09 | 7421.42 |
| Test 2   | 2.15 | 5.75 | 50.28 | 527.40 | 7537.15 |
| Test 3   | 1.47 | 5.53 | 49.83 | 507.02 | 7522.35 |
| Test 4   | 0.83 | 5.22 | 49.53 | 586.78 | 7518.62 |
| Test 5   | 1.40 | 5.56 | 50.87 | 511.57 | 7232.77 |
| Vidurkis | 1.63 | 5.57 | 49.91 | 537.37 | 7446.46 |

### Skaidymas

|          | 1k    | 10k   | 100k | 1m    | 10m    |
|----------|-------|-------|------|-------|--------|
| Test 1   | 0.274 | 0.950 | 9.35 | 95.68 | 5632.38 |
| Test 2   | 0.296 | 0.950 | 9.32 | 99.88 | 5513.58 |
| Test 3   | 0.247 | 0.979 | 9.48 | 94.62 | 5450.52 |
| Test 4   | 0.105 | 0.936 | 9.12 | 97.78 | 5567.45 |
| Test 5   | 0.176 | 0.965 | 9.66 | 95.79 | 5536.07 |
| Vidurkis | 0.220 | 0.956 | 9.39 | 96.75 | 5539.20 |

### Bendras laikas

|          | 1k    | 10k   | 100k   | 1m      | 10m     |
|----------|-------|-------|--------|---------|---------|
| Test 1   | 15.87 | 57.43 | 424.55 | 4684.27 | 58144.5 |
| Test 2   | 15.97 | 58.13 | 431.30 | 4479.47 | 58602.4 |
| Test 3   | 12.11 | 55.74 | 429.75 | 4345.47 | 56936.1 |
| Test 4   | 5.06  | 50.43 | 424.56 | 4742.20 | 57750.1 |
| Test 5   | 12.42 | 56.59 | 436.25 | 4372.12 | 56956.1 |
| Vidurkis | 12.29 | 55.66 | 429.28 | 4524.71 | 57677.8 |

---

```markdown
## Deque - 2 Strategija (atnaujinta)

Visi laikai milisekundėmis (ms).

### Nuskaitymas

|          | 1k    | 10k   | 100k   | 1m      | 10m     |
|----------|-------|-------|--------|---------|---------|
| Test 1   | 11.60 | 49.89 | 383.31 | 4385.35 | 44636.3 |
| Test 2   | 9.25  | 47.10 | 372.39 | 3764.18 | 45237.2 |
| Test 3   | 10.65 | 73.99 | 374.13 | 3817.78 | 44441.0 |
| Test 4   | 10.44 | 48.09 | 372.21 | 3809.94 | 45328.7 |
| Test 5   | 9.36  | 47.83 | 374.99 | 3767.63 | 44741.5 |
| Vidurkis | 10.26 | 53.38 | 375.41 | 3908.98 | 44876.9 |

### Rūšiavimas

|          | 1k   | 10k  | 100k  | 1m     | 10m    |
|----------|------|------|-------|--------|--------|
| Test 1   | 2.06 | 5.86 | 48.23 | 614.52 | 7732.58 |
| Test 2   | 1.26 | 5.42 | 49.44 | 504.20 | 7858.98 |
| Test 3   | 1.72 | 5.40 | 48.62 | 479.06 | 5053.31 |
| Test 4   | 1.40 | 5.42 | 49.29 | 534.95 | 7768.81 |
| Test 5   | 1.40 | 5.38 | 48.50 | 480.01 | 5102.92 |
| Vidurkis | 1.57 | 5.50 | 48.82 | 522.55 | 6703.32 |

### Skaidymas

|          | 1k    | 10k  | 100k  | 1m      | 10m     |
|----------|-------|------|-------|---------|---------|
| Test 1   | 1.041 | 3.64 | 43.55 | 1461.46 | 22516.4 |
| Test 2   | 0.457 | 3.24 | 34.63 | 416.03  | 22718.4 |
| Test 3   | 0.534 | 2.87 | 30.64 | 402.08  | 21202.8 |
| Test 4   | 0.517 | 3.11 | 30.85 | 642.73  | 22625.0 |
| Test 5   | 0.517 | 3.37 | 30.22 | 400.48  | 21126.1 |
| Vidurkis | 0.613 | 3.25 | 33.98 | 664.56  | 22037.7 |

### Bendras laikas

|          | 1k    | 10k   | 100k   | 1m      | 10m     |
|----------|-------|-------|--------|---------|---------|
| Test 1   | 14.70 | 59.39 | 475.08 | 6461.33 | 74885.2 |
| Test 2   | 10.97 | 55.76 | 456.46 | 4684.41 | 75814.6 |
| Test 3   | 12.91 | 82.26 | 453.39 | 4698.93 | 70697.1 |
| Test 4   | 12.36 | 57.39 | 452.35 | 4987.62 | 75722.5 |
| Test 5   | 11.28 | 56.58 | 453.71 | 4648.12 | 70970.5 |
| Vidurkis | 12.44 | 62.28 | 458.20 | 5096.08 | 73617.9 |
```

## Deque - 3 Strategija

Visi laikai milisekundėmis (ms).

### Nuskaitymas

|          | 1k    | 10k   | 100k   | 1m      | 10m     |
|----------|-------|-------|--------|---------|---------|
| Test 1   | 10.07 | 50.35 | 374.20 | 3785.55 | 43137.6 |
| Test 2   | 13.33 | 49.86 | 377.27 | 3773.47 | 44600.5 |
| Test 3   | 10.10 | 49.27 | 375.73 | 3802.40 | 45007.0 |
| Test 4   | 10.10 | 48.70 | 377.94 | 3903.04 | 43944.4 |
| Test 5   | 10.29 | 49.07 | 380.84 | 3785.55 | 44474.9 |
| Vidurkis | 10.78 | 49.45 | 377.20 | 3810.00 | 44232.9 |

### Rūšiavimas

|          | 1k    | 10k  | 100k  | 1m     | 10m     |
|----------|-------|------|-------|--------|---------|
| Test 1   | 0.553 | 4.77 | 42.79 | 478.82 | 4567.97 |
| Test 2   | 0.365 | 5.08 | 43.27 | 444.69 | 5315.38 |
| Test 3   | 0.554 | 4.73 | 43.06 | 432.57 | 5310.14 |
| Test 4   | 0.527 | 4.73 | 35.42 | 431.86 | 5657.35 |
| Test 5   | 0.523 | 4.77 | 31.27 | 431.86 | 5420.23 |
| Vidurkis | 0.504 | 4.81 | 39.16 | 443.96 | 5254.21 |

### Skaidymas

|          | 1k    | 10k  | 100k  | 1m     | 10m     |
|----------|-------|------|-------|--------|---------|
| Test 1   | 1.271 | 3.33 | 30.84 | 619.60 | 19294.3 |
| Test 2   | 0.889 | 5.08 | 36.08 | 991.93 | 22601.9 |
| Test 3   | 1.611 | 4.72 | 43.05 | 825.90 | 20725.1 |
| Test 4   | 1.281 | 3.22 | 31.44 | 578.07 | 20908.5 |
| Test 5   | 1.281 | 3.17 | 31.27 | 988.44 | 21975.8 |
| Vidurkis | 1.267 | 3.91 | 34.54 | 800.79 | 21101.1 |

### Bendras laikas

|          | 1k    | 10k   | 100k   | 1m      | 10m     |
|----------|-------|-------|--------|---------|---------|
| Test 1   | 11.89 | 58.45 | 447.83 | 4883.97 | 66999.9 |
| Test 2   | 14.58 | 59.39 | 456.77 | 5210.09 | 72517.7 |
| Test 3   | 12.21 | 57.22 | 450.22 | 5066.16 | 71042.2 |
| Test 4   | 11.93 | 56.65 | 456.97 | 4813.03 | 70510.3 |
| Test 5   | 12.13 | 57.01 | 455.43 | 5323.34 | 71870.9 |
| Vidurkis | 12.55 | 57.74 | 453.44 | 5059.32 | 70588.2 |


---

## List - 1 Strategija

Visi laikai milisekundėmis (ms).

### Nuskaitymas

|          | 1k    | 10k   | 100k    | 1m      | 10m     |
|----------|-------|-------|---------|---------|---------|
| Test 1   | 13.59 | 54.24 | 379.89  | 3943.33 | 40250.9 |
| Test 2   | 13.58 | 57.19 | 382.77  | 3968.93 | 40631.2 |
| Test 3   | 11.68 | 52.51 | 380.10  | 3971.06 | 41113.4 |
| Test 4   | 16.18 | 55.03 | 388.94  | 4067.37 | 41585.3 |
| Test 5   | 10.16 | 52.17 | 392.73  | 4026.84 | 40928.5 |
| Vidurkis | 13.04 | 54.23 | 384.89  | 3995.51 | 40901.9 |

### Rūšiavimas

|          | 1k    | 10k  | 100k  | 1m     | 10m    |
|----------|-------|------|-------|--------|--------|
| Test 1   | 0.663 | 2.55 | 27.48 | 497.25 | 8495.51 |
| Test 2   | 0.596 | 2.46 | 27.16 | 491.73 | 8867.71 |
| Test 3   | 0.360 | 2.38 | 27.07 | 480.91 | 8809.47 |
| Test 4   | 0.463 | 2.36 | 28.36 | 504.00 | 8999.86 |
| Test 5   | 0.356 | 2.41 | 27.98 | 523.57 | 8443.38 |
| Vidurkis | 0.488 | 2.43 | 27.61 | 499.49 | 8723.19 |

### Skaidymas

|          | 1k    | 10k  | 100k  | 1m     | 10m    |
|----------|-------|------|-------|--------|--------|
| Test 1   | 0.521 | 1.48 | 24.14 | 325.30 | 3949.59 |
| Test 2   | 0.364 | 1.50 | 23.80 | 315.92 | 3878.52 |
| Test 3   | 0.247 | 1.41 | 24.59 | 311.18 | 4378.01 |
| Test 4   | 0.377 | 1.44 | 24.77 | 319.42 | 4510.39 |
| Test 5   | 0.246 | 1.50 | 26.25 | 344.72 | 4143.00 |
| Vidurkis | 0.351 | 1.47 | 24.71 | 323.31 | 4171.90 |

### Bendras laikas

|          | 1k    | 10k   | 100k   | 1m      | 10m     |
|----------|-------|-------|--------|---------|---------|
| Test 1   | 14.77 | 58.27 | 431.52 | 4765.88 | 52695.9 |
| Test 2   | 14.54 | 61.68 | 433.73 | 4776.58 | 53177.4 |
| Test 3   | 12.29 | 56.31 | 431.76 | 4763.15 | 54300.9 |
| Test 4   | 17.02 | 58.83 | 442.07 | 4890.79 | 55095.6 |
| Test 5   | 10.76 | 56.07 | 446.96 | 4895.13 | 53514.9 |
| Vidurkis | 13.88 | 58.23 | 437.21 | 4818.31 | 53756.9 |

---

## List - 2 Strategija

Visi laikai milisekundėmis (ms).

### Nuskaitymas

|          | 1k    | 10k   | 100k   | 1m      | 10m     |
|----------|-------|-------|--------|---------|---------|
| Test 1   | 14.24 | 55.20 | 390.15 | 4015.58 | 40874.2 |
| Test 2   | 10.79 | 52.93 | 383.62 | 3963.16 | 41192.1 |
| Test 3   | 10.48 | 52.57 | 389.42 | 3996.42 | 40633.9 |
| Test 4   | 11.01 | 52.15 | 390.66 | 4013.23 | 40909.1 |
| Test 5   | 11.24 | 52.57 | 383.62 | 3963.16 | 41192.1 |
| Vidurkis | 11.55 | 53.08 | 387.49 | 3990.31 | 40960.3 |

### Rūšiavimas

|          | 1k    | 10k  | 100k  | 1m     | 10m    |
|----------|-------|------|-------|--------|--------|
| Test 1   | 0.682 | 2.56 | 30.54 | 505.98 | 9010.43 |
| Test 2   | 0.375 | 2.73 | 28.30 | 568.12 | 8710.90 |
| Test 3   | 0.362 | 2.40 | 28.06 | 491.59 | 8624.25 |
| Test 4   | 0.363 | 2.46 | 28.70 | 506.72 | 8952.23 |
| Test 5   | 0.364 | 2.46 | 28.70 | 506.72 | 8952.23 |
| Vidurkis | 0.429 | 2.52 | 28.86 | 515.82 | 8850.01 |

### Skaidymas

|          | 1k    | 10k  | 100k  | 1m     | 10m    |
|----------|-------|------|-------|--------|--------|
| Test 1   | 0.356 | 2.68 | 16.22 | 213.01 | 4269.70 |
| Test 2   | 0.245 | 2.63 | 16.17 | 217.63 | 4229.54 |
| Test 3   | 0.250 | 2.61 | 16.12 | 209.80 | 4472.93 |
| Test 4   | 0.244 | 2.70 | 15.96 | 212.13 | 4187.75 |
| Test 5   | 0.244 | 2.70 | 15.96 | 212.13 | 4187.75 |
| Vidurkis | 0.268 | 2.67 | 16.09 | 212.94 | 4269.53 |

### Bendras laikas

|          | 1k    | 10k   | 100k   | 1m      | 10m     |
|----------|-------|-------|--------|---------|---------|
| Test 1   | 15.28 | 60.45 | 436.92 | 4734.56 | 54154.3 |
| Test 2   | 11.41 | 58.29 | 428.09 | 4748.91 | 54132.5 |
| Test 3   | 11.10 | 57.58 | 433.60 | 4697.81 | 53731.1 |
| Test 4   | 11.62 | 57.31 | 435.33 | 4732.07 | 54049.1 |
| Test 5   | 11.85 | 57.31 | 435.33 | 4732.07 | 54049.1 |
| Vidurkis | 12.25 | 58.19 | 433.85 | 4728.88 | 54023.2 |

## List - 3 Strategija

Visi laikai milisekundėmis (ms).

### Nuskaitymas

|          | 1k    | 10k   | 100k   | 1m      | 10m     |
|----------|-------|-------|--------|---------|---------|
| Test 1   | 10.46 | 52.18 | 400.07 | 4026.28 | 41060.6 |
| Test 2   | 13.94 | 54.45 | 396.40 | 4065.21 | 40980.2 |
| Test 3   | 10.85 | 52.46 | 391.10 | 4033.89 | 40661.7 |
| Test 4   | 11.39 | 52.76 | 399.86 | 4057.94 | 40718.6 |
| Test 5   | 11.84 | 52.64 | 399.86 | 4026.28 | 40980.2 |  
| Vidurkis | 11.70 | 52.90 | 397.46 | 4041.92 | 40880.3 |

### Rūšiavimas

|          | 1k    | 10k  | 100k  | 1m     | 10m    |
|----------|-------|------|-------|--------|--------|
| Test 1   | 0.575 | 2.18 | 26.49 | 411.11 | 7404.69 |
| Test 2   | 0.958 | 2.26 | 25.90 | 431.47 | 7703.56 |
| Test 3   | 0.524 | 2.17 | 25.71 | 408.23 | 8023.54 |
| Test 4   | 0.531 | 2.18 | 27.54 | 415.31 | 7719.74 |
| Test 5   | 0.321 | 2.17 | 26.52 | 415.31 | 7719.74 |
| Vidurkis | 0.582 | 2.19 | 26.43 | 416.29 | 7714.25 |

### Skaidymas

|          | 1k    | 10k  | 100k  | 1m     | 10m    |
|----------|-------|------|-------|--------|--------|
| Test 1   | 0.326 | 2.18 | 28.13 | 295.82 | 3833.33 |
| Test 2   | 0.480 | 2.26 | 28.10 | 293.31 | 3861.21 |
| Test 3   | 0.323 | 2.17 | 25.71 | 280.79 | 3804.40 |
| Test 4   | 0.321 | 2.17 | 27.62 | 274.96 | 3928.39 |
| Test 5   | 0.321 | 2.19 | 25.54 | 274.96 | 3928.39 |
| Vidurkis | 0.354 | 2.19 | 27.02 | 283.97 | 3871.14 |

### Bendras laikas

|          | 1k    | 10k   | 100k   | 1m      | 10m     |
|----------|-------|-------|--------|---------|---------|
| Test 1   | 11.36 | 57.25 | 454.68 | 4733.21 | 52298.6 |
| Test 2   | 15.38 | 59.75 | 450.40 | 4789.98 | 52545.0 |
| Test 3   | 11.70 | 57.52 | 444.42 | 4722.91 | 52489.6 |
| Test 4   | 12.24 | 57.10 | 453.02 | 4748.21 | 52366.8 |
| Test 5   | 12.49 | 57.00 | 452.00 | 4748.21 | 52366.8 |
| Vidurkis | 12.63 | 57.72 | 450.90 | 4748.50 | 52413.4 |


## Bendro laiko palyginimas (vidurkiai ms.)

| Konteineris | Strategija | 1k    | 10k   | 100k   | 1m      | 10m     |
|-------------|------------|-------|-------|--------|---------|---------|
| Vector      | 1          | 12.20 | 52.00 | 364.00 | 3745.00 | 38196.0 |
| Vector      | 2          | 11.67 | 52.18 | 369.15 | 3791.61 | 39617.1 |
| Vector      | 3          | 5.10  | 43.47 | 372.36 | 3731.69 | 37713.6 |
| List        | 1          | 13.88 | 58.23 | 437.21 | 4818.31 | 53756.9 |
| List        | 2          | 12.25 | 58.19 | 433.85 | 4728.88 | 54023.2 |
| List        | 3          | 12.63 | 57.72 | 450.90 | 4748.50 | 52413.4 |
| Deque       | 1          | 12.29 | 55.66 | 429.28 | 4524.71 | 57677.8 |
| Deque       | 2          | 12.44 | 62.28 | 458.20 | 5096.08 | 73617.9 |
| Deque       | 3          | 12.55 | 57.74 | 453.44 | 5059.32 | 70588.2 |

## Rezultatų apžvalga

### Konteinerių palyginimas

Iš gautų rezultatų matoma, kad **vector** konteineris yra greičiausias visose operacijose.
Tai lemia jo vientisos atminties struktūra — visi elementai saugomi gretimose atminties
vietose, todėl procesorius gali efektyviai naudoti talpyklą (cache). Su 10 milijonų įrašų
vector bendras laikas siekė ~38 sekundes, o tai yra gerokai greičiau nei list (~53s) ar deque (~58-74s).

**List** konteineris rodo vidutinį našumą — greitesnis nei deque, bet lėtesnis nei vector.
List naudoja susieto sąrašo struktūrą, kur kiekvienas elementas saugo rodyklę į kitą elementą,
todėl atminties prieiga yra netiesioginė ir lėtesnė. Tačiau list turi vieną svarbų privalumą —
elementų trynimas bet kurioje vietoje yra O(1), todėl 2 strategijoje list pasirodo geriau nei deque.

**Deque** konteineris pasirodė lėčiausias, ypač 2 strategijoje su 10 milijonų įrašų (~74s).
Deque naudoja fiksuoto dydžio atminties blokų seką, todėl prieiga prie elementų reikalauja
papildomo netiesioginio kreipinio. Taip pat programos uždarymas su 10 milijonų įrašų užtrunka
ilgiau nei vector ar list, nes deque turi atlaisvinti kiekvieną bloką atskirai.

### Strategijų palyginimas

**1 strategija** — greičiausia arba panaši į 3 strategiją daugumai konteinerių, tačiau
neefektyviausia atminties atžvilgiu, nes tas pats studentas egzistuoja dviejuose
konteineriuose vienu metu (3 konteineriai atmintyje).

**2 strategija** — efektyvesnė atminties atžvilgiu (2 konteineriai), tačiau lėtesnė.
Tai ypač pastebima su deque konteineriu — 2 strategija su deque 10m įrašų užtruko ~74s,
palyginti su ~58s 1 strategijoje. Tai lemia dažni trynimai iš deque vidurio, kurie
reikalauja elementų perstūmimo. Su list konteineriu trynimai efektyvesni (O(1)),
todėl skirtumas mažesnis.

**3 strategija** — naudoja `std::partition` algoritmą, kuris pertvarko elementus vietoje
vienu praėjimu. Tai greičiausia strategija vector konteineriui (10m: ~37.7s), tačiau
deque atveju rezultatai nėra geresni už 1 strategiją dėl konteinerio struktūros ypatumų.
List 3 strategija taip pat šiek tiek geresnė už 1 ir 2 strategijas.

### Bendros išvados

- **Greičiausias konteineris**: `vector` — visose operacijose ir strategijose
- **Greičiausia strategija**: 3 strategija su `vector` (`std::partition`) — 10m: ~37.7s
- **Lėčiausia kombinacija**: 2 strategija su `deque` — 10m: ~73.6s
- **Geriausias atminties efektyvumas**: 2 arba 3 strategija (tik 2 konteineriai atmintyje)
- Nuskaitymas iš failo dominuoja bendrą laiką (~90%), rūšiavimas ~6%, skaidymas ~4%
- Laikas auga beveik tiesiškai (O(n)) didėjant įrašų skaičiui, išskyrus rūšiavimą (O(n log n))
- `Deque` pranašumas atsiskleidžia tik greitam įterpimui iš abiejų galų — šioje užduotyje
  jo privalumai nepasireiškė


## Testavimo sistemos parametrai

| Parametras | Reikšmė |
|------------|---------|
| Modelis | MacBook Air M4 |
| Procesorius | Apple M4 (10 branduolių) |
| RAM | 16 GB |
| Saugykla | 512 GB SSD |
| Operacinė sistema | macOS |


## v0.4 Testavimo nuotraukos

![](testavimas/testavimo%20nuotraukos/1testavimas01.png)
![](testavimas/testavimo%20nuotraukos/1testavimas02.png)
![](testavimas/testavimo%20nuotraukos/1testavimas03.png)
![](testavimas/testavimo%20nuotraukos/2tyrimas01.png)
![](testavimas/testavimo%20nuotraukos/2tyrimas02.png)
![](testavimas/testavimo%20nuotraukos/2tyrimas03.png)
![](testavimas/testavimo%20nuotraukos/2tyrimas04.png)
![](testavimas/testavimo%20nuotraukos/2tyrimas05.png)

## v1.0 Testavimo nuotraukos

![](testavimas/v1.0%20testavimo%20nuotraukos/Screenshot%202026-03-17%20at%2019.48.19.png)
![](testavimas/v1.0%20testavimo%20nuotraukos/Screenshot%202026-03-17%20at%2019.49.32.png)
![](testavimas/v1.0%20testavimo%20nuotraukos/Screenshot%202026-03-17%20at%2019.50.32.png)
![](testavimas/v1.0%20testavimo%20nuotraukos/Screenshot%202026-03-17%20at%2019.51.29.png)
![](testavimas/v1.0%20testavimo%20nuotraukos/Screenshot%202026-03-17%20at%2019.52.26.png)
![](testavimas/v1.0%20testavimo%20nuotraukos/Screenshot%202026-03-17%20at%2020.59.43.png)
![](testavimas/v1.0%20testavimo%20nuotraukos/Screenshot%202026-03-17%20at%2021.03.53.png)
![](testavimas/v1.0%20testavimo%20nuotraukos/Screenshot%202026-03-17%20at%2021.05.35.png)
![](testavimas/v1.0%20testavimo%20nuotraukos/Screenshot%202026-03-17%20at%2021.07.56.png)
![](testavimas/v1.0%20testavimo%20nuotraukos/Screenshot%202026-03-17%20at%2021.09.39.png)
![](testavimas/v1.0%20testavimo%20nuotraukos/Screenshot%202026-03-18%20at%2011.43.06.png)
![](testavimas/v1.0%20testavimo%20nuotraukos/Screenshot%202026-03-18%20at%2011.45.11.png)
![](testavimas/v1.0%20testavimo%20nuotraukos/Screenshot%202026-03-18%20at%2011.47.15.png)
![](testavimas/v1.0%20testavimo%20nuotraukos/Screenshot%202026-03-18%20at%2011.48.39.png)
![](testavimas/v1.0%20testavimo%20nuotraukos/Screenshot%202026-03-18%20at%2011.50.00.png)
![](testavimas/v1.0%20testavimo%20nuotraukos/Screenshot%202026-03-18%20at%2011.52.00.png)
![](testavimas/v1.0%20testavimo%20nuotraukos/Screenshot%202026-03-18%20at%2011.53.18.png)
![](testavimas/v1.0%20testavimo%20nuotraukos/Screenshot%202026-03-18%20at%2011.54.38.png)
![](testavimas/v1.0%20testavimo%20nuotraukos/Screenshot%202026-03-18%20at%2011.55.56.png)
![](testavimas/v1.0%20testavimo%20nuotraukos/Screenshot%202026-03-18%20at%2011.57.11.png)
![](testavimas/v1.0%20testavimo%20nuotraukos/Screenshot%202026-03-18%20at%2011.58.51.png)
![](testavimas/v1.0%20testavimo%20nuotraukos/Screenshot%202026-03-18%20at%2012.00.31.png)
![](testavimas/v1.0%20testavimo%20nuotraukos/Screenshot%202026-03-18%20at%2012.01.42.png)
![](testavimas/v1.0%20testavimo%20nuotraukos/Screenshot%202026-03-18%20at%2012.02.51.png)
![](testavimas/v1.0%20testavimo%20nuotraukos/Screenshot%202026-03-18%20at%2012.04.01.png)
![](testavimas/v1.0%20testavimo%20nuotraukos/Screenshot%202026-03-18%20at%2012.07.24.png)
![](testavimas/v1.0%20testavimo%20nuotraukos/Screenshot%202026-03-18%20at%2012.09.11.png)
![](testavimas/v1.0%20testavimo%20nuotraukos/Screenshot%202026-03-18%20at%2012.10.58.png)
![](testavimas/v1.0%20testavimo%20nuotraukos/Screenshot%202026-03-18%20at%2012.40.11.png)
![](testavimas/v1.0%20testavimo%20nuotraukos/Screenshot%202026-03-18%20at%2012.41.35.png)
![](testavimas/v1.0%20testavimo%20nuotraukos/Screenshot%202026-03-18%20at%2012.42.47.png)
![](testavimas/v1.0%20testavimo%20nuotraukos/Screenshot%202026-03-18%20at%2012.44.02.png)
![](testavimas/v1.0%20testavimo%20nuotraukos/Screenshot%202026-03-18%20at%2012.45.30.png)
![](testavimas/v1.0%20testavimo%20nuotraukos/Screenshot%202026-03-18%20at%2012.48.29.png)
![](testavimas/v1.0%20testavimo%20nuotraukos/Screenshot%202026-03-18%20at%2012.50.22.png)
![](testavimas/v1.0%20testavimo%20nuotraukos/Screenshot%202026-03-18%20at%2012.52.13.png)
![](testavimas/v1.0%20testavimo%20nuotraukos/Screenshot%202026-03-18%20at%2012.54.05.png)
![](testavimas/v1.0%20testavimo%20nuotraukos/Screenshot%202026-03-18%20at%2012.56.13.png)
![](testavimas/v1.0%20testavimo%20nuotraukos/Screenshot%202026-03-18%20at%2012.58.30.png)
![](testavimas/v1.0%20testavimo%20nuotraukos/Screenshot%202026-03-18%20at%2013.00.03.png)
![](testavimas/v1.0%20testavimo%20nuotraukos/Screenshot%202026-03-18%20at%2013.01.52.png)
![](testavimas/v1.0%20testavimo%20nuotraukos/Screenshot%202026-03-18%20at%2013.03.26.png)
![](testavimas/v1.0%20testavimo%20nuotraukos/Screenshot%202026-03-18%20at%2013.04.58.png)
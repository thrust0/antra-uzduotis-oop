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

## Įdiegimo instrukcija

### Reikalavimai
- C++17 arba naujesnė versija
- g++ kompiliatorius
- make

### Kompiliavimas

Pasirinkite norimą konteinerio versiją ir eikite į atitinkamą aplanką:
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

## Naudojimosi instrukcija

### Programos paleidimas
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
├── v0.4/              # v0.4 programos šaltinio kodas
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



Here are the tables for Vector Strategy 2 and Strategy 3:

---

## Vector - 2 Strategija

Visi laikai milisekundėmis (ms).

### Nuskaitymas

|          | 1k    | 10k   | 100k   | 1m      | 10m     |
|----------|-------|-------|--------|---------|---------|
| Test 1   | 9.08  | 47.88 | 333.04 | 3435.34 | 34809.7 |
| Test 2   | 9.76  | 47.35 | 333.95 | 3431.25 | 34656.3 |
| Test 3   | 7.18  | 41.93 | 331.39 | 3429.52 | 34860.4 |
| Test 4   | 10.21 | 48.04 | 327.44 | 3410.6  | 34994.2 |
| Test 5   | 11.94 | 52.82 | 327.81 | 3413.66 | 35183.2 |
| Vidurkis | 9.63  | 47.60 | 330.73 | 3424.07 | 34900.8 |

### Rūšiavimas

|          | 1k    | 10k   | 100k  | 1m     | 10m    |
|----------|-------|-------|-------|--------|--------|
| Test 1   | 0.604 | 2.548 | 22.09 | 220.11 | 2234.45 |
| Test 2   | 0.663 | 2.588 | 22.03 | 221.42 | 2236.67 |
| Test 3   | 0.759 | 2.443 | 21.80 | 220.87 | 2228.63 |
| Test 4   | 0.995 | 2.558 | 21.64 | 218.37 | 2283.25 |
| Test 5   | 0.815 | 2.642 | 21.62 | 219.06 | 2378.28 |
| Vidurkis | 0.767 | 2.556 | 21.84 | 219.96 | 2272.26 |

### Skaidymas

|          | 1k    | 10k   | 100k  | 1m     | 10m    |
|----------|-------|-------|-------|--------|--------|
| Test 1   | 0.246 | 1.285 | 11.43 | 127.93 | 1613.4 |
| Test 2   | 0.242 | 1.267 | 11.37 | 127.38 | 1561.66 |
| Test 3   | 0.299 | 1.219 | 11.61 | 127.09 | 1736.61 |
| Test 4   | 0.362 | 1.271 | 11.18 | 125.36 | 1680.96 |
| Test 5   | 0.316 | 1.379 | 11.50 | 128.59 | 1746.94 |
| Vidurkis | 0.293 | 1.284 | 11.42 | 127.27 | 1667.91 |

### Bendras laikas

|          | 1k    | 10k   | 100k   | 1m      | 10m     |
|----------|-------|-------|--------|---------|---------|
| Test 1   | 9.93  | 51.71 | 366.56 | 3783.38 | 38657.6 |
| Test 2   | 10.67 | 51.59 | 367.35 | 3780.05 | 38454.6 |
| Test 3   | 8.24  | 45.59 | 364.79 | 3777.47 | 38825.7 |
| Test 4   | 11.57 | 51.87 | 360.26 | 3754.32 | 38958.4 |
| Test 5   | 13.07 | 56.84 | 360.93 | 3761.31 | 39308.4 |
| Vidurkis | 10.70 | 51.52 | 363.98 | 3771.31 | 38840.9 |

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

## Deque - 2 Strategija

Visi laikai milisekundėmis (ms).

### Nuskaitymas

|          | 1k    | 10k   | 100k   | 1m      | 10m     |
|----------|-------|-------|--------|---------|---------|
| Test 1   | 8.02  | 46.96 | 377.99 | 3783.29 | 44064.0 |
| Test 2   | 9.91  | 48.31 | 374.73 | 3788.55 | 44364.3 |
| Test 3   | 10.80 | 48.08 | 372.40 | 3753.27 | 44391.1 |
| Test 4   | 9.20  | 48.61 | 374.30 | 3755.75 | 44617.1 |
| Test 5   | 13.66 | 50.66 | 371.98 | 3773.06 | 44409.1 |
| Vidurkis | 10.32 | 48.52 | 374.28 | 3770.78 | 44369.1 |

### Rūšiavimas

|          | 1k   | 10k  | 100k  | 1m     | 10m    |
|----------|------|------|-------|--------|--------|
| Test 1   | 1.25 | 5.30 | 48.52 | 480.73 | 5109.05 |
| Test 2   | 1.47 | 5.39 | 50.37 | 544.66 | 7433.60 |
| Test 3   | 1.41 | 5.37 | 48.74 | 487.15 | 5226.02 |
| Test 4   | 1.32 | 5.40 | 48.55 | 481.96 | 5114.59 |
| Test 5   | 2.20 | 5.69 | 48.71 | 489.08 | 5356.94 |
| Vidurkis | 1.53 | 5.43 | 48.98 | 496.71 | 5648.04 |

### Skaidymas

|          | 1k    | 10k  | 100k  | 1m      | 10m     |
|----------|-------|------|-------|---------|---------|
| Test 1   | 0.422 | 2.86 | 29.79 | 533.31  | 43181.2 |
| Test 2   | 0.471 | 3.02 | 34.61 | 927.12  | 40675.2 |
| Test 3   | 0.415 | 2.95 | 29.84 | 664.85  | 41843.3 |
| Test 4   | 0.454 | 2.89 | 29.40 | 645.97  | 40382.7 |
| Test 5   | 0.623 | 4.00 | 37.26 | 1109.63 | 39820.1 |
| Vidurkis | 0.477 | 3.14 | 32.18 | 776.18  | 41180.5 |

### Bendras laikas

|          | 1k    | 10k   | 100k   | 1m      | 10m     |
|----------|-------|-------|--------|---------|---------|
| Test 1   | 9.69  | 54.35 | 456.29 | 4797.33 | 92354.2 |
| Test 2   | 11.84 | 57.24 | 459.72 | 5260.32 | 92473.0 |
| Test 3   | 12.63 | 56.40 | 450.97 | 4905.27 | 91460.4 |
| Test 4   | 10.98 | 56.89 | 452.25 | 4883.68 | 90114.4 |
| Test 5   | 16.48 | 60.66 | 457.94 | 5371.76 | 89586.1 |
| Vidurkis | 12.32 | 57.11 | 455.43 | 5043.67 | 91197.6 |

---

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


Here are all the tables for List:

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
| Test 1   | 13.83 | 55.66 | 391.55 | 4034.63 | 41048.5 |
| Test 2   | 11.30 | 52.48 | 394.49 | 4012.59 | 40770.5 |
| Test 3   | 8.63  | 50.25 | 397.68 | 4063.25 | 41077.2 |
| Test 4   | 10.28 | 52.17 | 398.84 | 4019.53 | 40599.0 |
| Test 5   | 9.96  | 51.72 | 400.49 | 4067.01 | 40603.4 |
| Vidurkis | 10.80 | 52.46 | 396.61 | 4039.40 | 40819.7 |

### Rūšiavimas

|          | 1k    | 10k  | 100k  | 1m     | 10m    |
|----------|-------|------|-------|--------|--------|
| Test 1   | 0.490 | 2.52 | 28.50 | 508.47 | 8908.93 |
| Test 2   | 0.409 | 2.36 | 28.36 | 498.39 | 8518.52 |
| Test 3   | 0.318 | 2.36 | 28.33 | 604.80 | 8911.66 |
| Test 4   | 0.354 | 2.41 | 28.64 | 510.96 | 8451.63 |
| Test 5   | 0.358 | 2.41 | 30.38 | 515.69 | 8736.89 |
| Vidurkis | 0.386 | 2.41 | 28.84 | 527.66 | 8705.53 |

### Skaidymas

|          | 1k    | 10k  | 100k  | 1m     | 10m    |
|----------|-------|------|-------|--------|--------|
| Test 1   | 0.618 | 2.62 | 35.89 | 454.69 | 5415.44 |
| Test 2   | 0.522 | 2.68 | 34.89 | 457.92 | 5807.53 |
| Test 3   | 0.408 | 2.64 | 35.84 | 482.14 | 5682.79 |
| Test 4   | 0.447 | 2.61 | 35.68 | 497.30 | 5262.39 |
| Test 5   | 0.445 | 2.74 | 35.14 | 470.82 | 5457.35 |
| Vidurkis | 0.488 | 2.66 | 35.49 | 472.57 | 5525.10 |

### Bendras laikas

|          | 1k    | 10k   | 100k   | 1m      | 10m     |
|----------|-------|-------|--------|---------|---------|
| Test 1   | 15.09 | 60.81 | 455.93 | 4997.78 | 55372.9 |
| Test 2   | 12.23 | 57.52 | 457.73 | 4968.90 | 55096.6 |
| Test 3   | 9.36  | 55.25 | 462.35 | 5150.19 | 55671.6 |
| Test 4   | 11.08 | 57.20 | 463.16 | 5027.79 | 54313.0 |
| Test 5   | 10.76 | 56.87 | 466.01 | 5053.51 | 54797.6 |
| Vidurkis | 11.70 | 57.49 | 461.04 | 5039.63 | 55050.3 |

---

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




```markdown
## Rezultatų apžvalga

### Konteinerių palyginimas

Iš gautų rezultatų matoma, kad **vector** konteineris yra greičiausias beveik visose operacijose.
Tai lemia jo vientisos atminties struktūra - visi elementai saugomi gretimose atminties vietose,
todėl procesorius gali efektyviai naudoti talpyklą (cache).

**List** konteineris rodo vidutinį našumą. Nuskaitymas ir rūšiavimas yra lėtesni nei vector,
tačiau spartesni nei deque. List naudoja susieto sąrašo struktūrą - kiekvienas elementas
saugo rodyklę į kitą elementą, todėl atminties prieiga yra netiesiogine ir lėtesnė.
Tačiau list turi savų privalumų - efektyvus elementų įterpimas ir trynimas bet kurioje vietoje.

**Deque** konteineris pasirodė lėčiausias, ypač su 10 milijonų įrašų. Deque naudoja
fiksuoto dydžio atminties blokų seką, todėl prieiga prie elementų reikalauja papildomo
netiesioginio kreipinio. Programos uždarymas su 10 milijonų įrašų užtrunka ilgiau nei
vector ar list, nes deque turi atlaisvinti kiekvieną bloką atskirai.

### Strategijų palyginimas

**1 strategija** - greičiausia skaidymo operacija, tačiau neefektyviausia atminties atžvilgiu,
nes tas pats studentas egzistuoja dviejuose konteineriuose vienu metu.

**2 strategija** - efektyvesnė atminties atžvilgiu, tačiau lėtesnė už 1 strategiją.
Tai ypač pastebima su deque konteineriu, kur dažni trynimai iš vidurio yra "skausmingi"
dėl elemento perstūmimo poreikio. Su list konteineriu trynimai efektyvesni.

**3 strategija** - naudoja `std::partition` algoritmą, kuris pertvarko elementus vietoje
vienu praėjimu. Tai greičiausia strategija vector ir list konteineriams, tačiau deque
atveju rezultatai nėra tokie ryškūs dėl konteinerio struktūros ypatumų.

### Bendros išvados

- **Geriausias konteineris** nuosekliam darbui (nuskaitymas, rūšiavimas, skaidymas): `vector`
- **Geriausias konteineris** dažnam įterpimui/trynimui iš bet kurios vietos: `list`
- **Deque** pranašumas atsiskleidžia tik kai reikia greitai įterpti elementus iš abiejų galų
- Laikas auga beveik tiesiškai (O(n)) didėjant įrašų skaičiui, išskyrus rūšiavimą (O(n log n))
- Skaidymo operacija sudaro mažiausią laiko dalį - dominuoja nuskaitymas iš failo (~90% laiko)
```

## Testavimo sistemos parametrai

| Parametras | Reikšmė |
|------------|---------|
| Modelis | MacBook Air M4 |
| Procesorius | Apple M4 (10 branduolių) |
| RAM | 16 GB |
| Saugykla | 512 GB SSD |
| Operacinė sistema | macOS |

## Testavimo nuotraukos
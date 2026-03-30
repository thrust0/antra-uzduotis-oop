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

# Testavimas 

## Struct vs Class spartos palyginimas

Visi laikai milisekundėmis (ms). Naudotas vector konteineris, 1 strategija.

### Struct versija

#### 100k įrašų

|          | Nuskaitymas | Rūšiavimas | Skaidymas | Bendras |
|----------|-------------|------------|-----------|---------|
| Test 1   | 343.46      | 21.26      | 8.46      | 373.18  |
| Test 2   | 346.63      | 21.87      | 8.31      | 376.81  |
| Test 3   | 342.31      | 21.93      | 8.33      | 372.57  |
| Test 4   | 342.66      | 21.38      | 8.23      | 372.27  |
| Test 5   | 367.63      | 21.72      | 9.31      | 398.66  |
| Vidurkis | 348.54      | 21.63      | 8.53      | 378.70  |

#### 1m įrašų

|          | Nuskaitymas | Rūšiavimas | Skaidymas | Bendras |
|----------|-------------|------------|-----------|---------|
| Test 1   | 3334.32     | 218.66     | 93.19     | 3646.18 |
| Test 2   | 3371.16     | 218.92     | 92.63     | 3682.72 |
| Test 3   | 3342.76     | 219.94     | 92.29     | 3654.99 |
| Test 4   | 3331.78     | 216.35     | 92.38     | 3640.51 |
| Test 5   | 3433.12     | 222.07     | 94.32     | 3749.51 |
| Vidurkis | 3362.63     | 219.19     | 92.96     | 3674.78 |

### Class versija

#### 100k įrašų

|          | Nuskaitymas | Rūšiavimas | Skaidymas | Bendras |
|----------|-------------|------------|-----------|---------|
| Test 1   | 348.75      | 56.57      | 10.79     | 416.10  |
| Test 2   | 352.28      | 56.45      | 10.42     | 419.15  |
| Test 3   | 369.45      | 56.67      | 11.20     | 437.32  |
| Test 4   | 349.42      | 56.39      | 10.91     | 416.73  |
| Test 5   | 355.41      | 55.56      | 10.25     | 421.22  |
| Vidurkis | 355.06      | 56.33      | 10.71     | 422.10  |

#### 1m įrašų

|          | Nuskaitymas | Rūšiavimas | Skaidymas | Bendras |
|----------|-------------|------------|-----------|---------|
| Test 1   | 3422.96     | 611.87     | 163.48    | 4198.32 |
| Test 2   | 3408.48     | 605.54     | 165.10    | 4179.12 |
| Test 3   | 3389.49     | 617.11     | 171.96    | 4178.55 |
| Test 4   | 3395.70     | 609.05     | 166.34    | 4171.09 |
| Test 5   | 3379.33     | 614.55     | 162.77    | 4156.65 |
| Vidurkis | 3399.19     | 611.62     | 165.93    | 4176.75 |

---

### Struct vs Class palyginimas (vidurkiai ms.)

| Versija | Failo dydis | Nuskaitymas | Rūšiavimas | Skaidymas | Bendras |
|---------|-------------|-------------|------------|-----------|---------|
| Struct  | 100k        | 348.54      | 21.63      | 8.53      | 378.70  |
| Class   | 100k        | 355.06      | 56.33      | 10.71     | 422.10  |
| Struct  | 1m          | 3362.63     | 219.19     | 92.96     | 3674.78 |
| Class   | 1m          | 3399.19     | 611.62     | 165.93    | 4176.75 |

### Rezultatų apžvalga

Iš gautų rezultatų matyti, kad `struct` versija yra greitesnė už `class` versiją abiejuose
failo dydžiuose. Didžiausias skirtumas pastebimas **rūšiavimo** operacijoje:

- 100k įrašų: struct ~21ms vs class ~56ms — class versija lėtesnė **2.6x**
- 1m įrašų: struct ~219ms vs class ~611ms — class versija lėtesnė **2.8x**

Tai gali būti susiję su tuo, kad class versijoje rūšiavimo metu naudojami getter metodai
(`get_first_name()`, `get_last_name()`, `get_result()`) vietoje tiesioginės prieigos prie
laukų, o tai sukelia papildomą funkcijų iškvietimo išlaidą (function call overhead).

Nuskaitymo ir skaidymo laikai yra panašūs abiejose versijose, todėl pagrindinis
našumo skirtumas slypi rūšiavimo operacijoje su getter metodais.

## Kompiliatoriaus flag'ų testavimas

### O1 flag

#### 100k įrašų

|          | Nuskaitymas | Rūšiavimas | Skaidymas | Bendras |
|----------|-------------|------------|-----------|---------|
| Test 1   | 135.33      | 11.05      | 2.08      | 148.46  |
| Test 2   | 128.35      | 10.98      | 1.67      | 140.99  |
| Test 3   | 119.40      | 10.69      | 1.45      | 131.54  |
| Test 4   | 127.97      | 10.95      | 1.57      | 140.49  |
| Test 5   | 126.87      | 11.11      | 1.56      | 139.53  |
| Vidurkis | 127.58      | 10.96      | 1.67      | 140.20  |

#### 1m įrašų

|          | Nuskaitymas | Rūšiavimas | Skaidymas | Bendras |
|----------|-------------|------------|-----------|---------|
| Test 1   | 1088.33     | 135.46     | 41.50     | 1265.30 |
| Test 2   | 1072.10     | 136.79     | 32.33     | 1241.21 |
| Test 3   | 1058.04     | 132.80     | 36.33     | 1227.17 |
| Test 4   | 1067.59     | 131.71     | 32.01     | 1231.31 |
| Test 5   | 1065.44     | 134.19     | 30.95     | 1230.58 |
| Vidurkis | 1070.30     | 134.19     | 34.62     | 1239.11 |

### O2 flag

#### 100k įrašų

|          | Nuskaitymas | Rūšiavimas | Skaidymas | Bendras |
|----------|-------------|------------|-----------|---------|
| Test 1   | 133.40      | 10.91      | 1.99      | 146.31  |
| Test 2   | 128.09      | 10.77      | 1.92      | 140.78  |
| Test 3   | 125.78      | 11.09      | 1.82      | 138.69  |
| Test 4   | 126.81      | 10.64      | 1.93      | 139.38  |
| Test 5   | 126.70      | 10.82      | 1.60      | 139.12  |
| Vidurkis | 128.16      | 10.85      | 1.85      | 140.86  |

#### 1m įrašų

|          | Nuskaitymas | Rūšiavimas | Skaidymas | Bendras |
|----------|-------------|------------|-----------|---------|
| Test 1   | 1062.86     | 127.80     | 31.85     | 1222.51 |
| Test 2   | 1050.66     | 130.13     | 30.28     | 1211.07 |
| Test 3   | 1054.82     | 126.83     | 35.21     | 1216.86 |
| Test 4   | 1061.46     | 126.14     | 28.90     | 1216.51 |
| Test 5   | 1056.94     | 127.66     | 29.06     | 1213.66 |
| Vidurkis | 1057.35     | 127.71     | 31.06     | 1216.12 |

### O3 flag

#### 100k įrašų

|          | Nuskaitymas | Rūšiavimas | Skaidymas | Bendras |
|----------|-------------|------------|-----------|---------|
| Test 1   | 123.43      | 10.56      | 1.53      | 135.52  |
| Test 2   | 125.85      | 10.50      | 1.56      | 137.90  |
| Test 3   | 132.01      | 10.87      | 1.54      | 144.42  |
| Test 4   | 124.95      | 10.67      | 1.54      | 137.16  |
| Test 5   | 132.31      | 10.34      | 1.59      | 144.24  |
| Vidurkis | 127.71      | 10.59      | 1.55      | 139.85  |

#### 1m įrašų

|          | Nuskaitymas | Rūšiavimas | Skaidymas | Bendras |
|----------|-------------|------------|-----------|---------|
| Test 1   | 1055.89     | 123.89     | 28.96     | 1208.73 |
| Test 2   | 1053.39     | 125.93     | 28.99     | 1208.31 |
| Test 3   | 1055.18     | 123.69     | 29.40     | 1208.27 |
| Test 4   | 1054.15     | 123.85     | 29.71     | 1207.71 |
| Test 5   | 1054.06     | 124.67     | 29.36     | 1208.09 |
| Vidurkis | 1054.53     | 124.41     | 29.28     | 1208.22 |

---

## Kompiliatoriaus optimizavimo flagų palyginimas (vidurkiai ms.)

### 100k įrašų

| Flag | Nuskaitymas | Rūšiavimas | Skaidymas | Bendras | Failo dydis |
|------|-------------|------------|-----------|---------|-------------|
| O0   | 355.06      | 56.33      | 10.71     | 422.10  | ?           |
| O1   | 127.58      | 10.96      | 1.67      | 140.20  | ?           |
| O2   | 128.16      | 10.85      | 1.85      | 140.86  | ?           |
| O3   | 127.71      | 10.59      | 1.55      | 139.85  | ?           |

### 1m įrašų

| Flag | Nuskaitymas | Rūšiavimas | Skaidymas | Bendras | Failo dydis |
|------|-------------|------------|-----------|---------|-------------|
| O0   | 3399.19     | 611.62     | 165.93    | 4176.75 | ?           |
| O1   | 1070.30     | 134.19     | 34.62     | 1239.11 | ?           |
| O2   | 1057.35     | 127.71     | 31.06     | 1216.12 | ?           |
| O3   | 1054.53     | 124.41     | 29.28     | 1208.22 | ?           |

### Išvados

Optimizavimo flagai turi labai didelę įtaką programos veikimo greičiui:

- **O0 → O1** perėjimas duoda didžiausią spartą — bendras laikas 100k atveju
  sumažėjo nuo ~422ms iki ~140ms, t.y. programa tapo **3x greitesnė**
- **O1 → O2** skirtumas minimalus — ~140ms vs ~141ms (100k atveju), praktiškai
  jokio skirtumo
- **O2 → O3** taip pat minimalus skirtumas — ~141ms vs ~140ms (100k atveju),
  O3 šiek tiek geresnis tik rūšiavimo operacijoje
- Didžiausią naudą optimizavimas duoda **rūšiavimo** operacijai — O0: ~56ms,
  O1: ~11ms, tai yra **5x pagreitis** vien pirmojo lygio optimizavimo dėka
- Nuskaitymas taip pat labai pagerėjo — O0: ~355ms, O1: ~128ms (**2.8x greičiau**)

**Rekomendacija**: naudoti `-O2` flagą — jis duoda beveik tokį pat greitį kaip
`-O3`, tačiau yra saugesnis ir labiau nuspėjamas kompiliacijos atžvilgiu.
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

## v1.2 Pakeitimai

### Rule of Five

Realizuoti visi penki klasės valdymo metodai:

* **Destruktorius** `~Students()` — atlaisvina objekto užimamą atmintį kai objektas sunaikinamas
* **Kopijavimo konstruktorius** `Students(const Students&)` — sukuria naują objektą kaip egzistuojančio kopiją
* **Perkėlimo konstruktorius** `Students(Students&&)` — sukuria naują objektą "pavogdamas" duomenis iš laikinojo objekto, originalo laukai išvalomi
* **Kopijavimo priskyrimas** `operator=(const Students&)` — kopijuoja vieno egzistuojančio objekto duomenis į kitą
* **Perkėlimo priskyrimas** `operator=(Students&&)` — perkelia duomenis iš vieno egzistuojančio objekto į kitą, originalo laukai išvalomi

### Įvesties/Išvesties operatoriai

Realizuoti įvesties ir išvesties operatoriai leidžia naudoti `Students` klasę kaip įprastą tipą:

**Įvesties operatorius** `operator>>`
* Nuskaito studento duomenis iš bet kokio `istream` srauto
* Naudojimas:
```cpp
Students s;
cin >> s;          // įvedimas iš klaviatūros
failo_srautas >> s; // nuskaitymas iš failo
ss >> s;           // nuskaitymas iš stringstream
```

**Išvesties operatorius** `operator<<`
* Išveda studento duomenis į bet kokį `ostream` srautą
* Naudojimas:
```cpp
cout << s;              // išvedimas į ekraną
failo_srautas << s;     // išvedimas į failą
cout << s1 << s2;       // galima grandinti
```

### Operatorių panaudojimas programoje

* `operator>>` naudojamas `file_input` funkcijoje vietoje rankinio nuskaitymo
* `push_back(std::move(student))` naudojamas vektoriuje — iškviečiamas perkėlimo konstruktorius vietoje kopijavimo, tai padidina programos efektyvumą

## v1.5 Pakeitimai

### Klasių hierarchija

Vietoje vienos `Students` klasės sukurtos dvi klasės — abstrakti bazinė klasė `Zmogus` ir iš jos išvestinė klasė `Students`:

| Klasė    | Tipas     | Aprašymas                                        |
|----------|-----------|--------------------------------------------------|
| Zmogus   | Abstrakti | Bazinė klasė, aprašanti bendrą žmogų             |
| Students | Išvestinė | Paveldi iš Zmogus, aprašanti studentą            |

### Abstrakti klasė Zmogus

* Saugo bendrus žmogaus laukus: `first_name_`, `last_name_`
* Turi geterius ir seterius vardui bei pavardei
* Objektų kūrimas **negalimas** — klasė abstrakti dėl grynai virtualaus metodo `print()`:
```cpp
// Human z;  // KLAIDA: cannot instantiate abstract class
Students s;   // VEIKIA — išvestinė klasė

![Evidence](https://github.com/thrust0/antra-uzduotis-oop/blob/v1.5/testavimas/v1.5%20testavimas/humanclass.png)
```

### Grynai virtualus metodas `print()`

* Apibrėžtas `Human` klasėje kaip `virtual void print() const = 0`
* Kiekviena išvestinė klasė **privalo** jį realizuoti
* `Students` klasėje išveda vardą, pavardę, galutinį balą ir medianą į terminalą:
```cpp
Students s;
s.print();  // išveda: Vardas Pavarde  8.50  7.00
```

### Students klasė

* Paveldi `first_name_`, `last_name_` ir jų geterius/seterius iš `Zmogus`
* Išlaiko visus v1.2 laukus: `exam_`, `grade_`, `result_`, `median_`
* Visos v1.2 funkcijos veikia kaip anksčiau

### Rule of Five atnaujinimas

Visi penki metodai atnaujinti, kad teisingai dirbtų su bazine klase:

* **Kopijavimo konstruktorius** — iškviečia `Zmogus(other)` bazinės klasės laukams nukopijuoti
* **Perkėlimo konstruktorius** — iškviečia `Zmogus(std::move(other))` bazinės klasės laukams perkelti
* **Kopijavimo priskyrimas** — iškviečia `Zmogus::operator=(other)`
* **Perkėlimo priskyrimas** — iškviečia `Zmogus::operator=(std::move(other))`
* **Destruktorius** — valo tik `Students` laukus, `Zmogus` destruktorius valo `first_name_`, `last_name_`

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

# v1.1 Testavimas 

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

## Kompiliatoriaus flag'ų testavimas su class

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

## Kompiliatoriaus flag'ų testavimas su vector ir struct

### O1 flag

#### 100k įrašų

|          | Nuskaitymas | Rūšiavimas | Skaidymas | Bendras  |
|----------|-------------|------------|-----------|---------|
| Test 1   | 135.684     | 3.70154    | 1.29704   | 140.683 |
| Test 2   | 138.617     | 3.52021    | 1.20837   | 143.346 |
| Test 3   | 127.712     | 3.50537    | 1.24404   | 132.461 |
| Test 4   | 129.904     | 3.71896    | 1.47983   | 135.102 |
| Test 5   | 129.978     | 3.55979    | 1.21850   | 134.756 |
| Vidurkis | 132.379     | 3.60117    | 1.28956   | 137.270 |

#### 1M įrašų

|          | Nuskaitymas | Rūšiavimas | Skaidymas | Bendras  |
|----------|-------------|------------|-----------|---------|
| Test 1   | 1090.01     | 40.8152    | 21.5749   | 1152.40  |
| Test 2   | 1102.61     | 40.6104    | 22.8170   | 1166.04  |
| Test 3   | 1082.05     | 41.2377    | 21.6985   | 1144.99  |
| Test 4   | 1072.87     | 37.9223    | 16.7601   | 1127.56  |
| Test 5   | 1080.12     | 38.3368    | 16.3278   | 1134.79  |
| Vidurkis | 1085.532    | 39.7845    | 19.8357   | 1145.158 |
### O2 flag

#### 100k įrašų

|          | Nuskaitymas | Rūšiavimas | Skaidymas | Bendras |
|----------|-------------|------------|-----------|---------|
| Test 1   | 133.283     | 3.59425    | 1.29846   | 138.176 |
| Test 2   | 121.035     | 3.49146    | 1.20692   | 125.734 |
| Test 3   | 126.867     | 3.58421    | 1.22900   | 131.680 |
| Test 4   | 126.599     | 3.55088    | 1.19371   | 131.344 |
| Test 5   | 127.760     | 3.56492    | 1.36338   | 132.688 |
| Vidurkis | 127.109     | 3.55714    | 1.25029   | 131.924 |

#### 1M įrašų

|          | Nuskaitymas | Rūšiavimas | Skaidymas | Bendras  |
|----------|-------------|------------|-----------|---------|
| Test 1   | 1065.36     | 40.3533    | 22.1378   | 1127.85  |
| Test 2   | 1073.22     | 38.8847    | 16.5845   | 1128.68  |
| Test 3   | 1050.72     | 39.1975    | 22.6092   | 1112.52  |
| Test 4   | 1059.89     | 38.3563    | 17.2757   | 1115.52  |
| Test 5   | 1052.05     | 39.3190    | 17.0005   | 1108.37  |
| Vidurkis | 1060.248    | 39.2222    | 19.1215   | 1118.588 |
### O3 flag

#### 100k įrašų

|          | Nuskaitymas | Rūšiavimas | Skaidymas | Bendras |
|----------|-------------|------------|-----------|---------|
| Test 1   | 134.351     | 3.61796    | 1.40821   | 139.378 |
| Test 2   | 119.753     | 3.73612    | 1.33633   | 124.826 |
| Test 3   | 128.811     | 3.56196    | 1.22354   | 133.597 |
| Test 4   | 128.811     | 3.56196    | 1.22354   | 133.597 |
| Test 5   | 127.670     | 3.59371    | 1.20146   | 132.465 |
| Vidurkis | 127.879     | 3.61434    | 1.27862   | 132.773 |

#### 1M įrašų

|          | Nuskaitymas | Rūšiavimas | Skaidymas | Bendras  |
|----------|-------------|------------|-----------|---------|
| Test 1   | 1056.75     | 40.3224    | 16.6638   | 1113.73  |
| Test 2   | 1043.12     | 38.8180    | 16.8788   | 1098.81  |
| Test 3   | 1053.68     | 39.2343    | 16.9585   | 1109.87  |
| Test 4   | 1053.68     | 39.2343    | 16.9585   | 1109.87  |
| Test 5   | 1061.45     | 38.8582    | 16.9589   | 1117.27  |
| Vidurkis | 1053.736    | 39.2934    | 16.8837   | 1109.910 |
---

## Kompiliatoriaus optimizavimo flagų palyginimas (vidurkiai ms.)

### 100k įrašų

| Flag | Implementacija | Nuskaitymas | Rūšiavimas | Skaidymas | Bendras |
|------|----------------|-------------|------------|-----------|---------|
| O0   | Class          | 355.06      | 56.33      | 10.71     | 422.10  |            
| O0   | Struct         | 348.54      | 21.63      | 8.53      | 378.70  |         
| O1   | Class          | 127.58      | 10.96      | 1.67      | 140.20  |            
| O1   | Struct         | 132.379     | 3.60117    | 1.28956   | 137.270 |           
| O2   | Class          | 128.16      | 10.85      | 1.85      | 140.86  |            
| O2   | Struct         | 127.109     | 3.55714    | 1.25029   | 131.924 |
| O3   | Class          | 127.71      | 10.59      | 1.55      | 139.85  |
| O3   | Struct         | 127.879     | 3.61434    | 1.27862   | 132.773 |

### 1m įrašų

| Flag | Implementacija | Nuskaitymas | Rūšiavimas | Skaidymas | Bendras  |
|------|----------------|-------------|------------|-----------|----------|
| O0   | Class          | 3399.19     | 611.62     | 165.93    | 4176.75  |            
| O0   | Struct         | 3362.63     | 219.19     | 92.96     | 3674.78  |            
| O1   | Class          | 1070.30     | 134.19     | 34.62     | 1239.11  |            
| O1   | Struct         | 1085.532    | 39.7845    | 19.8357   | 1145.158 |            
| O2   | Class          | 1057.35     | 127.71     | 31.06     | 1216.12  |            
| O2   | Struct         | 1060.248    | 39.2222    | 19.1215   | 1118.588 | 
| O3   | Class          | 1054.53     | 124.41     | 29.28     | 1208.22  |
| O3   | Struct         | 1053.736    | 39.2934    | 16.8837   | 1109.910 |

### Object failų dydžiai (Kilobaitais)

|        | O0  | O1  | O2  | O3  | 
|--------|-----|-----|-----|-----|
| Struct | 261 | 120 | 120 | 136 |
| Class  | 262 | 121 | 121 | 120 |

### v1.1 Išvados

Optimizavimo flagai turi labai didelę įtaką programos veikimo greičiui:

- **O0 → O1** perėjimas duoda didžiausią spartą — bendras laikas 100k atveju
  sumažėjo nuo ~422ms (class, be optimizacijos) iki ~137ms (struct su O1),
  t.y. programa tapo **~3x greitesnė**.

- **O1 → O2** skirtumas minimalus — struct versijoje 100k atveju ~137ms vs ~132ms,
  praktiškai jokio reikšmingo skirtumo.

- **O2 → O3** taip pat minimalus skirtumas — ~132ms vs ~133ms (100k atveju),
  rezultatai praktiškai identiški.

- Didžiausią naudą optimizavimas duoda **rūšiavimo** operacijai — struct versijoje
  O0: ~21ms, O1: ~3.6ms, tai yra **~6x pagreitis** vien pirmojo lygio optimizavimo dėka.
  Class versijoje efektas dar ryškesnis: O0: ~56ms, O1: ~11ms (**~5x pagreitis**).

- Nuskaitymas taip pat labai pagerėjo — O0 (struct): ~348ms, O1 (struct): ~132ms (**~2.6x greičiau**).

- Struct implementacija su bet kuriuo optimizavimo flagu yra greitesnė už class
  implementaciją — ypač rūšiavimo operacijoje dėl tiesioginės prieigos prie laukų
  vietoje getter metodų.

- Taip pat matomas **objektinio failo dydžio sumažėjimas naudojant optimizaciją**.
  Be optimizacijos (O0) programos dydis yra apie **261–262 KB**, tačiau naudojant
  **O1 arba O2** jis sumažėja iki maždaug **120–121 KB**. Naudojant **O3** dydis
  šiek tiek padidėja (pvz., struct versijoje iki ~136 KB), nes aukštesnio lygio
  optimizacijos gali generuoti papildomą kodą siekiant maksimalaus našumo.
  
# v1.2 testavimas

Visi klasės metodai patikrinti `test.cpp` faile naudojant `assert` funkcijas:

| Testas | Rezultatas |
|--------|------------|
| Numatytasis konstruktorius | ✓ |
| Kopijavimo konstruktorius | ✓ |
| Perkėlimo konstruktorius | ✓ |
| Kopijavimo priskyrimas | ✓ |
| Perkėlimo priskyrimas | ✓ |
| Destruktorius | ✓ |
| `operator>>` | ✓ |
| `operator<<` | ✓ |

![Test Photo](https://github.com/thrust0/antra-uzduotis-oop/blob/v1.2/testavimas/antrastest.png)

# v1.5 testavimas

Visi klasės metodai patikrinti `test.cpp` faile naudojant `assert` funkcijas:

| Testas | Rezultatas |
|--------|------------|
| Numatytasis konstruktorius | ✓ |
| Kopijavimo konstruktorius | ✓ |
| Perkėlimo konstruktorius | ✓ |
| Kopijavimo priskyrimas | ✓ |
| Perkėlimo priskyrimas | ✓ |
| Destruktorius | ✓ |
| `operator>>` | ✓ |
| `operator<<` | ✓ |

![Test Photo](https://github.com/thrust0/antra-uzduotis-oop/blob/v1.5/testavimas/v1.5%20testavimas/testrun.png)
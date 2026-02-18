# Pažymių skaičiuoklė

Trumpas aprašymas
- Programa skaito arba generuoja studentų vardus ir pažymius, apskaičiuoja galutinį balą (pagal vidurkį arba medianą) ir išveda lentelę su rezultatais.
- Yra dvi implementacijos:
  - `uzduotis.cpp` — naudojamas `std::vector` (patogesnis, RAII).
  - `with-c-array/uzduotis-array.cpp` — užduoties reikalavimui atlikta versija su C-stiliaus dinaminiais masyvais.

Reikalavimai
- C++ kompiliatorius (g++, clang++) su C++17 arba naujesniu standartu.
- macOS: Terminal arba VS Code integruotas kompiliatorius.
- Kataloge `vardai/` turi būti vardų failai (pridedama prie projekto):  
  `vyriski-vardai.txt`, `vyriskos-pavardes.txt`, `moteriski-vardai.txt`, `moteriskos-pavardes.txt`

Failų struktūra (pvz.)
- uzduotis.cpp
- with-c-array/uzduotis-array.cpp
- vardai/
  - vyriski-vardai.txt
  - vyriskos-pavardes.txt
  - moteriski-vardai.txt
  - moteriskos-pavardes.txt

Kompiliavimas (macOS / Terminal)
- Vector versija:
  g++ -std=c++17 uzduotis.cpp -o uzduotis
- C-array versija:
  g++ -std=c++17 with-c-array/uzduotis-array.cpp -o uzduotis-array

Vykdymas
- Paleisk iš projekto šaknies (taip, kad relative kelias `vardai/` būtų randamas):
  - ./uzduotis
  arba
  - ./uzduotis-array
- Jei paleidi iš kitos vietos, `random_name_generator()` gali nepavykti atidaryti failų. Array versija bando ir `../vardai/` kaip fallback.

Meniu ir darbo eiga
- Programoje pasirinkite:
  1 — rankiniu būdu įvesti vardus ir pažymius
  2 — įvesti vardus, bet pažymius sugeneruoti atsitiktinai
  3 — sugeneruoti vardus iš failų ir rankiniu būdu įvesti pažymius
  4 — išeiti iš programos

Įvestis ir sentineliai
- Kai įvedinėjate pažymius, programa leidžia nesudėti išankstinio `n`. Tiesiog įveskite vieną pažymį po kito.
- Baigti pažymių įvedimą — įveskite `;` (kabliataškį). Funkcija `get_int()` grąžina -1 sentinelui.
- Po pažymių įvedimo programa paprašo egzamino pažymio (0–10). Egzamino įvedime taip pat galima naudoti sentinelį, jei funkcija yra kviečiama tokiu kontekstu.

Išvedimas
- Programoje vartotojas renkasi ar nori matyti galutinį balą pagal vidurkį ar pagal medianą (`v` arba `m`).
- Skaičiai išvedami su dviem skaitmenimis po kablelio (naudojamas `std::fixed` + `std::setprecision(2)`), lentelė formatuota su `setw`.

Skirtumai tarp versijų (ką reikėtų žinoti prie gynimo)
- `std::vector` versija automatiškai valdo atmintį ir kopijavimą — saugesnė.
- C‑masyvų versija:
  - kiekvienam studentui skiriamas `new int[grade_count]`,
  - saugomas `grade_count`,
  - `group` yra dinaminis `Students*` masyvas su rankiniu `resize_group()` (dauginama talpa).
  - būtina užtikrinti, kad kiekvienas `new[]` būtų poruojamas su `delete[]` (pabaigoje vykdomas atlaisvinimas).
  - aptarkite, kodėl reikalingas deep-copy arba move-semantika (shallow copy pavojai).

Žinomi punktai / patarimai
- Jei programos metu gaunate klaidą „Error opening name files“, patikrinkite, ar vykdote programą iš katalogo, kuriame yra `vardai/`. Alternatyviai paleiskite iš projekto šaknies arba perkelkite `vardai/` į tą katalogą.
- Norint testuoti atminties klaidas, rekomenduojama kompiliuoti su AddressSanitizer:
  g++ -std=c++17 -fsanitize=address,undefined -g with-c-array/uzduotis-array.cpp -o uzduotis-array-asan

Versijavimas (git)
- Repo turėjo darbines šakas: `v.pradine` (pradinė) ir `v0.1` (array + vector versijos).
- Įsitikinkite, kad yra ne mažiau nei reikalaujami „sync“ (commit + push) kiekiai ir sukurti release/tag'ai.

# Duomenų apdorojimas (2 užduotis)

## Užduoties aprašymas
- Parašykite programą, kuri nuskaito šiuos studentų duomenis:
- vardą ir pavardę
- n atliktų namų darbų (nd) rezultatus (10-balėje sistemoje), o taip pat egzamino (egz) rezultatą.
- Tuomet iš šių duomenų, suskaičiuoja galutinį balą (galutinis):  
`galutinis = 0.4 * vidurkis/mediana + 0.6 * egzaminas`
 - Duomenys pateikiami į ekraną tokiu ar panašiu pavidalu (kur galutinis apskaičiuotas balas pateikiamas dviejų skaičių po kablelio tikslumu):
``` 
Pavardė     Vardas       Galutinis (Vid.) / Galutinis (Med.)
-----------------------------------------------------------
Arvydas     Sabonis      x.xx               x.xx
Rimas       Kurtinaitis  y.yy               y.yy
...
```

## Įdiegimas (Unix kompiuteryje) naudojant `Clang` kompiliatorių 

- `git clone https://github.com/Elijus99/OPP_2uzd_DuomenuApdorojimas.git`
- `cd OPP_2uzd_DuomenuApdorojimas`
- `make`
- `make test`

## Naudojimosi instrukcija

- Paleisti programą.
- Pasirinkti ką naudosite galutinio balo skaičiavimui, namų darbų vidurkį ar medianą (Įvesti "v" arba "m").
- Jei norite sugeneruoti studentų sąrašą įveskite "y", jei nenorite - "n". Pasirinkus "y", įveskite kiek įrašų sąraše norite generuoti.
- Jei norite nuskaityti duomenis iš failo "kursiokai.txt" įveskite "y", jei nenorite - "n".
- Įveskite skaičių studentų, kurių duomenis norite įrašyti.
- Jei studentų skaičių pasirinkote didesnį, nei 0, įveskite 1-0 studento vardą, pavardę. Jei norite studento namų darbų pažymius bei egzamino rezultatą įrašyti pats/pati įveskite "i". Jei norite juos sugeneruoti automatiškai įveskite "g". Pasirinkus "i" įveskite studento namų darbų pažymius, kai norėsite sustabdyti šio studento pažymių vedimą įveskite "-1". Tada įveskite egzamino rezultatą. Pakartokite šiuos žingsnius visų studentų duomenims įvesti.

## Spartos analizė [v0.4]

```
Faile generuojamų įrašų kiekis      Programos veikimo laikas

10                                  0.0072s
100                                 0.0089s
1000                                0.0159s
10000                               0.0748s
100000                              0.6115s
```

## Konteinerių spartos analizė [v0.5]

```
Konteineris      Naudojamų įrašų kiekis      Nuskaitymas       Rusiavimas

Vector           10                          0.0005s           0.0000s
Vector           100                         0.0009s           0.0000s
Vector           1000                        0.0043s           0.0000s
Vector           10000                       0.0351s           0.0002s
Vector           100000                      0.3633s           0.0021s

Deque            10                          0.0005s           0.0000s
Deque            100                         0.0008s           0.0000s
Deque            1000                        0.0040s           0.0000s
Deque            10000                       0.0364s           0.0005s
Deque            100000                      0.3497s           0.0052s

List             10                          0.0005s           0.0000s
List             100                         0.0008s           0.0000s
List             1000                        0.0036s           0.0000s
List             10000                       0.0296s           0.0004s
List             100000                      0.3272s           0.0036s
```

## Konteinerių spartos analizė [v1.0]

Versijose v0.4 ir v0.5 studentai į "vargšiukus" ir "kietiakus" buvo skirstomi įrašu struktūroje, o ne keliant studentus į kitą/kitus konteinerius. 

**1 strategija** - Tas pats studentas yra dvejuose konteineriuose: bendrame studentai ir viename iš suskaidytų (vargšiukai arba kietiakai).

```
Naudojamų įrašų kiekis      Deque            Vector              List

10                          0.0057s          0.0032s             0.0050s
100                         0.0123s          0.0042s             0.0120s
1000                        0.0621s          0.0221s             0.0591s
10000                       0.3325s          0.1301s             0.3125s
100000                      3.0097s          1.1985s             2.9600s
```

**2 strategija** - Jei studentas yra vargšiukas, jis įkeliamas į naująjį "vargšiukų" konteinerį ir ištrinamas iš bendro studentai konteinerio. Po šio žingsnio studentai konteineryje lieka vien tik kietiakai.

```
Naudojamų įrašų kiekis      Deque            Vector              List

10                          0.0060s          0.0032s             0.0055s
100                         0.0145s          0.0043s             0.0131s
1000                        0.0667s          0.0236s             0.0632s
10000                       0.3464s          0.1395s             0.3242s
100000                      3.1185s          1.2724s             3.0120s
```

## Programos spartos analizė, pritaikius algoritmus, naudojant `std::vector` [v1.0]

```
Naudojamų įrašų kiekis      Be algoritmų       Su algoritmais

10                          0.0042s            0.0032s
100                         0.0045s            0.0043s
1000                        0.0343s            0.0236s
10000                       0.8038s            0.1395s
100000                     54.0647s            1.2724s
```
- Skiltyje "Be algoritmų" nurodyta programos sparta naudojant tik `vector.erase()` funkciją.

- Skiltyje "Su algoritmais" nurodyta programos sparta pritaikius `std::remove_if` algoritmą.

## iterpkKietus() ir raskMinkstus() funkcijų spartos analizė [Papildoma uzduotis]

```
Naudojamų įrašų kiekis    raskMinkstus()                iterpKietus()            std::Vector pakeistas į std::deque

10000                      0.5386s                       1.9865s                 0.0059s
100000                    54.5750s                     194.5236s                 0.0454s
```

## Versijų istorija (changelog)

### [Papildoma uzduotis](https://github.com/Elijus99/OPP_2uzd_DuomenuApdorojimas/releases/tag/v0.4p) - (2019-03-24)

**Pridėta** 

- Sukurta funkcija raskMinkstus().
- Funkcija raskMinkstus() modifikuota, pakeistas pavadinimas į iterpkKietus().
- Atlikta funkcijų raskMinkstus() ir iterpkKietus() spartos analizė.

**Koreguota**

- Papildytas **README** failas

### [v1.0](https://github.com/Elijus99/OPP_2uzd_DuomenuApdorojimas/releases/tag/v1.0) - (2019-03-09)

**Pridėta**

- Optimizuotas studentų rūšiavimas į "vargšiukus" ir "kietiakus".
- Pateikti konteinerių spartos analizės duomenys skirtingoms rūšiavimo strategijoms.
- Programai pritaikyti algoritmai.
- Pateikti vektoriaus spartos analizės duomenys prieš bei po algoritmų pritaikymo.

**Koreguota**

- Papildytas **README** failas

### [v0.5](https://github.com/Elijus99/OPP_2uzd_DuomenuApdorojimas/releases/tag/v0.5) - (2019-03-01)

**Pridėta**

- Atlikta konteinerių spartos analizė.

**Koreguota**

- `std::vector<stud>` pakeistas į `std::deque<stud>` dėl didesnės spartos
- Papildytas **README** failas

### [v0.4](https://github.com/Elijus99/OPP_2uzd_DuomenuApdorojimas/releases/tag/v0.4) - (2019-02-26)

**Pridėta**

- Studentų sąrašų failų generavimas
- Studentų rūšiavimas į "vargšiukus" (galutinis balas < 5.0) ir "kietiakus" (galutinis balas >= 5.0) ir jų išvedimas į atskirus failus
- Programos spartos analizė

**Koreguota**

- Papildytas **README** failas

### [v0.3](https://github.com/Elijus99/OPP_2uzd_DuomenuApdorojimas/releases/tag/v0.3) - (2019-02-22)

**Koreguota**

- Atliktas kodo refactoring'as (sukurti failai functions.cpp, functions.h, libraries.h, į juos perkelta atitinkamos kodo dalys)
- Panaudotas Exception Handling'as
- Papildytas **README** failas

### [v0.2](https://github.com/Elijus99/OPP_2uzd_DuomenuApdorojimas/releases/tag/v0.2) - (2019-02-17)

**Pridėta**

- Duomenų nuskaitymas iš "kursiokai.txt" failo
- Studentų sąrašas rikiuojamas abėcėlės tvarka (Norint, kad programa rikiuotų tvarkingai, vardai turi prasidėti iš didžiosios raidės)

**Koreguota**

- Papildytas **README** failas

### [v0.1](https://github.com/Elijus99/OPP_2uzd_DuomenuApdorojimas/releases/tag/v0.1) - (2019-02-16)

**Pridėta**

- Pirmoji programos versija

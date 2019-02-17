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

## Versijų istorija (changelog)

### [v0.2](https://github.com/Elijus99/OPP_2uzd_DuomenuApdorojimas/releases/tag/v0.2) - (2019-02-17)

**Pridėta**

- Duomenų nuskaitymas iš "kursiokai.txt" failo
- Studentų sąrašas rikiuojamas abėcėlės tvarka

**Koreguota**

- Papildytas **README** failas

### [v0.1](https://github.com/Elijus99/OPP_2uzd_DuomenuApdorojimas/releases/tag/v0.1) - (2019-02-16)

**Pridėta**

- Pirmoji programos versija

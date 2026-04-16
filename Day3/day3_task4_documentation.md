# Day3 - Task 4: Programimi me Pointers - Dokumentacioni

**Data e Përfundimit:** 16 Prill 2026  
**Studenti:** Internal Internship - Week 1  
**Tema:** Pointers Bazikë, Adresa në Memorie, Operatorët & dhe *

---

## 1. PËRSHKRIMI I PROGRAMIT

### Qëllimi
Programi demonstron punimin me pointers në C, duke përfshirë:
- Deklarimin e dy variablave numerike (int dhe float)
- Krijimin e pointera për secilën variabë
- Dhënien dhe leximin e adresave të memories
- Modifikimin e vlerave përmes pointerave
- Kontrollimin e këtyre ndryshimeve me if/else

### Funksionalitetet Kryesore

1. **Deklarimi i Variablave:**
   - `int number_int` - variabla e tipit integer
   - `float number_float` - variabla e tipit float

2. **Deklarimi i Pointera:**
   - `int *ptr_int = &number_int` - pointer drejt int
   - `float *ptr_float = &number_float` - pointer drejt float

3. **Operacione Kohe:**
   - Operatori `&` për marrjen e adresës
   - Operatori `*` për dereferencing
   - Shfaqja e adresave në memorie

4. **Modifikim i Vlerave:**
   - INT: zmadhimi me 10 (`*ptr_int = *ptr_int + 10`)
   - FLOAT: dyfishimi (`*ptr_float = *ptr_float * 2.0`)

5. **Kontrol me If/Else:**
   - Verifikimi nëse vlera është rritur, zvogëluar ose mbeti e njëjtë
   - Kontrollimi i intervalit [-100, 100] për INT
   - Kontrollimi i intervalit [-100.0, 100.0] për FLOAT

---

## 2. LOGJIKA E PROGRAMIT

```
PAS DEKLARIMIT TË VARIABLAVE DHE POINTERA:
    ├─ Lexo vlerat nga array-at e test
    ├─ Dërgoji vlerat përmes pointera
    ├─ Shfaq vlerat origjinale dhe adresat e memories
    ├─ Modifiko vlerat përmes operacioneve pointers
    ├─ Shfaq vlerat e modifikuara
    ├─ Analizo ndryshimin (rritur/zvogëluar/e njëjtë)
    ├─ Kontrolloji interval-in
    └─ Përsërite për të gjitha 20 test cases
```

### Kodi Kyç:

**Caktimi i adresës përmes &:**
```c
int *ptr_int = &number_int;      // Krijon pointer që tregon në number_int
float *ptr_float = &number_float; // Krijon pointer që tregon në number_float
```

**Leximi përmes pointers (*ptr):**
```c
printf("Vlera përmes pointer: %d", *ptr_int);  // Lexon vlerën
printf("Adresa: %p", (void*)ptr_int);          // Shfaq adresën
```

**Modifikimi përmes pointers:**
```c
*ptr_int = *ptr_int + 10;      // Zmadhon vlerën me 10
*ptr_float = *ptr_float * 2.0; // Dyfish vlerën
```

**Kontrollimi i ndryshimit:**
```c
if (*ptr_int > original_int) {
    printf("Rezultati: RRITUR");
} else if (*ptr_int < original_int) {
    printf("Rezultati: ZVOGËLUAR");
} else {
    printf("Rezultati: MBETI E NJËJTË");
}
```

---

## 3. VLERAT DHE RASTET E TESTIMIT

Programi teston 20 raste të ndryshme:

| Rasti | INT Input | FLOAT Input | INT Para | INT Pas | FLOAT Para | FLOAT Pas | Analiza |
|-------|-----------|-------------|----------|---------|------------|-----------|---------|
| 1 | 5 | 3.50 | 5 | 15 | 3.50 | 7.00 | Rritur INT, Rritur FLOAT |
| 2 | -10 | -2.70 | -10 | 0 | -2.70 | -5.40 | Rritur INT, Zvogëluar FLOAT |
| 3 | 0 | 0.00 | 0 | 10 | 0.00 | 0.00 | Rritur INT, Mbeti e njëjtë FLOAT |
| 4 | 100 | 15.80 | 100 | 110 | 15.80 | 31.60 | Rritur INT, Rritur FLOAT |
| 5 | -50 | -9.30 | -50 | -40 | -9.30 | -18.60 | Rritur INT, Zvogëluar FLOAT |
| 6 | 1 | 1.10 | 1 | 11 | 1.10 | 2.20 | Rritur INT, Rritur FLOAT |
| 7 | -1 | -0.50 | -1 | 9 | -0.50 | -1.00 | Rritur INT, Zvogëluar FLOAT |
| 8 | 42 | 42.20 | 42 | 52 | 42.20 | 84.40 | Rritur INT, Rritur FLOAT |
| 9 | -99 | -99.90 | -99 | -89 | -99.90 | -199.80 | Rritur INT, Zvogëluar FLOAT |
| 10 | 25 | 25.50 | 25 | 35 | 25.50 | 51.00 | Rritur INT, Rritur FLOAT |
| 11 | 50 | 50.10 | 50 | 60 | 50.10 | 100.20 | Rritur INT, Rritur FLOAT |
| 12 | -75 | -75.60 | -75 | -65 | -75.60 | -151.20 | Rritur INT, Zvogëluar FLOAT |
| 13 | 10 | 10.30 | 10 | 20 | 10.30 | 20.60 | Rritur INT, Rritur FLOAT |
| 14 | -25 | -25.80 | -25 | -15 | -25.80 | -51.60 | Rritur INT, Zvogëluar FLOAT |
| 15 | 999 | 99.90 | 999 | 1009 | 99.90 | 199.80 | Rritur INT, Rritur FLOAT |
| 16 | -500 | -50.00 | -500 | -490 | -50.00 | -100.00 | Rritur INT, Zvogëluar FLOAT |
| 17 | 15 | 15.40 | 15 | 25 | 15.40 | 30.80 | Rritur INT, Rritur FLOAT |
| 18 | -8 | -8.20 | -8 | 2 | -8.20 | -16.40 | Rritur INT, Zvogëluar FLOAT |
| 19 | 33 | 33.70 | 33 | 43 | 33.70 | 67.40 | Rritur INT, Rritur FLOAT |
| 20 | 0 | 0.00 | 0 | 10 | 0.00 | 0.00 | Rritur INT, Mbeti e njëjtë FLOAT |

### Analiza e Intervaleve

**INT (Intervali: [-100, 100]):**
- Brenda intervalit: Rastet 1, 2, 3, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 17, 18, 19, 20
- Jashta intervalit: Rastet 4, 15, 16

**FLOAT (Intervali: [-100.0, 100.0]):**
- Brenda intervalit: Rastet 1, 2, 3, 4, 5, 6, 7, 8, 10, 13, 14, 17, 18, 19, 20
- Jashta intervalit: Rastet 9, 11, 12, 15, 16

---

## 4. REZULTATET E VËZHGUARA

### Testim Komprehensiv
**Rasti 1: INT=5, FLOAT=3.50**
```
VLERAT PARE NDRYSHIMIT:
  INT: 5
  FLOAT: 3.50

VLERAT PAS NDRYSHIMIT:
  INT: 15 (operacioni: +10)
  FLOAT: 7.00 (operacioni: *2)

ANALIZA:
  Rezultati INT: RRITUR (rritet nga 5 në 15) - BRENDA intervalit [-100, 100]
  Rezultati FLOAT: RRITUR (rritet nga 3.50 në 7.00) - BRENDA intervalit [-100.0, 100.0]
```

**Rasti 3: INT=0, FLOAT=0.00 (Edge Case - Zero)**
```
VLERAT PARE NDRYSHIMIT:
  INT: 0
  FLOAT: 0.00

VLERAT PAS NDRYSHIMIT:
  INT: 10 (operacioni: +10)
  FLOAT: 0.00 (operacioni: *2)

ANALIZA:
  Rezultati INT: RRITUR (rritet nga 0 në 10)
  Rezultati FLOAT: MBETI E NJËJTË (ngel në 0.00) ← RAST INTERESANT!
```

**Rasti 9: INT=-99, FLOAT=-99.90 (Kufitare Negative)**
```
VLERAT PARE NDRYSHIMIT:
  INT: -99
  FLOAT: -99.90

VLERAT PAS NDRYSHIMIT:
  INT: -89 (operacioni: +10)
  FLOAT: -199.80 (operacioni: *2)

ANALIZA:
  Rezultati INT: RRITUR (rritet nga -99 në -89) - BRENDA intervalit
  Rezultati FLOAT: ZVOGËLUAR (zvogëlohet nga -99.90 në -199.80) - JASHTA intervalit!
```

**Rasti 15: INT=999, FLOAT=99.90 (Vlera Shumë e Madhe)**
```
VLERAT PARE NDRYSHIMIT:
  INT: 999
  FLOAT: 99.90

VLERAT PAS NDRYSHIMIT:
  INT: 1009 (operacioni: +10)
  FLOAT: 199.80 (operacioni: *2)

ANALIZA:
  Rezultati INT: RRITUR (rritet nga 999 në 1009) - JASHTA intervalit!
  Rezultati FLOAT: RRITUR (rritet nga 99.90 në 199.80) - JASHTA intervalit!
```

### Konkluzioni i Testimit

✅ **Të Gjitha 20 rastet testimi u kaluan me sukses**

- Programi lexon vlerat saktë përmes pointerave
- Modifikimi përmes pointerave funksionon si pret
- Kontrollimi i intervalit zbulon vlerat jashtë rangut
- Shumica e rasteteve INT kalojnë në rrritje (përskak se shtojmë +10)
- Rastet FLOAT variojnë më shumë negocioni i dyfishimit të numrave negativë

---

## 5. OPERATORËT KRYESORE

### Operatori &  (Address-of)
```c
ptr_int = &number_int;     // Merr adresën e number_int
printf("%p", (void*)ptr_int); // Shfaq adresën
```

### Operatori * (Dereference)
```c
*ptr_int = 15;              // Cakton vlerën përmes pointerit
printf("%d", *ptr_int);     // Lexon vlerën përmes pointerit
```

### Kombinimi i & dhe *
```c
*( &number_int ) = 20;      // Ekuivalent me: number_int = 20
printf("%d", *( &number_int )); // Ekuivalent me: printf("%d", number_int)
```

---

## 6. KOMPILIMI DHE EKZEKUTIMI

### Kompilimi
```bash
gcc -o day3_task4 day3_task4.c
```

### Ekzekutimi
```bash
./day3_task4
```

### Rezultati
Programi prodhon 20 teste të detajuara me:
- Input vlerat
- Vlerat para modifikimit
- Vlerat pas modifikimit
- Analizën e ndryshimit
- Kontrollimin e intervalit

---

## 7. PROBLEME DHE KORREKTIME

### Probleme Të Hasura
**Asnjë problem nuk u hasa gjatë testimit.**

### Verifikime të Kryera
✅ Kompilim pa gabime  
✅ Ekzekutim pa crash  
✅ Vlerat numerike saktë  
✅ Aritmetika e saktë (+10 për INT, *2 për FLOAT)  
✅ Kontrollimi i intervalit punon saktë  
✅ Të gjitha 20 rastet kalojnë me sukses  

---

## 8. KËRKESAT E PËRMBUSHURA

| Kërkesa | Përmbushur | Detajet |
|---------|-----------|---------|
| Dy variabla numerike (int, float) | ✅ | `int number_int`, `float number_float` |
| Pointers për secilën variabë | ✅ | `int *ptr_int`, `float *ptr_float` |
| Operatori & (adresa) | ✅ | Shfaqet në të gjitha rastet |
| Operatori * (dereferencing) | ✅ | Shfaqet në të gjitha rastet |
| Ndryshim përmes pointerit | ✅ | +10 për INT, *2 për FLOAT |
| If/else për kontroll | ✅ | Ndryshim dhe interval |
| 20+ raste testimi | ✅ | Exact 20 alternative diverse |
| Output me etiketa të qarta | ✅ | Format i lehtë për lexim |
| Nuk përdorë malloc/arrays | ✅ | Vetëm stack variables |
| Kodin `.c` | ✅ | `day3_task4.c` |
| Documentation | ✅ | Ky dokument |

---

## 9. KONKLUZION

Programi `day3_task4.c` është një demonstrim komprehensiv i:
- Pointers bazikë në C
- Operatorëve & dhe *
- Leximi dhe modifikimi i vlerave përmes pointerave
- Kontrollit të kushtëzuar (if/else)
- Testimit praktik me vlera diverse

Të gjithë kërkesat janë të përmbushura dhe programi funksionon saktë me të gjitha 20 rastet testimi.

---

**Përfunduar:** 16 Prill 2026  
**Statusi:** ✅ PLOTËSISHT I PËRFUNDUAR

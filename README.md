<div align="right">
  <a href="#magyar">Magyar</a> | <a href="#english">English</a>
</div>

<a name="english"></a>

# C Algorithms & Console Applications

A structured collection of C programs developed during university coursework and algorithmic practice, covering file-backed CRUD operations, dynamic/array memory processing, sorting, searching, and statistical calculations.

### Repository Structure

- `warehouse-crud/`
  - `warehouse_manager.c` — File-backed warehouse inventory CRUD application (`raktar.txt`) using structs (`Termek`), search, deletion, and custom sorting.
- `applications/`
  - `bmi_calculator.c` — Modular BMI calculator for a cohort with range validation and formatted ASCII table output.
  - `eur_huf_analyzer.c` — Four-stage EUR/HUF exchange-rate dataset analyzer (array initialization, validated input, random fill, moving/offset averages).
  - `student_height_analyzer.c` — Cohort height analyzer computing extremes, conditional averages (`magas`/`alacsony`), and rank lookups.
- `algorithms/`
  - `binary_search_desc.c` — Custom descending binary search and standard library `bsearch()` demonstration.
  - `selection_sort_stats.c` — Selection sort implementation paired with grade mean, median, and mode statistics.
  - `interval_statistics.c` — Interval analysis calculating arithmetic mean of negatives, geometric mean of positives, and prime counts.
  - `fibonacci.c`, `day_of_year.c`, `leap_year_grade.c`, `circle_calc.c`, `rectangle_calc.c`, `operator_precedence.c` — Core C fundamentals and math exercises.

### Build Example (`gcc`)
```bash
gcc -Wall -Wextra applications/bmi_calculator.c -o bmi_calculator
gcc -Wall -Wextra algorithms/interval_statistics.c -o interval_statistics -lm
```

---

<a name="magyar"></a>

# C Algoritmusok és Konzolos Alkalmazások

Egyetemi és algoritmusgyakorlási feladatok rendszerezett gyűjteménye C nyelven: fájlalapú raktárkezelő CRUD rendszer, tömb- és struktúraműveletek, kereső- és rendezőalgoritmusok, valamint statisztikai számítások.

### Tartalom

- `warehouse-crud/`
  - `warehouse_manager.c` — Szövegfájlra épülő (`raktar.txt`) raktárkészlet-kezelő alkalmazás (`Termek` struktúra, felvétel, keresés, törlés, rendezés, listázás).
- `applications/`
  - `bmi_calculator.c` — Moduláris testtömegindex (BMI) számító és értékelő alkalmazás formázott táblázattal.
  - `eur_huf_analyzer.c` — Négyrészes EUR/HUF árfolyam-elemző program (inicializálás, ellenőrzött beolvasás, véletlen feltöltés, átlagszámítás).
  - `student_height_analyzer.c` — Diákok magasságadatait elemző program min/max, feltételes átlag (`magas`/`alacsony`) és helyezés-kereséssel.
- `algorithms/`
  - `binary_search_desc.c` — Csökkenő sorrendű bináris keresés kézi implementációja és `bsearch()` összevetése.
  - `selection_sort_stats.c` — Minimumkiválasztásos rendezés, valamint átlag-, medián- és móduszszámítás.
  - `interval_statistics.c` — Intervallum-elemző: negatív számok számtani átlaga, pozitívak mértani átlaga és prímszám-számlálás.
  - `fibonacci.c`, `day_of_year.c`, `leap_year_grade.c`, `circle_calc.c`, `rectangle_calc.c`, `operator_precedence.c` — Alapozó algoritmusok és C gyakorlatok.

### Fordítás (`gcc`)
```bash
gcc -Wall -Wextra applications/bmi_calculator.c -o bmi_calculator
gcc -Wall -Wextra algorithms/interval_statistics.c -o interval_statistics -lm
```

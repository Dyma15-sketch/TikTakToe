# TikTakToe

**TikTakToe** este un joc simplu de strategie în care jucătorul concurează împotriva unui adversar într-un meci de X și 0 pe o grilă 3x3.  
Scopul jocului este de a completa trei celule consecutiv — vertical, orizontal sau diagonal — pentru a câștiga partida.  
Dacă niciunul dintre jucători nu reușește acest lucru, jocul se încheie la egalitate.

---

## Instrucțiuni de construire

Pentru început, am deschis **Git Bash**, am accesat locația proiectului și am executat următoarele comenzi pentru a mă asigura că am ultimele modificări din ramura principală și pentru a crea o nouă ramură pentru laboratorul 2:

```bash
# selectarea ramurii principale
git checkout main

# obținerea ultimelor modificări
git pull

# crearea și comutarea pe o nouă ramură
git checkout -B lab02

```
 Am creat fișiere sursă .cpp corespunzătoare fiecărui fișier antet .hpp, unde fiecare fișier .cpp conține implementarea metodelor definite în fișierele header. La final, am creat fișierul main.cpp, care conține punctul de intrare al aplicației.

Pentru compilare, am folosit MINGW64, am creat fișierul Makefile cu comenzile care vor crea fișierele obiect si aplicația (TikTakToe.exe) folosind urmatoarele comenzi în MINGW64:

```bash
make clean
make
```
Pentru o mai bună organizare, am creat următoarele directoare:

 * include/ – conține fișierele .hpp

 * src/ – conține fișierele .cpp

 * obj/ – conține fișierele obiect .o


 Am creat un fișier .gitignore pentru a exclude din controlul versiunilor fișierele generate automat în timpul compilării, precum:
 * .exe
 * .o

 Pentru a adăuga, comite și publica modificările în depozitul remote, am executat următoarele comenzi:

 ```bash
 # adaugă toate fișierele pentru urmărire
git add *

# verifică starea fișierelor
git status

# creează un commit
git commit -m "first compilation"

# publică commit-ul în depozitul remote
git push
```









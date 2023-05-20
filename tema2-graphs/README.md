
# Tema 2 Proiectarea Algoritmilor - Grafuri.

# Autor

- Alexandru LICURICEANU 325CD

# Organizare

* Alaturi de probeleme propriu-zise, am implementat de asemenea si un checker simplu
care doar compara datele din fisierul cu rezultatul algoritmului cu rezultatul de
referinta. Ca sa functioneze corect, in directorul din care este rulat programul
trebuie sa existe 3 directoare numite `pb1_out`, `pb2_out` si `pb3_out`. Aici se vor
genera fisierele care contin rezultatele implementarilor de la problemele temei.

* Fisierele de test se afla in directoarele `pb1_tests`, `pb2_tests` si `pb3_tests`.
Inauntrul fiecaruiea se afla 2 fisiere, `test#.in` care contine datele de intrare si
`test#.out` care este fisierul de referinta pentru testul respectiv.

* Problemele au fost implementate in `task1.cpp`, `task2.cpp` si `task3.cpp`.

* Programul de checker se afla in `checker.cpp`. De asemenea, in fisierul `util.h` am
definit diverse constante.

# Detalii implementare

## Problema 1
* Algoritmul se bazeaza pe parcurgeri in adancime a grafului pentru a gasi cicluri si
functioneaza astfel:

  * Functia `hasCycle()` functioneaza ca un wrapper pentru parcurgerea DFS.
  * Setez fiecare nod ca fiind nevizitat si initializez un vector care va contine
nodurile care fac parte din drumul unei parcurgeri DFS.
  * Iterez fiecare nod, daca acesta nu a fost vizitat, apelez `hasCycleUtil()`.
  * Daca `hasCycleUtil()` returneaza 1 ineseamna ca s-a gasit un ciclu.
  
  * Cand este apelata functia `hasCycleUtil`, este marcat nodul ca fiind vizitat
si este adaugat la drumul din DFS. 
  * Iterez fiecare vecin al nodului curent si daca nu a fost vizitat, apelez
`hasCycleUtil()`. Daca oricare vecin din iteratie face parte din drumul curent,
atunci inseamna ca s-a gasit un ciclu si functia returneaza true.

## Problema 2
* Algoritmul se bazeaza pe utilizarea unei stive pentru a stoca nodurile in
ordine topologica si apoi gaseste costurile minime folosind un algoritm asemanator cu
Bellman-Ford.

  * Initializez un vector cu distantele de la nodul sursa la celelalte noduri. Momentan
toate valorile sunt infinit, in afara de costul drumului de la nodul sursa la el insusi,
care este 0.
  * Initializez un vector de noduri vizitate. Initial toate nodurile sunt marcate ca fiind
nevizitate.
  * Initializez o stiva care sa stocheze nodurile in ordine topologica.

  * Iterez toate nodurile din graf, daca nodul nu este vizitat, apelez functia
`topologicalSortUtil()`. Aceasta marcheaza nodul ca fiind vizitat, itereaza toti vecinii
nodului si daca vecinul nu a fost vizitat, se apeleaza din nou `topologicalSortUtil()`.
  * Daca nodul la care se ajunge cu apelurile recursive nu are vecini, acesta se pune direct pe
stiva. Cand se incheie apelurile recursive, nodurile care nu au vecini vor fi primele care vor
fi puse pe stiva.

  * Dupa ce se face sortarea topologica, cat timp stiva nu este goala, scoate nodul de pe stiva.
  * Daca distanta pana la nod nu este infinit, itereaza toti vecinii sai si relaxeaza muchiile si
actualizeaza costul minim daca se poate.

## Problema 3
* Nu am implementat solutia pentru problema 3.

# Rulare

```
make
./checker (sau ./checker <1 | 2 | 3>)
```

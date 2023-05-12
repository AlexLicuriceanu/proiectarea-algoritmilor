Tema 1 PA - Alexandru Licuriceanu 325CD

- Rulare:
	make 
	./tema
	
- Organizare:
	- În Solution.cpp se găsesc implementați algoritmii descriși in pdf.
	- Fiecare tip de problemă are un director denumit sugestiv, în care
	se află un fișier de test, "test.in". Ieșirea la rulearea fiecărui
	algoritm se va afla în directorul său, într-un fișier numit "test.out".
	
	- Formatul fișierelor "test.in" este diferit în funcție de problemă:
		- Divide et impera:
			Prima linie: 	Numărul elementelor din vector.
			A doua linie:	Elementele vectorului.
		
		- Greedy:
			Prima linie:	Distanța cerută între caracterele identice.
			A doua linie:	Șirul de caractere de procesat.
			
		- Programare dinamică:
			Prima linie: 		Numărul de noduri ale arborelui, 
								Numărul de muchii ale arborelui.
			Restul liniilor:	Muchiile arborelui.
			
		- Backtracking:
			Prima linie: 		 Numărul de cuvinte din dicțioar (N).
			Următoarele N linii: Un cuvânt din dicțioar pe fiecare linie.
			Ultima linie:		 Șirul de caractere de procesat.
			
	- Fișierele "test.out" se vor genera în directoarele aferente atunci
	când se rulează algoritmii.
	
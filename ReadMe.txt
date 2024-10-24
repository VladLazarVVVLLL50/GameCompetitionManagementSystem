#ReadMe Proiect PA:

##1. Explicare main.c

Functia main primeste ca parametrii un integer argc si un vector de stringuri unde sunt detaliate fisierele de imput (c.in,d.in), respectiv de output r.out.
Deschidem fisierele de cerinte si de rezultate, initializam un vector de taskuri si citim lista de taskuri. 
In functie de task-urile cerute rezolvam fiecare task prin functii specifice (solve_task_"task_number"), toate functiile vor fi explicate ulterior.
Drept variabile vom folosi un integer ce va insemna numarul de echipe, o lista cu echipele si o lista de castigatori necesara pt taskurile 4 si 5. Toate aceste variabile se vor abdata pe masura ce inaintam in task-uri
La final eliberam zonele de memorie folosite si inchidem fisierele.

##2. Rezolvarea primului task: 

Pentru a rezolva primul task vom folosi o functie apelata in main solve_task_1 ce va primi fisierul de citire cu datele echipelor si va returna lista cu echipele formata si numarul de echipe.
Initial deschidem fisierul cu date si citim numarul de echipe.
Initializam o lista de echipe list_head cu NULL.
Intr-un ciclu for citim datele despre fiecare echipa si o construim prin functia create_team adaugam echipa creeata in funtie la inceputul listei de echipe conform cerintei prin functii specifice listelor explicate mai jos.
In functia create_team creem fiecare echipa citita.
Deschidem fisierul de date si declaram buffer-uri pt numele echipei si prenumele si numele fiecarui jucator.
Intr-un ciclu for citim pt fiecare echipa lista de jucatori cu nume prenume si punctaj individual si adagam fiecare jucator in lista de jucatori asociata fiecarei echipe prin functii definite in biblioteca de liste.

##3. Rezolvarea task-ului 2:

Task-ul doi este executat de functia solve_task_2 apelata in main ce se foloseste de informatiile de la task ul 1 
In functia de rezolvare a task-ului 2 creem o variabila ce arata noul numar de echipe dupa reducerea numarului de echipe. Acesta este calculat prin functia reduce_number
Parcurgem lista de echipe pt. a afla cele mai mici n scoruri si elilinam echipele asociate acestor scoruri, unde n = numarul vechi de echipe - numarul nou de echipe
Calculul scorului unei echipe se face prin functia find score ce parcurge o intreaga echipa si calculeaza scorul conform formulei din cerinta
Functia eliminate_teams este folosita petru a elimina echipa cu cel mai mic scor din lista de echipe, astfel se cauta echipa cuscor minim si se elimina cu ajutorul functiei eliminate_team din biblioteca cu liste
In final taskul 2 returneaza in main lista actualizata de echipe si noul numar de echipe

##4. Rezolvarea task-ului 3:
Task-ul 3 se rezolva prin functia solve_task_3 apelata in main ce contine lista actualizata de echipe de la task-ul 2 si noul numar de echipe aceasta returneaza conform cerintei lista cu cele 8 echipe castigatoare si afiseaza rundele si castigatorii de la fiecare runda
Incepem prin a declara 2 stive una de castigatori si una de invinsi, dar si o lista de match-uri declaram si o variabila ce retine runda curenta dar si o variabila ce va retine runda unde vor fi doar cele 8 echipe castigatoare.
Afisam lista cu toate echipele si le bagam in coada de matchuri.
Cat timp au ramas echipe in coada de match uri afisam nuarul rundei si runda curenta si vedem scorul maxim dintre 2 echipe aflate intr un match, conform scorului le adaugam fie in stiva de invingatori, fie in stiva de invinsi totodata cresem punctajul echipei invingatoare conform cerintei.
Apoi afisam echipele din stiva invingatorilor si in punem in coada de match uri daca suntem la runda cu cei 8 invingatori ii adaugam pe toti in lista de invingatori pe care o returnam. de asemenea stergem echipele din lista de invinsi.
Acest proces continua pana nu a ramas decat o singura echipa invingatoare

##5. Rezolvarea task-urilor 4 si 5:
Aceste task-uri se rezolva printr-o singura funtie ce primeste lista de invingatori generata la task-ul anterior, fisierul de afisare si numarul task-ului ce trebuie rezolvat (4 sau 5)
Initial inseram intr-un arbore binar continutul listei de invingatori prin functii dein biblioteca de arbori apoi parcurgem arborele in inordine inversa pt a arata echipele conform cerintei
Daca trebuie rezolvat si task-ul 5 creem un AVL si il populam cu echipele din arborele binar parcurs in inordine
Prin urmare arborele avl creat va trebui echilibrat doar prin rotatii la dreapta
Dupa ce creem AVL-ul il parcurgem pe nivele si afisam continutul nivelului 2

##Biblioteci destinate structurilor de date:

Pentru rezolvarea task-urilor folosim 4 biblioteci ce descriu funtiile folosite petru crearea si manipularea urmatoarelor structuri de date: liste, stive, cozi si arbori.
Toate functiile sunt similare cu cele prezentate la curs dar updatate petru cerintele problemei.





# OOP-2DGame

# Nume Proiect

Proiectul "Mini_Golf" este un joc simplu în care utilizatorul trebuie să navigheze un personaj dintr-o poziție de start până la o poziție finală pe o hartă generată aleator.

## Descriere

Scopul jocului este de a ajunge dintr-o poziție de start, situată în colțul din stânga sus al hărții, până la o poziție finală, situată în colțul din dreapta jos al hărții. Utilizatorul poate naviga personajul în sus, în jos, la stânga și la dreapta pe harta generată ALEATORIU in Map.cpp.

## Funcționalități

- Generarea aleatoare a hărții: Harta este generată aleatoriu la fiecare pornire a jocului, asigurând o experiență unică la fiecare rulare.
- Navigare: Utilizatorul poate naviga personajul folosind tastele săgeată sau tastele W, A, S și D.
          : Inamicul poate naviga personajul folosind tastele săgeată sau tastele Key_up, down, ....
## Cerințe

- Compiler C++
- Biblioteca SDL (Simple DirectMedia Layer) pentru afișarea hărții și a personajului

## Probleme cunoscute

- Coliziuni: Încă nu am implementat funcționalitatea de coliziune, astfel încât personajul poate trece prin obstacole sau pereți pe hartă.
- Detectarea sfârșitului jocului: Jocul se termină când personajul ajunge la poziția finală pe hartă. (se adauga in viitorul apropiat)
- Voi incerca sa modific mapa intr-un graf, sa adaug superputeri la inamic, sa blocheze anumite casute, sa fac un min-cut -1 pentru numarul de casute pe
- care le poate bloca.

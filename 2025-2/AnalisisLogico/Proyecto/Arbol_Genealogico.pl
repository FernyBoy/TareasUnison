% ===========================
% ÁRBOL GENEALÓGICO - PROLOG
% ===========================

% --- Hechos básicos ---

hombre(fernando).
hombre(oiram).
hombre(gerardo).
hombre(dante).
hombre(elias).
hombre(amaya).
hombre(alejandro).
hombre(ivan).
hombre(andres).
hombre(victor).
hombre(alan).

mujer(flor).
mujer(ariana).
mujer(melissa).
mujer(emi).
mujer(michelle).
mujer(melina).
mujer(karol).


% --- Relación padre ---
padre(fernando, dante).
padre(fernando, elias).
padre(oiram, emi).
padre(oiram, michelle).
padre(gerardo, amaya).
padre(gerardo, alejandro).
padre(gerardo, ivan).
padre(elias, andres).
padre(elias, melina).
padre(elias, karol).
padre(amaya, victor).
padre(amaya, alan).

% --- Relación madre ---
madre(flor, dante).
madre(flor, elias).
madre(ariana, emi).
madre(ariana, michelle).
madre(melissa, amaya).
madre(melissa, alejandro).
madre(melissa, ivan).
madre(emi, andres).
madre(emi, melina).
madre(emi, karol).
madre(michelle, victor).
madre(michelle, alan).

% ===========================
% REGLAS
% ===========================

progenitor(X, Y) :- padre(X, Y).
progenitor(X, Y) :- madre(X, Y).

% ABUELOS
abuelo(X, Y) :-
    hombre(X),
    progenitor(X, Z),
    progenitor(Z, Y).

abuela(X, Y) :-
    mujer(X),
    progenitor(X, Z),
    progenitor(Z, Y).

% HERMANOS
hermano(X, Y) :-
    hombre(X),
    progenitor(P, X),
    progenitor(P, Y),
    X \= Y.

hermana(X, Y) :-
    mujer(X),
    progenitor(P, X),
    progenitor(P, Y),
    X \= Y.

% Funcion neutra
hermanos(X, Y) :- hermano(X, Y).
hermanos(X, Y) :- hermana(X, Y).

% TÍOS
tio(X, Y) :-
    hombre(X),
    hermanos(X, P),
    progenitor(P, Y).

tia(X, Y) :-
    mujer(X),
    hermanos(X, P),
    progenitor(P, Y).

% PRIMOS
primo(X, Y) :-
    hombre(X),
    progenitor(PX, X),
    progenitor(PY, Y),
    hermanos(PX, PY),
    X \= Y.

prima(X, Y) :-
    mujer(X),
    progenitor(PX, X),
    progenitor(PY, Y),
    hermanos(PX, PY),
    X \= Y.

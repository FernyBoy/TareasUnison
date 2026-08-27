#lang racket

; --- 1 ---
(struct verdadero-exp ()        #:transparent)
(struct falso-exp     ()        #:transparent)
(struct y-exp         (izq der) #:transparent)
(struct o-exp         (izq der) #:transparent)
(struct no-exp        (cuerpo)  #:transparent)



; --- 2 ---
(y-exp (verdadero-exp) (no-exp (falso-exp)))
(o-exp (no-exp (verdadero-exp)) (y-exp (falso-exp) (verdadero-exp)))



; --- 3 ---
; (a) y (b), esto dado que no-exp solo acepta un valor, mientras que y necesita de dos expresiones



; --- 4 ---
(struct fin       ()          #:transparent)
(struct avanza    (num prog)  #:transparent)
(struct gira-izq  (prog)      #:transparent)
(struct gira-der  (prog)      #:transparent)



; --- 5 ---
(avanza 3 (gira-izq (avanza 2 (fin))))
(gira-der (gira-der (fin)))



; --- 6 ---
; Hay 2 avanza y el struct más adentro es fin



; --- 7 ---
(struct aqui    ()                      #:transparent)
(struct norte   (num ruta)              #:transparent)
(struct este    (num ruta)              #:transparent)
(struct repite  (num ruta-izq ruta-der) #:transparent)



; --- 8 ---
(repite 3 (norte 2 (aqui)) (este 5 (aqui)))



; --- 9 ---
; Arbol   ::=   hoja(Num)
;          |    Rama(Arbol, Arbol)
;          |    etiq(Nombre, Arbol)

#lang racket

(struct circulo     (radio)       #:transparent)
(struct rectangulo  (base altura) #:transparent)
(struct cuadrado    (lado)        #:transparent)

(define (area f)
    (match f
        [(circulo r)      (* 3.1416 r r)]
        [(rectangulo b h) (* b h)]
        [(cuadrado l)     (* l l)]))



; --------------------------------------------
; 1. Dos figuras más
; --------------------------------------------
(struct triangulo   (base altura) #:transparent)
(struct rombo       (diagonal-mayor diagonal-menor) #:transparent)



; --------------------------------------------
; 2. Las tres cosas que te dio struct
; --------------------------------------------
(define t (triangulo 6 4))
t
(triangulo-base t)
(triangulo-altura t)
(triangulo? t)

(define r (rombo 8 6))
r
(rombo-diagonal-mayor r)
(rombo-diagonal-menor r)
(rombo? r)



; --------------------------------------------
; 3. Un error que conviene provocar
; --------------------------------------------
;(triangulo 6)
;triangulo: arity mismatch;
 ;the expected number of arguments does not match the given number
  ;expected: 2
  ;given: 1
  ;context...:



; --------------------------------------------
; 4. Extender area
; --------------------------------------------
(define (area2 f)
    (match f
        [(circulo r)      (* 3.1416 r r)]
        [(rectangulo b h) (* b h)]
        [(cuadrado l)     (* l l)]
        [(triangulo b h)  (/ (* b h) 2)]
        [(rombo dM dm)    (/ (* dM dm) 2)]))

(area2 (triangulo 6 4))
(area2 (rombo 8 6))
(area2 (circulo 3))
(area2 (cuadrado 4))



; --------------------------------------------
; 5. Perimetro, desde cero 
; --------------------------------------------
(define (perimetro f)
    (match f
        [(circulo r)      (* 3.1416 r 2)]
        [(rectangulo b h) (+ b b h h)]
        [(cuadrado l)     (* 4 l)]))

(perimetro (circulo 3))
(perimetro (rectangulo 2 5))
(perimetro (cuadrado 4))



; --------------------------------------------
; 6. El comodín
; --------------------------------------------
(define (tiene-lados-iguales? f)
    (match f
        [(cuadrado _) #t]
        [(rombo _ _)    #t]
        [_ #f]))

(tiene-lados-iguales? (cuadrado 4))
(tiene-lados-iguales? (rombo 8 6))
(tiene-lados-iguales? (rectangulo 2 5))



; --------------------------------------------
; 7. sin escribir código
; --------------------------------------------
; Al momento de hacer la llamada

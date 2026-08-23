#lang racket

(define (mapea f lst)
    (if (null? lst)
        '()
        (cons (f (car lst)) (mapea f (cdr lst)))))

(define (cuadrado n)
    (* n n))

(define (doble n)
    (* n 2))

(mapea cuadrado '(1 2 3 4))
(mapea doble '(10 20))

#lang racket

(define (suma-lista lst)
    (if (null? lst)
        0
        (+ (car lst) (suma-lista (cdr lst)))))

(suma-lista '(10 20 30))
(suma-lista '())

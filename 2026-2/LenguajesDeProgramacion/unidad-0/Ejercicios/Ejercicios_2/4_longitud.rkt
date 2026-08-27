#lang racket

(define (longitud lst)
    (if (null? lst)
        0
        (+ 1 (longitud (cdr lst)))))

(longitud '(a b c))
(longitud '())

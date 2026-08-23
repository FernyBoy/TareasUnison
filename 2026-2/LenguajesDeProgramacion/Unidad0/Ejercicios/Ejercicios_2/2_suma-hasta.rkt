#lang racket

(define (suma-hasta n)
    (if (= n 0)
        0
        (+ n (suma-hasta (- n 1)))))

(suma-hasta 5)
(suma-hasta 0)

#lang racket

(define (filtra f lst)
    (cond 
        [(null? lst) '()]
        [(f (car lst)) (cons (car lst) (filtra f (cdr lst)))]
        [else (filtra f (cdr lst))]))

(define (even n)
    (if (= n 0)
        #t
        (if(< n 1)
            #f
            (even (- n 2)))))

(define (positivo n)
    (if (> n 0)
        #t
        #f))

(filtra even? '(1 2 3 4 5 6))
(filtra positivo '(-2 5 0 7 -1))

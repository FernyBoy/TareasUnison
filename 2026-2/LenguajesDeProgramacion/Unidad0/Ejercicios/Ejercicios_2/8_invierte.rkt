#lang racket

(define (concat lst1 lst2)
    (if (null? lst1)
        lst2
        (cons (car lst1) (concat (cdr lst1) lst2))))

(define (invierte lst)
    (if (null? lst)
        '()
        (concat (invierte (cdr lst)) (list (car lst)))))

(invierte '(1 2 3 4))
(invierte '(a))

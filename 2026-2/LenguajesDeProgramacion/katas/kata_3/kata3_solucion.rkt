#lang racket

(define (maximo lst)
    (if (> (car lst) (maximo (cdr lst)))
        (car lst)
        (maximo(cdr lst))
    )
    
)

(maximo '(3 9 2 7))

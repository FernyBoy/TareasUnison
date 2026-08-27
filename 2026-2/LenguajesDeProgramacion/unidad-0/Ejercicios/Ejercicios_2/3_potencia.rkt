#lang racket

(define (potencia b e)
    (if (= e 0)
        1
        (* b (potencia b (- e 1)))))

(potencia 3 4)
(potencia 5 0)

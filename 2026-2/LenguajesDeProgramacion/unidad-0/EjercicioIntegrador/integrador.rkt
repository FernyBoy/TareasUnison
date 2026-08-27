#lang racket



;; ============================================================
;;
;; Sección 1. representación
;;
;; ============================================================

(struct num-exp (n)                   #:transparent)
(struct id-exp (nombre)               #:transparent)
(struct add-exp (izq der)             #:transparent)
(struct mul-exp (izq der)             #:transparent)
(struct with-exp (nombre expr cuerpo) #:transparent)
;; ============================================================





;; ============================================================
;;
;; Sección 2. la función calc
;;
;; ============================================================

(define (asocs-vacias) '())
(define (extender asocs nombre valor)
    (cons (cons nombre valor) asocs))
(define (buscar nombre asocs)
    (cdr (assoc nombre asocs)))

(define (calc e asocs)
    (match e
        [(num-exp n)        n]
        [(id-exp nombre)    (buscar nombre asocs)]
        [(add-exp izq der)  (+ (calc izq asocs) (calc der asocs))]
        [(mul-exp izq der)  (* (calc izq asocs) (calc der asocs))]
        [(with-exp n e c)   (calc c (extender asocs n (calc e asocs)))]))



;; ===== Casos de verificación =====
;; -- (a) --
(calc (add-exp (num-exp 3) (mul-exp (num-exp 2) (num-exp 4))) '())

;; -- (b) --
(calc (with-exp 
          'y 
          (add-exp (num-exp 3) (num-exp 4)) 
          (mul-exp (id-exp 'y) (id-exp 'y))) 
      '())

;; -- (c) --
(calc (with-exp 
          'x
          (add-exp (num-exp 2) (num-exp 3))
          (with-exp 
              'y
              (mul-exp (id-exp 'x) (num-exp 2))
              (add-exp (id-exp 'x) (id-exp 'y))
              )
          )
      '())

;; -- (d) --
(calc (with-exp
          'a
          (num-exp 5)
          (mul-exp  
              (with-exp
                  'b
                  (add-exp (id-exp 'a) (num-exp 1))
                  (id-exp 'b)
              ) 
              (id-exp 'a)
          )
      )
      '())
;; ============================================================





;; ============================================================
;;
;; Sección 3. el trazado
;;
;; ============================================================
;; Expresión: with x = add(2, 3) in with y = mul(x, 2) in add(x, y)
#|
(calc (with-exp 'x (add-exp (num-exp 2) (num-exp 3)) (with-exp 'y (mul-exp (id-exp 'x) (num-exp 2)) (add-exp (id-exp 'x) (id-exp 'y)))) sigma0)
(calc (with-exp 'y (mul-exp (id-exp 'x) (num-exp 2)) (add-exp (id-exp 'x) (id-exp 'y))) (extender sigma0 'x (calc (add-exp (num-exp 2) (num-exp 3)) sigma0)))           [with]
(calc (with-exp 'y (mul-exp (id-exp 'x) (num-exp 2)) (add-exp (id-exp 'x) (id-exp 'y))) (extender sigma0 'x ((calc (num-exp 2) sigma0) + (calc (num-exp 3) sigma0))))   [add]
(calc (with-exp 'y (mul-exp (id-exp 'x) (num-exp 2)) (add-exp (id-exp 'x) (id-exp 'y))) (extender sigma0 'x (2 + (calc (num-exp 3) sigma0))))                           [num]
(calc (with-exp 'y (mul-exp (id-exp 'x) (num-exp 2)) (add-exp (id-exp 'x) (id-exp 'y))) (extender sigma0 'x (2 + 3)))                                                   [num]
(calc (with-exp 'y (mul-exp (id-exp 'x) (num-exp 2)) (add-exp (id-exp 'x) (id-exp 'y))) sigma1)
(calc (add-exp (id-exp 'x) (id-exp 'y)) (extender sigma1 'y (calc (mul-exp (id-exp 'x) (num-exp 2)) sigma1)))                                                           [with]
(calc (add-exp (id-exp 'x) (id-exp 'y)) (extender sigma1 'y ((calc (id-exp 'x) sigma1) x (calc (num-exp 2) sigma1))))                                                   [mul]
(calc (add-exp (id-exp 'x) (id-exp 'y)) (extender sigma1 'y ((buscar 'x sigma1) x (calc (num-exp 2) sigma1))))                                                          [id]
(calc (add-exp (id-exp 'x) (id-exp 'y)) (extender sigma1 'y (5 x (calc (num-exp 2) sigma1))))
(calc (add-exp (id-exp 'x) (id-exp 'y)) (extender sigma1 'y (5 x 2)))                                                                                                   [num]
(calc (add-exp (id-exp 'x) (id-exp 'y)) sigma2)
((calc (id-exp 'x) sigma2) + (calc (id-exp 'y) sigma2))                                                                                                                 [add]
((buscar 'x sigma2) + (calc (id-exp 'y) sigma2))                                                                                                                        [id]
(5 + (calc (id-exp 'y) sigma2)) 
(5 + (buscar 'y sigma2))                                                                                                                                                [id]
(5 + 10)
15
|#

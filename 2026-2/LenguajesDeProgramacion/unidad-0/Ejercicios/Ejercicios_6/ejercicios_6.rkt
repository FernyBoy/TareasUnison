#lang racket

;; =============================
;; 1. Sea h definida así
;; =============================
;; Traza h(4)
;; h(4) = h(4 - 1) + 3                      =   h(3) + 3
;; h(4) = (h(3 - 1) + 3) + 3                =   (h(2) + 3) + 3
;; h(4) = ((h(2 - 1) + 3) + 3) + 3          =   ((h(1) + 3) + 3) + 3
;; h(4) = (((h(1 - 1) + 3) + 3) + 3) + 3    =   (((h(0) + 3) + 3) + 3) + 3 
;; h(4) = (((2 + 3) + 3) + 3) + 3
;; h(4) = 14



;; =============================
;; 2. Sea g definida así
;; =============================
;; Traza g(3)
;; g(3) = 3 + g(3 - 1) = 3 + g(2)
;; g(3) = 3 + (2 + g(2 - 1)) = 3 + (2 + g(1))
;; g(3) = 3 + (2 + (1 + g(1 - 1))) = 3 + (2 + (1 + g(0)))
;; g(3) = 3 + (2 + (1 + 0))
;; g(3) = 6



;; =============================
;; 3. Sin trazar
;; =============================
;; La regla [rec] se aplica 10 veces y la regla [base] se aplica 1 vez



;; =============================
;; 4. Traza add(2, mul(3, 4))
;; =============================
;; (calc (add-exp (num-exp 2) (mul-exp (num-exp 3) (num-exp 4))))
;; (calc (num-exp 2)) + (calc (mul-exp (num-exp 3) (num-exp 4)))
;; 2 + (calc (mul-exp (num-exp 3) (num-exp 4)))
;; 2 + ((calc (num-exp 3)) x (calc (num-exp 4)))
;; 2 + (3 x (calc (num-exp 4)))
;; 2 + (3 x 4)
;; 2 + 12
;; 14



;; ==================================
;; 5. Traza mul(add(1, 1), add(2, 3))
;; ==================================
;; (calc (mul-exp (add-exp (num-exp 1) (num-exp 1)) (add-exp (num-exp 2) (num-exp 3))))
;; (calc (add-exp (num-exp 1) (num-exp 1))) x (calc (add-exp (num-exp 2) (num-exp 3)))
;; ((calc (num-exp 1)) + (calc (num-exp 1))) x (calc (add-exp (num-exp 2) (num-exp 3)))
;; ((calc (num-exp 1)) + (calc (num-exp 1))) x ((calc (num-exp 2)) + (calc (num-exp 3)))
;; (1 + (calc (num-exp 1))) x ((calc (num-exp 2)) + (calc (num-exp 3)))
;; (1 + 1) x ((calc (num-exp 2)) + (calc (num-exp 3)))
;; (1 + 1) x (2 + (calc (num-exp 3)))
;; (1 + 1) x (2 + 3)
;; 2 x (2 + 3)
;; 2 x 5
;; 10



;; =============================
;; 6. Traza neg(add(2, 3))
;; =============================
;; (calc (neg-exp (add-exp (num-exp 2) (num-exp 3))))
;; -(calc (add-exp (num-exp 2) (num-exp 3)))
;; -((calc (num-exp 2)) + (calc (num-exp 3)))
;; -(2 + (calc (num-exp 3)))
;; -(2 + 3)
;; -5



;; =============================
;; 7. Comprobar
;; =============================
(struct num-exp (n)       #:transparent)
(struct add-exp (izq der) #:transparent)
(struct mul-exp (izq der) #:transparent)
(struct neg-exp (cuerpo)  #:transparent)

(define (calc e)
    (match e
        [(num-exp n)        n]
        [(add-exp izq der)  (+ (calc izq) (calc der))]
        [(mul-exp izq der)  (* (calc izq) (calc der))]
        [(neg-exp cuerpo)   (- (calc cuerpo))]))


(calc (add-exp (num-exp 2) (mul-exp (num-exp 3) (num-exp 4))))
(calc (mul-exp (add-exp (num-exp 1) (num-exp 1)) (add-exp (num-exp 2) (num-exp 3))))
(calc (neg-exp (add-exp (num-exp 2) (num-exp 3))))



;; ==============================================
;; 8. Traza cuantos-nodos sobre add(3, mul(2, 4))
;; ==============================================
;; (cuantos-nodos (add-exp (num-exp 3) (mul-exp (num-exp 2) (num-exp 4))))
;; 1 + (cuantos-nodos (num-exp 3)) + (cuantos-nodos (mul-exp (num-exp 2) (num-exp 4)))
;; 1 + 1 + (cuantos-nodos (mul-exp (num-exp 2) (num-exp 4)))
;; 1 + 1 + (1 + (cuantos-nodos (num-exp 3)) + (cuantos-nodos (num-exp 4)))
;; 1 + 1 + (1 + 1 + (cuantos-nodos (num-exp 4)))
;; 1 + 1 + (1 + 1 + 1)
;; 5



;; ===========================================
;; 9. Traza cuantos-nodos sobre neg(add(1, 2))
;; ===========================================
;; (cuantos-nodos (neg-exp (add-exp (num-exp 1) (num-exp 2))))
;; 1 + (cuantos-nodos (add-exp (num-exp 1) (num-exp 2)))
;; 1 + (1 + (cuantos-nodos (num-exp 1)) + (cuantos-nodos (num-exp 2)))
;; 1 + (1 + 1 + (cuantos-nodos (num-exp 2)))
;; 1 + (1 + 1 + 1)
;; 4

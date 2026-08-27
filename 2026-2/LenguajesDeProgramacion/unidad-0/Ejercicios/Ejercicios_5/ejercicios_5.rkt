#lang racket

;; ===========================================================================
;; calc, un evaluador para expresiones aritméticas
;;
;; Unidad 0, sesión 5 (L, 17 de agosto de 2026).
;; Lenguajes de Programación. LCC, Universidad de Sonora.
;;
;; Este es el código que discutimos en clase, completo y comentado.
;; Es el primer programa del curso cuya entrada es otro programa.
;;
;; CÓMO CORRERLO
;; 
;;   En DrRacket: abre este archivo y presiona Run. Todo lo que está
;;   definido aquí queda disponible en el panel de abajo (en el REPL),
;;   y ahí puedes probar lo que quieras. Los ejemplos de más abajo
;;   están para que los teclees.
;;
;;   En la terminal lo puedes correr así:
;;      racket -i -e '(require "u0-calc.rkt")'
;;
;; QUÉ HACER CON ÉL
;;   Léelo, córrelo y modifícalo. La mejor forma de comprobar que entendiste
;;   la sesión es agregarle una operación nueva: escribe la producción, define
;;   el struct, agrega el caso en calc, y pruébalo.
;;
;; DÓNDE SE EXPLICA CADA COSA
;;   Sesión 4: la gramática, los structs, construir árboles a mano.
;;   Sesión 5: calc, y las dos formas de agregar la resta.
;; ===========================================================================

;; ---------------------------------------------------------------------------
;; LA GRAMÁTICA
;;
;;   Exp ::= Num
;;        |  add(Exp, Exp)
;;        |  mul(Exp, Exp)
;;        |  neg(Exp)
;;
;; Cuatro producciones. Cada una se convierte en un struct, y cada Exp del
;; lado derecho se convierte en un campo.
;; ---------------------------------------------------------------------------

;; ---------------------------------------------------------------------------
;; LA REPRESENTACIÓN: un struct por producción
;;
;; #:transparent es para que el REPL nos deje ver lo que hay adentro. Sin él,
;; Racket imprime #<num-exp> y no se puede depurar nada.
;; ---------------------------------------------------------------------------

                                            ; SINTAXIS CONCRETA
                                            ; -----------------
(struct num-exp (n)        #:transparent)   ; Num
(struct add-exp (izq der)  #:transparent)   ; add(Exp, Exp)
(struct mul-exp (izq der)  #:transparent)   ; mul(Exp, Exp)
(struct neg-exp (cuerpo)   #:transparent)   ; neg(Exp)

;; Los campos de add-exp y mul-exp son a su vez expresiones: es un dato
;; definido en términos de sí mismo, igual que una lista. Por eso calc es
;; recursiva.

;; ---------------------------------------------------------------------------
;; EL EVALUADOR
;;
;; calc : Exp -> número
;;
;; Un caso por variante. Cada caso hace una sola cosa, y la hace para su
;; variante. La forma del dato dicta la forma de la función.
;; ---------------------------------------------------------------------------

;; (define (calc e)
;;  (match e
;;    [(num-exp n)       n]
;;    [(add-exp izq der) (+ (calc izq) (calc der))]
;;    [(mul-exp izq der) (* (calc izq) (calc der))]
;;    [(neg-exp cuerpo)  (- (calc cuerpo))]))

;; Ojo con el caso de add-exp: izq y der NO son números, son expresiones.
;; (+ izq der) no tendría sentido (estarías sumando dos árboles). Para sumar
;; hace falta el valor de cada lado, y quien sabe calcular eso es calc.

;; ---------------------------------------------------------------------------
;; LA RESTA, SIN TOCAR calc
;;
;; En clase vimos dos caminos para agregar la resta. El primero era definir un
;; struct sub-exp y agregarle un caso a calc. Este es el segundo:
;;
;; sub-exp NO es un struct. Es una función que arma un árbol con las piezas
;; que ya teníamos (restar b es sumar el negativo de b), así que calc no se
;; entera de que existe la resta y no cambia ni una línea.
;;
;;   > (sub-exp (num-exp 5) (num-exp 2))
;;   (add-exp (num-exp 5) (neg-exp (num-exp 2)))
;;
;; Los dos caminos funcionan. Cuál conviene es la pregunta que dejamos abierta
;; con la lectura de Steele, y que vuelve en la unidad 1.
;; ---------------------------------------------------------------------------

(define (sub-exp a b)
  (add-exp a (neg-exp b)))

;; ---------------------------------------------------------------------------
;; QUÉ SE VE DESDE AFUERA
;;
;; provide dice qué este archivo puede ser usado por otros
;; archivos. Lo vemos más adelante. Por ahora basta con saber que está
;; aquí para que otro archivo pueda construir estos mismos structs sin
;; volver a definirlos.
;; ---------------------------------------------------------------------------

(provide (struct-out num-exp)
         (struct-out add-exp)
         (struct-out mul-exp)
         (struct-out neg-exp)
         calc
         sub-exp)

;; ===========================================================================
;; PARA PROBAR EN EL REPL
;;
;; Copia estas líneas una por una después de presionar Run.
;;
;;   > (define p (add-exp (num-exp 3)
;;                        (mul-exp (num-exp 2) (num-exp 4))))
;;   > p
;;   (add-exp (num-exp 3) (mul-exp (num-exp 2) (num-exp 4)))
;;   > (calc p)
;;   11
;;
;;   > (calc (num-exp 5))
;;   5
;;
;;   > (calc (neg-exp (add-exp (num-exp 1) (num-exp 2))))
;;   -3
;;
;;   > (calc (sub-exp (num-exp 5) (num-exp 2)))
;;   3
;;
;;   > (calc (mul-exp (add-exp (num-exp 1) (num-exp 2))
;;                    (add-exp (num-exp 3) (num-exp 4))))
;;   21
;;
;; ===========================================================================

(define p (add-exp (num-exp 3) (mul-exp (num-exp 2) (num-exp 4))))

(define q (neg-exp (add-exp (num-exp 1) (num-exp 2))))

(define r (mul-exp (add-exp (num-exp 2) (num-exp 3)) 
                   (mul-exp (num-exp 2) (num-exp 2))))

(define s (mul-exp (add-exp (num-exp 1) (num-exp 2))
                   (add-exp (num-exp 3) (num-exp 4))))

;; =============================
;; 1. max
;; =============================
(struct max-exp (n1 n2))
(define (calc e)
  (match e
    [(num-exp n)        n]
    [(add-exp izq der)  (+ (calc izq) (calc der))]
    [(mul-exp izq der)  (* (calc izq) (calc der))]
    [(neg-exp cuerpo)   (- (calc cuerpo))]
    [(max-exp n1 n2)    (max (calc n1) (calc n2))]))



;; =============================
;; 2. Sin escribir código
;; =============================
;; Es posible, podemos crear una función con un if que devuelva el valor mayor



;; =============================
;; 3. cuantos-nodos
;; =============================
(define (cuantos-nodos arbol)
    (match arbol
        [(num-exp _)        1]
        [(add-exp izq der)  (+ 1 (cuantos-nodos izq) (cuantos-nodos der))]
        [(mul-exp izq der)  (+ 1 (cuantos-nodos izq) (cuantos-nodos der))]
        [(neg-exp nodo)     (+ 1 (cuantos-nodos nodo))]
        [(max-exp izq der)  (+ 1 (cuantos-nodos izq) (cuantos-nodos der))]))



;; =============================
;; 4. profundidad
;; =============================
(define (profundidad arbol)
    (match arbol
        [(num-exp _)        1]
        [(add-exp izq der)  (+ 1 (max (profundidad izq) (profundidad der)))]
        [(mul-exp izq der)  (+ 1 (max (profundidad izq) (profundidad der)))]
        [(neg-exp nodo)     (+ 1 (profundidad nodo))]
        [(max-exp izq der)  (+ 1 (max (profundidad izq) (profundidad der)))]))



;; =============================
;; 5. a-texto
;; =============================
(define (a-texto e)
    (match e
        [(num-exp n)        (number->string n)]
        [(add-exp izq der)  (string-append "add(" (a-texto izq) ", " (a-texto der) ")")]
        [(mul-exp izq der)  (string-append "mul(" (a-texto izq) ", " (a-texto der) ")")]
        [(neg-exp nodo)     (string-append "neg(" (a-texto nodo) ")")]
        [(max-exp izq der)  (string-append "max(" (a-texto izq) ", " (a-texto der) ")")]))



;; =============================
;; Pruebas
;; =============================
(calc p)
(calc q)
(calc r)
(calc s)
(calc (max-exp (num-exp 3) (num-exp 5)))
(cuantos-nodos (num-exp 7))
(cuantos-nodos p)
(cuantos-nodos q)
(cuantos-nodos r)
(profundidad (num-exp 7))
(profundidad p)
(profundidad s)
(a-texto p)
(a-texto r)

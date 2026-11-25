#lang racket

#|
   TAREA 1. Extender el lenguaje LET

   Nombre: Angel Fernando Bórquez Guerrero

   Aquí va la prosa de las secciones 1, 2 y 4 de cada constructo, en el
   orden del enunciado. Solo aparecen las secciones que te toca escribir: las
   demás vienen dadas en el enunciado. La sección 3 es el código: tus struct
   en ast.rkt y tus cláusulas en interp.rkt y en desugar.rkt, en los lugares
   marcados.

   not
   ---
   4. Contraste

   | Expresión          | Especificación        | Implementación                |
   |--------------------|-----------------------|-------------------------------|
   | not(zero?(0))      | #f, por [not-v]       | (boolval #f)                  |
   | not(less?(2, 1))   | #t, por [not-f]       | (boolval #t)                  |
   | not(3)   (borde)   | sin regla: no hay     | val->bool: Esperaba un        |
   |                    | [not-*] con v1 = 3    | booleano pero me diste 3      |

   Coinciden. En el borde, la especificación no da valor porque ninguna regla
   tiene a 3 como premisa, y la implementación falla en val->bool: ambas
   dicen "no hay valor", así que ninguna tiene que cambiar.


   and
   ---
   4. Contraste

   | Expresión                      | Especificación               | Implementación |
   |--------------------------------|------------------------------|----------------|
   | and(true, false)               | if true then false else      | (boolval #f)   |
   |                                | false ⇝ ... = #f, por [if-v] |                |
   | and(zero?(0), equal?(1, 1))    | [if-v], luego [equal?-v]: #t | (boolval #t)   |
   | and(false, car(emptylist))     | [if-f]: false = #f; e2 no se | (boolval #f)   |
   |   (borde)                      | evalúa                       |                |

   Coinciden. El borde muestra que la traducción a if hace que and sea
   perezoso en e2: car(emptylist) fallaría si se evaluara, y no se evalúa.


   or
   --
   1. Propuesta informal

   La disyunción lógica de dos expresiones. Se evalúa primero e1, que tiene
   que dar un booleano. Si da verdadero, el valor del or es verdadero y e2
   no se evalúa. Si da falso, se evalúa e2, que también tiene que dar un
   booleano, y ese booleano es el valor del or. Va en el núcleo.

   2. Especificación formal

   Expression ::= or(Expression, Expression)        (or-exp e1 e2)

              (value-of e1 ρ) = #t
   ----------------------------------------- [or-v]
       (value-of (or-exp e1 e2) ρ) = #t

       (value-of e1 ρ) = #f     (value-of e2 ρ) = v2     v2 ∈ Bool
   ----------------------------------------------------------------- [or-f]
                 (value-of (or-exp e1 e2) ρ) = v2

   En [or-v] e2 no aparece en las premisas: no se evalúa. En [or-f] e2 se
   evalúa y a su valor se le exige ser booleano; si e1 no da booleano o e2
   da otra cosa, ninguna regla aplica y el or no tiene valor.

   4. Contraste

   | Expresión                    | Especificación               | Implementación            |
   |------------------------------|------------------------------|---------------------------|
   | or(false, true)              | [or-f] con v2 = #t: #t       | (boolval #t)              |
   | or(true, car(emptylist))     | [or-v]: #t, e2 no se evalúa  | (boolval #t)              |
   |   (borde)                    |                              |                           |
   | or(false, 5)   (borde)       | sin regla: [or-f] exige      | val->bool: Esperaba un    |
   |                              | v2 ∈ Bool y 5 no lo es       | booleano pero me diste 5  |

   Coinciden. La cláusula dada solo evalúa e2 en la rama falsa, como dice
   [or-v], y le aplica val->bool, que es la premisa v2 ∈ Bool de [or-f].


   xor
   ---
   1. Propuesta informal

   La disyunción exclusiva: es verdadera cuando exactamente una de las dos
   expresiones es verdadera. Se evalúa e1; si es verdadera, el xor vale la
   negación de e2, y si es falsa, vale e2 tal cual. Es azúcar: se traduce a
   un if con un not adentro, así que hereda de ellos que e1 y e2 deben dar
   booleanos.

   2. Especificación formal

   Expression ::= xor(Expression, Expression)       (xor-exp e1 e2)

   xor(e1, e2) ⇝ if e1 then not(e2) else e2         [xor]

   4. Contraste

   | Expresión           | Especificación                       | Implementación            |
   |---------------------|--------------------------------------|---------------------------|
   | xor(true, true)     | if true then not(true) else true;    | (boolval #f)              |
   |                     | [if-v], [not-v]: #f                  |                           |
   | xor(false, true)    | [if-f]: true = #t                    | (boolval #t)              |
   | xor(true, 7)        | [if-v], luego not(7): sin regla,     | val->bool: Esperaba un    |
   |   (borde)           | 7 no es booleano                     | booleano pero me diste 7  |

   Coinciden. Nota del borde: xor(false, 7) sí tendría valor 7 según [xor],
   porque la rama else devuelve e2 sin exigirle nada; la implementación hace
   lo mismo. Si se quisiera que xor siempre exija booleanos habría que cambiar
   la especificación, no la implementación.


   cond
   ----
   2. Especificación formal: solo la regla de cond end

   cond end ⇝ car(emptylist)                        [cond-vacío]

   Un cond al que no le queda ninguna rama no tiene valor que dar, así que se
   traduce a una expresión del núcleo que no tiene valor: car(emptylist) no
   cumple la premisa de [car], que pide una lista v :: ℓ.

   4. Contraste

   | Expresión                                 | Especificación                     | Implementación        |
   |-------------------------------------------|------------------------------------|-----------------------|
   | let x = 3 in cond zero?(x) ==> 100        | [cond] dos veces, [if-f], [if-v]:  | (intval 200)          |
   |   zero?(-(x,3)) ==> 200 end               | 200                                |                       |
   | cond true ==> 1 car(emptylist) ==> 2 end  | [cond], [if-v]: 1; la segunda      | (intval 1)            |
   |                                           | prueba no se evalúa                |                       |
   | cond end   (borde)                        | [cond-vacío] ⇝ car(emptylist):     | car: contract         |
   |                                           | sin valor, [car] no aplica a ⟨⟩    | violation, given '()  |

   Coinciden. En el borde ambas fallan: la especificación no tiene regla que
   dé valor a car(⟨⟩) y la implementación truena en el car de Racket.


   list
   ----
   4. Contraste

   | Expresión                         | Especificación                          | Implementación                       |
   |-----------------------------------|-----------------------------------------|--------------------------------------|
   | let x = 4 in list(x, -(x,1),      | [list] tres veces, [list-vacía],        | (listval (list (intval 4)            |
   |   -(x,3))                         | luego [cons] tres veces: 4 :: 3 :: 1 :: ⟨⟩ | (intval 3) (intval 1)))           |
   | list()   (borde)                  | [list-vacía] ⇝ emptylist: ⟨⟩            | (listval '())                        |
   | list(list(), true)                | [list], [list-vacía] adentro: ⟨⟩ :: #t :: ⟨⟩ | (listval (list (listval '())    |
   |                                   |                                         | (boolval #t)))                       |

   Coinciden en las tres, incluido el borde list(), que llega a cons-exp cero
   veces y queda en emptylist.


   unpack
   ------
   2. Especificación formal

   Expression ::= unpack {Identifier}* = Expression in Expression
                                                    (unpack-exp xs e1 e2)

   xs es la lista de nombres x1 ... xn, con n ≥ 0, sin comas.

       (value-of e1 ρ) = v1 :: ... :: vn :: ⟨⟩
   --------------------------------------------------------------- [unpack]
     (value-of (unpack-exp (x1 ... xn) e1 e2) ρ)
         = (value-of e2 [x1=v1]...[xn=vn]ρ)

       (value-of e1 ρ) = v1 :: ... :: vm :: ⟨⟩     m ≠ n
   --------------------------------------------------------------- [unpack-err]
     (value-of (unpack-exp (x1 ... xn) e1 e2) ρ) = error

   En [unpack] la lista tiene exactamente n elementos, uno por nombre, y el
   entorno se extiende una vez por cada nombre, en orden, antes de evaluar el
   cuerpo. Con n = 0 y la lista vacía, [unpack] aplica y el cuerpo se evalúa
   en ρ sin cambios. Si la lista tiene otra cantidad de elementos aplica
   [unpack-err] y el unpack no tiene valor; e2 no se evalúa. Si e1 no da una
   lista, ninguna regla aplica.

   4. Contraste

   | Expresión                                       | Especificación                     | Implementación              |
   |-------------------------------------------------|------------------------------------|-----------------------------|
   | let u = 7 in unpack x y = list(u, 3) in -(x, y) | [unpack], n = 2: -(7, 3) = 4       | (intval 4)                  |
   | unpack = list() in 42   (borde)                 | [unpack], n = 0, lista ⟨⟩: 42      | (intval 42)                 |
   | unpack = list(1) in 42   (borde)                | [unpack-err], n = 0, m = 1: error  | unpack: 0 nombres pero la   |
   |                                                 |                                    | lista tiene 1 elementos     |

   Coinciden. La auxiliar extend-env* sigue la estructura de las dos reglas:
   compara las longitudes primero ([unpack-err]) y si coinciden extiende el
   entorno un nombre a la vez ([unpack]).

|#

(require "ast.rkt"
         "env.rkt"
         "vals.rkt")

(provide
    (contract-out
    [value-of (-> expression? env?
                    expval?)]))

;; Intérprete del lenguaje LET
(define (value-of e ρ)
    (match e
        [(const-exp n)    (intval n)]
        [(var-exp x)      (apply-env ρ x)]
        [(diff-exp e1 e2)
        (define v1 (value-of e1 ρ))
        (define v2 (value-of e2 ρ))
        (intval (- (val->int v1)
                    (val->int v2)))]
        [(zero?-exp e1)
        (define v1 (value-of e1 ρ))
        (boolval (zero? (val->int v1)))]
        [(if-exp e1 e2 e3)
        (define v1 (value-of e1 ρ))
        (if (val->bool v1)
            (value-of e2 ρ)
            (value-of e3 ρ))]
        [(let-exp x e1 e2)
        (define v1 (value-of e1 ρ))
        (define ρ* (extend-env x v1 ρ))
        (value-of e2 ρ*)]

        ;; La aritmética que va en el núcleo: minus, mul y quotient
        [(minus-exp e1)
        (define v1 (value-of e1 ρ))
        (intval (- (val->int v1)))]
        [(mul-exp e1 e2)
        (define v1 (value-of e1 ρ))
        (define v2 (value-of e2 ρ))
        (intval (* (val->int v1)
                    (val->int v2)))]
        [(quotient-exp e1 e2)
        (define v1 (value-of e1 ρ))
        (define v2 (value-of e2 ρ))
        (intval (quotient (val->int v1)
                        (val->int v2)))]

        ;; Los booleanos que van en el núcleo: equal? y less?
        [(equal?-exp e1 e2)
        (define v1 (value-of e1 ρ))
        (define v2 (value-of e2 ρ))
        (boolval (equal? v1 v2))]
        [(less?-exp e1 e2)
        (define v1 (value-of e1 ρ))
        (define v2 (value-of e2 ρ))
        (boolval (val<? v1 v2))]

        ;; Las listas
        [(emptylist-exp)
        (listval '())]
        [(cons-exp e1 e2)
        (define v1 (value-of e1 ρ))
        (define v2 (value-of e2 ρ))
        (listval (cons v1 (val->list v2)))]
        [(car-exp e1)
        (define v1 (value-of e1 ρ))
        (car (val->list v1))]
        [(cdr-exp e1)
        (define v1 (value-of e1 ρ))
        (listval (cdr (val->list v1)))]
        [(null?-exp e1)
        (define v1 (value-of e1 ρ))
        (boolval (null? (val->list v1)))]

        ;; --- AQUÍ van tus cláusulas del núcleo: not-exp y unpack-exp ---
        [(not-exp e1)
        (define v1 (value-of e1 ρ))
        (boolval (not (val->bool v1)))]
        [(unpack-exp xs e1 e2)
        (define v1 (value-of e1 ρ))
        (define ρ* (extend-env* xs (val->list v1) ρ))
        (value-of e2 ρ*)]

        ;; La tarea, lo que viene hecho en el núcleo: or
        [(or-exp e1 e2)
        (define v1 (value-of e1 ρ))
        (if (val->bool v1)
            (boolval #t)
            (boolval (val->bool (value-of e2 ρ))))]))

;; Si una cláusula necesita una función auxiliar, va aquí abajo, con nombre
;; propio, y no escondida dentro de la cláusula.

;; --- AQUÍ van tus auxiliares, cada una con nombre propio ---

;; Extiende ρ con varios nombres a la vez: xs es la lista de nombres y vs la
;; de valores, en el mismo orden. Se extiende una vez por cada nombre. Si las
;; longitudes no coinciden, es un error.
(define (extend-env* xs vs ρ)
    (cond
        [(not (= (length xs) (length vs)))
        (error 'unpack
               "~a nombres pero la lista tiene ~a elementos"
               (length xs) (length vs))]
        [(null? xs) ρ]
        [else
        (extend-env (first xs) (first vs)
                    (extend-env* (rest xs) (rest vs) ρ))]))

;; El orden de los valores expresados: false es menor que todo lo demás,
;; true es mayor que todo lo demás, y entre números es el < de siempre.
;; Es estricto: ningún valor es menor que sí mismo.
(define (val<? v1 v2)
    (match (list v1 v2)
        [(list (boolval #f) (boolval #f)) #f]
        [(list (boolval #f) _)            #t]
        [(list (boolval #t) _)            #f]
        [(list _            (boolval #f)) #f]
        [(list _            (boolval #t)) #t]
        [(list (intval n1)  (intval n2))  (< n1 n2)]))

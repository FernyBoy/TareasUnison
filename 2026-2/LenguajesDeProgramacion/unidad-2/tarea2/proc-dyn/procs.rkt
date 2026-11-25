#lang racket

;; Procedimientos. apply-procedure vive en interp.rkt, porque evalúa el cuerpo
;; con value-of.
;;
;; Con vinculación dinámica el cuerpo se evalúa en el entorno de la llamada,
;; así que el procedimiento ya no guarda el entorno de su creación: es solo el
;; parámetro y el cuerpo. El struct conserva el nombre closure para no tocar
;; el resto del intérprete, aunque ya no cierra sobre ningún entorno.

(require "ast.rkt")

(provide
 (contract-out
  ;; El parámetro y el cuerpo del procedimiento
  [struct closure ([x symbol?]
                   [body expression?])]))

(struct closure (x body) #:transparent)

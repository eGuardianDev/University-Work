#lang racket



(define (get-smallest-rec xs)
  (cond
    [(empty? xs) (error "Cannot pass empty list")]
    [(= 1 (length xs)) (car xs)]
    [else (min (car xs) (get-smallest-rec (cdr xs)))]))

(define (get-smallest-proc xs)
  (apply min xs)
  )

(define (get-smallest-fold-proc xs)
  (foldl min (car xs) (cdr xs))
  )

(define (get-smallest-fold-no-proc xs)
  (foldl (λ (x acc) (min x acc)) (car xs) (cdr xs))
)

; using a recursive procedure
(= (get-smallest-rec '(1 2 5)) 1)
(= (get-smallest-rec '(2 1 5)) 1)
(= (get-smallest-rec '(2 1 -1 5)) -1)

; with a predefined procedure
(= (get-smallest-proc '(1 2 5)) 1)
(= (get-smallest-proc '(2 1 5)) 1)
(= (get-smallest-proc '(2 1 -1 5)) -1)

; using a folding with a predefined procedure
(= (get-smallest-fold-proc '(1 2 5)) 1)
(= (get-smallest-fold-proc '(2 1 5)) 1)
(= (get-smallest-fold-proc '(2 1 -1 5)) -1)

; using a folding without a predefined procedure
(= (get-smallest-fold-no-proc '(1 2 5)) 1)
(= (get-smallest-fold-no-proc '(2 1 5)) 1)
(= (get-smallest-fold-no-proc '(2 1 -1 5)) -1)
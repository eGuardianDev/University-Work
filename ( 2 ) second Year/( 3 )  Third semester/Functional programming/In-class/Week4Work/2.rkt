#lang racket



(define (my-length-iter xs)
  (define (helper ys count)
    (if (empty? ys)
        count
        (helper (cdr ys) (add1 count))))
  (helper xs 0)
  )

(define (my-length-rec xs)
  (if (empty? xs)
      0
      (add1 (my-length-rec (cdr xs)))
  ))

(define (my-length-proc xs)
  (length xs)
  )

; using an iterative procedure
(= (my-length-iter '()) 0)
(= (my-length-iter '(1 2 5 6 4 8)) 6)

; using a recursive procedure
(= (my-length-rec '()) 0)
(= (my-length-rec '(1 2 5 6 4 8)) 6)

; using a predefined procedure
(= (my-length-proc '()) 0)
(= (my-length-proc '(1 2 5 6 4 8)) 6)
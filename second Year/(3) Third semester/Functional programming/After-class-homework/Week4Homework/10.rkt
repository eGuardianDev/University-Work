#lang racket


(define (concat-proc xs ys)
  (append xs ys))

(define (concat-rec xs ys)
  (if (empty? xs)
      ys
      (concat-rec (reverse (cdr (reverse xs) ))  (cons (car (reverse xs)) ys))))


; using a predefined procedure
(equal? (concat-proc '(1 2 3) '(4 5 6)) '(1 2 3 4 5 6))
(equal? (concat-proc '(1 2 3) '(1 2 3)) '(1 2 3 1 2 3))

; using a linearly iterative process
(equal? (concat-rec '(1 2 3) '(4 5 6)) '(1 2 3 4 5 6))
(equal? (concat-rec '(1 2 3) '(1 2 3)) '(1 2 3 1 2 3)) ; my test
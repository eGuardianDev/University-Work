#lang racket


(define (shuffle-merge xs ys)
  (cond
    [(and (empty? xs) (empty? ys)) null]
    [(empty? xs) (shuffle-merge ys xs)]
    [else (cons (car xs) (shuffle-merge ys (cdr xs)))]))


(shuffle-merge '(1) '()) ; → '(1)
(shuffle-merge '(3 4 5) '(2)) ; → '(3 2 4 5)
(shuffle-merge '(3 4 5) '(9 2)) ; → '(3 9 4 2 5)
(shuffle-merge '(3 2 8) '(5 6 1 9 11)) ; → '(3 5 2 6 8 1 9 11)
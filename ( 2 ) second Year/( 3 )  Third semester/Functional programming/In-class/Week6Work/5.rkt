#lang racket
(require math/number-theory)


(define (primes-prod x)
  (define (helper current acc)
    (cond
      [(> current (sqrt x)) acc]
      [(prime? current) (helper (add1 current) (* current acc))]
      [else (helper (add1 current) acc)]))
  (helper 2 1))


(primes-prod 12) ; → 6
(primes-prod 49) ; → 210
(primes-prod 1200) ; → 200560490130
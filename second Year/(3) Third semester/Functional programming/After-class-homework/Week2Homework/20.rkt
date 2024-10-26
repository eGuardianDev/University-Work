#lang racket
(require math/number-theory) ; API: https://docs.racket-lang.org/math/number-theory.html

(define (sum-divisible-numbers start finish k)
  (define (sum-number result n)
    (cond
      [(zero? n) result]
      [else (sum-number (+ result (remainder n 10)) (quotient n 10))]))
  (define (helper current end sum)
    (cond
      [(> current end) sum]
      [(divides? k (sum-number 0 current)) (helper (add1 current) end (+ sum current) )]
      [else (helper (add1 current) end sum)]
      ))
  (if (< start finish)
      (helper start finish 0)
      (helper finish start 0)))

(= (sum-divisible-numbers 0 10 5) 5)
(= (sum-divisible-numbers 0 100 5) 990)
(= (sum-divisible-numbers 100 0 5) 990)

(= (sum-divisible-numbers 0 15 3) 45) ; my test
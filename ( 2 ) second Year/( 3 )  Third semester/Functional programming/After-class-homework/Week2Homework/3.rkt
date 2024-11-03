#lang racket
(require math/number-theory) ; API: https://docs.racket-lang.org/math/number-theory.html

(define (sum-prime-divs-rec n)
  (define (helper current)
    (cond
      [(zero? current) 0]
      [(and (prime? current) (zero? (remainder n current))) (+ current (helper (sub1 current)))]
      [else (helper (sub1 current))]))
  (helper n))

(= (sum-prime-divs-rec 0) 0)
(= (sum-prime-divs-rec 6) 5) ; 2 + 3
(= (sum-prime-divs-rec 18) 5) ; 2 + 3
(= (sum-prime-divs-rec 19) 19)
(= (sum-prime-divs-rec 45136) 53) ; my test

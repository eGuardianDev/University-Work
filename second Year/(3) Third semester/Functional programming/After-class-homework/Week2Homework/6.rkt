#lang racket

(require math/number-theory) ; API: https://docs.racket-lang.org/math/number-theory.html

(define (contains-digit? leftover d )
  (cond
    [(= (remainder leftover 10) d) #t]
    [(not(zero? leftover)) (contains-digit? (quotient leftover 10) d )]
    [else #f]))

(define (sum-special-primes n d)
  (define (helper current count)
    (cond
      [(= count n) 0 ] 
      [(and (prime? current) (contains-digit? current d )) 
        (+ current (helper (add1 current) (add1 count))) ]
      [else (helper (add1 current) count)]))
  (helper 0 0))

(= (sum-special-primes 5 2) 392)
(= (sum-special-primes 5 3) 107)
(= (sum-special-primes 10 3) 462)
(= (sum-special-primes 10 4) 2446) ; my test

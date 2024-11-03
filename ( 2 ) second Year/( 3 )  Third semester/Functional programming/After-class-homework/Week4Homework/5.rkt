#lang racket
(require math/number-theory) ; API: https://docs.racket-lang.org/math/number-theory.html

(define (biggest-prime-divisor x)
  (define (helper currentNumber)
    (if (and (divides? currentNumber x) (prime? currentNumber) )
        currentNumber
        (helper (sub1 currentNumber))))
  (helper x))


(define (factorize x)
  (define (helper ys leftover)
    (if (>= 1 leftover)
        ys
      (helper (append (list(biggest-prime-divisor leftover)) ys) (quotient leftover (biggest-prime-divisor leftover)))))
  (cond
      [(not(integer? x))  (error "not an natural number")]
      [(< x 2) (error "Need a value greater than 2")]
      [else (helper `() x)]))

(equal? (factorize 2) '(2))
(equal? (factorize 6) '(2 3))
(equal? (factorize 13) '(13))
(equal? (factorize 123) '(3 41))
(equal? (factorize 152) '(2 2 2 19))
(equal? (factorize 12356498) '(2 7 11 19 41 103))

(equal? (factorize 234) '(2 3 3 13)) ; my test
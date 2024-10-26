#lang racket

(require math/number-theory) ; API: https://docs.racket-lang.org/math/number-theory.html

(define (sum-digits n)
  (cond
    [(zero? n) 0]
    [else (+ (remainder n 10) (sum-digits (quotient n 10) ))]))

(define (interesting? n)
  (divides? (sum-digits  n) n))

(equal? (interesting? 410) #t)
(equal? (interesting? 212) #f)
(equal? (interesting? 567) #f)
(equal? (interesting? 70) #t)
(equal? (interesting? 5) #t)
(equal? (interesting? 4) #t)

(equal? (interesting? 2350) #t); my test


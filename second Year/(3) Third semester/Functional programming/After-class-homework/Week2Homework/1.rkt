#lang racket

(define (count-digits-iter x)
  (define (helper count leftover)
     (if (zero? leftover)
         count
         (helper (add1 count) (quotient leftover 10))))
  (if (< x 0) (error "Input cannot be negative") (helper 0 x))) ; validation is in another if

(define (count-digits-rec x)
 (define (helper k)
 (if (zero? k)
     0
     (add1 (count-digits-rec (quotient k 10)))))
  (if (< x 0) (error "Input cannot be negative") (helper x)))

(= (count-digits-iter 12345) 5)
(= (count-digits-iter 123) 3)
(= (count-digits-iter 1234567) 7); my test

(= (count-digits-rec 12345) 5)
(= (count-digits-rec 123) 3)
(= (count-digits-rec 1234567) 7); my test

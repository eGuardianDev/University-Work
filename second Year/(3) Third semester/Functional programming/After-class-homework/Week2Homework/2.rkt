#lang racket

;; validate pls

(define (sum-digits-iter n)
  (define (helper sum leftover)
    (if (< leftover 10)
        (+ sum leftover )
        (helper (+ sum (remainder leftover 10)) (quotient leftover 10))))
  (if (< n 0) (error "Input cannot be negative") (helper 0 n)))

(= (sum-digits-iter 12345) 15)
(= (sum-digits-iter 123) 6)
(= (sum-digits-iter 432) 9) ; my test
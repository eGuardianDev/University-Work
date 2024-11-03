#lang racket


(define (num-to-xs n)
  (define (helper result leftover)
    (if (zero? leftover)
        result
        (helper (cons (remainder leftover 10) result) (quotient leftover 10))))
  (helper `() n))

(define (xs-to-num xs)
  (foldl (λ (x acc) (+ (* acc 10)  x)) 0 xs))

(define (sort-n xs)
  (xs-to-num (sort (num-to-xs xs) >)))

(= (sort-n 1714) 7411)
(= (sort-n 123450) 543210)
(= (sort-n 123405) 543210)
(= (sort-n 123045) 543210)
(= (sort-n 120345) 543210)
(= (sort-n 102345) 543210)
(= (sort-n 8910) 9810)
(= (sort-n 321) 321)
(= (sort-n 29210) 92210)
(= (sort-n 1230) 3210)
(= (sort-n 55345) 55543)
(= (sort-n 14752) 75421)
(= (sort-n 329450) 954320)
(= (sort-n 9125) 9521)
(= (sort-n 1234) 4321) ; my test
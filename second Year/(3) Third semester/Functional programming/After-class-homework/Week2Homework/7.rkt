#lang racket


(define (count-occurrences n x)
  (define (helper leftover)
    (cond
      [(< leftover 10) (if (= leftover x) 1 0 )]
      [(= x (remainder leftover 10)) (add1 (helper(quotient leftover 10)))]
      [else (helper (quotient leftover 10)) ]))
  (helper n))

(= (count-occurrences 121 1) 2)
(= (count-occurrences 222 1) 0)
(= (count-occurrences 100 0) 2)
(= (count-occurrences 0 0) 1)
(= (count-occurrences 1233 3) 2) ; my test
#lang racket


(define (remove-first-occurrence n x)
  (define (helper current leftover step)
    (cond
      [(zero? current) leftover]
      [(= x (remainder current 10)) (+ (* (quotient current 10) (expt 10 step) ) leftover )]
      [else (helper (quotient current 10) ( + (* (remainder current 10) (expt 10 step) ) leftover) (add1 step))]
     )
  )
  (helper n 0 0))

(= (remove-first-occurrence 15365 5) 1536)
(= (remove-first-occurrence 15360 0) 1536)
(= (remove-first-occurrence 15300 0) 1530)
(= (remove-first-occurrence 15365 1) 5365)
(= (remove-first-occurrence 35365 3) 3565)
(= (remove-first-occurrence 1212 1) 122)
(= (remove-first-occurrence 1212 2) 121)
(= (remove-first-occurrence (remove-first-occurrence 1212 1) 1) 22)


(= (remove-first-occurrence 15234 2) 1534) ; my test
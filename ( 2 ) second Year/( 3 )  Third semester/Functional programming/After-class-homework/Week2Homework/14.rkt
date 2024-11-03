#lang racket

(define (sum-numbers start finish)
  (define (decreasing? a)
    (define (holder current)
      (cond
        [(< current 10) #t ]
        [(<= (remainder current 10) (remainder (quotient current 10) 10)) 
          (holder (quotient current 10))]
        [else #f]))
    (holder a))
  (define (helper current end)
    (cond
      [(> current end) 0]
      [(decreasing? current) (+ current (helper (add1 current) end))]
      [else (helper (add1 current) end)]))
  (if (> start finish)
      (helper finish start)
      (helper start finish)))
   
(= (sum-numbers 1 9) 45)
(= (sum-numbers 199 203) 200)
(= (sum-numbers 219 225) 663)
(= (sum-numbers 225 219) 663)
(= (sum-numbers 150 250) 1284) ; my test

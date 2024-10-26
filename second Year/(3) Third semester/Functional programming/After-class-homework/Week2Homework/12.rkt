#lang racket

(define (find-sum a b n)
  (define (calculate current count sum )
    (cond
      [(= count n) sum ]
      [(> count (- n 4)) 
        (calculate (+ current (* (expt 2 count) b)) (add1 count) (+ sum  (+ current (* (expt 2 count) b))))]
      [else (calculate (+ current (*(expt 2 count) b)) (add1 count) 0)]))
  (calculate a 0 0 ))

(= (find-sum 0 2 10) 3578) ; 510 + 1022 + 2046
(= (find-sum 5 3 5) 174) ; 26 + 50 + 98

(= (find-sum 6 2 3) 40) ; my test
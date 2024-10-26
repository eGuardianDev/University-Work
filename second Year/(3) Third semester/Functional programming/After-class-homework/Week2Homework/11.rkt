#lang racket
(require math/number-theory) ; API: https://docs.racket-lang.org/math/number-theory.html

(define (nth-cubic n )
  (define (formula x y)
    (/(- (expt x 3) (expt y 3))(- x y)))
  (define (helper count current selected)
    (cond
      [(= count n) selected]
      [(prime? (formula (add1 current) current)) 
        (helper (add1 count) (add1 current) (formula (add1 current) current))]
      [else (helper count (add1 current) selected)]))
  (if (< n 1)
      (error "Need value >=1")
      (helper 0 0 0)))



(= (nth-cubic 1) 7)
(= (nth-cubic 4) 61) ; 61 is the 4th cubic prime number
(= (nth-cubic 50) 55897) ; 55897 is the 50th cubic prime number
(= (nth-cubic 100) 283669)
(= (nth-cubic 200) 1570357)

(= (nth-cubic 23) 5419) ; my test
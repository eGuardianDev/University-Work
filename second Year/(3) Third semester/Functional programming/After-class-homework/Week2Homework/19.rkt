#lang racket


(define (calc-series-sum x n)
  (define (doubleFac n)
    (if (<= n 0)
        1
        (* n (doubleFac (- n 2)))))
  (define (helper result v)
  (if (< v 0)
      result
      (helper (+ result ( /(*(expt -2 (add1 v)) (expt x v)) (doubleFac (add1 (* v 2))) )) (sub1 v))))
  (helper 0 n)
  )
(calc-series-sum 1 0) ; -2
(calc-series-sum 1 1) ; -2/3
(calc-series-sum 1 2) ; -1 1/5
(calc-series-sum 1 3) ; -1 1/21
(calc-series-sum 1 4) ; -1 11/135
(calc-series-sum 1 5) ; -1 29/385
(calc-series-sum 1 6) ; -1 937/12285

(calc-series-sum 1 7) ; -1 11873/155925 ; my test
#lang racket


(define (calculate-sum x n)
  (if (zero? n)
      1
      (+ (expt x n) (calculate-sum x (sub1 n)))))


(= (calculate-sum 5 0) 1)
(= (calculate-sum 5 1) 6)
(= (calculate-sum 10 1) 11)
(= (calculate-sum 1 11) 12)
(= (calculate-sum 2 11) 4095)
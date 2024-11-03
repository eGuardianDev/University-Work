#lang racket

;; 1 4 7 10 13
(define (p n)
  (define (helper current toAdd sum)
    (cond
      [(> current n) sum]
      [else (helper (add1 current) (+ toAdd 3) (+ sum toAdd))]))
  (helper 1 1 0))


(= (p 1) 1)
(= (p 2) 5)
(= (p 3) 12)
(= (p 4) 22)
(= (p 5) 35)
(= (p 6) 51)
(= (p 7) 70); my test
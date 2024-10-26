#lang racket


(define (accumulate-rec f unUsed-Acc start end change next) ; acc isn't in use. But its a variable in the test
  (if (equal? start end)
      (change start)
      (f (change start) (accumulate-rec f unUsed-Acc (next start) end change next))))


; 1 + 2 + 3 + ... + 100
(= (accumulate-rec + 0 1 100 identity add1) 5050)

; 1 - (2 - (3 - (4 - 5)))
(= (accumulate-rec - 0 1 5 identity add1) 3)

; 1 * 2 * 3 * ... * 10
(= (accumulate-rec * 1 1 10 identity add1) 3628800)

; 1 * 3 * 5 * ... * 10
(= (accumulate-rec * 1 1 15 identity (curry + 2)) 2027025)

; 1^2 + 3^2 + 5^2 + ... + 100^2
(= (accumulate-rec + 0 1 100 (λ (x) (expt x 2)) add1) 338350)


(= (accumulate-rec + 0 1 25 (λ (x) (expt x 4)) add1) 2153645); my test
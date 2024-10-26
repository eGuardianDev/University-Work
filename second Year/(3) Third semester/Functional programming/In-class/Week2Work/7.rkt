#lang racket



(define (find-max n)
  (define (helper leftover max-number)
    (cond
      [(zero? leftover) max-number ]
      [(<= (remainder leftover 10) max-number) (helper (quotient leftover 10) max-number) ]
      [else (helper (quotient leftover 10) ( remainder leftover 10))]))
  (helper n 0)
)





(= (find-max 55345) 5)
(= (find-max 14752) 7)
(= (find-max 329450) 9)
(= (find-max 9521) 9)
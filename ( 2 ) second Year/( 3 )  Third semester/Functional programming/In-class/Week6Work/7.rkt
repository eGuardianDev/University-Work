#lang racket


(define (next x y border)
  (if (>= (add1 x) (sub1 border))
      (cons 1 (add1 y) )
      (cons (add1 x)  y)))

(define (g-l-sum input)
  (define (helper x y)
   (cond
     [(equal? (+ (gcd x y) (lcm x y)) input )
       (cons x y)]
       [else (let ([temp (next x y input)]) (helper (car temp) (cdr temp)))]))
  (helper 1 1)
  )


(g-l-sum 2) ; → '(1 . 1)
(g-l-sum 14) ; → '(6 . 4)


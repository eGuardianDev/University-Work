#lang racket


(define (higher-composed-eval f g)
  (λ (x y) (g (f x) (f y)))
)


(= ((higher-composed-eval (λ (x) (* x 2)) +) 5 8) 26)
(= ((higher-composed-eval (curry expt 10) remainder) 42.69 6) 536832)
#lang racket

(define (derive f h)
  (λ (a)
    (/ (- (f (+ a h)) (f a)) h)))


(= ((derive (λ (x) (* 2 x x x)) 1e-3) 2) 24.0120019999992)
(= ((derive (λ (x) (* 2 x x x)) 1e-6) 2) 24.000012004421478)
  
(= ((derive (λ (x) (* 2 x x x)) 1e-9) 2) 24.000001985768904) ; my test
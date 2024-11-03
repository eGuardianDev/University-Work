#lang racket


(define (apply-n f n)
  (λ (x)
    (if (equal? 1 n)
        (f x)
        (f ((apply-n f (sub1 n))x)))))


(= ((apply-n (λ (x) (* 2 x)) 5) 2) 64)
(= ((apply-n (λ (x) (quotient x 10)) 2) 100) 1)

(= ((apply-n (λ (x) (* x 10)) 4) 5) 50000) ; my test
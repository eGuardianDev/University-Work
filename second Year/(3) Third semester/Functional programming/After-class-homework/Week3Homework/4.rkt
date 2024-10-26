#lang racket

(define (derive-n f n h)
  (λ (a)
    (if (equal? 1 n)
        (/ (- (f (+ a h)) (f a)) h)
        (/ (- ( (derive-n f (sub1 n) h) (+ a h)) ((derive-n f (sub1 n) h) a))h))))

(= ((derive-n (λ (x) (* 2 x x x)) 3 1e-3) 2) 12.000015203739167)
(= ((derive-n (λ (x) (* 2 x x x)) 4 1e-3) 3) 0.06394884621840902) ; my test
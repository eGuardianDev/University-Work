#lang racket


(define (derive-x f h)
  (λ (x y)
    (/ (- (f (+ x h) y) (f x y)) h)))

(define (derive-y f h)
  (λ (x y)
    (/ (- (f x (+ y h)) (f x y)) h)))


(define (g x y) (+ (* x x x) (* x y) (* y y)))
(= ((derive-x g 0.0001) 2 3) 15.000600010033338)
(= ((derive-y g 0.0001) 2 3) 8.00009999998963)

(= ((derive-x g 0.0001) 5 3) 78.00150001003203) ; my test
(= ((derive-y g 0.0001) 5 3) 11.000099999876056) ; my test
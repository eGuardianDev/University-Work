#lang racket

(define (my-reverse-foldl xs)
  (foldl cons `() xs))


(equal? (my-reverse-foldl '(1 2 3 4 5)) '(5 4 3 2 1))
(equal? (my-reverse-foldl '(11 2 3 8 5)) '(5 8 3 2 11))
(equal? (my-reverse-foldl '(1 2 3)) '(3 2 1)) ; my test
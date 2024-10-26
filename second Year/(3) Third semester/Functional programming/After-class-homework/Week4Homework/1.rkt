#lang racket

(define (remove-all-no-proc x xs)
  (define (helper ys leftover)
    (cond
      [(empty? leftover) ys]
      [(equal? x (car leftover)) (helper ys (cdr leftover))]
      [else (helper (append ys (list (car leftover))) (cdr leftover))]))
  (helper `() xs))

(define (remove-all-proc x xs)
  (remove* (list x) xs))


; without using a predefined procedure
(equal? (remove-all-no-proc 1 '(1 1 1 2)) '(2))
(equal? (remove-all-no-proc 1 '(2 5 6)) '(2 5 6))
(equal? (remove-all-no-proc 1 '(1)) '())
(equal? (remove-all-no-proc 1 '(1 2 1 1)) '(2))
(equal? (remove-all-no-proc "RNN" '("CNN" "RNN" "GAN" "RNN")) '("CNN" "GAN"))
(equal? (remove-all-no-proc "cat" '("dog" "cat" "rat" "cat")) '("dog" "rat")) ; my test

; using a predefined procedure
(equal? (remove-all-proc 1 '(1 1 1 2)) '(2))
(equal? (remove-all-proc 1 '(2 5 6)) '(2 5 6))
(equal? (remove-all-proc 1 '(1)) '())
(equal? (remove-all-proc 1 '(1 2 1 1)) '(2))
(equal? (remove-all-proc "RNN" '("CNN" "RNN" "GAN" "RNN")) '("CNN" "GAN"))
(equal? (remove-all-proc "cat" '("dog" "cat" "rat" "cat")) '("dog" "rat")) ; my test
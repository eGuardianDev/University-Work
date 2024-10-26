#lang racket



(define (remove-first-proc x xs)
  (define (helper result ys)
    (cond
      [(empty? ys) result]
      [(equal? x (car ys)) (append result (cdr ys))]
      [else (helper (append result (list (car ys))) (cdr ys))]
      )
    )
  (helper `() xs)
  )

(define (remove-first-no-proc x xs)
  (remove x xs))

; using a predefined procedure
(equal? (remove-first-proc 1 '(1 1 1 2)) '(1 1 2))
(equal? (remove-first-proc 1 '(2 5 6)) '(2 5 6))
(equal? (remove-first-proc 1 '(1)) '())
(equal? (remove-first-proc 1 '(2 1)) '(2))
(equal? (remove-first-proc "RNN" '("CNN" "RNN" "GAN" "RNN")) '("CNN" "GAN" "RNN"))

; without using a predefined procedure
(equal? (remove-first-no-proc 1 '(1 1 1 2)) '(1 1 2))
(equal? (remove-first-no-proc 1 '(2 5 6)) '(2 5 6))
(equal? (remove-first-no-proc 1 '(1)) '())
(equal? (remove-first-no-proc 1 '(2 1)) '(2))
(equal? (remove-first-no-proc "RNN" '("CNN" "RNN" "GAN" "RNN")) '("CNN" "GAN" "RNN"))
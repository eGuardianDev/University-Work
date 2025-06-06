#lang racket

(define (ordered xs)
  (λ (predicate)
    (define (helper leftover)
      (cond
        [(empty? (cdr leftover)) #t]
        [(predicate (car leftover) (car (cdr leftover))) (helper (cdr leftover))]
        [else #f]))
    (helper xs)
    ))

(define (ordered-no-expl-booleans xs)
  (λ (predicate)
    ((ordered xs) predicate))
  )

; with freedom to solve however you like it
(equal? ((ordered '(1 2 3 5)) (λ (x y) (< x y))) #t)
(equal? ((ordered '(1 8 29 92)) (λ (x y) (= y (+ (* x 3) 5)))) #t)
(equal? ((ordered '(1 8 3 14)) (λ (x y) (= y (+ (* x 3) 5)))) #f)

; using a linearly recursive process without returning explicitly #t and/or #f
(equal? ((ordered-no-expl-booleans '(1 2 3 5)) (λ (x y) (< x y))) #t)
(equal? ((ordered-no-expl-booleans '(1 8 29 92)) (λ (x y) (= y (+ (* x 3) 5)))) #t)
(equal? ((ordered-no-expl-booleans '(1 8 3 14)) (λ (x y) (= y (+ (* x 3) 5)))) #f)
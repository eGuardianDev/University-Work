#lang racket


(define (run-for-all p?s element)
  (cond
    [(empty? p?s) #t]
    [(not((car p?s) element)) #f]
    [else (run-for-all (cdr p?s) element)]))

(define (where xs p?s)
  (cond
    [(empty? xs) `()]
    [(run-for-all p?s (car xs)) (cons (car xs) (where (cdr xs) p?s))]
    [else (where (cdr xs) p?s)]))



(equal? (where '(3 4 5 6 7 8 9 10) (list even? (lambda (x) (> x 5)))) '(6 8 10)) ; all even numbers greater than 5
(equal? (where '(3 4 5 7) (list even? (lambda (x) (> x 5)))) '()) ; no numbers are even and greater than 5
(equal? (where '() (list odd? (λ (x) (> x 3)) (λ (x) (< x 20)))) '())
(equal? (where '(1 2 3 4 5 6 7 8 9 10 11 13 15) (list odd? (λ (x) (> x 3)) (λ (x) (< x 20)))) '(5 7 9 11 13 15))
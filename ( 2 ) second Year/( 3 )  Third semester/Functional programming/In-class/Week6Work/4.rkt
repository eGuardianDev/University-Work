#lang racket
#; ;don't do this
(define (list-contains-zero? xs)
  (cond
    [(null? xs) #f]
    [(zero? (car xs)) #t]
    [else (list-contains-zero? (cdr xs))]))
#;
(define (zero-rows xs)
  (cond
    [(null? xs) null]
    [(list-contains-zero? (car xs)) (cons (map (λ (x) 0) (car xs)) (zero-rows (cdr xs)))]
    [else  (cons (car xs) (zero-rows (cdr xs)))]))


(define (zero-rows xss)
  (map (λ (xs) (if (member 0 xs) (map (λ (x) 0) xs) xs)) xss)
  )

(equal? (zero-rows '((1 2 0) (3 4 1) (0 5 7) (4 2 4))) '((0 0 0) (3 4 1) (0 0 0) (4 2 4)))
(equal? (zero-rows '((2 1 2 4) (0 2 0 1) (4 4 1 4) (4 1 3 1))) '((2 1 2 4) (0 0 0 0) (4 4 1 4) (4 1 3 1)))
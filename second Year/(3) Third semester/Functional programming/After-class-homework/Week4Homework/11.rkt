#lang racket

(define (my-list-ref xs i)
  (define (helper current leftover)
    (if (equal? current i)
        (car leftover)
        (helper (add1 current) (cdr leftover))))
  (if (< i 0)
      (error "Invalid index!")
      (helper 0 xs)))
    
(= (my-list-ref '(1 2 3) 0) 1)
(= (my-list-ref '(1 2 3) 1) 2)
(= (my-list-ref '(1 2 3 5 1 2) 4) 1) ; my test
(equal? (my-list-ref '("Hello" 2 ("nested list")) 0) "Hello")
(my-list-ref '(1 2 3) -100) ; error: Invalid index!
#lang racket

(define (deep-delete xss)
  (define (helper xss dept)
    (cond
      [(null? xss) null]
      [(list? (car xss)) (cons (helper (car xss) (add1 dept)) (helper (cdr xss) dept))]
      [(> dept (car xss))   (helper (cdr xss) dept)]
      [else (cons (car xss) (helper (cdr xss) dept))]))
  (helper xss 1))

; can reach "1" by applying "car" one time and "2" can be reached with "caadr".
(equal? (deep-delete '(1 (2 (2 4) 1) 0 (3 (1)))) '(1 (2 (4)) (3 ())))
(equal? (deep-delete '(3 ((1)) 1 ((((3)) 2) 42) 3 (6) 1 0 (3 1 (((9))) 0))) '(3 (()) 1 (((())) 42) 3 (6) 1 (3 (((9))))))
#lang racket

#;
(define (graph-contains-points xs f)
    (cond
      [(null? xs) #t]
      [(equal? (cdar xs) (f (caar xs))) (graph-contains-points (cdr xs) f)]
      [else #f]
    )
)
(define (graph-contains-points xs f)
    (andmap (λ (x) (equal? (f (car x)) (cdr x))) xs))

(equal? (graph-contains-points '((1 . 2) (2 . 3) (3 . 4)) add1) #t)
(equal? (graph-contains-points '((1 . 2) (2 . 4) (3 . 4)) add1) #f)
(equal? (graph-contains-points '((1 . "11") (2 . "21") (3 . "31")) (λ (x) (string-append (number->string x) "1"))) #t)
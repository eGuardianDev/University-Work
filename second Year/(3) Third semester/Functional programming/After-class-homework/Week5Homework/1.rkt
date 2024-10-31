#lang racket

(define (longest-ascending-sub xs)
  (define (helper current-longest current-builded last-number leftover)
    (cond
      [(empty? leftover) current-longest]
      [(>= (car leftover) last-number)
       (let ([newlist (append current-builded (list (car leftover)))])
         (if (> (length newlist) (length current-longest))
             (helper newlist newlist (car leftover) (cdr leftover))
             (helper current-longest newlist (car leftover) (cdr leftover))))]
      [else (helper current-longest (list (car leftover)) (car leftover) (cdr leftover))]))
  (helper (list (car xs)) (list (car xs)) (car xs) (cdr xs)))

(equal? (longest-ascending-sub '(1 0 5)) '(0 5))
(equal? (longest-ascending-sub '(1 5 2 3 1 5 6 7 7 1 5)) '(1 5 6 7 7))
(equal? (longest-ascending-sub '(1 5 2 3 1 5 2 7 7 15)) '(2 7 7 15))
(equal? (longest-ascending-sub '(1 5 2 3 4 5 6 7 7 1 5)) '(2 3 4 5 6 7 7))
(equal? (longest-ascending-sub '(1 5 2 4 6 8 3 4 1)) '(2 4 6 8))
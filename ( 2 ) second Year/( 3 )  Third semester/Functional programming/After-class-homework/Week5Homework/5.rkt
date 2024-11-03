#lang racket

(define (right-max xs)
  (define (helper biggest result leftover)
    (if (empty? leftover)
        result
        (helper (max biggest (car leftover))
                (cons (max biggest (car leftover)) result)
                (cdr leftover))))
  (helper (car (reverse xs)) `() (reverse xs)))


(equal? (right-max '(1 2 3 4 -5 6 7 -2 -1 0)) '(7 7 7 7 7 7 7 0 0 0))
(equal? (right-max '(5 8 9 12)) '(12 12 12 12))
(equal? (right-max '(4 3 2 1 0)) '(4 3 2 1 0))
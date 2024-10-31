#lang racket


(define (count-occurrences occ xs)
  (cond
    [(> (length occ) (length xs)) 0]
    [(equal? occ (take xs 2)) (add1 (count-occurrences occ (cdr xs)))]
    [else (count-occurrences occ (cdr xs))]))


(= (count-occurrences '(6 6) '(2 2)) 0)
(= (count-occurrences '(1 5) '(1 5 2 3 1 5 6 7 7 1 5)) 3)
(= (count-occurrences '(5 5) '(5 5 5 3 1 5 6 7 5 5 5)) 4)
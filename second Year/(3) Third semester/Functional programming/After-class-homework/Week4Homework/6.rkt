#lang racket


(define (kth-max-min xs)
  (define new-list (filter (λ (x) (< x 0) ) (remove-duplicates (sort xs (λ (a b) (< a b))))))
  (λ (x)
    (cond
      [(<= x 0)(error "not a valid index")]
      [(< (length new-list) x) (error "no such number!")]
      [else (list-ref new-list (sub1 x))])))



(= ((kth-max-min '(-1)) 1) -1)
(= ((kth-max-min '(-1 -5 -6 -6 -6 -6)) 2) -5)
(= ((kth-max-min '(-1 -1 -5 -6 -6 -6 -6)) 2) -5)
(= ((kth-max-min '(1 2 3 4 -5 6 7 -2 -1 0)) 2) -2)
(= ((kth-max-min '(1 2 -5 -2 -10)) 2) -5) ; my test
((kth-max-min '(-1 0 -1 0 -2 3 1 -1)) 3) ; error: No such number!
#lang racket


(define (kth-number xs)
  (λ (p? index)
    (let ([new-list (filter p? xs)])
      (if (< (length new-list) index)
          (error "index doesn't exist")
          (list-ref (sort xs <) (sub1 index))))))


(equal? ((kth-number '(1 2 3 4 -5 6)) odd? 2) 1)
(equal? ((kth-number '(1 2 3 4 -5 6)) negative? 1) -5)
(equal? ((kth-number '(1 2 3 4 -5 -5 6)) negative? 2) -5)
(equal? ((kth-number '(1 -4 2 3 4 -5 -5 6)) negative? 3) -4)
((kth-number '(-1 0 -1 0 -2)) negative? 4)
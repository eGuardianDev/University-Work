#lang racket


(define (insert-at val pos xs)
  (define (helper index current-list leftover)
    (if (equal? pos index)
        (append current-list (list val) leftover)
        (helper (add1 index) (append current-list (list (car leftover))) (cdr leftover))))
  (if (or (< pos 0) (> pos (length xs)))
      (error "invalid position")
      (helper 0 `() xs)))


(equal? (insert-at 1 0 '()) '(1))
(equal? (insert-at 1 0 '(2)) '(1 2))
(equal? (insert-at 10 1 '(1 2 3)) '(1 10 2 3))
(equal? (insert-at 1 0 '()) '(1))
(equal? (insert-at 1 0 '(2)) '(1 2))
(equal? (insert-at 10 1 '(1 2 3)) '(1 10 2 3))
(equal? (insert-at 7 0 '(1 2 3)) '(7 1 2 3))
(equal? (insert-at 7 1 '(1 2 3)) '(1 7 2 3))
(equal? (insert-at 7 3 '(1 2 3)) '(1 2 3 7))
(equal? (insert-at 1 0 '(0 0 0)) `(1 0 0 0)) ; my test
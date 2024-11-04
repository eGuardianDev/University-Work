#lang racket
#| ; old version
(define (counter-bigger-than-element xs element)
  (cond
    [(empty? xs) 0]
    [(< element (car xs)) (add1 (counter-bigger-than-element (cdr xs) element))]
    [else  (counter-bigger-than-element (cdr xs) element)]))

(define (num-bigger-elements xs)
  (define (helper result leftover)
    (if (empty? leftover)
        (reverse result)
        (helper (cons (cons (car leftover)
                            (counter-bigger-than-element xs (car leftover)))
                      result)
                (cdr leftover))))
  (helper `() xs))
|#

; new version
(define (num-bigger-elements xs)
  (map (λ (x) (cons x (length(filter (λ (y) (> y x)) xs)))) xs))

(equal? (num-bigger-elements '(5 6 3 4)) '((5 . 1) (6 . 0) (3 . 3) (4 . 2)))
(equal? (num-bigger-elements '(1 1 1)) '((1 . 0) (1 . 0) (1 . 0)))
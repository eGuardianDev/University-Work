#lang racket

(define (rev-fold xs)
  (foldr (λ (x acc) (+ (* acc 10)x)) 0 xs))

; second version (no reverse)
(define (rev-lin-iter xs)
  (define (helper step acc leftover)
    (if (empty? leftover)
        acc
        (helper (* step 10) (+ acc (* (car leftover) step) ) (cdr leftover))))
  (helper 1 0  xs))

; using folding
(= (rev-fold '(1 2 3)) 321)
(= (rev-fold '(1 2 3 4 5 6 7 8 9)) 987654321)
(= (rev-fold '(1 3 5)) 531) ; my test

; using a linearly iterative procedure
(= (rev-lin-iter '(1 2 3)) 321)
(= (rev-lin-iter '(1 2 3 4 5 6 7 8 9)) 987654321)
(= (rev-lin-iter '(1 3 5)) 531) ; my test
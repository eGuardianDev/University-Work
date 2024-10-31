#lang racket


(define (get-fib n)
  (define (helper a b m)
    (if (zero? m)
        a
        (helper b (+ a b) (sub1 m))))
  (helper 0 1 n))
(define (group-digits n)
  (define (helper xs leftover)
    (if (zero? leftover)
        xs
        (helper (cons  (remainder leftover 10) xs)
                (quotient leftover 10))))
  (helper `() n))

(define (how-often-sorted xs)
  (define (helper result leftover last count)
    (cond
      [(empty? leftover) (append result (list (cons last count)))]
      [(< last (car leftover)) (helper (append result (list (cons last count)))
                                       (cdr leftover) (car leftover) 1)]
      [else (helper result
                    (cdr leftover)
                    last (add1 count))]))
  (helper `() (sort xs <) (car (sort xs <)) 0))

(define (get-smallest-most-common-digit n)
  (car (sort (how-often-sorted  n) (λ (a b) (> (cdr a) (cdr b))))))


(define (around-fib n)
  (λ (k)
    (define (helper leftover result)
      (if (empty? leftover)
          result
          (helper (drop leftover (min k (length leftover)))
                  (append result (list (get-smallest-most-common-digit
                                        (take leftover (min k (length leftover))))) ))))
    (helper (group-digits (get-fib n)) `()) )
  )
  
(equal? ((around-fib 100) 25) '((1 . 3)))
(equal? ((around-fib 180) 25) '((1 . 5) (7 . 3)))
(equal? ((around-fib 1700) 25) '((1 . 4) (2 . 5) (0 . 6) (4 . 5) (5 . 7) (2 . 4) (6 . 7) (3 . 5) (0 . 4) (8 . 5) (4 . 5) (4 . 4) (7 . 7) (7 . 6) (2 . 2)))
(equal? ((around-fib 500) 42)'((0 . 6) (2 . 7) (2 . 6)))
(equal? ((around-fib 6000) 242) '((5 . 31) (8 . 33) (8 . 31) (7 . 35) (7 . 31) (4 . 7)))
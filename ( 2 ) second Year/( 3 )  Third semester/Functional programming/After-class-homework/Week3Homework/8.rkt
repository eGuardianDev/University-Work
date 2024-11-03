#lang racket

(require math/number-theory) ; API: https://docs.racket-lang.org/math/number-theory.html

(define (accumulate f acc start end change next)
  (if (> start end)
      acc
     (accumulate f (f (change start) acc) (next start) end change next)))
(define (any? start finish p?)
  (accumulate (λ (a acc) (or a acc)) #f start finish p? add1))

(define (cubed-interval-till n)
  (accumulate + 0 2 n (λ (x) (expt x 3)) (λ (x) (+ x 3))))

(define (fact-accum n)
  (accumulate * 1 1 n identity add1))
  
(define (prime-accum? n)
  (if (equal? n 1)
      #f
      (accumulate (λ (a acc) (and a acc)) #t 2 (sub1 n) (λ (x) (not (divides? x n))) add1)))


(equal? (any? 1001 1500 (λ (x) (< x 1000))) #f)
(equal? (any? 1 100 odd?) #t)
(equal? (any? 5 50 even?) #t) ; my test

(= (cubed-interval-till 11) 1976)
(= (cubed-interval-till 15) 4720)
(= (cubed-interval-till 3) 8) ; my test 

(= (fact-accum 5) 120)
(= (fact-accum 8) 40320)
(= (fact-accum 4) 24) ; my test

(equal? (prime-accum? 1) #f)
(equal? (prime-accum? 2) #t)
(equal? (prime-accum? 3) #t)
(equal? (prime-accum? 6) #f)
(equal? (prime-accum? 42) #f)
(equal? (prime-accum? 61) #t)
(equal? (prime-accum? 11) #t) ; my test
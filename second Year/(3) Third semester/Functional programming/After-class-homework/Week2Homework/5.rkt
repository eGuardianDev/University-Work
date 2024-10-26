#lang racket
(require math/number-theory) ; API: https://docs.racket-lang.org/math/number-theory.html
(define (sum-of-devisions n)
  (define (helper current)
    (cond
      [(= current (sub1 n )) 0]
      [(divides? current n) (+ current ( helper (add1 current)))]
        [(helper (add1 current))]))
  (helper 0))

(define (amicable? x y)
  (and (= (sum-of-devisions x) y) (= x (sum-of-devisions y))))

(equal? (amicable? 200 300) #f)
(equal? (amicable? 220 284) #t)
(equal? (amicable? 284 220) #t)
(equal? (amicable? 1184 1210) #t)
(equal? (amicable? 2620 2924) #t)
(equal? (amicable? 6232 6368) #t)
(equal? (amicable? 13 12) #f) ; my test
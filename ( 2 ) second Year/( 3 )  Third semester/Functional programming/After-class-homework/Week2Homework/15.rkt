#lang racket

(define (sub-num? x y)
  (define (checker leftover current)
    (cond
      [(zero? current) #t]
      [(= (remainder leftover 10) (remainder current 10)) 
        (checker (quotient leftover 10) (quotient current 10))]
      [else #f]))
  (define (try-on leftover)
    (cond
      [(checker leftover x) #t]
      [(zero? leftover) #f]
      [else (try-on (quotient leftover 10))]))
  (try-on y))

(equal? (sub-num? 123 5123783) #t)
(equal? (sub-num? 0 0) #t)
(equal? (sub-num? 10 101) #t)
(equal? (sub-num? 101 101) #t)
(equal? (sub-num? 10 0) #f)
(equal? (sub-num? 1253 5123783) #f)
(equal? (sub-num? 12 0) #f)

(equal? (sub-num? 4567 57) #f) ; my test
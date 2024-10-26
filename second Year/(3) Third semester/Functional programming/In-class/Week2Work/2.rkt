#lang racket

(require math/number-theory)

(define (num-prime? x)
  
  (define (helper current)
    (cond
        [(= 1 current) #t]
        ;[(zero? (remainder x current)) #f]
        [(divides? current x) #f]
        [else (helper (sub1 current))]))

    (if (< x 2)
        (error "n must be >= 2")
        (helper (sub1 x)))
)  
 


;(equal? (num-prime? 1) #f)
(equal? (num-prime? 2) #t)
(equal? (num-prime? 3) #t)
(equal? (num-prime? 6) #f)
(equal? (num-prime? 42) #f)
(equal? (num-prime? 61) #t)
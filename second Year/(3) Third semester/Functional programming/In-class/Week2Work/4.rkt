#lang racket

(require math/number-theory) ; API: https://docs.racket-lang.org/math/number-theory.html

(define (perfect? n)
  (and (> n 0) (= n (-(divisor-sum n) n))))

(equal? (perfect? 6) #t)
(equal? (perfect? 33550336) #t)
(equal? (perfect? 495) #f)
(equal? (perfect? 1) #f)
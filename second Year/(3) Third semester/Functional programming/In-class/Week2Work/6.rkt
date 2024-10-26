#lang racket

(define (num-len n)
  (if (< n 10)
      1
      (add1 (num-len (quotient n 10)))))


(define (narcissistic? n)
  (define (helper leftover sum)
    (cond
      [(zero? leftover) (= sum n)]
      [else (helper (quotient leftover 10) (+ sum (expt(remainder leftover 10 ) (num-len n) )))]))
  (helper n 0))


(equal? (narcissistic? 7) #t)
(equal? (narcissistic? 12) #f)
(equal? (narcissistic? 153) #t)
(equal? (narcissistic? 370) #t)
(equal? (narcissistic? 371) #t)
(equal? (narcissistic? 1634) #t)
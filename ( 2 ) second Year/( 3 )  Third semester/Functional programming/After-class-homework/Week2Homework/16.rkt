#lang racket

(define (digital-root n)
  (define (helper k)
    (cond
      [(zero? k) 0]
      [else (+ (remainder k 10) (helper (quotient k 10)))]))
  (define (check p)
    (if (< (helper p) 10)
        (helper p)
        (check (helper p))))
  (check n))

(= (digital-root 16) 7)
; => 1 + 6
; => 7
(= (digital-root 942) 6)
; => 9 + 4 + 2
; => 15
; => 1 + 5
; => 6
(= (digital-root 132189) 6)
(= (digital-root 493193) 2)
(= (digital-root 1234123) 7)

(= (digital-root 4322 ) 2) ; my test
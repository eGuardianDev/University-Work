#lang racket



(define (sum-digits-rec x)
  (define (helper n remember)
    (if (zero? n) 0
        (+ (helper (quotient n 10) (remainder n 10)) (remainder n 10)))

  )
  (helper x 0)
)

(= (sum-digits-rec 123) 6)
(= (sum-digits-rec 12345) 15)

;this does't require my own test in acceptance criteria, but
(= (sum-digits-rec 945) 18) ;my test
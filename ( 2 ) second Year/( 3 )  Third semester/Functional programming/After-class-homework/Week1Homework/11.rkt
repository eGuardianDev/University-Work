#lang racket

; code from exercise 10
(define (palindrome? x )
   (define (rev x)
     (define (helper current-number saved step max-steps)
       
          (if (zero? current-number) saved
              (helper (quotient current-number 10) (+ saved(* (remainder current-number 10) (expt 10 (- max-steps step)))) (add1 step) max-steps)

          )
         )
 (define (max-steps-cal number steps)
    (if (zero? number) steps
        (max-steps-cal (quotient number 10) (add1 steps))))
  
  (if (< x 0 ) (error "Cannot use negative number")
       (helper x 0 0 (sub1(max-steps-cal x 0)))
     

  )
)
 (= x ( rev x))
)



(equal? (palindrome? 1) #t)
(equal? (palindrome? 6) #t)
(equal? (palindrome? 1010) #f)
(equal? (palindrome? 505) #t)
(equal? (palindrome? 123321) #t)
(equal? (palindrome? 654) #f)
(equal? (palindrome? 121) #t)
(equal? (palindrome? 12) #f)
(equal? (palindrome? 120) #f)
(equal? (palindrome? 12321) #t)
(equal? (palindrome? 1221) #t)

;this does't require my own test in acceptance criteria, but
(equal? (palindrome? 01233210) #f) ; my test

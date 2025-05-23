#lang racket

; this implementation is not linear, but iterative
; this is the old version
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



(= (rev 1) 1)
(= (rev 123) 321)
(= (rev 987654321) 123456789)

(= (rev 0124) 421) ; my test
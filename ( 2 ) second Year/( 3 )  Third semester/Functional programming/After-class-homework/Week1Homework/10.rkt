#lang racket


(define (rev x)

  (define (helper input output)
      (if (zero?  input ) output
          (helper (quotient input 10) (*(+ output (remainder input 10))10))
     )
    )

    (if (< x 0 ) (error "Cannot use negative number")
       (/ (helper x 0 ) 10)
     

  )
)

(= (rev 1) 1)
(= (rev 123) 321)
(= (rev 987654321) 123456789)

(= (rev 0124) 421) ; my test
#lang racket


(define (can-carry? c k w)

  (define (helper c1 k1 w1)
    (cond
    [(< k1 0) #f]
    [(zero? c1) #t]
    [else (helper (sub1 c1) (- k1 w1) w1)]
    )
  )

  (cond
    [(< c 1) (error "invalid carrying capacity")]
    [(< k 0) (error "invalid kilogram carrying capacity")]
    [(< w 0) (error "invalid product kilograms")]
    [else (helper c k w)]
    )  
)



(equal? (can-carry? 5 15 3) #t)
(equal? (can-carry? 1 5 4) #t)
(equal? (can-carry? 13 25 2) #f)
(equal? (can-carry? 24 104.44 21.12) #f)
(equal? (can-carry? 51 34.75 19.852) #f)
(equal? (can-carry? 42 95.11 0.51) #t)

(equal? (can-carry? 50 150 3) #t) ; my test
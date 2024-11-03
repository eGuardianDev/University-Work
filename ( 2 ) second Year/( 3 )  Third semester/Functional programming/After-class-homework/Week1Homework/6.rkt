#lang racket


(define (leap-year-one-line? x )
   (or (=(remainder x 400) 0) ( and (= (remainder x 4) 0 ) (not(= (remainder x 100) 0)))) 
)

(define (leap-year-guards? x)
  (cond
    [(= (remainder x 400) 0) #t]
    [(= (remainder x 100) 0) #f]
    [(= (remainder x 4) 0) #t]
    [else #f]

    )
)


(equal? (leap-year-one-line? 2020) #t)
(equal? (leap-year-one-line? 1988) #t)
(equal? (leap-year-one-line? 1600) #t)
(equal? (leap-year-one-line? 2400) #t)
(equal? (leap-year-one-line? 2023) #f)
(equal? (leap-year-one-line? 1700) #f)
(equal? (leap-year-one-line? 1800) #f)
(equal? (leap-year-one-line? 2100) #f)

(equal? (leap-year-one-line? 2431) #f) ; my test



(equal? (leap-year-guards? 2020) #t)
(equal? (leap-year-guards? 1988) #t)
(equal? (leap-year-guards? 1600) #t)
(equal? (leap-year-guards? 2400) #t)
(equal? (leap-year-guards? 2023) #f)
(equal? (leap-year-guards? 1700) #f)
(equal? (leap-year-guards? 1800) #f)
(equal? (leap-year-guards? 2100) #f)


(equal? (leap-year-guards? 2431) #f) ; my test
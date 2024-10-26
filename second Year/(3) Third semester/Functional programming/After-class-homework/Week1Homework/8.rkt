#lang racket

(define (growing-plant up-speed down-speed desired-height)
  (define (helper up down desired count height)
    
     (if (>= (+ height up) desired) count
         (helper up down desired (add1 count) (- (+ height up) down))
      )
  
       
  )
    (helper up-speed down-speed desired-height 1 0)
)


(= (growing-plant 5 2 5) 1)
(= (growing-plant 5 2 6) 2)
(= (growing-plant 10 9 4) 1)
(= (growing-plant 100 10 910) 10) ; up-speed=100, down-speed=10, desired-height=910

(= (growing-plant 10 3 19) 3) ; my test
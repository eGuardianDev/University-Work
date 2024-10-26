#lang racket


(define (snail column-height snail-crawls snail-slides)
  
  ( define (helper height crawls slides count-days current-pos)
     
     (if (>= (+ current-pos crawls) height)
         count-days
         (helper height crawls slides (add1 count-days) (- (+ current-pos crawls) slides))

         )

   )
  (helper column-height snail-crawls snail-slides 1 0) 
 
)


(= (snail 3 2 1) 2)
(= (snail 10 3 1) 5)
(= (snail 10 3 2) 8)
(= (snail 100 20 5) 7)
(= (snail 5 10 3) 1)

(= (snail 4 1 0) 4) ; my test
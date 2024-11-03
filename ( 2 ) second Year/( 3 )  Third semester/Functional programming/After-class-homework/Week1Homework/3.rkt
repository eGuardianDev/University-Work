#lang racket



(define (sum-cubes-pow x y)
  ( + ( expt x 3) (expt y 3))
)

(define (sum-cubes-no-pow x y)
  (define (pow x counter)
    ( if (= counter 0 )
         1
         (* x (pow x (sub1 counter)))
     )
    
)
   (+ (pow x 3) (pow y 3))
  )


(= (sum-cubes-pow 5 1) 126)
(= (sum-cubes-pow 10 50) 126000)

(= (sum-cubes-pow 9 5) 854) ; my test


(= (sum-cubes-no-pow 5 1) 126)
(= (sum-cubes-no-pow 10 50) 126000)

(= (sum-cubes-no-pow 25 3) 15652) ; my test
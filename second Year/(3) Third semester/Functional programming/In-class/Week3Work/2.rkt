#lang racket

(define (my-lambda x)
  (λ (x) x)
  )

(define (my-identity)
  (λ (x) (identity x)
)    )
(define (my-lanbda f)
  (λ (x) (f x)
 )   )

(define (negate-pred p?)
  (λ (x) (not (p? x))
))
(define (my-compose f g)
  (λ (x) (f (g x ))
)  )

(define (partially-apply f x)
  (curry f x)
)


    
; write 2 tests for subtask 1

(= ((my-lambda identity) 5) 5)
(equal? ((my-lambda identity) "Tensorflow") "Tensorflow")
(= ((my-lambda string-length) "Tensorflow") 10)

(equal? ((negate-pred even?) 6) #f)

(equal? ((my-compose even? string-length) "Tensorflow") #t)
(equal? ((my-compose (λ (x) (- x 5)) (λ (y) (+ y 25))) 5) 25)

(= ((partially-apply (λ (x y) (+ x y)) 5) 10) 15)
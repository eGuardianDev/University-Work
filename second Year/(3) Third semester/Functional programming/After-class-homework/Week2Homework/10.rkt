#lang racket



(define (automorphic? n)
  (define (checker m n)
    (cond
      [(or (zero? m) (zero? n) ) #t]
      [(= (remainder m 10) (remainder n 10)) (checker (quotient m 10) (quotient n 10))]
      [else #f]))
  (if (exact-positive-integer? n) ;from docs
      (checker (* n n) n)
      (error "not a natural number")))

(equal? (automorphic? 3)#f)
(equal? (automorphic? 10)#f)
(equal? (automorphic? 5)#t)
(equal? (automorphic? 25)#t)
(equal? (automorphic? 76)#t) 
(equal? (automorphic? 890625)#t) 
(equal? (automorphic? 625)#t) 
(equal? (automorphic? 36) #f)
(equal? (automorphic? 11) #f)

(equal? (automorphic? 41) #f); my test
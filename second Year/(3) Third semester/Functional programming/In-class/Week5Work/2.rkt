#lang racket
#; ; my way
(define (replace xs pairs)
  (cond
    [(empty? xs) `()]
    [(not (equal? (assoc (car xs) pairs) #f)) (cons (cdr (assoc (car xs) pairs)) (replace (cdr xs) pairs)) ]
    [else (cons (car xs) (replace (cdr xs) pairs))]))

(define (replace xs dict)
  (map (λ (x)
         (let ([data (assoc x dict)])
           (if data
           (cdr data)
           x)))
       xs))

(equal? (replace '(1 2 3 4) '((1 . 11) (2 . 22))) '(11 22 3 4))
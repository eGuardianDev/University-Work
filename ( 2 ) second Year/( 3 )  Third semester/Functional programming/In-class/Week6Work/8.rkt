#lang racket

#;
(define (get-pos-of-one xss)
  (define (drop-until xss)
     (if (list? (car xss))
         xss
         (drop-until (cdr xss)))
    )
  (let ([new (drop-until (map (λ (x) (member 1 x)) xss))])
    (cons  (- 5  (length new)) (- 5 (length (car new))))
    ))

(define (get-pos-of-one xss)
  (let* ([temp (map (λ (x) (member 1 x)) xss)]
         [final (member (car (filter list? temp)) temp)])
    (+ (abs (- 3 (length final))) (abs (- 3 (length (car final)))) )))

(define (steps-bm xss)
  (let ([pair (get-pos-of-one xss)])
    ;(+(abs (- 2 (car pair))) (abs(- 2 (cdr pair))))
    pair
    ))

(define m `((0 0 0 0 0)
            (0 0 1 0 0)
            (0 0 0 0 0)
            (0 0 0 0 0)
            (0 0 0 0 0)))
  

(steps-bm '((0 0 0 0 0)
            (0 0 0 0 1)
            (0 0 0 0 0)
            (0 0 0 0 0)
            (0 0 0 0 0)) ) ; → 3

(steps-bm '((0 0 0 0 0)
            (0 0 0 0 0)
            (0 1 0 0 0)
            (0 0 0 0 0)
            (0 0 0 0 0)) ) ; → 1

(steps-bm '((0 0 0 0 0)
            (0 0 0 0 0)
            (0 0 1 0 0)
            (0 0 0 0 0)
            (0 0 0 0 0)) ) ; → 0

(steps-bm '((0 0 0 0 0)
            (0 0 0 0 0)
            (0 0 0 0 0)
            (0 0 0 0 0)
            (0 0 0 0 1)) ) ; → 4

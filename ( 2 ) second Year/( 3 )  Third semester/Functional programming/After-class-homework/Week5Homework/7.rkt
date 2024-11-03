#lang racket
(require math/number-theory)


(define (make-list-from-digits n)
  (define (helper xs leftover)
    (if (zero? leftover)
        xs
        (helper (cons (remainder leftover 10) xs )
                (quotient leftover 10))))
  (helper `() n))
  
(define (make-number-from-list xs)
  (define (helper current ys)
    (if (empty? ys)
        current
        (helper (+ (* current 10) (car ys)) (cdr ys)) 
        ))
  (helper 0 (reverse xs)))
  
(define (sort-digits n)
  (make-number-from-list (sort (make-list-from-digits `() n) < )))

(define (num-of-digits n)
  (if (zero? n)
      0
      (add1 (num-of-digits (quotient n 2)))))

(define (palindromize n)
  (define (helper xs leftover)
    (if (empty? leftover)
        (append xs (reverse xs))
        (helper (cons (car leftover) xs) (cddr leftover))))
  (if (divides? 2 (num-of-digits n))
      (make-number-from-list (helper `() (sort (make-list-from-digits n) >)))
      (error "Not an even number")))


(equal? (palindromize 11) 11 )
(equal? (palindromize 3354457878)  3457887543)
(equal? (palindromize 11335445789789) 13457899875431)
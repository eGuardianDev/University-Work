#lang racket

; start of task 1
(define (len-of-number n)
  (if (zero? n)
      0
      (add1 (len-of-number (quotient n 10)))))

(define (sum-digits sum leftover)
  (if (< leftover 10)
      (+ sum leftover )
      (sum-digits (+ sum (remainder leftover 10)) (quotient leftover 10))))

(define (endurance k)
  (define (count-steps-of-sums n count)
    (if (< n 10)
        count
        (count-steps-of-sums (sum-digits 0 n) (add1 count))))
  (count-steps-of-sums k 0))

(define (min-endurance-max-length a b)
  (define (helper current end biggest value biggest-length)
    (cond
      [(> current end) biggest]
      [(and (<= (endurance current) value) (> (len-of-number current) biggest-length))
       (helper (add1 current) end current (endurance current) (len-of-number current) )]
      [(and (< (endurance current) value) (= (len-of-number current) biggest-length))
       (helper (add1 current) end current (endurance current) (len-of-number current) )]
      [else (helper (add1 current) end biggest value biggest-length) ]))
  (helper (add1 a) b a (endurance a) (len-of-number a)))
; end of task 1

; tests for task 1
(equal? (min-endurance-max-length 333 1000) 1000)
(equal? (min-endurance-max-length 333 2000) 1000)
(equal? (min-endurance-max-length 356 460)  360)
(equal? (min-endurance-max-length 498 701)  500)
(equal? (min-endurance-max-length 583 889) 600)
(equal? (min-endurance-max-length 34 621)  100)
(equal? (min-endurance-max-length 234 651)  234)
; end of task 1 tests


; start of task 2
(define (subtract-list xs ys)
  (if (empty? (cdr ys))
      xs
      (subtract-list (append xs (list (abs (- (car ys ) (car (cdr ys)))) )) (cdr ys))))

(define (list-all-zeros? xs)
    (cond
      [(empty? xs) #t]
      [(zero? (car xs)) (list-all-zeros? (cdr xs))]
      [else #f]))

(define (sum-predictions strategy data)
  (define (sum-predictions-helper xs)
    (define (helper1 ys)
      (if (list-all-zeros? ys)
          0
          (+ (car(reverse ys)) (helper1 (subtract-list `() ys)))))
    (define (helper2 ys)
      (if (list-all-zeros? ys)
          0
          (- (car ys) (helper2 (subtract-list `() ys)))))
    (cond
      [(equal? strategy "backwards") (helper2 xs)]
      [(equal? strategy "forwards") (helper1 xs)]
      [else (error "Invalid argument for direction")]))
  
  (define (counter count xs)
    (if (empty? xs)
        count
        (counter (+ count (sum-predictions-helper (car xs))) (cdr xs))))
  (counter 0 data))
; end of task 2

; start of task 2 tests 
(equal? (sum-predictions "backwards" (list (list 10 13 16 21 30 45))) 5)
(equal? (sum-predictions "forwards" (list (list 10 13 16 21 30 45)))  68) 
(equal? (sum-predictions "backwards" (list (list 7 9 12 16 21 27 34))) 6) 
(equal? (sum-predictions "forwards" (list (list 7 9 12 16 21 27 34))) 42)
(equal? (sum-predictions "forwards" (list (list 7 9 12) (list 7 9 12 16)
(list 7 9 12 16 21))) 64)
(equal? (sum-predictions "backwards" (list (list 21 30 45) (list 16 21 30
45) (list 13 16 21 30 45))) 41)
(equal? (sum-predictions "forwards" (list (list 0 3 6 9 12 15) (list 1 3 6
10 15 21) (list 10 13 16 21 30 45))) 114)
; end of task 2 tests
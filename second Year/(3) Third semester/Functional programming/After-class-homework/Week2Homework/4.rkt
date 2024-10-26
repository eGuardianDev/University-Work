#lang racket

; from exercise 10, homework 1
(define (rev x)
  (define (helper input output)
      (if (zero?  input ) output
          (helper (quotient input 10) (*(+ output (remainder input 10))10)))    )
    (if (< x 0 ) (error "Cannot use negative number")
       (/ (helper x 0 ) 10)))
; end

(define (num-palindromes-rec a b)
  (define (helper current ends)
    (cond
      [(> current ends) 0]
      [(= (rev current) current) (add1 (helper (add1 current) ends))]
      [else (helper (add1 current) ends)]))
  (if (> a b)
      (helper b a)
      (helper a b)))

(define (num-palindromes-iter a b)
  (define (helper current ends sum)
    (cond
      [(> current ends) sum]
      [(= (rev current) current) (helper (add1 current) ends (add1 sum))]
      [else (helper (add1 current) ends sum)]))
  (if (> a b)
      (helper b a 0)
      (helper a b 0)))

(= (num-palindromes-rec 1 101) 19)
(= (num-palindromes-rec 1 100) 18)
(= (num-palindromes-rec 100 1) 18)
(= (num-palindromes-rec 5 12) 6) ; my test

(= (num-palindromes-iter 1 101) 19)
(= (num-palindromes-iter 1 100) 18)
(= (num-palindromes-iter 100 1) 18)
(= (num-palindromes-iter 5 12) 6) ; my test

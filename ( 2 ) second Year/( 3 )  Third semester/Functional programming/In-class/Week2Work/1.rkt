#lang racket


(define (pow-rec x n)
  (if (zero? n ) 1
      (* x (pow-rec x (sub1 n)))))


(define (pow-iter x n)
  (define (helper x n res)
    (if (zero? n) res (helper x (sub1 n) (* res x))))
  (helper x n 1)
  )
  
(= (pow-rec 2 5) 32)
(= (pow-rec 15 3) 3375)

(= (pow-iter 2 5) 32)
(= (pow-iter 15 3) 3375)

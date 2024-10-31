#lang racket

(define (assoc-rec element xs)
  (if (equal? element (car (car xs)))
      (cdr (car xs))
      (assoc-rec element (cdr xs))))

(define (assoc-hop el xs)
  (let ([final (dropf xs (λ (pair) (not (equal? (car pair) el))))])
    (if (empty? final)
        #f
        (cdr (car final)))))
  
(define (assoc-builtin el xs)
  (cdr (assoc el xs)))



; using a recursive process
(equal? (assoc-rec 1 (list '(2 . "Two") '(3 . "Three") '(1 . "One"))) "One")

; using a higher order procedure
(equal? (assoc-hop 1 (list '(2 . "Two") '(3 . "Three") '(1 . "One"))) "One")
(equal? (assoc-hop 42 (list '(2 . "Two") '(3 . "Three") '(1 . "One"))) #f)

; using a built-in procedure
(equal? (assoc-builtin 1 (list '(2 . "Two") '(3 . "Three") '(1 . "One"))) "One")
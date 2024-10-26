#lang racket

(define (repeater word)
  (λ (n in-between)
   (if (equal? 1 n)
       word
       (string-append word in-between ((repeater word) (sub1 n) in-between)))))


(equal? ((repeater "I love Racket") 3 " ") "I love Racket I love Racket I love Racket")
(equal? ((repeater "Quack") 5 "!") "Quack!Quack!Quack!Quack!Quack")
(equal? ((repeater "bark") 5 " ") "bark bark bark bark bark") ; my test
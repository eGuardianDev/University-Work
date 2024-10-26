#lang racket

(require math/number-theory) ; API: https://docs.racket-lang.org/math/number-theory.html

(define (max-multiple d b)
  (define (helper current)
    (if (and (divides? d current) (<= current b) (> current 0 ))
        current
        (helper (sub1 current))))
  (helper b))


(= (max-multiple 2 7) 6)
(= (max-multiple 3 10) 9)
(= (max-multiple 7 17) 14)
(= (max-multiple 10 50) 50)
(= (max-multiple 37 200) 185)
(= (max-multiple 7 100) 98)

(= (max-multiple 7 34) 28) ; my test
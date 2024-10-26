#lang racket
(require math/number-theory) ; API: https://docs.racket-lang.org/math/number-theory.html

(define (my-sin n x)
  (define (helper i result)
  (if (> i n)
      result
      (helper (add1 i)
                  (+ result
                     (/ (* (expt -1 i ) (expt x (add1(* 2 i)) ))
                        (factorial (add1 (* 2 i))))))))
  (helper 0 0))
d
(= (my-sin 100 1.570796) 0.9999999999999465) ; 90 degrees => 0.9999999999999465
(= (my-sin 100 0.5235988) 0.5000000211324931) ; 30 degrees => 0.5000000211324931
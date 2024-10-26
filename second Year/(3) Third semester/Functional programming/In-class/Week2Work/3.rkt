#lang racket
	(require math/number-theory) ; API: https://docs.racket-lang.org/math/number-theory.html

(define (sum-divs x)
  (define (helper sum start)
    (cond
      [(zero? start) sum]
      [(divides? start x) (helper (+ sum start) (sub1 start))]
      [else (helper sum (sub1 start))]))
  (if (< x 0)
      0
      (helper 0 x)))

(= (sum-divs 0) 0)
(= (sum-divs 1) 1)
(= (sum-divs 6) 12) ; 1 + 2 + 3 + 6
(= (sum-divs -6) 0)
(= (sum-divs 12345) 19776)
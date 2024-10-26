#lang racket

;; from exercise 17
(define (remove-first-occurrence n x)
  (define (helper current leftover step)
    (cond
      [(zero? current) leftover]
      [(= x (remainder current 10)) (+ (* (quotient current 10) (expt 10 step) ) leftover )]
      [else (helper (quotient current 10) ( + (* (remainder current 10) (expt 10 step) ) leftover) (add1 step))]))
  (helper n 0 0))
;; end

(define (sort-n n)

  (define (len n)
    (if (zero? n)
        0
        (add1 (len(quotient n 10)))
    ))
  (define (find-max k max-num)
    (cond
      [(zero? k) max-num]
      [(> (remainder k 10) max-num) (find-max (quotient k 10) (remainder k 10))]
      [else (find-max (quotient k 10) max-num)]))
  (define (helper current sorted count)
    (cond
      [(zero? count) sorted]
      [else (helper (remove-first-occurrence current (find-max current 0)) (+(* sorted 10) (find-max current 0)) (sub1 count))]))
  (helper n 0 (len n))
  )



(= (sort-n 1714) 7411)
(= (sort-n 123450) 543210)
(= (sort-n 123405) 543210)
(= (sort-n 123045) 543210)
(= (sort-n 120345) 543210)
(= (sort-n 102345) 543210)
(= (sort-n 8910) 9810)
(= (sort-n 321) 321)
(= (sort-n 29210) 92210)
(= (sort-n 1230) 3210)
(= (sort-n 55345) 55543)
(= (sort-n 14752) 75421)
(= (sort-n 329450) 954320)
(= (sort-n 9125) 9521)

(= (sort-n 0392) 932) ; my test
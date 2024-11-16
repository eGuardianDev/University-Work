#lang racket

; ex 1
(define (find-start xs)
  (let* ([newMap (map (λ (x) (member "S" x)) xs)]
         [Final (member (car (filter (λ (x) (list? x)) newMap)) newMap)])
    (cons (abs( - (length Final) (length xs))) (abs (- (length (car Final)) (length (car xs)))))))


; tests
(find-start '(("." "." ".")
              ("." "." ".")
              ("." "S" ".")
              ("." "." ".")))
;→ '(2 . 1)
(find-start '(("." "." "F" "J")
              ("S" "-" "|" ".")
              ("." "." "J" ".")))
;→ '(1 . 0)



; ex 2
(define (valid-position? player-map position) ; additional function
  (and (>= (car position) 0) (>= (cdr position) 0)
       (< (car position) (length player-map)) (< (cdr position) (length player-map))))

(define (get-next-steps player-map current-position)
  (define (pos-checking x) ; this function is very specific for get-next-steps, so I won't be global
    (if (valid-position? player-map x)
        (list x)
        null))
  (let ([current-symbol (car (drop (car (drop player-map (car current-position)))  (cdr current-position))) ]
        [currY (car current-position)]
        [currX (cdr current-position)])
    (cond
      [(equal? current-symbol "S") (append
                                    (pos-checking (cons (sub1 currY) currX))
                                    (pos-checking (cons (add1 currY) currX))
                                    (pos-checking (cons currY (add1 currX)))
                                    (pos-checking (cons currY (sub1 currX))))]
      [(equal? current-symbol "F") (append
                                    (pos-checking (cons (add1 currY) currX))
                                    (pos-checking (cons currY (add1 currX))))]
      [(equal? current-symbol "7") (append
                                    (pos-checking (cons (add1 currY) currX))
                                    (pos-checking (cons currY (sub1 currX))))]
      [(equal? current-symbol "J") (append
                                    (pos-checking (cons (sub1 currY) currX))
                                    (pos-checking (cons currY (sub1 currX))))]
      [(equal? current-symbol "L") (append
                                    (pos-checking (cons (sub1 currY) currX))
                                    (pos-checking (cons currY (add1 currX))))]
      [(equal? current-symbol ".") null]
      [(equal? current-symbol "|") (append
                                    (pos-checking (cons (sub1 currY) currX))
                                    (pos-checking (cons (add1 currY) currX)))]
      [(equal? current-symbol "-") (append
                                    (pos-checking (cons currY (sub1 currX)))
                                    (pos-checking (cons currY (add1 currX))))])))


; tests
(get-next-steps '(("." "." ".")
                  ("." "." ".")
                  ("." "S" ".")
                  ("." "." "."))
                '(2 . 1))
;→ '((1 . 1) (3 . 1) (2 . 2) (2 . 0))
(get-next-steps '(("." "." "F" "J")
                  ("S" "-" "|" ".")
                  ("." "." "J" "."))
                '(1 . 2))
;→ '((0 . 2) (2 . 2))
(get-next-steps '(("." "." "F" "J")
                  ("S" "-" "|" ".")
                  ("." "." "J" "."))
                '(0 . 3))
;→ '((0 . 2))




; ex 3
(define (num-steps-farthest player-map)
  (define (get-all-next step) (get-next-steps player-map step))

  (define (search current-pos last-pos count)
    (let ([nexts (remove last-pos (get-all-next current-pos))])
      (if (empty? nexts)
          count
          (map (λ (x) (search x current-pos (add1 count))) nexts))))
  
    (car (sort (flatten (search (find-start player-map) (find-start player-map) 0)) >)))


;tests
(num-steps-farthest '(("." ".")
                      ("S" ".")
                      ("." ".")))
;→ 1
(num-steps-farthest '(("." "." ".")
                      ("S" "-" "|")
                      ("." "." ".")))
;→ 3
(num-steps-farthest '(("." "." "F" "J")
                      ("S" "-" "|" ".")
                      ("." "." "J" ".")))
;→ 4
(num-steps-farthest '(("." "." "." ".")
                      ("." "." "F" "J")
                      ("S" "-" "|" ".")
                      ("." "." "J" ".")))
;→ 5
(num-steps-farthest '(("." "." "." "|")
                      ("." "." "F" "J")
                      ("S" "-" "|" ".")
                      ("." "." "J" ".")))
;→ 5
(num-steps-farthest '(("F" "-" "7" "." "." "|")
                      ("|" "." "|" "." "F" "J")
                      ("|" "." "S" "-" "|" ".")
                      ("|" "." "." "." "|" ".")
                      ("L" "-" "-" "." "J" ".")))
;→ 11
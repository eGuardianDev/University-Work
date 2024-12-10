#lang racket

(define (find-start xs)
  (let* ([newMap (map (λ (x) (member "S" x)) xs)]
         [Final (member (car (filter (λ (x) (list? x)) newMap)) newMap)])
    (cons (abs( - (length Final) (length xs))) (abs (- (length (car Final)) (length (car xs)))))))

(define (valid-position? player-map position)
  (and (>= (car position) 0) (>= (cdr position) 0)
       (< (car position) (length player-map)) (< (cdr position) (length player-map))))

(define (get-next-steps player-map current-position)
  (define (pos-checking x) ; this function is very specific for get-next-steps, so It won't be global
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



(define (get-diff x y)
  (+ (abs (- (car x) (car y)))  (abs (- (cdr x) (cdr y)))))

(define (custom-zip xs)
  (if (null? xs)
      null
      (cons (cons (car xs) (cons (cadr xs) (caddr xs))) (custom-zip (cdddr xs)))))

(define (num-steps-farthest-away player-map)
  (define (get-all-next step) (get-next-steps player-map step))
  
  (define (search current-pos last-pos count size starting-pos furthest-pos)
    (let ([nexts (remove last-pos (get-all-next current-pos))]
          [current-symbol (car (drop (car (drop player-map (car current-pos))) (cdr current-pos)))])
      (cond
         [(and (> count 0) (equal? current-symbol "S")) (cons count furthest-pos)] ; finded loop with S in it and save it
         [(> count size) (cons 0 (cons 0 0))] ; currently in loop that doesn't end with S, because it passed more places than the board size
         [(> (get-diff starting-pos current-pos) (get-diff starting-pos furthest-pos )) ; continue to next step but check if furthest value is this and save it
          (map (λ (x) (search x current-pos (add1 count) size starting-pos current-pos)) nexts)] ; save it
         [else (map (λ (x) (search x current-pos (add1 count) size starting-pos furthest-pos)) nexts)]))) ; don't save it
  
       (let* (
              [start-pos (find-start player-map)]
              [beginWalk (custom-zip (flatten (search start-pos
                                                      start-pos
                                                      0
                                                      (* (length (car player-map)) (length player-map))
                                                      start-pos
                                                      start-pos)))] ; start the search/walk
              [final  (sort (map (λ (x) (cons (car x) (get-diff (cons (cadr x) (cddr x)) start-pos ))) beginWalk) (λ (a b) (> (cdr a) (cdr b))))])
         ;get furthest positions
         (quotient (caar final) 2))) ; filter data and



(num-steps-farthest-away '(("7" "-" "F" "7" "-")
                          ("." "F" "J" "|" "7")
                          ("S" "J" "L" "L" "7")
                          ("|" "F" "-" "-" "J")
                          ("L" "J" "." "L" "J")))
;→ 8
(num-steps-farthest-away '(("-" "." "|" "F" "7")
                           ("." "S" "-" "7" "|")
                           ("L" "|" "7" "|" "|")
                           ("-" "L" "-" "J" "|")
                           ("L" "|" "-" "J" "F")))
;→ 4
(num-steps-farthest-away '(("F" "-" "-" "7")
                           ("|" "F" "-" "7")
                           ("." "S" "." "|")
                           ("|" "L" "-" "J")
                           ("L" "-" "-" "J")))
;→ 4
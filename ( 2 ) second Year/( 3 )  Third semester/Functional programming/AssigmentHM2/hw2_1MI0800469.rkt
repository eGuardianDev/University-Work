#lang racket

; ex 1
(define (find-start xs)
  (let* ([newMap (map (λ (x) (member "S" x)) xs)]
         [Final (member (car (filter (λ (x) (list? x)) newMap)) newMap)])
    (cons (abs( - (length Final) (length xs))) (abs (- (length (car Final)) (length (car xs)))))))

(define (get-diff x y)
  (+ (abs (- (car x) (car y)))  (abs (- (cdr x) (cdr y)))))


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


(define (custom-zip xs)
  (if (null? xs)
      null
      (cons (cons (car xs) (cons (cadr xs) (caddr xs))) (custom-zip (cdddr xs)))))



; ex 3
#;
(define (num-steps-farthest-away player-map)
  (define (get-all-next step) (get-next-steps player-map step))
  (define (search current-pos last-pos count size starting-pos furthest-pos)

    (let ([nexts (remove last-pos (get-all-next current-pos))]
          [current-symbol (car (drop (car (drop player-map (car current-pos)))  (cdr current-pos)))]
          [currY (car last-pos)]
          [currX (cdr last-pos)])

      (cond
         [(and (> count 0) (equal? current-symbol "S")) (cons count furthest-pos)]
         [(> count size) (cons 0 (cons 0 0))]
         [(> (get-diff starting-pos current-pos) (get-diff starting-pos furthest-pos ))
          (map (λ (x) (search x current-pos (add1 count) size starting-pos current-pos)) nexts)]
         [else (map (λ (x) (search x current-pos (add1 count) size starting-pos furthest-pos)) nexts)])))
  
       (let* ([begi (custom-zip (flatten (search (find-start player-map)
                                (find-start player-map)
                                0
                                (* (length (car player-map)) (length player-map))
                                (find-start player-map)
                                (find-start player-map))))]
             [fin  (sort (map (λ (x) (cons (car x)(get-diff (cons (cadr x) (cddr x)) (find-start player-map) ))) begi) (λ (a b) (> (cdr a) (cdr b))))])
           fin) )


(define (custom-flatten xs)
  (cond
    [(null? xs) null]
    [(not (list? (car xs))) xs]
    [else (custom-flatten (car xs))]
  ))

(define (symbol-on-map player-map x y)
 (car (drop (car (drop player-map x))
            y)))


(define (group xs)
  (cond
    [(null? xs) null]
    [(ormap (λ (x) (equal? x (car xs))) (cdr xs)) (append (list (car xs)) (group (cdr xs) ))]
    [else (group (cdr xs))]))

(define (num-steps-farthest-away player-map)
  (define (get-all-next step) (get-next-steps player-map step))
  (define (search current-pos last-pos count size curr-path paths)

    (let ([nexts (remove last-pos (get-all-next current-pos))]
          [current-symbol (car (drop (car (drop player-map (car current-pos)))  (cdr current-pos)))]
          [currY (car last-pos)]
          [currX (cdr last-pos)])

      (cond
         [(and (> count 0) (equal? current-symbol "S")) (reverse (cdr (reverse curr-path)))]
         [(> count size) 0]
         [else (map (λ (x) (search x current-pos (add1 count) size (append (list (symbol-on-map player-map (car current-pos) (cdr current-pos))) curr-path ) paths)) nexts)])))
  
       (let* ([begi (search (find-start player-map)
                                (find-start player-map)
                                0
                                (* (length (car player-map)) (length player-map))
                                null null)]
             [fin (map (λ (x) (custom-flatten x)) begi)])
          (group (append fin (map reverse fin)))))

         
(num-steps-farthest-away '(("7" "-" "F" "7" "-")
                           ("." "F" "J" "|" "7")
                           ("S" "J" "L" "L" "7")
                           ("|" "F" "-" "-" "J")
                           ("L" "J" "." "L" "J")))
;→ 8

(num-steps-farthest-away '(("-" "L" "|" "F" "7")
                           ("7" "S" "-" "7" "|")
                           ("L" "|" "7" "|" "|")
                           ("-" "L" "-" "J" "|")
                           ("L" "|" "-" "J" "F")))
;→ 4

(num-steps-farthest-away '(("." "." "." ".")
                           ("." "F" "7" ".")
                           ("." "S" "|" ".")
                           ("." "L" "J" ".")
                           ("." "." "." ".")))
;→ 3

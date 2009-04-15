(define TT 75)

(define (point MP time)
  (* MP (+ 0.3 (/ (* 0.7 TT TT) (+ (* 10 time time) (* TT TT))))))

(define (taken-time MP pt)
  (* TT (sqrt (/ (- (/ 0.7 (- (/ pt MP) 0.3)) 1) 10))))

(define (minsec min)
  (let* ([m (floor->exact min)]
		 [s (floor->exact (* (- min m) 60))])
	(format #t "~d'~d''\n" m s)))

#?=(taken-time 250 203.42)
(minsec (taken-time 250 203.42))
#|
#?=(point 250 0)
#?=(point 250 1)
#?=(point 250 2)
#?=(point 250 3)
#?=(point 250 4)
#?=(point 250 5)
|#
#?=(point 250 75)
#?=(point 500 75)
#?=(point 1000 75)
#?=(taken-time 250 181.818181)

#?=(+ (point 250 15) (point 500 60))
(minsec (taken-time 250 242.10))

#?=(taken-time 250 201.66)
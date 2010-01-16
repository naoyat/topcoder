
(define (weight timesPlayed)
  (- (/ 1 (- 1 (+ (/ 0.42 (+ timesPlayed 1)) 0.18))) 1))

#|
(dotimes (timesPlayed 1000)
  (format #t "timesPlayed=~d, weight=~d\n"
		  timesPlayed (weight timesPlayed) ))
|#

(define (cap timesPlayed)
  (+ 150 (/. 1500 (+ timesPlayed 2))))

(dotimes (timesPlayed 1000)
  (format #t "timesPlayed=~d, weight=~d, cap=~d\n"
		  timesPlayed
		  (weight timesPlayed)
		  (cap timesPlayed)
		  ))

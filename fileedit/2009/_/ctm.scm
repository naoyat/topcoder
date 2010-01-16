
(let ([mx #(-820 442)]
	  [my #(795 -687)]
	  [vx #(-816 -842)]
	  [vy #(-753 -722)])
  (let loop ((t 0.0))
	(let ([xs (make-vector 2)]
		  [ys (make-vector 2)]
		  [xmin 2000] [xmax -2000]
		  [ymin 2000] [ymax -2000]
		  )
	  (dotimes (i 2)
		(vector-set! xs i (+ (vector-ref mx i)
							 (* (vector-ref vx i) t)))
		(vector-set! ys i (+ (vector-ref my i)
							 (* (vector-ref vy i) t)))
		)
	  
	(loop (+ t 0.01))
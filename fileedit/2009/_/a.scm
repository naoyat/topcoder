(require "../../project_euler/euler-lib")

(print (map (lambda (c)
			  (if (<= 0 c)
				  (+ (* 4 c c) (* -3 c) 1)
				  (+ (* 4 c c) (- c) 1) ))
			(numbers-between -3 3)))

#!/usr/bin/env gosh
(use srfi-1)

(define TT 75)

(define (point MP time)
  (* MP (+ 0.3 (/ (* 0.7 TT TT) (+ (* 10 time time) (* TT TT))))))

(define (taken-time MP pt)
  (* TT (sqrt (/ (- (/ 0.7 (- (/ pt MP) 0.3)) 1) 10))))

(define (minsec min)
  (let* ([m (floor->exact min)]
		 [s (floor->exact (* (- min m) 60))])
	(format "~d'~d''\n" m s)))

(define (usage)
  (format #t "Usage: ~a -point <full-point> <minute>\n" *program-name*)
  (format #t "    or ~a -time <full-point> <point>\n" *program-name*)
  (exit 2))

(define (main args)   ;entry point
  (if (not (= 4 (length args)));(null? (cdr args))
      (usage)
      (case (string->symbol (second args))
        [(-point) (let ([full-point (string->number (third args))]
                        [minute (string->number (fourth args))])
         (print (point full-point minute)))]
        [(-time) (let ([full-point (string->number (third args))]
                       [point (string->number (fourth args))])
         (print (minsec (taken-time full-point point))))]
        [else (usage)] ))
  0)


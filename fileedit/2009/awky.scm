(define *input-field-separator* " ")
(define *output-field-separator* " ")
(define $0 "")

(define-macro (getline . args)
  (let-optionals* args (target $0)
	(if (null? args)
		`(set! $0 (read-line))
		`(set! ,target (read-line)) )))

(define (split str delim)
  (list str)
  )

(define (FS= fs) (set! *input-field-separator* fs))
(define (OFS= ofs) (set! *output-field-separator* ofs))
(define (print . args)
  (display (string-join (map x->string args) *output-field-separator*))
  (newline))

(define-macro (awk begin-proc end-proc . body-procs)
  `(begin (,begin-proc)
		  (let loop ()
			(getline)
			(unless (eof-object? $0)
			  (call/cc (lambda (exit)
						 ,@body-procs
						 (loop)
						 ))))
		  (,end-proc)))

(define-macro (BEGIN . body)
  `(lambda () ,@body))
(define-macro (END . body)
  `(lambda () ,@body))

(awk
 (BEGIN (FS= "\t")
		(OFS= ", "))
 (END (print 1 2 3))
 )

#|
(begin 文字列のリストが $0 あたりに入ってて... )
(#// ...)

(END ....)

(define (main args)
  )

(define $0 "abcdefg hijklmn")
(print $0)

awkeme -f script ...
|#

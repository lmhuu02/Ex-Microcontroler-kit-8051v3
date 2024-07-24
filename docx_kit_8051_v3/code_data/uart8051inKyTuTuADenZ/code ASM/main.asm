; NGUYEN NGOC NGAN _ DH GTVT TP HCM
; Xtal = 11.0592MHz
org 	00h

INIT:
	mov		TMOD,#20h	; timer 1 mode 2
	mov		SCON,#52h	; UART mode 1 
	mov		TH1,#(-3)	; baudrate =9600
	mov		TL1,#(-3)
	setb	TR1
MAIN:
	mov		DPTR,#string1
	acall	out_string
	mov		A,#13			; ma ASCII cua ky tu xuong dong
	acall	out_char
	mov		DPTR,#string0
	acall	out_string
	mov		A,#13			; ma ASCII cua ky tu xuong dong
	acall	out_char
	mov		A,#'A'
next:
	acall	out_char
	inc		A
	cjne 	A,#'Z'+1,next
	sjmp	$
; chuong trinh con
;**** xuat chuoi ky tu*******
out_string:
next_char:
	clr		A
	movc	A,@A+DPTR
	jz		end_string
	inc		DPTR
	acall	out_char
	sjmp	next_char
end_string:
ret
;****** xuat 1 ky tu*********
out_char:
	jnb		TI,$
	clr		TI
	mov		SBUF,A
ret
string0:
DB		"ngocnganblog.wordpress.com",0
string1:
DB		"Hello World",0

 end
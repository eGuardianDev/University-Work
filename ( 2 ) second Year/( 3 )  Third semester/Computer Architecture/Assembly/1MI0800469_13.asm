masm
model small

.data

handleMul dw 0
handleSub dw 0

;display minus
minus	db	'-'
point_minus dd minus


filenameMul db 'mul.txt',0
point_fnameMul	dd	filenameMul

filenameSub db 'sub.txt',0
point_fnameSub	dd	filenameSub


;vars
a db 0
b db 0

;flag
lessThan db 0

;result

subRes db 0
point_subRes dd subRes

mulRes db 0,0
point_mulRes dd mulRes

;count for output
count db 1


.stack	256
.code
main:

	; Setup
	mov	ax,@data 
	mov	ds,ax 

	; Input
	
	mov ah, 01h
	int 21h
	sub al, 30h
	mov a, al
	
	mov ah, 01h
	int 21h
	sub al, 30h
	mov b, al
	
	;;everything saved in a, b
	

	; Multiply
	xor ax, ax
	mov al, a
	xor cx,cx
	mov cl, b

	mul cx

	; all calculate
	
	;fix numbers
	xor dx,dx
	xor ah,ah

	mov dl,10

	div dl

	; mov ah,30h
	mov mulRes, ah
	add mulRes, 30h

	;check if 2 digits
	cmp al, 0
	je skip

	; add 30 to create asci symbol
	add ah,30h
	add al,30h
	; reverse config for outputing
	mov mulRes,al
	mov [mulRes+1],ah
	
	; count 2 digits
	inc count
skip:
	
	; multiplication done!


	; create file
	xor	cx,cx
	lds	dx,point_fnameMul
	mov	ah,3ch
	int	21h
	
	; openning file
	mov	al,02h 
	lds	dx,point_fnameMul 
	mov	ah,3dh 
	int	21h
	mov handleMul, ax

	; write data
	mov	bx,handleMul 
	mov	cl,count
	lds	dx,point_mulRes
	mov	ah,40h 
	int	21h 

	jc	exit 
	nop 
	



;---- subtraction start here ----
	xor ax, ax

	mov ah, a
	mov al, b

	sub ah, al
	;result stored in ah


; compare to see if minus sign is needed
	mov al, a

	cmp al, b
	jge notLessThan
	
	mov lessThan,1

; fix binary less than zero
	xor ah, 255
	inc ah


notLessThan:

	; save result
	mov subRes, ah
	add subRes, 30h


	; output file
	
	; create file
	xor	cx,cx
	lds	dx, point_fnameSub
	mov	ah,3ch
	int	21h	

	; open file
	mov	al,02h 
	lds	dx, point_fnameSub 
	mov	ah,3dh 
	int	21h
	mov handleSub, ax	

	; if less than 0 add minus sign
	cmp lessThan, 0 
	je noSign

	;write minus sign
	mov	bx,handleSub 
	mov	cl,1
	lds	dx,point_minus
	mov	ah,40h 
	int	21h 

noSign:

	;write value 
	mov	bx,handleSub
	mov	cl,1
	lds	dx,point_subRes
	mov	ah,40h 
	int	21h 

	
	; close all opened files
	
	mov	ah,3Eh 
	mov	bx,handleSub
	int	21h

	mov	ah,3Eh 
	mov	bx,handleMul
	int	21h


exit:
	mov	ax,4c00h
	int	21h
end	main
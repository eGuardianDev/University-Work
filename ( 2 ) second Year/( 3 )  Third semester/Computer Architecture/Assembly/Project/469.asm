model small

.data

helpMessage db "Help menu:", 0ah, 0dh, " h - help", 0ah, 0dh ," c - count sentences", 0ah, 0dh, " p - print currently opened text", 0ah, 0dh , " s - select word", 0ah, 0dh , " f - find word", 0ah, 0dh, " . (dot) - find symbols", 0ah, 0dh , " esc - exit", 0dh, 0ah, "$"
invalidSearchWord db "The search is bad - contains space or is null", 0dh, 0ah, "$"
findedWordTable db "Row | Num",0ah,0dh,"$"
currCountSentencesMsg db "Current sentences are: $"
SelectSymbolToFindMsg db "You can search for this symbols by pressing them on the keyboard: . , - ! ?",0ah, 0dh,"$"
WordSelectMsg db "Select your word:",0ah, 0dh,"$"
noWordFoundMsg db "Sadly, no words found.",0ah, 0dh,"$"
badCharMsg db "Current selected character is not valid!",0ah, 0dh,"$"
errorReadingMsg db "Something went wrong during file read.$"
badPathMsg db "Your file was not found.",0ah, 0dh,"$"
enterFileNameMessage db "Enter file name: $"
noSymbolsAreFoundMsg db "Nothing was found for selected symbol symbol $"
leavingProgramMsg db "Exiting program. $"
	

;symbol counter
wordBeforeSymbol db 251 dup(0)
currentSymbol db 0 
isMinusPresentFlag db 0
areAnySymbolsFoundFlag db 0

isCurrWordGoodFlag db 1
hasNewWordFlag db 0 ; used for checking new words for exmaple " - Hello." only one word "Hello.", but " - " shoudn't be new word
; word search
rowNumber db 1
wordNumber db -1
currentWord db 251 dup(0)
isWordFlag db 0

;
IsGoodWordFlag db 0
anyWordsFoundFlag db 0


currentWordIsBad db 0

; counters
foundedASymbolDuringSearch db 0
sentencesCount db 0

; file system
file_Handle dw 0
inputFile db 101 dup(0)
point_inputFile	dd	inputFile

buf db 502 dup(0)
readWordBuf db 251 dup(0)

.stack 256
.code
.386
main:

	; Setup
	mov	ax,@data 
	mov	ds,ax 


	mov ah, 09h
	mov dx, offset enterFileNameMessage
	int 21h
	; setup for read
	mov cx, 100 
WriteNextCharacter:
	mov ah, 01h
	int 21h

	cmp al, 27 ; esc
	jne notExiting
	
	mov ah, 02h
	;make new line to look better
	mov dl, 0ah
	int 21h
	mov dl, 0dh
	int 21h

	jmp exit

	notExiting:

	cmp al, 13 ; is new line
	je exitFileNameWriting

	cmp al, 08 ; backspace
	jne dontRemoveOneCharFileName

	cmp cx, 100
	jne notBorderTouching
	
	mov ah, 02h
	mov dl, 32
	int 21h
	jmp WriteNextCharacter
	notBorderTouching:
	;clean one character
	inc cx
	mov bx, 100
	sub bx, cx
	mov [inputFile+bx],0
	inc cx

	mov ah, 02h
	mov dl, 32
	int 21h
	mov dl, 8
	int 21h

	;continue as normal
	loop WriteNextCharacter

dontRemoveOneCharFileName:

	;save to buffer
	mov bx, 100
	sub bx, cx
	mov [inputFile + bx],al
	
	loop WriteNextCharacter

exitFileNameWriting:


	; openning file
	mov	al,02h 
	lds	dx,point_inputFile
	mov	ah,3dh 
	int	21h
	mov file_Handle, ax

	jnc fileFound

	;file is not found or something went wrong
	mov ah, 09h
	mov dx, offset badPathMsg
	int 21h
	mov ah, 02h

	jmp exit

	fileFound:

	;read file
	xor	al, al
	mov	ah, 3FH
	mov	bx, file_Handle 
	mov cx, 500
	mov dx, offset buf
	int	21h
	jc	exit 
	nop 

	jnc fileReadsGood
	
	;files isn't read well
	mov ah, 09h
	mov dx, offset errorReadingMsg
	int 21h
	jmp exit
	

	fileReadsGood:
	; close files
	mov	ah,3Eh 
	mov	bx,file_Handle
	int	21h

helpmsg:
	mov ah, 09h
	mov dx, offset helpMessage
	int 21h

logicLoop:

	mov ah, 07h ; read keyboard pressed character (no echo)
	int 21h

	cmp al, 1Bh ; esc - exit 
	je exit

	cmp al, 63h ; c - count sentences 
	je startCountingSentences
	
	
	cmp al, 70h ; p - print (opened text)
	je startPrint

	cmp al, 104 ; h - help (opened text)
	je helpmsg

	cmp al, 73h ; s - search (for specific word)
	je startSearch
	
	cmp al, 66h ; f - find words
	je startFindWords
		
	cmp al, 2Eh ; . (dot) - find specific symbols
	je startFindSymbols
	
	
	jmp logicLoop ; infinite loop



startFindSymbols:

	mov wordNumber, -1
	mov ah, 09h
	mov dx, offset SelectSymbolToFindMsg
	int 21h
	mov ah, 07h ; read keyboard pressed character (no echo)
	int 21h
	mov areAnySymbolsFoundFlag, 0

	cmp al, 2Eh ; .
	je validSymbolSelected
	cmp al ,2Dh ; -
	je validSymbolSelected
	cmp al ,21h ; !
	je validSymbolSelected
	cmp al ,3Fh ; ?
	je validSymbolSelected
	cmp al ,2Ch ; ,
	je validSymbolSelected

	mov ah, 09h
	mov dx, offset badCharMsg
	int 21h
	jmp logicLoop


validSymbolSelected:

	mov currentSymbol, al

continueFindingWordSymbols:

	;load text and words
	mov si, offset buf
	mov di, offset wordBeforeSymbol

	; reset counters
	mov wordNumber, 0
	mov hasNewWordFlag,0
	mov rowNumber, 1
	
	mov isCurrWordGoodFlag, 1
	;show info about collums
	mov ah, 09h
	mov dx, offset findedWordTable
	int 21h

	jmp findWordSymbols

checkingForMinusSpace:

	;read one word
	mov dl, [si] ; text
	mov [di], dl
	inc di
	inc si

	mov isMinusPresentFlag, 1
	; if end of word is found
	cmp dl, 32  ; " "
	je newSpaceFoundBetweenSymbols
	cmp dl, 0ah  ; \n
	je newSpaceFoundBetweenSymbols
	cmp dl, 2Eh ; .
	je newSpaceFoundBetweenSymbols
	cmp dl ,21h ; !
	je newSpaceFoundBetweenSymbols
	cmp dl ,3Fh ; ?
	je newSpaceFoundBetweenSymbols
	cmp dl ,2Ch ; ,
	je newSpaceFoundBetweenSymbols

	mov hasNewWordFlag, 1 

	jmp checkForEndOfSymbolFind

checkForEndOfSymbolFindForMinus:
	cmp BYTE PTR [si], 0 	
	jne checkingForMinusSpace

	cmp areAnySymbolsFoundFlag, 1
	je logicLoop

	mov ah, 03h
	int 10h
	dec dh
	mov ah, 02h
	int 10h
	mov ah, 09h
	mov dx, offset noSymbolsAreFoundMsg
	int 21h

	mov ah, 02h
	mov dl, currentSymbol
	int 21h
	mov ah, 02h
	mov dl, 10
	int 21h
	mov ah, 02h
	mov dl, 13
	int 21h

	jmp logicLoop

findWordSymbols:

	;read one word
	mov dl, [si] ; text
	mov [di], dl
	inc di
	inc si


	; if end of word is found
	cmp dl, 32  ; " "
	je newSpaceFoundBetweenSymbols
	cmp dl, 0ah  ; \n
	je newSpaceFoundBetweenSymbols
	cmp dl, 2Eh ; .
	je newSpaceFoundBetweenSymbols
	cmp dl ,2Dh ; -
	je checkingForMinusSpace
	cmp dl ,21h ; !
	je newSpaceFoundBetweenSymbols
	cmp dl ,3Fh ; ?
	je newSpaceFoundBetweenSymbols
	cmp dl ,2Ch ; ,
	je newSpaceFoundBetweenSymbols


	mov hasNewWordFlag, 1 

	jmp checkForEndOfSymbolFind

wordSymbolReset:

	mov isMinusPresentFlag, 0
	mov cx, 250
	clearReadBufferSymbol:
	mov bx, 250
	sub bx, cx
	mov [wordBeforeSymbol + bx],0
	loop clearReadBufferSymbol

	mov di, offset wordBeforeSymbol
	
	jmp checkForEndOfSymbolFind

foundWordSymbol:

	; compare if our symbol is good
	cmp dl, 0ah  ; \n
	jne skipSpaceCheckForMinus

	skipSpaceCheckForMinus:

	cmp currentSymbol, 2Dh
	jne compareSymbol
	
	cmp isMinusPresentFlag, 1
	je dontCheckForSymbol
	jne wordSymbolReset

	compareSymbol:

	cmp dl, currentSymbol 
	jne wordSymbolReset
	
	dontCheckForSymbol:

	mov areAnySymbolsFoundFlag, 1
	mov ah, 0
	mov al, rowNumber
	
	mov bl, 10
	
	;do cal
	xor dx, dx

	xor ah,ah
	div bl
	mov dl ,ah
	push dx

	xor ah,ah
	div bl
	mov dl ,ah
	push dx
	
	xor ah,ah
	div bl
	mov dl ,ah
	push dx

	; max 3 becuase 500 cannot have more than ~ 166 sentences

	
	; display
	mov ah, 02h
	xor dx,dx
	pop dx
	add dl,30h
	int 21h

	xor dx,dx
	pop dx
	add dl,30h
	int 21h

	xor dx,dx
	pop dx
	add dl,30h
	int 21h

	mov dl, 32 ; " " <- this symbol
	int 21h
	mov dl, 124 ; | <- this symbol
	int 21h
	mov dl, 32 ; " " <- this symbol
	int 21h





	mov ah, 0
	mov al, wordNumber
	
	mov bl, 10
	
	;do cal
	xor dx, dx

	xor ah,ah
	div bl
	mov dl ,ah
	push dx

	xor ah,ah
	div bl
	mov dl ,ah
	push dx
	
	xor ah,ah
	div bl
	mov dl ,ah
	push dx

	; max 3 becuase 500 cannot have more than ~ 166 sentences

	
	; display
	mov ah, 02h
	xor dx,dx
	pop dx
	add dl,30h
	int 21h

	xor dx,dx
	pop dx
	add dl,30h
	int 21h

	xor dx,dx
	pop dx
	add dl,30h
	int 21h

	mov dl, 32
	int 21h



	mov di, offset wordBeforeSymbol

	displayWordSymbolUntilZero:

	mov dl, [di]
	int 21h
	inc di

	cmp BYTE ptr dx, 0
	jne displayWordSymbolUntilZero

	mov ah, 02h
	mov dl, 0ah ; print new line
	int 21h
	mov dl, 0dh ; carage return
	int 21h

	jmp wordSymbolReset

newSpaceFoundBetweenSymbols:

	cmp isMinusPresentFlag, 0
	je skipMinusRemoveEndSymbol
	
	cmp currentSymbol, 2Dh
	jne skipMinusRemoveEndSymbol

	dec di
	mov byte ptr [di], 0h
	inc di
	
	skipMinusRemoveEndSymbol:

	; ;check \n
	cmp dl, 0ah  ; \n
	jne	skipNewRowAddSymbol
	inc rowNumber
	mov wordNumber, -1
	skipNewRowAddSymbol:
	
	cmp hasNewWordFlag, 1
	je skipBadNewFlagSymbol

	mov isCurrWordGoodFlag, 0
	jmp skipIncWordNumberSymbol
	skipBadNewFlagSymbol:

	jne skipIncWordNumberSymbol

	cmp currentSymbol, 2Dh
	jne continueAsNormalIncrement
	
	cmp dl, 2Eh ; .
	je dontAddNormalIncrement
	cmp dl ,21h ; !
	je dontAddNormalIncrement
	cmp dl ,3Fh ; ?
	je dontAddNormalIncrement
	cmp dl ,2Ch ; ,
	je dontAddNormalIncrement
	
	continueAsNormalIncrement:
	inc wordNumber
	dontAddNormalIncrement:
	
	cmp currentSymbol, 2Dh
	je skipIncWordNumberSymbol
	mov hasNewWordFlag, 0		
	skipIncWordNumberSymbol:


	cmp isCurrWordGoodFlag, 1
	je continueSpacesSymbol

	mov isCurrWordGoodFlag, 1
	jmp wordSymbolReset

	continueSpacesSymbol:

	jmp foundWordSymbol

checkForEndOfSymbolFind:
	cmp BYTE PTR [si], 0 	
	jne findWordSymbols


	cmp areAnySymbolsFoundFlag, 1
	je logicLoop


	mov ah, 03h
	int 10h
	dec dh
	mov ah, 02h
	int 10h
	mov ah, 09h
	mov dx, offset noSymbolsAreFoundMsg
	int 21h
	mov ah, 02h
	mov dl, currentSymbol
	int 21h
	mov ah, 02h
	mov dl, 10
	int 21h
	mov ah, 02h
	mov dl, 13
	int 21h


		

	jmp logicLoop

; ! end of search for symbols



startFindWords:

	mov anyWordsFoundFlag, 0
	mov wordNumber, -1

	cmp IsGoodWordFlag, 1 
	je continueFindingWords

	;else bad word 
	mov ah, 09h
	mov dx, offset invalidSearchWord
	int 21h
	jmp logicLoop

	continueFindingWords:

	;load text and words
	mov si, offset buf
	mov di, offset readWordBuf
	; reset counters
	mov wordNumber, 0
	mov hasNewWordFlag,0
	mov rowNumber, 1
	
	mov isCurrWordGoodFlag, 1
	;show info about collums
	mov ah, 09h
	mov dx, offset findedWordTable
	int 21h

findWords:

	;read one word
	mov dl, [si] ; text
	mov dh, [di] ; word
	;move one step 
	inc si
	inc di


	; if end of word is found
	cmp dl, 32  ; " "
	je newSpaceFound
	cmp dl, 0ah  ; \n
	je newSpaceFound
	cmp dl, 2Eh ; .
	je newSpaceFound

	cmp dh ,2Dh
	je skipall
	cmp dl ,2Dh ; -
	je newSpaceFound
	cmp dl ,21h ; !
	je newSpaceFound
	cmp dl ,3Fh ; ?
	je newSpaceFound
	cmp dl ,2Ch ; ,
	je newSpaceFound

	;check \n
	skipall:


	mov hasNewWordFlag, 1 
	; if symbols are not the same
	cmp dl, dh
	je wordIsNotBad

	mov isCurrWordGoodFlag, 0
	jmp wordreset
 	
	wordIsNotBad:


	jmp checkForEndOfFind

wordreset:	
	mov di, offset readWordBuf
	jmp checkForEndOfFind

foundWord:
; setup calculate
	mov anyWordsFoundFlag, 1
	mov ah, 0
	mov al, rowNumber
	
	mov bl, 10
	
	;do cal
	xor dx, dx

	xor ah,ah
	div bl
	mov dl ,ah
	push dx

	xor ah,ah
	div bl
	mov dl ,ah
	push dx
	
	xor ah,ah
	div bl
	mov dl ,ah
	push dx

	; max 3 becuase 500 cannot have more than ~ 166 sentences

	
	; display
	mov ah, 02h
	xor dx,dx
	pop dx
	add dl,30h
	int 21h

	xor dx,dx
	pop dx
	add dl,30h
	int 21h

	xor dx,dx
	pop dx
	add dl,30h
	int 21h

	mov dl, 32 ; " " <- this symbol
	int 21h
	mov dl, 124 ; | <- this symbol
	int 21h
	mov dl, 32 ; " " <- this symbol
	int 21h





	mov ah, 0
	mov al, wordNumber
	
	mov bl, 10
	
	;do cal
	xor dx, dx

	xor ah,ah
	div bl
	mov dl ,ah
	push dx

	xor ah,ah
	div bl
	mov dl ,ah
	push dx
	
	xor ah,ah
	div bl
	mov dl ,ah
	push dx

	; max 3 becuase 500 cannot have more than ~ 166 sentences

	
	; display
	mov ah, 02h
	xor dx,dx
	pop dx
	add dl,30h
	int 21h

	xor dx,dx
	pop dx
	add dl,30h
	int 21h

	xor dx,dx
	pop dx
	add dl,30h
	int 21h





	mov dl, 0ah ; print new line
	int 21h
	mov dl, 0dh ; carage return
	int 21h

	jmp wordreset

newSpaceFound:
	
	cmp dl, 0ah
	jne	skipNewRowAdd
	mov wordNumber, -1
	inc rowNumber
	skipNewRowAdd:

	cmp hasNewWordFlag, 1
	je skipBadNewFlag

	badNewFlag:
	mov isCurrWordGoodFlag, 0
	jmp skipIncWordNumber
	skipBadNewFlag:

	jne skipIncWordNumber
	inc wordNumber
	mov hasNewWordFlag, 0		
	skipIncWordNumber:


	cmp isCurrWordGoodFlag, 1
	je continueSpaces

	mov isCurrWordGoodFlag, 1
	jmp wordreset

	continueSpaces:

	cmp BYTE PTR[di-1],0
	jne wordreset

	cmp BYTE PTR [di], 0 
	je foundWord
	jne wordreset	

checkForEndOfFind:
	cmp BYTE PTR [si], 0 	
	jne findWords


	cmp anyWordsFoundFlag, 1
	je logicLoop


	mov ah, 03h
	int 10h
	dec dh
	mov ah, 02h
	int 10h
	mov ah, 09h
	mov dx, offset noWordFoundMsg
	int 21h

		

	jmp logicLoop




startCountingSentences:
	mov SI, offset buf
	mov sentencesCount, 0
countSentences:
	mov dl, [SI]
	inc SI

	; 2Eh ; .
	; 2Dh ; -
	; 21h ; !
	; 3Fh ; ?
	; 2Ch ; ,

	cmp dl, 2Eh ; .
	je addToCount 
	cmp dl, 21h ; !
	je addToCount 
	cmp dl, 3Fh ; ?
	je addToCount 

	mov foundedASymbolDuringSearch, 1
	jmp skipAdding
addToCount:

	cmp foundedASymbolDuringSearch, 0
	je skipAdding
 	mov foundedASymbolDuringSearch, 0
	inc sentencesCount
skipAdding:

	
	cmp BYTE PTR [SI], 0  ;CMP [SI], 0	
	jne countSentences

	; display data
	mov ah, 09h
	mov dx, offset currCountSentencesMsg
	int 21h

	; calculate 


	; setup calculate
	mov ah, 0
	mov al, sentencesCount
	
	mov bl, 10
	
	;do cal
	xor dx, dx

	xor ah,ah
	div bl
	mov dl ,ah
	push dx

	xor ah,ah
	div bl
	mov dl ,ah
	push dx
	
	xor ah,ah
	div bl
	mov dl ,ah
	push dx

	; max 3 becuase 500 cannot have more than ~ 166 sentences

	
	; display
	mov ah, 02h
	xor dx,dx
	pop dx
	add dl,30h
	int 21h

	xor dx,dx
	pop dx
	add dl,30h
	int 21h

	xor dx,dx
	pop dx
	add dl,30h
	int 21h

	mov dl, 0ah ; print new line
	int 21h
	mov dl, 0dh ; carage return
	int 21h


	jmp logicLoop



startSearch:

	mov ah, 09h
	mov dx, offset WordSelectMsg
	int 21h
	
	; read chars
	mov cx, 250
 	mov IsGoodWordFlag, 1

	; makes buffers 0s or else it will override old data without cleaning
clearReadBuffer:
	mov bx, 250
	sub bx, cx
	mov [readWordBuf + bx],0
	loop clearReadBuffer
	
	; setup for read
	mov cx, 250
searchReadChar:
	mov ah, 01h
	int 21h

	cmp al, 13 ; is new line
	je startWritingWord

	cmp al, 08
	jne dontRemoveOneChar

	cmp cx, 250
	je searchReadChar
	;clean one character
	inc cx
	mov bx, 250
	sub bx, cx
	mov [readWordBuf+bx],0
	inc cx

	mov ah, 02h
	mov dl, 32
	int 21h
	mov dl, 8
	int 21h

	;continue as normal
	loop searchReadChar

dontRemoveOneChar:

	;save to buffer
	mov bx, 250
	sub bx, cx
	mov [readWordBuf + bx],al
	
	loop searchReadChar

startWritingWord:

	; check if word is null
	cmp cx, 250
	je wordIsBadInSomeWay
	
	mov cx, 250
	mov di, offset readWordBuf
	loopAndCheckWord:
	cmp BYTE PTR [di], 0
	je doneWord
	
	cmp BYTE PTR [di], 32 ; has space
	je wordIsBadInSomeWay

	inc di 
	loop loopAndCheckWord


	wordIsBadInSomeWay:
	mov IsGoodWordFlag, 0 
	mov ah, 09h
	mov dx, offset invalidSearchWord
	int 21h
	

doneWord:
	xor cx,cx
	jmp logicLoop

startPrint:
	; mov SI, ds
	mov SI, offset buf
	mov ah,02h
print:


	; ! current search word is bad
	; ! to be removed
; 	cmp IsGoodWordFlag, 0
; 	jne wordIsGood
; 	mov ah, 09h
; 	mov dx, offset invalidSearchWord
; 	int 21h
; 	jmp logicLoop

; wordIsGood:	

	mov dl, [SI]
	int 21h

	inc SI

	cmp dl, 0ah
	jne skipCR ; skip carage return
	mov dl, 0dh
	int 21h
skipCR:
	
	cmp BYTE PTR [si], 0 
	jne print

	mov dl, 0ah ; print new line
	int 21h
	mov dl, 0dh ; carage return
	int 21h
	
	jmp logicLoop
	



exit:

	mov ah, 09h
	mov dx, offset leavingProgramMsg
	int 21h
	
	mov	ax,4c00h
	int	21h

end	main
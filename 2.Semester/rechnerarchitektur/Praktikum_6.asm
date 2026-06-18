ORG 0x7C00
BITS 16
_start:

cli 
xor ax, ax
mov ds, ax
mov es, ax
mov ss, ax
mov sp, 0x7C00
sti
cld 
call _testVGA

mov si, titel
call _printText

call _newLine

call _wait5Seconds

mov si, name
call _printText

call _newLine

call _printTime

call _shutdownTimer



jmp $
; ggf hier Daten definieren.
_data: 

_printText:
lodsb
cmp al, 0
je _end

mov ah, 0Eh      
int 10h

jmp _printText

_end:
ret

_wait5Seconds:
mov ah, 86h
mov cx, 004Ch
mov dx, 4B40h
int 15h
ret

_newLine:
mov al, 13
mov ah, 0Eh
int 10h

mov al, 10
mov ah, 0Eh
int 10h

ret

_printChar:
mov ah, 0Eh
int 10h
ret

_printKomma:
xor al, al
mov al, ':'
mov ah, 0Eh
int 10h
ret

_printTime:

mov ah, 02h
int 1Ah

mov si, date
call _printText

mov al, ch
add al, 2 
daa       

cmp al, 24h 
jb _passt
sub al, 24h 

_passt:
mov bl, al

xor ax, ax
mov ah, bl
shr ah, 4
add ah, '0'
mov al, ah
call _printChar

xor ax, ax 
mov al, bl
shl al, 4
shr al, 4

add al, '0'
call _printChar

call _printKomma


xor ax, ax
mov ah, cl
shr ah, 4
add ah, '0'
mov al, ah
call _printChar

xor ax, ax 
mov al, cl
shl al, 4
shr al, 4
add al, '0'
call _printChar

call _printKomma

xor ax, ax
mov ah, dh
shr ah, 4
add ah, '0'
mov al, ah
call _printChar

xor ax, ax 
mov al, dh
shl al, 4
shr al, 4
add al, '0'
call _printChar

_shutdownTimer:
mov byte [counter], 10
_loop:
call _newLine
mov al, [counter]
cmp al, 10
jne _singleDigit

mov al, '1'
call _printChar
mov al, '0'
call _printChar
jmp _jumpSingle
_singleDigit:
add al, '0'
call _printChar
_jumpSingle:
dec byte [counter]
mov ah, 86h
mov cx, 000Fh
mov dx, 4240h
int 15h
mov al, [counter]
cmp al, 0
je _shutdown 
jmp _loop

_testVGA:
mov ax, 0B800h
mov es, ax

xor di, di        

mov ax, 1F20h      

mov cx, 2000 

_clearLoop:
stosw               
loop _clearLoop

ret 
    

_shutdown:
mov ax, 5307h
mov bx, 0001h
mov cx, 0003h
int 15h
ret 











titel db "Mein Erster Bootloader", 0
name  db "Leon Heilmann", 0
date db "Uhrzeit: ", 0
counter db 10
times 510-($ - $$) db 0 ; Auffüllen auf 510 Bytes
dw 0xAA55 
section .text
    global _quadrat_test

_quadrat_test:
    push ebx
    mov ecx, [esp + 8]
    xor eax, eax

    cmp ecx, 0
    jle .fertig
    mov ebx, 1

.schleife:
    mov edx, ebx
    shl edx, 1
    sub edx, 1
    add eax, edx
    inc ebx
    loop .schleife

.fertig:
    shr eax, 1
    pop ebx
    ret
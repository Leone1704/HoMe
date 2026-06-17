.file   "Praktikum_5.c"
.text
.globl  addc
.def    addc;   .scl    2;  .type   32; .endef
.seh_proc addc

addc:
    pushq   %rbp
    .seh_pushreg   %rbp

    movq    %rsp, %rbp
    .seh_setframe  %rbp, 0

    subq    $16, %rsp
    .seh_stackalloc 16
    .seh_endprologue

    # Parameter sichern:
    # 1. Parameter a kommt in Windows x64 in %ecx
    movl    %ecx, 16(%rbp)

    # 2. Parameter b kommt in Windows x64 in %edx
    movl    %edx, 24(%rbp)

    # edx = a
    movl    16(%rbp), %edx

    # eax = b
    movl    24(%rbp), %eax

    # eax = eax + edx
    # also: eax = b + a
    addl    %edx, %eax

    # c = a + b
    movl    %eax, -4(%rbp)

    # if-Bedingung:
    # vergleiche a mit 10
    cmpl    $10, 16(%rbp)

    # wenn a <= 10, springe zum else-Block
    jle     .L2

    # then-Block:
    # c = c + 1
    addl    $1, -4(%rbp)

    # springe ans Ende der if/else-Struktur
    jmp     .L3

.L2:
    # else-Block:
    # c = c - 1
    subl    $1, -4(%rbp)

.L3:
    # return c;
    # Rueckgabewert wird in eax gelegt
    movl    -4(%rbp), %eax

    # Stack wieder abbauen
    addq    $16, %rsp
    popq    %rbp
    ret

.seh_endproc
.ident  "GCC: (Rev8, Built by MSYS2 project) 15.2.0"
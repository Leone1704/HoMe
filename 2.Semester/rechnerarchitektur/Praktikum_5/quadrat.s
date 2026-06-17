 .text
    .globl quadrat

quadrat:
   
    xorl %eax, %eax

   
    
    cmpl $0, %ecx
    jle .fertig
    movl $1, %r8d

.schleife:
   
    movl %r8d, %edx
    shll $1, %edx

    # edx = 2 * i - 1
    subl $1, %edx

    
    addl %edx, %eax

    # i++
    incl %r8d


    loop .schleife

.fertig:
    ret
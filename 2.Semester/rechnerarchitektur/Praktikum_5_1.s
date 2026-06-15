	.file	"Praktikum_5.c"
	.text
	.globl	addc
	.def	addc;	.scl	2;	.type	32;	.endef
	.seh_proc	addc
addc:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	16(%rbp), %edx
	movl	24(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, -4(%rbp)
	cmpl	$10, 16(%rbp)
	jle	.L2
	addl	$1, -4(%rbp)
	jmp	.L3
.L2:
	subl	$1, -4(%rbp)
.L3:
	movl	-4(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (Rev8, Built by MSYS2 project) 15.2.0"

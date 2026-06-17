	.file	"Praktikum_5_3.c"
	.text
	.globl	func
	.def	func;	.scl	2;	.type	32;	.endef
	.seh_proc	func
func:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L2
.L3:
	movl	16(%rbp), %eax
	andl	$1, %eax
	addl	%eax, -4(%rbp)
	shrl	16(%rbp)  # bit verschiebung
.L2:
	cmpl	$0, 16(%rbp)
	jne	.L3
	movl	-4(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (Rev8, Built by MSYS2 project) 15.2.0"

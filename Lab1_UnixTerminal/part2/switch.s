	.file	"switch.c"
	.section	.rodata
.LC0:
	.string	"number is 1! \n"
.LC1:
	.string	"number is 2! \n"
.LC2:
	.string	"number is 3! \n"
.LC3:
	.string	"It messed up... \n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$2, -4(%rbp)
	movl	-4(%rbp), %eax
	cmpl	$2, %eax
	je	.L3
	cmpl	$3, %eax
	je	.L4
	cmpl	$1, %eax
	jne	.L8
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	jmp	.L6
.L3:
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	jmp	.L6
.L4:
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	jmp	.L6
.L8:
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
.L6:
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-39)"
	.section	.note.GNU-stack,"",@progbits

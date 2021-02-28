	.file	"goto.c"
	.section	.rodata
.LC0:
	.string	"yes \n"
.LC1:
	.string	"no \n"
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
	movl	$1, -4(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L2
	nop
.L3:
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	jmp	.L4
.L2:
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movl	$1, %eax
.L4:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-39)"
	.section	.note.GNU-stack,"",@progbits

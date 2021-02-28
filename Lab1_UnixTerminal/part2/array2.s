	.file	"array2.c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$1600, %edi
	call	malloc
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	addq	$4, %rax
	movl	$2, (%rax)
	movq	-8(%rbp), %rax
	addq	$12, %rax
	movl	$6, (%rax)
	movq	-8(%rbp), %rax
	addq	$400, %rax
	movl	$200, (%rax)
	movq	-8(%rbp), %rax
	addq	$804, %rax
	movl	$199, (%rax)
	movq	-8(%rbp), %rax
	addq	$1200, %rax
	movl	$333, (%rax)
	movq	-8(%rbp), %rax
	addq	$1596, %rax
	movl	$999, (%rax)
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-39)"
	.section	.note.GNU-stack,"",@progbits

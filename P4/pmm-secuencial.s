	.file	"ej1a1.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC1:
	.string	"Tiempo sin optimizar: %11.9f\t"
.LC2:
	.string	"Resultado[0] %d\n"
.LC3:
	.string	"Resultado[39999] %d\n"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB4:
	.section	.text.startup,"ax",@progbits
.LHOTB4:
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB39:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$s+40000, %ebx
	subq	$160048, %rsp
	.cfi_def_cfa_offset 160064
	movq	%fs:40, %rax
	movq	%rax, 160040(%rsp)
	xorl	%eax, %eax
	movl	$s, %eax
	.p2align 4,,10
	.p2align 3
.L2:
	movl	$0, (%rax)
	movl	$0, 4(%rax)
	addq	$8, %rax
	cmpq	$s+40000, %rax
	jne	.L2
	movq	%rsp, %rsi
	xorl	%edi, %edi
	call	clock_gettime
	xorl	%r8d, %r8d
	.p2align 4,,10
	.p2align 3
.L3:
	movl	%r8d, %edi
	movl	$s, %eax
	xorl	%esi, %esi
	.p2align 4,,10
	.p2align 3
.L4:
	movl	(%rax), %edx
	addq	$8, %rax
	leal	(%rdi,%rdx,2), %edx
	addl	%edx, %esi
	cmpq	%rax, %rbx
	jne	.L4
	movl	$s+4, %eax
	xorl	%ecx, %ecx
	.p2align 4,,10
	.p2align 3
.L5:
	movl	(%rax), %edx
	addq	$8, %rax
	leal	(%rdx,%rdx,2), %edx
	subl	%edi, %edx
	addl	%edx, %ecx
	cmpq	$s+40004, %rax
	jne	.L5
	cmpl	%esi, %ecx
	cmovg	%esi, %ecx
	movl	%ecx, 32(%rsp,%r8,4)
	addq	$1, %r8
	cmpq	$40000, %r8
	jne	.L3
	leaq	16(%rsp), %rsi
	xorl	%edi, %edi
	call	clock_gettime
	movq	16(%rsp), %rax
	subq	(%rsp), %rax
	movl	$.LC1, %esi
	pxor	%xmm1, %xmm1
	movl	$1, %edi
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rax, %xmm1
	movq	24(%rsp), %rax
	subq	8(%rsp), %rax
	cvtsi2sdq	%rax, %xmm0
	movl	$1, %eax
	divsd	.LC0(%rip), %xmm0
	addsd	%xmm1, %xmm0
	call	__printf_chk
	movl	$10, %edi
	call	putchar
	movl	32(%rsp), %edx
	movl	$.LC2, %esi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk
	movl	160028(%rsp), %edx
	xorl	%eax, %eax
	movl	$.LC3, %esi
	movl	$1, %edi
	call	__printf_chk
	movq	160040(%rsp), %rbx
	xorq	%fs:40, %rbx
	jne	.L15
	addq	$160048, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
.L15:
	.cfi_restore_state
	call	__stack_chk_fail
	.cfi_endproc
.LFE39:
	.size	main, .-main
	.section	.text.unlikely
.LCOLDE4:
	.section	.text.startup
.LHOTE4:
	.comm	s,40000,64
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC0:
	.long	0
	.long	1104006501
	.ident	"GCC: (Ubuntu 4.9.2-10ubuntu13) 4.9.2"
	.section	.note.GNU-stack,"",@progbits

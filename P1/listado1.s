	.file	"listado1.c"
	.section	.rodata
	.align 8
.LC0:
	.string	"Faltan n\302\272 componentes del vector"
	.align 8
.LC1:
	.string	"Error en la reserva de espacio para los vectores"
	.align 8
.LC4:
	.string	"Tiempo(seg.):%11.9f\t / Tama\303\261o Vectores:%u\t/ V1[0]+V2[0]=V3[0](%8.6f+%8.6f=%8.6f) / /\tV1[%d]+V2[%d]=V3[%d](%8.6f+%8.6f=%8.6f) /\n"
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
	pushq	%r12
	pushq	%rbx
	addq	$-128, %rsp
	.cfi_offset 12, -24
	.cfi_offset 3, -32
	movl	%edi, -116(%rbp)
	movq	%rsi, -128(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	cmpl	$1, -116(%rbp)
	jg	.L2
	movl	$.LC0, %edi
	call	puts
	movl	$-1, %edi
	call	exit
.L2:
	movq	-128(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	atoi
	movl	%eax, -100(%rbp)
	movl	-100(%rbp), %eax
	salq	$3, %rax
	movq	%rax, %rdi
	call	malloc
	movq	%rax, -96(%rbp)
	movl	-100(%rbp), %eax
	salq	$3, %rax
	movq	%rax, %rdi
	call	malloc
	movq	%rax, -88(%rbp)
	movl	-100(%rbp), %eax
	salq	$3, %rax
	movq	%rax, %rdi
	call	malloc
	movq	%rax, -80(%rbp)
	cmpq	$0, -96(%rbp)
	je	.L3
	cmpq	$0, -88(%rbp)
	je	.L3
	cmpq	$0, -80(%rbp)
	jne	.L4
.L3:
	movl	$.LC1, %edi
	call	puts
	movl	$-2, %edi
	call	exit
.L4:
	movl	$0, -104(%rbp)
	jmp	.L5
.L10:
	movl	-104(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-96(%rbp), %rax
	leaq	(%rdx,%rax), %rcx
	movl	-100(%rbp), %eax
	testq	%rax, %rax
	js	.L6
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rax, %xmm0
	jmp	.L7
.L6:
	movq	%rax, %rdx
	shrq	%rdx
	andl	$1, %eax
	orq	%rax, %rdx
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rdx, %xmm0
	addsd	%xmm0, %xmm0
.L7:
	movsd	.LC2(%rip), %xmm1
	mulsd	%xmm0, %xmm1
	pxor	%xmm0, %xmm0
	cvtsi2sd	-104(%rbp), %xmm0
	movsd	.LC2(%rip), %xmm2
	mulsd	%xmm2, %xmm0
	addsd	%xmm0, %xmm1
	movq	%xmm1, %rax
	movq	%rax, (%rcx)
	movl	-104(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-88(%rbp), %rax
	leaq	(%rdx,%rax), %rcx
	movl	-100(%rbp), %eax
	testq	%rax, %rax
	js	.L8
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rax, %xmm0
	jmp	.L9
.L8:
	movq	%rax, %rdx
	shrq	%rdx
	andl	$1, %eax
	orq	%rax, %rdx
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rdx, %xmm0
	addsd	%xmm0, %xmm0
.L9:
	movsd	.LC2(%rip), %xmm1
	mulsd	%xmm1, %xmm0
	pxor	%xmm1, %xmm1
	cvtsi2sd	-104(%rbp), %xmm1
	movsd	.LC2(%rip), %xmm2
	mulsd	%xmm2, %xmm1
	subsd	%xmm1, %xmm0
	movq	%xmm0, %rax
	movq	%rax, (%rcx)
	addl	$1, -104(%rbp)
.L5:
	movl	-104(%rbp), %eax
	cmpl	-100(%rbp), %eax
	jb	.L10
	leaq	-64(%rbp), %rax
	movq	%rax, %rsi
	movl	$0, %edi
	call	clock_gettime
	movl	$0, -104(%rbp)
	jmp	.L11
.L12:
	movl	-104(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-80(%rbp), %rax
	addq	%rax, %rdx
	movl	-104(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rcx
	movq	-96(%rbp), %rax
	addq	%rcx, %rax
	movsd	(%rax), %xmm1
	movl	-104(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rcx
	movq	-88(%rbp), %rax
	addq	%rcx, %rax
	movsd	(%rax), %xmm0
	addsd	%xmm0, %xmm1
	movq	%xmm1, %rax
	movq	%rax, (%rdx)
	addl	$1, -104(%rbp)
.L11:
	movl	-104(%rbp), %eax
	cmpl	-100(%rbp), %eax
	jb	.L12
	leaq	-48(%rbp), %rax
	movq	%rax, %rsi
	movl	$0, %edi
	call	clock_gettime
	movq	-48(%rbp), %rdx
	movq	-64(%rbp), %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	pxor	%xmm1, %xmm1
	cvtsi2sdq	%rax, %xmm1
	movq	-40(%rbp), %rdx
	movq	-56(%rbp), %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rax, %xmm0
	movsd	.LC3(%rip), %xmm2
	divsd	%xmm2, %xmm0
	addsd	%xmm0, %xmm1
	movq	%xmm1, %rax
	movq	%rax, -72(%rbp)
	movl	-100(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %eax
	leaq	0(,%rax,8), %rdx
	movq	-80(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rbx
	movl	-100(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %eax
	leaq	0(,%rax,8), %rdx
	movq	-88(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %r11
	movl	-100(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %eax
	leaq	0(,%rax,8), %rdx
	movq	-96(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %r8
	movl	-100(%rbp), %eax
	leal	-1(%rax), %r12d
	movl	-100(%rbp), %eax
	leal	-1(%rax), %ecx
	movl	-100(%rbp), %eax
	leal	-1(%rax), %edx
	movq	-80(%rbp), %rax
	movq	(%rax), %r10
	movq	-88(%rbp), %rax
	movq	(%rax), %r9
	movq	-96(%rbp), %rax
	movq	(%rax), %rdi
	movl	-100(%rbp), %esi
	movq	-72(%rbp), %rax
	movq	%rbx, -136(%rbp)
	movsd	-136(%rbp), %xmm6
	movq	%r11, -136(%rbp)
	movsd	-136(%rbp), %xmm5
	movq	%r8, -136(%rbp)
	movsd	-136(%rbp), %xmm4
	movl	%r12d, %r8d
	movq	%r10, -136(%rbp)
	movsd	-136(%rbp), %xmm3
	movq	%r9, -136(%rbp)
	movsd	-136(%rbp), %xmm2
	movq	%rdi, -136(%rbp)
	movsd	-136(%rbp), %xmm1
	movq	%rax, -136(%rbp)
	movsd	-136(%rbp), %xmm0
	movl	$.LC4, %edi
	movl	$7, %eax
	call	printf
	movq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	free
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	free
	movq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	free
	movl	$0, %eax
	movq	-24(%rbp), %rbx
	xorq	%fs:40, %rbx
	je	.L14
	call	__stack_chk_fail
.L14:
	subq	$-128, %rsp
	popq	%rbx
	popq	%r12
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC2:
	.long	2576980378
	.long	1069128089
	.align 8
.LC3:
	.long	0
	.long	1104006501
	.ident	"GCC: (Ubuntu 4.9.2-10ubuntu13) 4.9.2"
	.section	.note.GNU-stack,"",@progbits

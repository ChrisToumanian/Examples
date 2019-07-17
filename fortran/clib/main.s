	.file	"main.f90"
	.text
	.section	.rodata
.LC0:
	.string	"main.f90"
.LC1:
	.ascii	"(A)"
.LC2:
	.ascii	"Fortran calling C"
.LC3:
	.ascii	"(A,I0,A,I0)"
.LC4:
	.ascii	"a="
.LC5:
	.ascii	", b="
.LC6:
	.ascii	"(I0)"
.LC7:
	.ascii	"(F0.0)"
	.text
	.type	MAIN__, @function
MAIN__:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$496, %rsp
	leaq	.LC0(%rip), %rax
	movq	%rax, -488(%rbp)
	movl	$3, -480(%rbp)
	leaq	.LC1(%rip), %rax
	movq	%rax, -424(%rbp)
	movl	$3, -416(%rbp)
	movl	$4096, -496(%rbp)
	movl	$6, -492(%rbp)
	leaq	-496(%rbp), %rax
	movq	%rax, %rdi
	call	_gfortran_st_write@PLT
	leaq	-496(%rbp), %rax
	movl	$17, %edx
	leaq	.LC2(%rip), %rsi
	movq	%rax, %rdi
	call	_gfortran_transfer_character_write@PLT
	leaq	-496(%rbp), %rax
	movq	%rax, %rdi
	call	_gfortran_st_write_done@PLT
	leaq	.LC0(%rip), %rax
	movq	%rax, -488(%rbp)
	movl	$4, -480(%rbp)
	leaq	.LC3(%rip), %rax
	movq	%rax, -424(%rbp)
	movl	$11, -416(%rbp)
	movl	$4096, -496(%rbp)
	movl	$6, -492(%rbp)
	leaq	-496(%rbp), %rax
	movq	%rax, %rdi
	call	_gfortran_st_write@PLT
	leaq	-496(%rbp), %rax
	movl	$2, %edx
	leaq	.LC4(%rip), %rsi
	movq	%rax, %rdi
	call	_gfortran_transfer_character_write@PLT
	leaq	-496(%rbp), %rax
	movl	$4, %edx
	leaq	a.3497(%rip), %rsi
	movq	%rax, %rdi
	call	_gfortran_transfer_integer_write@PLT
	leaq	-496(%rbp), %rax
	movl	$4, %edx
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	_gfortran_transfer_character_write@PLT
	leaq	-496(%rbp), %rax
	movl	$4, %edx
	leaq	b.3498(%rip), %rsi
	movq	%rax, %rdi
	call	_gfortran_transfer_integer_write@PLT
	leaq	-496(%rbp), %rax
	movq	%rax, %rdi
	call	_gfortran_st_write_done@PLT
	leaq	-8(%rbp), %rax
	movq	%rax, %rdx
	leaq	b.3498(%rip), %rsi
	leaq	a.3497(%rip), %rdi
	movl	$0, %eax
	call	add_@PLT
	movl	%eax, -4(%rbp)
	leaq	.LC0(%rip), %rax
	movq	%rax, -488(%rbp)
	movl	$6, -480(%rbp)
	leaq	.LC6(%rip), %rax
	movq	%rax, -424(%rbp)
	movl	$4, -416(%rbp)
	movl	$4096, -496(%rbp)
	movl	$6, -492(%rbp)
	leaq	-496(%rbp), %rax
	movq	%rax, %rdi
	call	_gfortran_st_write@PLT
	leaq	-8(%rbp), %rcx
	leaq	-496(%rbp), %rax
	movl	$4, %edx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_gfortran_transfer_integer_write@PLT
	leaq	-496(%rbp), %rax
	movq	%rax, %rdi
	call	_gfortran_st_write_done@PLT
	leaq	-8(%rbp), %rax
	movq	%rax, %rdx
	leaq	b.3498(%rip), %rsi
	leaq	a.3497(%rip), %rdi
	movl	$0, %eax
	call	subtract_@PLT
	movl	%eax, -4(%rbp)
	leaq	.LC0(%rip), %rax
	movq	%rax, -488(%rbp)
	movl	$8, -480(%rbp)
	leaq	.LC6(%rip), %rax
	movq	%rax, -424(%rbp)
	movl	$4, -416(%rbp)
	movl	$4096, -496(%rbp)
	movl	$6, -492(%rbp)
	leaq	-496(%rbp), %rax
	movq	%rax, %rdi
	call	_gfortran_st_write@PLT
	leaq	-8(%rbp), %rcx
	leaq	-496(%rbp), %rax
	movl	$4, %edx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_gfortran_transfer_integer_write@PLT
	leaq	-496(%rbp), %rax
	movq	%rax, %rdi
	call	_gfortran_st_write_done@PLT
	leaq	b.3498(%rip), %rsi
	leaq	a.3497(%rip), %rdi
	movl	$0, %eax
	call	multiply_@PLT
	movl	%eax, -8(%rbp)
	leaq	.LC0(%rip), %rax
	movq	%rax, -488(%rbp)
	movl	$10, -480(%rbp)
	leaq	.LC6(%rip), %rax
	movq	%rax, -424(%rbp)
	movl	$4, -416(%rbp)
	movl	$4096, -496(%rbp)
	movl	$6, -492(%rbp)
	leaq	-496(%rbp), %rax
	movq	%rax, %rdi
	call	_gfortran_st_write@PLT
	leaq	b.3498(%rip), %rsi
	leaq	a.3497(%rip), %rdi
	movl	$0, %eax
	call	multiply_@PLT
	movl	%eax, -12(%rbp)
	leaq	-12(%rbp), %rcx
	leaq	-496(%rbp), %rax
	movl	$4, %edx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_gfortran_transfer_integer_write@PLT
	leaq	-496(%rbp), %rax
	movq	%rax, %rdi
	call	_gfortran_st_write_done@PLT
	leaq	.LC0(%rip), %rax
	movq	%rax, -488(%rbp)
	movl	$11, -480(%rbp)
	leaq	.LC7(%rip), %rax
	movq	%rax, -424(%rbp)
	movl	$6, -416(%rbp)
	movl	$4096, -496(%rbp)
	movl	$6, -492(%rbp)
	leaq	-496(%rbp), %rax
	movq	%rax, %rdi
	call	_gfortran_st_write@PLT
	leaq	b.3498(%rip), %rsi
	leaq	a.3497(%rip), %rdi
	movl	$0, %eax
	call	divide_@PLT
	movd	%xmm0, %eax
	movl	%eax, -16(%rbp)
	leaq	-16(%rbp), %rcx
	leaq	-496(%rbp), %rax
	movl	$4, %edx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_gfortran_transfer_real_write@PLT
	leaq	-496(%rbp), %rax
	movq	%rax, %rdi
	call	_gfortran_st_write_done@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	MAIN__, .-MAIN__
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rdx
	movl	-4(%rbp), %eax
	movq	%rdx, %rsi
	movl	%eax, %edi
	call	_gfortran_set_args@PLT
	leaq	options.6.3517(%rip), %rsi
	movl	$7, %edi
	call	_gfortran_set_options@PLT
	call	MAIN__
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.data
	.align 4
	.type	a.3497, @object
	.size	a.3497, 4
a.3497:
	.long	5
	.align 4
	.type	b.3498, @object
	.size	b.3498, 4
b.3498:
	.long	2
	.section	.rodata
	.align 16
	.type	options.6.3517, @object
	.size	options.6.3517, 28
options.6.3517:
	.long	68
	.long	1023
	.long	0
	.long	1
	.long	1
	.long	0
	.long	31
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04) 7.4.0"
	.section	.note.GNU-stack,"",@progbits

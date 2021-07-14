	.section	.rodata
	.comm _gp, 4, 4
	.string_const0: .string "enter a: "
	.string_const1: .string "%d"
	.string_const2: .string "%d is not 0\n"
	.string_const3: .string "complete\n"
	.text
	.globl main
	.type main,@function
main:	nop
	pushq %rbp
	movq %rsp, %rbp
	leaq .string_const0(%rip), %rdi
	call printf@PLT
	leaq _gp(%rip), %rbx
	addq $0, %rbx
	leaq .string_const1(%rip), %rdi
	movq %rbx, %rsi
	movl $0, %eax
	call scanf@PLT
	leaq _gp(%rip), %rbx
	addq $0, %rbx
	movl (%rbx), %ecx
	movl $0, %ebx
	cmpl %ebx, %ecx
	movl $0, %ecx
	movl $1, %ebx
	cmovne %ebx, %ecx
	movl $-1, %eax
	testl %eax, %ecx
	je .L0
	leaq _gp(%rip), %rbx
	addq $0, %rbx
	movl (%rbx), %r8d
	leaq .string_const2(%rip), %rdi
	movl %r8d, %esi
	movl $0, %eax
	call printf@PLT
.L0:	nop
	leaq .string_const3(%rip), %rdi
	call printf@PLT
	leave
	ret

	.section	.rodata
	.comm _gp, 16, 4
	.string_const0: .string "10+30 = %d\n"
	.string_const1: .string "result is %d\n"
	.text
	.globl main
	.type main,@function
main:	nop
	pushq %rbp
	movq %rsp, %rbp
	movl $10, %ebx
	movl $30, %ecx
	addl %ecx, %ebx
	leaq .string_const0(%rip), %rdi
	movl %ebx, %esi
	movl $0, %eax
	call printf@PLT
	leaq _gp(%rip), %rbx
	addq $0, %rbx
	movl $1, %ecx
	movl %ecx, (%rbx)
	leaq _gp(%rip), %rbx
	addq $8, %rbx
	movl $3, %ecx
	movl %ecx, (%rbx)
	leaq _gp(%rip), %rbx
	addq $12, %rbx
	movl $4, %ecx
	movl %ecx, (%rbx)
	leaq _gp(%rip), %rbx
	addq $4, %rbx
	leaq _gp(%rip), %rcx
	addq $0, %rcx
	movl (%rcx), %r8d
	leaq _gp(%rip), %rcx
	addq $8, %rcx
	movl (%rcx), %r9d
	addl %r9d, %r8d
	leaq _gp(%rip), %rcx
	addq $12, %rcx
	movl (%rcx), %r9d
	addl %r9d, %r8d
	movl %r8d, (%rbx)
	leaq _gp(%rip), %rbx
	addq $4, %rbx
	movl (%rbx), %ecx
	leaq .string_const1(%rip), %rdi
	movl %ecx, %esi
	movl $0, %eax
	call printf@PLT
	leave
	ret

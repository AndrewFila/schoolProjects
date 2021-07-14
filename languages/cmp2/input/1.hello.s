	.section	.rodata
	.text
	.globl main
	.type main, @function
main:	nop
	pushq %rbp
	movq %rsp, %rbp
	leaq .str_const0(%rip), %rdi
	movl $0, %eax
	call printf@PLT
<StatementList> -> <Statement>
<ProcedureBody> -> <StatementList> <RBR>
<ProcedureDecl> -> <ProcedureHead> <ProcedureBody>
	leave
	ret

	.file	"1.c"
	.text
	.globl	a
	.bss
	.align 4
	.type	a, @object
	.size	a, 4
a:
	.zero	4


    .section	.rodata
    .LC0: .string	"enter a: "
    .LC1: .string	"%d"
    .LC2: .string	"%d is not 0\n"
    .LC3: .string	"complete"
    //start header
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16  //idk no need
	.cfi_offset 6, -16      //idk no need
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6 //idk no need
    //end header



    //start printf("enter a: ")
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	a(%rip), %rsi

    leaq	.LC1(%rip), %rdi    //scanf
	movl	$0, %eax
    call	__isoc99_scanf@PLT
	movl	a(%rip), %eax
    //end scanf

    //start if
	cmp $0, eax         //is a = 0
	je	.L2             //jump to .L2 if true
	movl	a(%rip), %eax
	movl	%eax, %esi


    leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
.L2:
	leaq	.LC3(%rip), %rdi
	call	puts@PLT
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 10.2.0"
	.section	.note.GNU-stack,"",@progbits

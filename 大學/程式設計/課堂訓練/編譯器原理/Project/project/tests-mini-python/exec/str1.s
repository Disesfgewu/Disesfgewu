	.text
str:
	pushq %rbp
	movq %rsp, %rbp
	movq $88, %rdi
	call malloc@PLT
	movq %rax, %r12
	pushq %r12
	movq $10, 0(%r12)
	movq $.LC0, %rdi
	movq %rdi, %rax
	popq %r12
	movq %rax, 8(%r12)
	pushq %r12
	movq $.LC1, %rdi
	movq %rdi, %rax
	popq %r12
	movq %rax, 16(%r12)
	pushq %r12
	movq $.LC2, %rdi
	movq %rdi, %rax
	popq %r12
	movq %rax, 24(%r12)
	pushq %r12
	movq $.LC3, %rdi
	movq %rdi, %rax
	popq %r12
	movq %rax, 32(%r12)
	pushq %r12
	movq $.LC4, %rdi
	movq %rdi, %rax
	popq %r12
	movq %rax, 40(%r12)
	pushq %r12
	movq $.LC5, %rdi
	movq %rdi, %rax
	popq %r12
	movq %rax, 48(%r12)
	pushq %r12
	movq $.LC6, %rdi
	movq %rdi, %rax
	popq %r12
	movq %rax, 56(%r12)
	pushq %r12
	movq $.LC7, %rdi
	movq %rdi, %rax
	popq %r12
	movq %rax, 64(%r12)
	pushq %r12
	movq $.LC8, %rdi
	movq %rdi, %rax
	popq %r12
	movq %rax, 72(%r12)
	pushq %r12
	movq $.LC9, %rdi
	movq %rdi, %rax
	popq %r12
	movq %rax, 80(%r12)
	pushq %r12
	movq %r12, %rax
	popq %r12
	movq %rax, %r15
	movq $10, %rax
	pushq %rax
	movq 16(%rbp), %rax
	popq %rbx
	cmpq %rbx, %rax
	jl .LC10
	movq $0, %rax
	jmp .LC11
.LC10:
	movq $1, %rax
.LC11:
	cmpq $0, %rax
	je .LC12
	movq 16(%rbp), %rax
	movq %rax, %rdx
	imulq $8, %rdx
	addq $8, %rdx
	movq %r15, %r12
	movq %rax, %rsi
	movq 0(%r12,%rdx,1), %rsi
	addq %rdx, %rax
	movq 0(%rsi), %rax
	movq 0(%r12,%rdx,1), %r12
	movq $24, %rdx
	movq 0(%r12,%rdx,1), %rax
	leave
	ret
	jmp .LC13
.LC12:
	movq $10, %rax
	pushq %rax
	movq 16(%rbp), %rax
	popq %rbx
	cqto
	idivq %rbx
	movq %rdx, %rax
	movq %rax, %rdx
	imulq $8, %rdx
	addq $8, %rdx
	movq %r15, %r12
	movq %rax, %rsi
	movq 0(%r12,%rdx,1), %rsi
	addq %rdx, %rax
	movq 0(%rsi), %rax
	movq 0(%r12,%rdx,1), %r12
	movq $24, %rdx
	movq 0(%r12,%rdx,1), %rax
	pushq %rax
	movq $10, %rax
	pushq %rax
	movq 16(%rbp), %rax
	popq %rbx
	cqto
	idivq %rbx
	pushq %rax
	call str
	addq $8, %rsp
	popq %rbx
	movq $10, %rax
	pushq %rax
	movq 16(%rbp), %rax
	popq %rbx
	cqto
	idivq %rbx
	movq %rdx, %rax
	movq %rax, %rdx
	imulq $8, %rdx
	addq $8, %rdx
	movq %r15, %r12
	movq %rax, %rsi
	movq 0(%r12,%rdx,1), %rsi
	addq %rdx, %rax
	movq 0(%rsi), %rax
	movq 0(%r12,%rdx,1), %r12
	movq $24, %rdx
	movq 0(%r12,%rdx,1), %rax
	pushq %rbx
	call strlen
	movq %rax, %r10
	popq %rbx
	movq %rbx, %rax
	pushq %rbx
	call strlen
	addq %r10, %rax
	addq $1, %rax
	movq %rax, %rdi
	call malloc
	movq %rax, %r12
	movq $10, %rax
	pushq %rax
	movq 16(%rbp), %rax
	popq %rbx
	cqto
	idivq %rbx
	movq %rdx, %rax
	movq %rax, %rdx
	imulq $8, %rdx
	addq $8, %rdx
	movq %r15, %r12
	movq %rax, %rsi
	movq 0(%r12,%rdx,1), %rsi
	addq %rdx, %rax
	movq 0(%rsi), %rax
	movq 0(%r12,%rdx,1), %r12
	movq $24, %rdx
	movq 0(%r12,%rdx,1), %rax
	movq %rax, %rsi
	movq %r12, %rdi
	call strcpy
	popq %rbx
	movq %rbx, %rax
	movq %rax, %rsi
	movq %r12, %rdi
	call strcat
	leave
	ret
.LC13:
	movq $0, %rax
	leave
	ret
	.globl	main
main:
	pushq %rbp
	movq %rsp, %rbp
	movq $0, %rax
	pushq %rax
	call str
	addq $8, %rsp
	movq %rax, %rsi
	movq $.LCd, %rdi
	movq $0, %rax
	call printf
	movq $10, %rdi
	call putchar
	movq $42, %rax
	pushq %rax
	call str
	addq $8, %rsp
	movq %rax, %rsi
	movq $.LCd, %rdi
	movq $0, %rax
	call printf
	movq $10, %rdi
	call putchar
	movq $1024, %rax
	pushq %rax
	call str
	addq $8, %rsp
	movq %rax, %rsi
	movq $.LCd, %rdi
	movq $0, %rax
	call printf
	movq $10, %rdi
	call putchar
	movq $0, %rax
	leave
	ret
print_list:
	pushq %r12
	pushq %r14
	pushq %r15
	movq 0(%r12), %r15
	xorq %r14, %r14
print_list_loop:
	cmpq %r14, %r15
	je print_list_end
	movq %r14, %rdx
	imulq $8, %rdx
	addq $8, %rdx
	leaq 0(%r12,%rdx,1), %rsi
	movq 0(%rsi), %rax
	movq %rax, %rsi
	movq $.LCd, %rdi
	call printf
	addq $1, %r14
	cmpq %r14, %r15
	je print_list_end
	movq $.LCcomma, %rdi
	call printf
	jmp print_list_loop
print_list_end:
	movq $.LCend, %rdi
	call printf
	movq $10, %rdi
	call putchar
	movq $0, %rax
	popq %r15
	popq %r14
	popq %r12
	ret
runtime_error:
	movq $.LCerror, %rdi
	call puts
	movq $1, %rdi
	call exit
	ret
	.data
.LCtrue:
	.string "True"
.LCfalse:
	.string "False"
.LCcomma:
	.string ", "
.LCstart:
	.string "["
.LCend:
	.string "]"
.LCs:
	.string "%s"
.LCd:
	.string "%d"
.LCnone:
	.string "None"
.LCerror:
	.string "Runtime Error"
.LC7:
	.string "7"
.LC2:
	.string "2"
.LC1:
	.string "1"
.LC0:
	.string "0"
.LC6:
	.string "6"
.LC4:
	.string "4"
.LC5:
	.string "5"
.LC9:
	.string "9"
.LC8:
	.string "8"
.LC3:
	.string "3"

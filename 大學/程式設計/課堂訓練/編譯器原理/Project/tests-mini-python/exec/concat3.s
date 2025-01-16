	.text
f:
	pushq %rbp
	movq %rsp, %rbp
	movq 24(%rbp), %rax
	pushq %rax
	movq 16(%rbp), %rax
	popq %rbx
	cmpq %rbx, %rax
	jge .LC0
	movq $0, %rax
	jmp .LC1
.LC0:
	movq $1, %rax
.LC1:
	cmpq $0, %rax
	je .LC2
	movq $8, %rdi
	call malloc@PLT
	movq %rax, %r12
	pushq %r12
	movq $0, 0(%r12)
	movq %r12, %rax
	popq %r12
	leave
	ret
	jmp .LC3
.LC2:
.LC3:
	movq 24(%rbp), %rax
	pushq %rax
	movq $1, %rax
	pushq %rax
	movq 16(%rbp), %rax
	popq %rbx
	addq %rbx, %rax
	pushq %rax
	call f
	addq $16, %rsp
	pushq %rax
	movq $16, %rdi
	call malloc@PLT
	movq %rax, %r12
	pushq %r12
	movq $1, 0(%r12)
	movq 16(%rbp), %rax
	popq %r12
	movq %rax, 8(%r12)
	pushq %r12
	movq %r12, %rax
	popq %r12
	popq %rbx
	addq %rbx, %rax
	leave
	ret
	movq $0, %rax
	leave
	ret
	.globl	main
main:
	pushq %rbp
	movq %rsp, %rbp
	movq $8, %rdi
	call malloc@PLT
	movq %rax, %r12
	pushq %r12
	movq $0, 0(%r12)
	movq %r12, %rax
	popq %r12
	pushq %rax
	movq $8, %rdi
	call malloc@PLT
	movq %rax, %r12
	pushq %r12
	movq $0, 0(%r12)
	movq %r12, %rax
	popq %r12
	popq %rbx
	addq %rbx, %rax
	movq %rax, %rsi
	movq $.LCd, %rdi
	movq $0, %rax
	call printf
	movq $10, %rdi
	call putchar
	movq $32, %rdi
	call malloc@PLT
	movq %rax, %r12
	pushq %r12
	movq $3, 0(%r12)
	movq $3, %rax
	popq %r12
	movq %rax, 8(%r12)
	pushq %r12
	movq $4, %rax
	popq %r12
	movq %rax, 16(%r12)
	pushq %r12
	movq $5, %rax
	popq %r12
	movq %rax, 24(%r12)
	pushq %r12
	movq %r12, %rax
	popq %r12
	pushq %rax
	movq $24, %rdi
	call malloc@PLT
	movq %rax, %r12
	pushq %r12
	movq $2, 0(%r12)
	movq $1, %rax
	popq %r12
	movq %rax, 8(%r12)
	pushq %r12
	movq $2, %rax
	popq %r12
	movq %rax, 16(%r12)
	pushq %r12
	movq %r12, %rax
	popq %r12
	popq %rbx
	addq %rbx, %rax
	movq %rax, %rsi
	movq $.LCd, %rdi
	movq $0, %rax
	call printf
	movq $10, %rdi
	call putchar
	movq $7, %rax
	pushq %rax
	movq $4, %rax
	pushq %rax
	call f
	addq $16, %rsp
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

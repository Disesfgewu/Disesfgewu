	.text
	.globl	main
main:
	pushq %rbp
	movq %rsp, %rbp
	movq $.LC1, %rdi
	movq %rdi, %rax
	pushq %rax
	movq $.LC0, %rdi
	movq %rdi, %rax
	popq %rbx
	movq $.LC0, %rdi
	movq %rdi, %rax
	call strlen
	movq %rax, %r10
	movq $.LC1, %rdi
	movq %rdi, %rax
	call strlen
	addq %r10, %rax
	addq $1, %rax
	movq %rax, %rdi
	call malloc
	movq %rax, %r12
	movq $.LC0, %rdi
	movq %rdi, %rax
	movq %rax, %rsi
	movq %r12, %rdi
	call strcpy
	movq $.LC1, %rdi
	movq %rdi, %rax
	movq %rax, %rsi
	movq %r12, %rdi
	call strcat
	movq %rax, %rsi
	movq $.LCs, %rdi
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
.LC1:
	.string "bar"
.LC0:
	.string "foo"

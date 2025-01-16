	.text
	.globl	main
main:
	pushq %rbp
	movq %rsp, %rbp
	movq $.LC0, %rdi
	movq %rdi, %rax
	pushq %rax
	movq $.LC0, %rdi
	movq %rdi, %rax
	popq %rbx
	movq $.LC0, %rdi
	movq %rdi, %rax
	movq %rdi, %rcx
	movq $.LC0, %rdi
	movq %rdi, %rax
	movq %rdi, %rsi
	movq %rcx, %rdi
	call strcmp
	cmpq $0, %rax
	je .LC1
	movq $0, %rax
	jmp .LC2
.LC1:
	movq $1, %rax
.LC2:
	cmpq $1, %rax
	jne .LC3
	movq $.LCtrue, %rdi
	jmp .LC4
.LC3:
	movq $.LCfalse, %rdi
.LC4:
	movq %rax, %rsi
	movq $.LCs, %rdx
	movq $0, %rax
	call printf
	movq $10, %rdi
	call putchar
	movq $.LC5, %rdi
	movq %rdi, %rax
	pushq %rax
	movq $.LC0, %rdi
	movq %rdi, %rax
	popq %rbx
	movq $.LC0, %rdi
	movq %rdi, %rax
	movq %rdi, %rcx
	movq $.LC5, %rdi
	movq %rdi, %rax
	movq %rdi, %rsi
	movq %rcx, %rdi
	call strcmp
	cmpq $0, %rax
	jg .LC6
	movq $0, %rax
	jmp .LC7
.LC6:
	movq $1, %rax
.LC7:
	cmpq $1, %rax
	jne .LC8
	movq $.LCtrue, %rdi
	jmp .LC9
.LC8:
	movq $.LCfalse, %rdi
.LC9:
	movq %rax, %rsi
	movq $.LCs, %rdx
	movq $0, %rax
	call printf
	movq $10, %rdi
	call putchar
	movq $.LC11, %rdi
	movq %rdi, %rax
	pushq %rax
	movq $.LC10, %rdi
	movq %rdi, %rax
	popq %rbx
	movq $.LC10, %rdi
	movq %rdi, %rax
	movq %rdi, %rcx
	movq $.LC11, %rdi
	movq %rdi, %rax
	movq %rdi, %rsi
	movq %rcx, %rdi
	call strcmp
	cmpq $0, %rax
	jg .LC12
	movq $0, %rax
	jmp .LC13
.LC12:
	movq $1, %rax
.LC13:
	cmpq $1, %rax
	jne .LC14
	movq $.LCtrue, %rdi
	jmp .LC15
.LC14:
	movq $.LCfalse, %rdi
.LC15:
	movq %rax, %rsi
	movq $.LCs, %rdx
	movq $0, %rax
	call printf
	movq $10, %rdi
	call putchar
	movq $.LC16, %rdi
	movq %rdi, %rax
	pushq %rax
	movq $.LC16, %rdi
	movq %rdi, %rax
	popq %rbx
	movq $.LC16, %rdi
	movq %rdi, %rax
	movq %rdi, %rcx
	movq $.LC16, %rdi
	movq %rdi, %rax
	movq %rdi, %rsi
	movq %rcx, %rdi
	call strcmp
	cmpq $0, %rax
	jge .LC17
	movq $0, %rax
	jmp .LC18
.LC17:
	movq $1, %rax
.LC18:
	cmpq $1, %rax
	jne .LC19
	movq $.LCtrue, %rdi
	jmp .LC20
.LC19:
	movq $.LCfalse, %rdi
.LC20:
	movq %rax, %rsi
	movq $.LCs, %rdx
	movq $0, %rax
	call printf
	movq $10, %rdi
	call putchar
	movq $.LC5, %rdi
	movq %rdi, %rax
	pushq %rax
	movq $.LC0, %rdi
	movq %rdi, %rax
	popq %rbx
	movq $.LC0, %rdi
	movq %rdi, %rax
	movq %rdi, %rcx
	movq $.LC5, %rdi
	movq %rdi, %rax
	movq %rdi, %rsi
	movq %rcx, %rdi
	call strcmp
	cmpq $0, %rax
	jne .LC21
	movq $0, %rax
	jmp .LC22
.LC21:
	movq $1, %rax
.LC22:
	cmpq $1, %rax
	jne .LC23
	movq $.LCtrue, %rdi
	jmp .LC24
.LC23:
	movq $.LCfalse, %rdi
.LC24:
	movq %rax, %rsi
	movq $.LCs, %rdx
	movq $0, %rax
	call printf
	movq $10, %rdi
	call putchar
	movq $.LC25, %rdi
	movq %rdi, %rax
	pushq %rax
	movq $.LC25, %rdi
	movq %rdi, %rax
	popq %rbx
	movq $.LC25, %rdi
	movq %rdi, %rax
	movq %rdi, %rcx
	movq $.LC25, %rdi
	movq %rdi, %rax
	movq %rdi, %rsi
	movq %rcx, %rdi
	call strcmp
	cmpq $0, %rax
	je .LC26
	movq $0, %rax
	jmp .LC27
.LC26:
	movq $1, %rax
.LC27:
	cmpq $1, %rax
	jne .LC28
	movq $.LCtrue, %rdi
	jmp .LC29
.LC28:
	movq $.LCfalse, %rdi
.LC29:
	movq %rax, %rsi
	movq $.LCs, %rdx
	movq $0, %rax
	call printf
	movq $10, %rdi
	call putchar
	movq $.LC10, %rdi
	movq %rdi, %rax
	pushq %rax
	movq $.LC5, %rdi
	movq %rdi, %rax
	popq %rbx
	movq $.LC5, %rdi
	movq %rdi, %rax
	movq %rdi, %rcx
	movq $.LC10, %rdi
	movq %rdi, %rax
	movq %rdi, %rsi
	movq %rcx, %rdi
	call strcmp
	cmpq $0, %rax
	jl .LC30
	movq $0, %rax
	jmp .LC31
.LC30:
	movq $1, %rax
.LC31:
	cmpq $1, %rax
	jne .LC32
	movq $.LCtrue, %rdi
	jmp .LC33
.LC32:
	movq $.LCfalse, %rdi
.LC33:
	movq %rax, %rsi
	movq $.LCs, %rdx
	movq $0, %rax
	call printf
	movq $10, %rdi
	call putchar
	movq $.LC10, %rdi
	movq %rdi, %rax
	pushq %rax
	movq $.LC0, %rdi
	movq %rdi, %rax
	popq %rbx
	movq $.LC0, %rdi
	movq %rdi, %rax
	movq %rdi, %rcx
	movq $.LC10, %rdi
	movq %rdi, %rax
	movq %rdi, %rsi
	movq %rcx, %rdi
	call strcmp
	cmpq $0, %rax
	jl .LC34
	movq $0, %rax
	jmp .LC35
.LC34:
	movq $1, %rax
.LC35:
	cmpq $1, %rax
	jne .LC36
	movq $.LCtrue, %rdi
	jmp .LC37
.LC36:
	movq $.LCfalse, %rdi
.LC37:
	movq %rax, %rsi
	movq $.LCs, %rdx
	movq $0, %rax
	call printf
	movq $10, %rdi
	call putchar
	movq $.LC16, %rdi
	movq %rdi, %rax
	pushq %rax
	movq $.LC25, %rdi
	movq %rdi, %rax
	popq %rbx
	movq $.LC25, %rdi
	movq %rdi, %rax
	movq %rdi, %rcx
	movq $.LC16, %rdi
	movq %rdi, %rax
	movq %rdi, %rsi
	movq %rcx, %rdi
	call strcmp
	cmpq $0, %rax
	jle .LC38
	movq $0, %rax
	jmp .LC39
.LC38:
	movq $1, %rax
.LC39:
	cmpq $1, %rax
	jne .LC40
	movq $.LCtrue, %rdi
	jmp .LC41
.LC40:
	movq $.LCfalse, %rdi
.LC41:
	movq %rax, %rsi
	movq $.LCs, %rdx
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
.LC0:
	.string ""
.LC5:
	.string "a"
.LC11:
	.string "c"
.LC10:
	.string "b"
.LC16:
	.string "ab"
.LC25:
	.string "abc"

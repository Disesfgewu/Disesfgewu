.section .data
msg:
    .asciz "%ld\n"
x:
    .quad 2
y:
    .quad 0

.section .text
.globl main

main:
    pushq   %rbp
    movq    %rsp, %rbp

    movq    x(%rip), %rbx
    imulq   %rbx, %rbx
    movq    %rbx, y(%rip)
    addq    x(%rip), %rbx

    movq    %rbx, %rsi
    leaq    msg(%rip), %rdi
    movl    $0,   %eax
    call    printf@PLT

    movq    $60,  %rax
    xor     %rdi, %rdi
    syscall

    popq	%rbp
    ret

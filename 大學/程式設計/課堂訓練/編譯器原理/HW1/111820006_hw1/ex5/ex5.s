.section .data

msg:
    .asciz "%d\n"

.section .text
.globl main

main:
    pushq   %rbp
    movq    %rsp, %rbp

    subq    $16,  %rsp

    movq    $3, -8(%rbp)
    
    movq    -8(%rbp), %rax
    imulq   %rax, %rax
    movq    %rax, %rsi
    leaq    msg(%rip), %rdi
    movl    $0,   %eax
    call    printf@PLT

    movq    $3, -8(%rbp) 
    movq    -8(%rbp), %rax
    addq    %rax, %rax
    movq    %rax, -16(%rbp)
    imulq   -8(%rbp), %rax

    movq    $3, %rcx
    addq    -8(%rbp), %rcx
    xor     %rdx, %rdx
    movq    %rax, %rbx
    movq    %rcx, %rax
    divq    %rcx

    addq    %rax, %rbx
    movq    %rbx, %rsi
    leaq    msg(%rip), %rdi
    movl    $0,   %eax
    call    printf@PLT 

    movq    $60,  %rax
    xor     %rdi, %rdi
    syscall

    popq	%rbp
    ret

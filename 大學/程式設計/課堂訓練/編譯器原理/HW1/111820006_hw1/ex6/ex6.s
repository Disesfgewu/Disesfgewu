.section .data
msg:
    .asciz "sqrt(%2d) = %2d\n"   

.section .text
.globl isqrt
.type isqrt, @function

isqrt:
    pushq   %rbp
    movq    %rsp, %rbp
    
    subq    $32, %rsp
    movq    %r10, -8(%rbp)
    movq    $0,  -16(%rbp)
    movq    $1,  -24(%rbp)
loop:
    movq    -24(%rbp), %r11
    cmp     -8(%rbp), %r11
    jg      return

    addq    $1, -16(%rbp)
    movq    -16(%rbp), %r12
    leaq    1(%r12 , %r12), %r13
    addq    %r13, -24(%rbp)
    jmp     loop
return:
    movq    -16(%rbp), %rax
    leave
    ret

.globl main
.type main, @function

main:
    pushq   %rbp
    movq    %rsp, %rbp

    subq    $16, %rsp
    movq    $0 , -8(%rbp)
main_loop:
    movq    $20, %r14
    cmp     %r14, -8(%rbp)
    jg      end

    movq    -8(%rbp), %r10
    call    isqrt
    movq    %rax, %rdx
    
    movq    -8(%rbp), %rsi
    leaq    msg(%rip), %rdi
    movq    $0, %rax
    call    printf@PLT 


    addq    $1, -8(%rbp)
    jmp     main_loop


end:
    movl    $0, %eax
    movq    $60,  %rax
    xor     %rdi, %rdi
    syscall

    popq	%rbp
    ret

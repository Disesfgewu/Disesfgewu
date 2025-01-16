.section .data
message: 
    .asciz "%d\n"

.section .text
.globl main

main:
    pushq   %rbp
    movq    %rsp, %rbp

    movq    $4, %rdi
    addq    $6, %rdi
    movq    %rdi, %rsi    
    leaq    message(%rip), %rdi  
    movl    $0, %eax   
    call    printf@PLT 

    xor     %rdi, %rdi    
    movq    $21, %rdi     
    imulq   $2,  %rdi     
    movq    %rdi, %rsi    
    leaq    message(%rip), %rdi  
    movl    $0, %eax   
    call    printf@PLT  

    xor     %rdx, %rdx
    xor     %rax, %rax    
    movq    $2, %rbx
    movq    $7, %rax
    divq    %rbx
    addq    $4, %rax
    movq    %rax, %rsi    
    leaq    message(%rip), %rdi  
    movl    $0, %eax   
    call    printf@PLT

    xor     %rdx, %rdx
    xor     %rax, %rax
    xor     %rbx, %rbx
    movq    $5,   %rbx
    movq    $10,  %rax
    divq    %rbx
    imulq   $6,   %rax
    movq    $3,   %rcx 
    subq    %rax, %rcx
    movq    %rcx, %rsi    
    leaq    message(%rip), %rdi  
    movl    $0,   %eax   
    call    printf@PLT

    xor     %rax, %rax
    movq    $60,  %rax
    xor     %rdi, %rdi
    syscall

    popq	%rbp
    ret
                

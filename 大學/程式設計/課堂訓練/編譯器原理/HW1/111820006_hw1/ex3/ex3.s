.section .data
true_msg: 
    .asciz "true\n"
false_msg:
    .asciz "false\n"
integer_msg:
    .asciz "%d\n"
.section .text
.globl main

main:
    pushq   %rbp
    movq    %rsp, %rbp
    
    movq    $1,   %rbx  
    movq    $0,   %rcx  
    and     %rbx, %rcx  
    cmp     $0, %rcx      
    je      print_false   
    jmp     print_true    

print_false:
    leaq    false_msg(%rip), %rdi  
    movl    $0,   %eax                
    call    printf@PLT                  

    jmp     second                     

print_true:
    leaq    true_msg(%rip), %rdi   
    movl    $0,   %eax                
    call    printf@PLT                  

second:
    movq    $3,   %rbx
    movq    $4,   %rcx
    cmp     %rbx, %rcx
    je      print_14
    jmp     print_10

print_14:
    movq    $14, %rsi    
    leaq    integer_msg(%rip), %rdi  
    movl    $0, %eax   
    call    printf@PLT
    jmp     third
print_10:
    movq    $10,  %rdx
    imulq   $2,   %rdx
    movq    %rdx, %rsi    
    leaq    integer_msg(%rip), %rdi  
    movl    $0,   %eax   
    call    printf@PLT
third:
    movq    $2,   %rbx
    movq    $3,   %rcx
    cmp     %rbx, %rcx
    je      print_true2
    
    xor     %rbx, %rbx
    movq    $2,   %rbx
    imulq   $3,   %rbx
    movq    $4,   %rcx
    cmp     %rbx, %rcx
    jle     print_true2

    leaq    false_msg(%rip), %rdi   
    movl    $0,   %eax                
    call    printf@PLT

    jmp     end      

print_true2:
    leaq    true_msg(%rip), %rdi   
    movl    $0,   %eax                
    call    printf@PLT 


end:
    movq    $60,  %rax              
    xor     %rdi, %rdi              
    syscall

    popq	%rbp
    ret
    
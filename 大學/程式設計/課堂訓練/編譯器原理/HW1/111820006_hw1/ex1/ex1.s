.section .data
message: 
    .string "n = %d\n"

.section .text
.globl main

main:
    pushq   %rbp
    movq    %rsp, %rbp
    movl    $42, %esi
    leaq	message(%rip), %rdi
    movl    $0, %eax
    call    printf@PLT
    movl	$0, %eax
    popq	%rbp
    ret
    
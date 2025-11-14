.intel_syntax noprefix
.global main
.extern GetStdHandle
.extern WriteConsoleA
.extern ExitProcess

.section .data
message:
    .ascii "Hello, Windows!\n"
msg_len = . - message

.section .bss
    .align 8
written: .quad 0

.section .text
main:
    mov rcx, -11                  # STD_OUTPUT_HANDLE
    call GetStdHandle             # rax = handle

    mov rcx, rax                  # hConsoleOutput
    lea rdx, [rip + message]      # lpBuffer
    mov r8, msg_len               # nNumberOfCharsToWrite
    lea r9, [rip + written]       # lpNumberOfCharsWritten
    sub rsp, 32                   # shadow space
    call WriteConsoleA
    add rsp, 32

    xor ecx, ecx                  # exit code 0 
    call ExitProcess

# useful commands to assemble and run:
# gcc -nostartfiles -o hello.exe hello.s -lkernel32
# ./hello.exe
# $LASTEXITCODE


        .section .iwram.code
        .align 2
.global RomXor
.type RomXor, %function
RomXor:
    push {r4-r12, lr}
    mov r1, #0x08000000
    mov r0, #0
xor_loop:
    ldmia r1!, {r2-r12, lr}
    cmp r1, #0x0A000000
    eor r0, r2
    eor r0, r3
    eor r0, r4
    eor r0, r5
    eor r0, r6
    eor r0, r7
    eor r0, r8
    eor r0, r9
    eorlt r0, r10
    eorlt r0, r11
    eorlt r0, r12
    eorlt r0, lr
    blt xor_loop
    pop {r4-r12, lr}
    bx lr

.cpu cortex-m0
.text
.align 2
.global print_asciz

print_asciz:
	push { R5, R0 }
	mov R5, R0
loop:
	ldrb r0, [ r5 ]
	add r0, r0, #0
	beq done
	bl uart_put_char
	add r5, r5, #1
	b loop
done:
	pop { r5, pc }

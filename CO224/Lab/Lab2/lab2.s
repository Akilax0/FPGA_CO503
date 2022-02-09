@ ARM Assembly - lab 2
@ Authour - Akilax0

	.text 	@ instruction memory
	.global main
main:
	@ stack handling, will discuss later
	@ push (store) lr to the stack
	sub sp, sp, #4
	str lr, [sp, #0]

	@ load values
	mov r0, #10
	mov r1, #5
	mov r2, #7
	mov r3, #-8

	
	@ Write YOUR CODE HERE
	
	@	Sum = 0;
	@	for (i=0;i<10;i++){
	@			for(j=5;j<15;j++){
	@				if(i+j<10) sum+=i*2
	@				else sum+=(i&j);	
	@			}	
	@	} 
	@ Put final sum to r5


	@ ---------------------
	mov r5, #0 @sum
	mov r6, #0 @i
Loop1:	
	mov r7,#5 @j
Loop2:

	add r8,r6,r7
	cmp r8,#10
	addlt r5,r5,r6,lsl #1
	and r9,r6,r7
	addge r5,r5,r9

	add r7,r7,#1	
	cmp r7,#14
	ble Loop2

	add r6,r6,#1
	cmp r6,#9
	ble Loop1
	
	@ ---------------------
	
	
	@ load aguments and print
	ldr r0, =format
	mov r1, r5
	bl printf

	@ stack handling (pop lr from the stack) and return
	ldr lr, [sp, #0]
	add sp, sp, #4
	mov pc, lr

	.data	@ data memory
format: .asciz "The Answer is %d (Expect 300 if correct)\n"


.cpu cortex-m0
.text
.align 2

.global decode

.bss
buffer:
    .skip 100          //maak buffer aan van 100 bytes

.text

add:
    push {r4, lr}
    mov r4, r0
    bl uart_put_char  //schrijf naar hwlib cout
    ldr r3, =buffer   //laadt de buffer in r3
    mov r1, #98       //zet de pointer op de 1-na-laatste van de buffer (buffer gaat van 0-99)
    add r1, r3, r1    //laadt in r1 de 1-na-laatste character


bufferloop:
    ldrb r2, [r1]     //load de index in r2
    strb r2, [r1,#1]  //schrijf die index naar index+1
    cmp r1, r3        //check of je op de eerste index van de buffer zit
    beq donebuffer   
    sub r1, r1, #1    //index - 1
    b bufferloop     

donebuffer:
    strb r4, [r3]     //zet de volgende character vooraan in de buffer
    pop {r4, pc}     


//r0 = ascii string
//r1 = leeg
//r2 = length
//r3 = pointer van de buffer
//r4 = counter
//r5 = pointer van de string
//r6 = buffer pointer
//r7 = offset

decode:
    push { r5, lr }
    ldr r0, =asc      //laadt de ascii string in r5 
    mov r5, r0

loop:
    ldrb r0, [ r5 ]
    cmp r0, #0         //check voor einde file
	beq done
    cmp r0, #'@'       //check @-teken
    beq convert

    bl add             //schrijf naar buffer
    bl uart_put_char   //schrijf naar hwlib cout

    add r5, r5, #1
	b loop
    

convert:
    //je zit nu op de @ character
    add r5, r5, #1
    ldrb r7, [ r5 ]   //sla offset op

    add r5, r5, #1
    ldrb r4, [ r5 ]   //sla length op

    add r5, r5, #1    //ga 1 verder zodat je geen cijfers meeneemt

    sub r7, r7, #'0'  //zet om naar getal - offset
    sub r4, r4, #'0'  //zet om naar getal - length
    ldr r6, =buffer   //laadt de buffer in r6


loop2:
    ldrb r0, [r6,r7]    //ga naar die pointer in de buffer
    bl add              //add de character die terug gehaald is in de buffer (zodat de complete zin ook in de buffer zit om later mogelijk opnieuw terug te vragen)

    sub r4, r4, #1      //haal 1 van de length af
    cmp r4, #0          //check of de length 0 is
    beq loop

    b loop2


done:
	pop { r5, pc}


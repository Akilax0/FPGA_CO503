Compile to ARM assembly using cross compiler
	sudo apt install gcc-arm-linux-gnueabi

Emulate arm processor using qemu
	sudo apt install qemu-user

Running ARM assembly programs

- Save file with .s
- assemble with 
	arm-linux-gnueabi-gcc -Wall example.s -o example
- Run
	qemu-arm -L /usr/arm-linux-gnueabi example




.section .data	# assembler directives
				# list memory storage
.section .text	# program instructions
				# list instructions
.globl _start	# program start symbol
_start:			# label to define value of symbol
movl $1, %eax	# Linux kernel command to exit program
				# operands: source, destination
				# $ stands for immediate mode addressing
				# 1 is the kernel exit system call for %eax
movl $0, %ebx	# return status number required in %ebx
int $0x80		# wakes kernel to run exit command
				# hex number

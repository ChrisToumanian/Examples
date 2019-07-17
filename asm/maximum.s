# PURPOSE:  This program finds the maximum number of a
#          set of data items.
#
# VARIABLES: The registers have the following uses:
#
# %edi - Holds the index of the data item being examined
# %ebx - Largest data item found
# %eax - Current data item
#
# The following memory locations are used:
#
# data_items - contains the item data.  A 0 is used
#              to terminate the data

.section .data

data_items:
.long 3,67,34,222,45,75,54,34,44,33,22,11,66,0	# reserves memory for list

.section .text

.globl _start
_start:
 movl $0, %edi             				# move 0 into the index register
 movl data_items(,%edi,4), %eax 		# load the first byte of data
 movl %eax, %ebx						# since this is the first item, %eax is biggest

start_loop:
 cmpl $0, %eax							# check if at end of array
 je loop_exit							# jump to exit
 incl %edi								# increment to load next value, edi++
 movl data_items(,%edi,4), %eax			# eax = data[edi]
 cmpl %ebx, %eax						# compare
 jle start_loop							# jump if new isn't bigger, if eax < ebx jump
 movl %eax, %ebx						# move value as largest, else eax = ebx
 jmp start_loop							# jump to start of loop
 
loop_exit:
 movl $1, %eax
 int  $0x80

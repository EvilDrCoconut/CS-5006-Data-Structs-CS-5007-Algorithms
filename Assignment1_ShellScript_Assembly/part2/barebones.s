# Build an executable using the following:
#
# clang barebones.s -o barebones  # clang is another compiler like gcc
#
.text
_barebones:

.data
	
.globl main

main:
					# (1) What are we setting up here?
					# Ans: we are pushing register rbp onto a stack
	pushq %rbp			# now we move data from register from rsp to rbp
	movq  %rsp, %rbp		#

					# (2) What is going on here
					# Ans: moving 1 byte of data to register rax
	movq $1, %rax			# moving 1 byte of data to register rdi
	movq $1, %rdi			#  moves the address of string 'hello' into register rsi.
	leaq .hello.str,%rsi		#


					# (3) What is syscall? We did not talk about this
					# in class.
					# Ans: it is a command call to the kernel of the operating system.
	syscall				# Which syscall is being run?
					# Ans: the syscall to return the value in rax

					# (4) What would another option be instead of 
					# using a syscall to achieve this?
					# Ans: You can directly call the function being used instead of indirectly calling the system.

	movq	$60, %rax		# (5) We are again setting up another syscall
	movq	$0, %rdi		# What command is it?
					# Ans:	We are once again asking for the return value in rax.
	syscall

	popq %rbp			# (Note we do not really need
					# this command here after the syscall)

.hello.str:
	.string "Hello World!\n"
	.size	.hello.str,13		# (6) Why is there a 13 here?
					# Ans:Its the number of characters (size) of .string "Hello World! \n" where \n is considered as one character.

# Brett Kriz
# replace this line with your partner's name (if you have one)
#
# CS3421 Homework 3
# Fall 2015
#
# Traverse a binary tree in order
#
    .text
# test program starts here
    la    $a0,tree
    jal   traverse        # call the function
    move  $t0,$v0	  # save return values
    move  $t1,$v1
    li    $t2,0		  # counter = 0
loop:
    bge   $t2,$t1,done
    lw    $a0,0($t0)	  # get next element of array
    li    $v0,1           # print it
    syscall
    la    $a0,space       # print a space
    li    $v0,4
    syscall
    addi  $t0,$t0,4	  # advance pointer to next element
    addi  $t2,$t2,1	  # increment counter
    b     loop
done:
    la    $a0,newline     # print a new line
    li    $v0,4
    syscall
    li    $v0,10          # exit
    syscall

# the test tree

    .data
    # The given tree seems reversed: having left larger than right...
tree:			
    .word 9
    .word a
    .word bb
a:
    .word 6
    .word c
    .word d
bb:
    .word 4
    .word -1
    .word -1
c:
    .word 7
    .word -1
    .word -1
d: 
    .word 2
    .word e
    .word f
e:
    .word 5
    .word -1
    .word -1
f:
    .word 1
    .word -1
    .word -1

# for debug printing
space:
    .asciiz  " "
newline:
    .asciiz  "\n"
    
    .align 2
ordering:
    .space 400
stack:
    .align 2
    .space 2400

# your traverse function starts here:
# DO NOT change the name of the function

# DO NOT MAKE ANY REFERENCES TO ANY LABELS DEFINED ABOVE 
    .text
traverse:		#In order

	# PROLOGUE HERE
	li	$t6,0			# Initialize tracking values
	li	$t7,0
	la 	$sp,stack
	addi	$sp,$sp,2400
	
recure:

	li	$t0,-1			#Conditional var
	addi	$t7,$t7,1		#Increment count
	addi	$sp,$sp,-20		#Store our return address

	lw	$t1,($a0)		# Node Value
	
	bne	$t1,$t0,pass1		# Value =/= -1
	b	skipr			# That shouldnt happen but oh well
	
pass1:	# Fetch and store values	

	lw	$t2,4($a0)		#Left
	lw	$t3,8($a0)		#Right

	sw	$ra,($sp)		#Save RA
	sw	$t1,4($sp)		#Value
	sw	$t2,8($sp)		#Left
	sw	$t3,12($sp)		#Right
	sw	$a0,16($sp)		#Save parent

	# Consider Left Child
	
	li	$t0,-1			#Conditional var
	lw	$t2,8($sp)
	beq	$t2,$t0,skipl		# t2 =/= -1
	move	$a0,$t2
	jal	recure
	lw	$ra, ($sp)		# Restore RA
	
skipl:	# Consider Center Value

	lw	$t9,4($sp)
	sw	$t9,ordering($t6)	# Save the node value
	addi	$t6,$t6,4		# and increment
	
skipc:	# Consider Right Child

	li	$t0,-1			#Conditional var
	lw	$t3,12($sp)
	beq	$t3,$t0,skipr		#t3 =/= -1
	move	$a0,$t3
	jal	recure
	lw	$ra, ($sp)		# Restore R

skipr:	# End of traverse

	lw	$ra,0($sp)		# Restore RA
	lw	$a0,16($sp)		# Restore a0
	addi	$sp,$sp,20		#Decrement and get
	
					# Move values and jump register
	
	la	$v0,ordering		
	move	$v1,$t7
	jr 	$ra












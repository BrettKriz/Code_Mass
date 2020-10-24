# Brett Kriz
# replace this line with your partner's name (if you have one)
#
# CS3421 Homework 2
# Fall 2015
#
        .text

# replace this line with your code to merge the arrays
	
	lw      $t1, len1
        lw      $t2, len2
        
        li	$t4, 0			# Count (0 based)
	li	$s2, 0			# Array1 counter
	li	$s3, 0			# Array2 counter

	li	$t7, 1			# First size paramiter
	add	$t3, $t1, $t2		# Store total length
	addi	$t3, $t3, -1		# Prevent off by 1
	blt	$t3, $t7, done		# Make sure we have length
	
	addi	$t1,$t1,-1
        addi	$t2,$t2,-1
	
# while loop
loop:
	bgt	$t4, $t3, done

# Body of loop, init values
	
	li	$s0, 0			# Array1 current var
	li	$s1, 0			# Array2 current var
	li	$t7, 2			# Compairison var (ensuring value)
	
	li	$s5, 0			# Flag values
	li	$s6, 0
	li	$s7, 222
	
	
	bgt	$s2, $t1, skip1		# Check iterator against len1
	sll     $t9, $s2, 2		# Generate adress
	lw	$s0, data1($t9)
	li	$s5, 1			# Mark sucess flag1

# Assess the current array positions

skip1:	
	bgt	$s3, $t2, skip2		# check iterator against len2
	sll     $t9, $s3, 2
	lw	$s1, data2($t9)
	li	$s6, 1			# Mark sucess flag2
	
skip2:
	add 	$t9, $s6, $s5		# Sum our flags to detrimine action
	li	$t7, 2
	
	
	beq	$t9, $zero, done	# 0 & 0 means we have no operations.
	bge	$t9, $t7, part2 	# s7 >= 2
	bne	$s5, $zero, ad1		# Commit to a winner
	bne	$s6, $zero, ad2
	
	b	done			# An error catch :/
	
# Part 2 - Handles the variables state for data3

part2:					# Ignore force adds
	bgt	$s1, $s0, ad1		# Direct to correct add section
	b	ad2
	
ad1:					# Add data1's item
	#move	$s7, $s0
	sw	$s0, ans
	lw	$s7, ans
	addi	$s2, $s2, 1		# Iterate data1s count
	b	addone

ad2:					# Add data2's item
	#move	$s7, $s1
	sw	$s1, ans
	lw	$s7, ans
	addi	$s3, $s3, 1
	b	addone
	
# Ad done - Insert the variable into data3
	
addone:					# Escape add ins
	sll     $t9, $t4, 2
	sw	$s7, data3($t9)
	addi	$t4, $t4, 1		# count++
	b	loop

done:
# here's the data (change it to test your code)
        .data
len1:   .word   7
len2:   .word   1
ans:	.word	333			# Debug value
	#	1, 2, 3, 4, 5
data1:  .word   59,62,73,89,97,98,99      	# len1 values 7
	#	2, 4, 6, 8, 10, 12
data2:  .word   20	# len2 values 7
data3:  .space  56                  	# (len1 + len2) * 4

# the code below prints the result array values and terminates execution
# DO NOT CHANGE IT!

        .text
        li      $t0,0
        lw      $t1,len1
        lw      $t2,len2
        add     $t1,$t1,$t2
prloop:
        bge     $t0,$t1,prdone
        sll     $t2,$t0,2
        lw      $a0,data3($t2)
        li      $v0,1
        syscall
        la      $a0,eol
        li      $v0,4
        syscall
        addi    $t0,$t0,1
        b       prloop
prdone:
        li      $v0,10
        syscall

        .data
eol:    .asciiz "\n"
bnr:	.asciiz "\n~~~~~~~~~~~~~~~~\n"
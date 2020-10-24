    .text
	lw $t1, x
    lbu  $t7,2($t1)
    sw   $t7,y
    
    
    lw      $a0,($t7)
    li      $v0,1
    syscall
    
    .data
x:  .word  0x12345678		# starts at address 12
y:  .word  0			# should become 0x56

.name "zork"
.comment "I'M ALIIIIVE"

l2:		sti r1, %:live, %1
#		and r1, %1, r1
		add r2, r3, r4

live:	live %1
		zjmp %:live

#1111 1111 1111 1111
#0000 0000 0000 0001

#0000 0000 0000 0001

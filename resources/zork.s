

.comment "coucou"
.name "zork"

l2:sti	r20,%:live,%1
		and r1, %0, r1
live:	live %1
		zjmp %:live
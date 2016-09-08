#by zaz, still not as good as rainbowdash though
#2013

.name		"helltrain"
.comment	"choo-choo, motherf*****s !"

entry:
	sti		r1, %:beegees_gen, %1
	sti		r1, %:beegees, %1
	sti		r1, %:cc_spawn, %1
	sti		r1, %:wall, %1
	sti		r1, %:cc4, %1
	sti		r1, %:cc4, %9
	sti		r1, %:cc4, %17
	sti		r1, %:cc4l, %1
	sti		r1, %:cc4ld, %2
	sti		r1, %:cc3, %1
	sti		r1, %:cc3, %9
	sti		r1, %:cc2, %1
	ld		%0, r16
	fork	%:cc_spawn

wall_prep:
	ld		%0, r2
	ld		%0, r16

wall:
	live	%4902343
	st		r1, -24
	st		r1, -33
	st		r1, -42
	st		r1, -51
	st		r1, -60
	st		r1, -69
	st		r1, -78
	st		r1, -87
	st		r1, -96
	st		r1, -105
	st		r1, -114
	st		r1, -123
	st		r1, -132
	st		r1, -141
	st		r1, -150
	st		r1, -159
	st		r1, -168
	st		r1, -177
	st		r1, -186
	st		r1, -195
	st		r1, -204
	st		r1, -213
	st		r1, -222
	st		r1, -231
	st		r1, -240
	st		r1, -249
	st		r1, -258
	st		r1, -267
	st		r1, -276
	st		r1, -285
	st		r1, -294
	st		r1, -303
	st		r1, -312
	st		r1, -321
	st		r1, -330
	st		r1, -339
	st		r1, -348
	st		r1, -357
	st		r1, -366
	st		r1, -375
	st		r1, -384
	st		r1, -393
	st		r1, -402
	st		r1, -411
	st		r1, -420
	st		r1, -429
	st		r1, -438
	st		r1, -447
	st		r1, -456
	st		r1, -465
	st		r1, -474
	st		r1, -483
	st		r1, -492
	st		r1, -501
	st		r1, -510
	zjmp	%:wall

beegees_gen:
	live	%4239423
	fork	%:beegees_gen
	ld		%0, r16

beegees:
	live	%3442302
	zjmp	%:beegees

cc_spawn:
	live	%4320423
	zjmp	%3
	fork	%:cc_spawn

cc4:
	live	%4329034
	fork	%:cc3
	live	%3401123
	fork	%:cc2
	live	%4590543
	fork	%:cc1
cc4ld:
	ld		%0, r2
	ld		%251883523, r3
	ld		%0, r16
cc4l:
	live	%4930423	
	ld		%0, r16
	zjmp	%:choochoo

cc2:
	live	%4342342
	fork	%:wall_prep
	ld		%251883523, r2
	ld		%386101251, r3
	ld		%0, r16
	ld		%0, r16
	zjmp	%:choochoo

cc3:
	live	%4239013
	fork	%:cc4
	live	%4093282
	fork	%:beegees_gen
	ld		%4294902016, r2
	ld		%436432899, r3
	ld		%0, r16
	ld		%0, r16
	ld		%0, r16
	zjmp	%:choochoo

cc1:
	ld		%57672192, r2
	ld		%318992387, r3
	ld		%0, r16
	zjmp	%:choochoo

choochoo:
	st		r2, 15
	st		r3, -1
cc_live:
	live	%0

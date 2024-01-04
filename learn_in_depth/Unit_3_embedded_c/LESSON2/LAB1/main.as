
main.o:     file format elf32-littlearm


Disassembly of section .text:

00000000 <main>:
   0:	e92d4800 	push	{fp, lr}
   4:	e28db004 	add	fp, sp, #4
   8:	e59f000c 	ldr	r0, [pc, #12]	@ 1c <main+0x1c>
   c:	ebfffffe 	bl	0 <uart_send>
  10:	e3a03000 	mov	r3, #0
  14:	e1a00003 	mov	r0, r3
  18:	e8bd8800 	pop	{fp, pc}
  1c:	00000000 	andeq	r0, r0, r0

Disassembly of section .data:

00000000 <string>:
   0:	6c6c6568 	cfstr64vs	mvdx6, [ip], #-416	@ 0xfffffe60
   4:	6f77206f 	svcvs	0x0077206f
   8:	00646c72 	rsbeq	r6, r4, r2, ror ip
	...

00000064 <string2>:
  64:	65636166 	strbvs	r6, [r3, #-358]!	@ 0xfffffe9a
	...

Disassembly of section .bss:

00000000 <x>:
   0:	00000000 	andeq	r0, r0, r0

Disassembly of section .debug_info:

00000000 <.debug_info>:
   0:	000000a6 	andeq	r0, r0, r6, lsr #1
   4:	04010005 	streq	r0, [r1], #-5
   8:	00000000 	andeq	r0, r0, r0
   c:	00000003 	andeq	r0, r0, r3
  10:	00ae1d00 	adceq	r1, lr, r0, lsl #26
  14:	00600000 	rsbeq	r0, r0, r0
  18:	00000000 	andeq	r0, r0, r0
  1c:	00200000 	eoreq	r0, r0, r0
  20:	00000000 	andeq	r0, r0, r0
  24:	3d040000 	stccc	0, cr0, [r4, #-0]
  28:	36000000 	strcc	r0, [r0], -r0
  2c:	05000000 	streq	r0, [r0, #-0]
  30:	00000036 	andeq	r0, r0, r6, lsr r0
  34:	04010063 	streq	r0, [r1], #-99	@ 0xffffff9d
  38:	00005307 	andeq	r5, r0, r7, lsl #6
  3c:	08010100 	stmdaeq	r1, {r8}
  40:	000000b5 	strheq	r0, [r0], -r5
  44:	0000d502 	andeq	sp, r0, r2, lsl #10
  48:	00260300 	eoreq	r0, r6, r0, lsl #6
  4c:	03050000 	movweq	r0, #20480	@ 0x5000
  50:	00000000 	andeq	r0, r0, r0
  54:	0000cd02 	andeq	ip, r0, r2, lsl #26
  58:	00260400 	eoreq	r0, r6, r0, lsl #8
  5c:	03050000 	movweq	r0, #20480	@ 0x5000
  60:	00000000 	andeq	r0, r0, r0
  64:	01007806 	tsteq	r0, r6, lsl #16
  68:	00740505 	rsbseq	r0, r4, r5, lsl #10
  6c:	03050000 	movweq	r0, #20480	@ 0x5000
  70:	00000000 	andeq	r0, r0, r0
  74:	69050407 	stmdbvs	r5, {r0, r1, r2, sl}
  78:	0800746e 	stmdaeq	r0, {r1, r2, r3, r5, r6, sl, ip, sp, lr}
  7c:	000000c3 	andeq	r0, r0, r3, asr #1
  80:	8d060702 	stchi	7, cr0, [r6, #-8]
  84:	09000000 	stmdbeq	r0, {}	@ <UNPREDICTABLE>
  88:	0000008d 	andeq	r0, r0, sp, lsl #1
  8c:	3d040a00 	vstrcc	s0, [r4, #-0]
  90:	0b000000 	bleq	98 <.debug_info+0x98>
  94:	000000a9 	andeq	r0, r0, r9, lsr #1
  98:	74050701 	strvc	r0, [r5], #-1793	@ 0xfffff8ff
  9c:	00000000 	andeq	r0, r0, r0
  a0:	20000000 	andcs	r0, r0, r0
  a4:	01000000 	mrseq	r0, (UNDEF: 0)
  a8:	Address 0xa8 is out of bounds.


Disassembly of section .debug_abbrev:

00000000 <.debug_abbrev>:
   0:	0b002401 	bleq	900c <string2+0x8fa8>
   4:	030b3e0b 	movweq	r3, #48651	@ 0xbe0b
   8:	0200000e 	andeq	r0, r0, #14
   c:	0e030034 	mcreq	0, 0, r0, cr3, cr4, {1}
  10:	3b01213a 	blcc	48500 <string2+0x4849c>
  14:	0f21390b 	svceq	0x0021390b
  18:	193f1349 	ldmdbne	pc!, {r0, r3, r6, r8, r9, ip}	@ <UNPREDICTABLE>
  1c:	00001802 	andeq	r1, r0, r2, lsl #16
  20:	25011103 	strcs	r1, [r1, #-259]	@ 0xfffffefd
  24:	030b130e 	movweq	r1, #45838	@ 0xb30e
  28:	110e1b0e 	tstne	lr, lr, lsl #22
  2c:	10061201 	andne	r1, r6, r1, lsl #4
  30:	04000017 	streq	r0, [r0], #-23	@ 0xffffffe9
  34:	13490101 	movtne	r0, #37121	@ 0x9101
  38:	00001301 	andeq	r1, r0, r1, lsl #6
  3c:	49002105 	stmdbmi	r0, {r0, r2, r8, sp}
  40:	000b2f13 	andeq	r2, fp, r3, lsl pc
  44:	00340600 	eorseq	r0, r4, r0, lsl #12
  48:	0b3a0803 	bleq	e8205c <string2+0xe81ff8>
  4c:	0b390b3b 	bleq	e42d40 <string2+0xe42cdc>
  50:	193f1349 	ldmdbne	pc!, {r0, r3, r6, r8, r9, ip}	@ <UNPREDICTABLE>
  54:	00001802 	andeq	r1, r0, r2, lsl #16
  58:	0b002407 	bleq	907c <string2+0x9018>
  5c:	030b3e0b 	movweq	r3, #48651	@ 0xbe0b
  60:	08000008 	stmdaeq	r0, {r3}
  64:	193f012e 	ldmdbne	pc!, {r1, r2, r3, r5, r8}	@ <UNPREDICTABLE>
  68:	0b3a0e03 	bleq	e8387c <string2+0xe83818>
  6c:	0b390b3b 	bleq	e42d60 <string2+0xe42cfc>
  70:	193c1927 	ldmdbne	ip!, {r0, r1, r2, r5, r8, fp, ip}
  74:	00001301 	andeq	r1, r0, r1, lsl #6
  78:	49000509 	stmdbmi	r0, {r0, r3, r8, sl}
  7c:	0a000013 	beq	d0 <string2+0x6c>
  80:	0b0b000f 	bleq	2c00c4 <string2+0x2c0060>
  84:	00001349 	andeq	r1, r0, r9, asr #6
  88:	3f002e0b 	svccc	0x00002e0b
  8c:	3a0e0319 	bcc	380cf8 <string2+0x380c94>
  90:	390b3b0b 	stmdbcc	fp, {r0, r1, r3, r8, r9, fp, ip, sp}
  94:	1113490b 	tstne	r3, fp, lsl #18
  98:	40061201 	andmi	r1, r6, r1, lsl #4
  9c:	00197c18 	andseq	r7, r9, r8, lsl ip
	...

Disassembly of section .debug_aranges:

00000000 <.debug_aranges>:
   0:	0000001c 	andeq	r0, r0, ip, lsl r0
   4:	00000002 	andeq	r0, r0, r2
   8:	00040000 	andeq	r0, r4, r0
	...
  14:	00000020 	andeq	r0, r0, r0, lsr #32
	...

Disassembly of section .debug_line:

00000000 <.debug_line>:
   0:	00000045 	andeq	r0, r0, r5, asr #32
   4:	00270003 	eoreq	r0, r7, r3
   8:	01020000 	mrseq	r0, (UNDEF: 2)
   c:	000d0efb 	strdeq	r0, [sp], -fp
  10:	01010101 	tsteq	r1, r1, lsl #2
  14:	01000000 	mrseq	r0, (UNDEF: 0)
  18:	00010000 	andeq	r0, r1, r0
  1c:	6e69616d 	powvsez	f6, f1, #5.0
  20:	0000632e 	andeq	r6, r0, lr, lsr #6
  24:	61750000 	cmnvs	r5, r0
  28:	682e7472 	stmdavs	lr!, {r1, r4, r5, r6, sl, ip, sp, lr}
  2c:	00000000 	andeq	r0, r0, r0
  30:	000c0500 	andeq	r0, ip, r0, lsl #10
  34:	00000205 	andeq	r0, r0, r5, lsl #4
  38:	05180000 	ldreq	r0, [r8, #-0]
  3c:	0a054b03 	beq	152c50 <string2+0x152bec>
  40:	2f01054b 	svccs	0x0001054b
  44:	01000602 	tsteq	r0, r2, lsl #12
  48:	Address 0x48 is out of bounds.


Disassembly of section .debug_str:

00000000 <.debug_str>:
   0:	20554e47 	subscs	r4, r5, r7, asr #28
   4:	20373143 	eorscs	r3, r7, r3, asr #2
   8:	332e3231 			@ <UNDEFINED> instruction: 0x332e3231
   c:	3220312e 	eorcc	r3, r0, #-2147483637	@ 0x8000000b
  10:	30333230 	eorscc	r3, r3, r0, lsr r2
  14:	20363236 	eorscs	r3, r6, r6, lsr r2
  18:	70636d2d 	rsbvc	r6, r3, sp, lsr #26
  1c:	72613d75 	rsbvc	r3, r1, #7488	@ 0x1d40
  20:	3632396d 	ldrtcc	r3, [r2], -sp, ror #18
  24:	732d6a65 			@ <UNDEFINED> instruction: 0x732d6a65
  28:	666d2d20 	strbtvs	r2, [sp], -r0, lsr #26
  2c:	74616f6c 	strbtvc	r6, [r1], #-3948	@ 0xfffff094
  30:	6962612d 	stmdbvs	r2!, {r0, r2, r3, r5, r8, sp, lr}^
  34:	666f733d 			@ <UNDEFINED> instruction: 0x666f733d
  38:	6d2d2074 	stcvs	0, cr2, [sp, #-464]!	@ 0xfffffe30
  3c:	206d7261 	rsbcs	r7, sp, r1, ror #4
  40:	72616d2d 	rsbvc	r6, r1, #2880	@ 0xb40
  44:	613d6863 	teqvs	sp, r3, ror #16
  48:	35766d72 	ldrbcc	r6, [r6, #-3442]!	@ 0xfffff28e
  4c:	206a6574 	rsbcs	r6, sl, r4, ror r5
  50:	7500672d 	strvc	r6, [r0, #-1837]	@ 0xfffff8d3
  54:	6769736e 	strbvs	r7, [r9, -lr, ror #6]!
  58:	2064656e 	rsbcs	r6, r4, lr, ror #10
  5c:	00746e69 	rsbseq	r6, r4, r9, ror #28
  60:	555c3a43 	ldrbpl	r3, [ip, #-2627]	@ 0xfffff5bd
  64:	73726573 	cmnvc	r2, #482344960	@ 0x1cc00000
  68:	376d6d5c 			@ <UNDEFINED> instruction: 0x376d6d5c
  6c:	65445c37 	strbvs	r5, [r4, #-3127]	@ 0xfffff3c9
  70:	6f746b73 	svcvs	0x00746b73
  74:	656c5c70 	strbvs	r5, [ip, #-3184]!	@ 0xfffff390
  78:	5f6e7261 	svcpl	0x006e7261
  7c:	74706564 	ldrbtvc	r6, [r0], #-1380	@ 0xfffffa9c
  80:	656c5c68 	strbvs	r5, [ip, #-3176]!	@ 0xfffff398
  84:	5f6e7261 	svcpl	0x006e7261
  88:	645f6e69 	ldrbvs	r6, [pc], #-3689	@ 90 <.debug_str+0x90>
  8c:	68747065 	ldmdavs	r4!, {r0, r2, r5, r6, ip, sp, lr}^
  90:	626d655c 	rsbvs	r6, sp, #92, 10	@ 0x17000000
  94:	65646465 	strbvs	r6, [r4, #-1125]!	@ 0xfffffb9b
  98:	5c635f64 	stclpl	15, cr5, [r3], #-400	@ 0xfffffe70
  9c:	5353454c 	cmppl	r3, #76, 10	@ 0x13000000
  a0:	5c324e4f 	ldcpl	14, cr4, [r2], #-316	@ 0xfffffec4
  a4:	3142414c 	cmpcc	r2, ip, asr #2
  a8:	69616d00 	stmdbvs	r1!, {r8, sl, fp, sp, lr}^
  ac:	616d006e 	cmnvs	sp, lr, rrx
  b0:	632e6e69 			@ <UNDEFINED> instruction: 0x632e6e69
  b4:	736e7500 	cmnvc	lr, #0, 10
  b8:	656e6769 	strbvs	r6, [lr, #-1897]!	@ 0xfffff897
  bc:	68632064 	stmdavs	r3!, {r2, r5, r6, sp}^
  c0:	75007261 	strvc	r7, [r0, #-609]	@ 0xfffffd9f
  c4:	5f747261 	svcpl	0x00747261
  c8:	646e6573 	strbtvs	r6, [lr], #-1395	@ 0xfffffa8d
  cc:	72747300 	rsbsvc	r7, r4, #0, 6
  d0:	32676e69 	rsbcc	r6, r7, #1680	@ 0x690
  d4:	72747300 	rsbsvc	r7, r4, #0, 6
  d8:	00676e69 	rsbeq	r6, r7, r9, ror #28

Disassembly of section .comment:

00000000 <.comment>:
   0:	43434700 	movtmi	r4, #14080	@ 0x3700
   4:	4128203a 			@ <UNDEFINED> instruction: 0x4128203a
   8:	47206d72 			@ <UNDEFINED> instruction: 0x47206d72
   c:	5420554e 	strtpl	r5, [r0], #-1358	@ 0xfffffab2
  10:	636c6f6f 	cmnvs	ip, #444	@ 0x1bc
  14:	6e696168 	powvsez	f6, f1, #0.0
  18:	2e323120 	rsfcssp	f3, f2, f0
  1c:	65522e33 	ldrbvs	r2, [r2, #-3635]	@ 0xfffff1cd
  20:	2820316c 	stmdacs	r0!, {r2, r3, r5, r6, r8, ip, sp}
  24:	6c697542 	cfstr64vs	mvdx7, [r9], #-264	@ 0xfffffef8
  28:	72612064 	rsbvc	r2, r1, #100	@ 0x64
  2c:	32312d6d 	eorscc	r2, r1, #6976	@ 0x1b40
  30:	2935332e 	ldmdbcs	r5!, {r1, r2, r3, r5, r8, r9, ip, sp}
  34:	32312029 	eorscc	r2, r1, #41	@ 0x29
  38:	312e332e 			@ <UNDEFINED> instruction: 0x312e332e
  3c:	32303220 	eorscc	r3, r0, #32, 4
  40:	32363033 	eorscc	r3, r6, #51	@ 0x33
  44:	Address 0x44 is out of bounds.


Disassembly of section .debug_frame:

00000000 <.debug_frame>:
   0:	0000000c 	andeq	r0, r0, ip
   4:	ffffffff 			@ <UNDEFINED> instruction: 0xffffffff
   8:	7c020001 	stcvc	0, cr0, [r2], {1}
   c:	000d0c0e 	andeq	r0, sp, lr, lsl #24
  10:	00000018 	andeq	r0, r0, r8, lsl r0
	...
  1c:	00000020 	andeq	r0, r0, r0, lsr #32
  20:	8b080e42 	blhi	203930 <string2+0x2038cc>
  24:	42018e02 	andmi	r8, r1, #2, 28
  28:	00040b0c 	andeq	r0, r4, ip, lsl #22

Disassembly of section .ARM.attributes:

00000000 <.ARM.attributes>:
   0:	00002b41 	andeq	r2, r0, r1, asr #22
   4:	61656100 	cmnvs	r5, r0, lsl #2
   8:	01006962 	tsteq	r0, r2, ror #18
   c:	00000021 	andeq	r0, r0, r1, lsr #32
  10:	45543505 	ldrbmi	r3, [r4, #-1285]	@ 0xfffffafb
  14:	0506004a 	streq	r0, [r6, #-74]	@ 0xffffffb6
  18:	01090108 	tsteq	r9, r8, lsl #2
  1c:	01140412 	tsteq	r4, r2, lsl r4
  20:	03170115 	tsteq	r7, #1073741829	@ 0x40000005
  24:	01190118 	tsteq	r9, r8, lsl r1
  28:	061e011a 			@ <UNDEFINED> instruction: 0x061e011a

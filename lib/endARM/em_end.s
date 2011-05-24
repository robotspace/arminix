.code 32
.sect .text
.global __etext, endtext
__etext:
endtext:
.sect .rom
.global endrom
endrom:
.sect .data
.global __edata, enddata
__edata:
enddata:
.sect .bss
.sect .end
.global __end, endbss
__end:
endbss:

.sect .text
.global _brksize
.extern endbss, _brksize
.sect .data 
_brksize: 
	.word endbss


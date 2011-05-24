#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "elf.h"

#define FLASH_START		0x60040000

int findELF(unsigned int address);
int readELF(unsigned int address);

extern int mem_cmp(int address, char *value, int count);
extern int mem_cpy(unsigned int source, unsigned int dest, unsigned int len);
extern void runprog(unsigned int addr);

Elf32_Ehdr elf_header;
Elf32_Phdr p_header[10];
Elf32_Shdr s_header;
	
	
void main(void)
{
    printf("ELF loader, last build: "__DATE__" "__TIME__"\n\rFor the Minix ARM project. By Leon Melis\n\n\r");
	if(!findELF(FLASH_START))
	{
		if(!readELF(FLASH_START))
		{
			printf("Running code at 0x%X...\n\n\r",p_header[0].p_paddr);
			runprog(p_header[0].p_paddr);	/* run it! */
		}
	}
	while(1);		/* something went wrong...*/
}

int findELF(unsigned int address){
	int ELF_magic=0x464c457f;		/* 0x7f,'E','L','F' */
	if(mem_cmp(address,&ELF_magic,4)!=0){
        printf("ERROR: no ELF at 0x%x!\n\r",address);
		return -1;
	}
	else{
		printf("Found ELF file at 0x%x\n\r",address);
		return 0;
	}
}

int readELF(unsigned int address){
	int i=0;
	
	mem_cpy(address, &elf_header, sizeof(elf_header));
	if(elf_header.e_type!=ET_EXEC){
		printf("ERROR: file is not executable!\n\r");
		return -1;
	}
	if(elf_header.e_machine!=EM_ARM){
		printf("ERROR: executable not suitable for ARM!\n\r");
		return -1;
	}
	printf("entry point: 0x%X\n\r",elf_header.e_entry);
	printf("number of programm headers: %d\n\r",elf_header.e_phnum);
	printf("number of section headers: %d\n\r",elf_header.e_shnum);
	for(i=0; i<elf_header.e_phnum; i++){
		mem_cpy(address+elf_header.e_phoff+(sizeof(p_header[0])*i), &p_header[i], sizeof(p_header));		/* wow, thats dirty! */
		printf("\nprogram header %d of %d type: %d\n\r",i+1,elf_header.e_phnum,p_header[i].p_type);
		printf("offset: 0x%X bytes\n\r",p_header[i].p_offset);
		printf("physical addr: 0x%X\n\r",p_header[i].p_paddr);
		printf("virtual addr: 0x%X\n\r",p_header[i].p_vaddr);
		printf("size in mem: 0x%X (%d bytes)\n\r",p_header[i].p_memsz,p_header[i].p_memsz);
		printf("size in file: 0x%X (%d bytes)\n\r",p_header[i].p_filesz,p_header[i].p_filesz);
		printf("alignment: 0x%X (%dk)\n\r",p_header[i].p_align,p_header[i].p_align/1024);
		printf("copying %d bytes from 0x%X to 0x%X...",p_header[i].p_filesz,address+p_header[i].p_offset,p_header[i].p_paddr);
		mem_cpy(address+p_header[i].p_offset,p_header[i].p_paddr,p_header[i].p_filesz);		/* copy executable to RAM */
		printf("done!\n\r");
	}
	return 0;
}

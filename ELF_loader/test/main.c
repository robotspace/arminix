#include <stdio.h>
#include <string.h>




int readAR();

typedef struct
{
	unsigned char 	file_name[16];
	unsigned char 	mod_time[12];
	unsigned char 	owner_id[6];
	unsigned char 	group_id[6];
	unsigned char 	file_mode[8];
	unsigned char 	file_size[10];
	unsigned char 	file_magic[2];
} ar_hdr;

ar_hdr ar_header;		//global AR header


main(int argc, char *argv)
{
	readAR();
	return 0;
}

int readAR(){
	FILE *fp ;
	char data[100000];		//Moet toch wat?
	long AR_magic = 0x0A3E686372613C21;		/* Magic string "!<arch>" */
	int i;
	fp = fopen ("pack.a","r");
	if(fp == NULL){
        printf("cannot open file");
        return(-1);
    }
	
	for(i = 0; i <= sizeof(data); i++){
		data[i] = fgetc(fp) ;
		if(data[i] == EOF) break;
	}
	
	
	
	if(memcmp(&data, &AR_magic, sizeof(AR_magic)) != 0){
        printf("ERROR: no AR!\n\r");
		return -1;
	}
	else{
		printf("Found valid AR file\n\r");
		memcpy(&ar_header, &data[8], sizeof(ar_header));	// 8 byte offset for AR Magic
		printf("filename: ");
		for(i=0; i<100; i++){			// Print file name (terminated with a '/')
			if(ar_header.file_name[i] == '/'){
				break;
			}
			printf("%c",ar_header.file_name[i]);
		}
		printf(" (");
		for(i=0; i<10; i++){
			if(ar_header.file_size[i] != 0x20){			//Ignore whitespace
				printf("%c",ar_header.file_size[i]);
			}
		}
		printf(" bytes)\n\r");
	}
}
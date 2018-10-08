#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	//declare variables
	FILE *source, *copy;
	//char fileCopy = *argv[2],file = argv[1],tempWord="";
	char word=' ';
	 
	
	source = fopen(argv[1], "r");
	
	//check if file can be opened 
	if(source == NULL){
		printf("Error file cannot be opened...\n");
		printf("Program Closing\n");
		exit(EXIT_FAILURE);
	}
	
	copy = fopen(argv[2], "w");
	//check if file can be created
	if(copy == NULL){
		printf("Error copied file cannot be created...\n");
		printf("Program Closing\n");
		exit(EXIT_FAILURE);
	}
	
	//copy text from file1 to copyfile
	while((word = fgetc(source)) != EOF){
		fputc(word, copy);
	}
	
	printf("File copied.\n");
	
	fclose(source);
	fclose(copy);
}//end of main

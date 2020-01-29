#include<stdio.h>
#include"vigenere.c"

int main(){
	char plaintext[100] = "ATTACKATDAWN"; 
	char keyword[100] = "LEMON";		     
	char encrypted[100] = "LXFOPVEFRNHR"; 
	int flag;

	printf("Enter keyword: ");
	scanf("%s",keyword);
	
	do{
	printf("Choose the operation you wish:\n");
	printf(" Enter '1' to 'encrypt' a message.\n Enter '2' to 'decrypt' a message.\n Enter '0' to exit.\n");
	scanf("%d",&flag); 
	if(flag==1){
		printf("Enter the message: ");
		scanf("%s",plaintext);
		encrypt(plaintext,keyword);
	}
	else if(flag==2){
		printf("Enter your encrypted message: ");
		scanf("%s",encrypted);
		decrypt(encrypted,keyword);
	}	
	else if(flag!=0)
		printf("Enter a valid integer(1,2 or 0)..\n");
	
	}while(flag!=0);

	printf("Exiting..");

	return 0;
}



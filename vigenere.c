#include"vigenere.h"

//this method gives the number of elements of an array
int getSize(char word[100]){
	int counter=0;
	while((word[counter]>=65 && word[counter]<=90) || (word[counter]>=97 && word[counter]<=122)){
		counter++;
	}	
	return counter;
}
void decrypt(char encrypted[100], char keyword[100]){
	int i,keywordLength,encryptedLength;
	encryptedLength = getSize(encrypted);
	
	char decrypted[encryptedLength];
	keywordLength = getSize(keyword);
	//the loop is used to shift each letter
	for(i=0;i<encryptedLength;i++){
		// 26 added for the cases negative numbers occurs
		if((encrypted[i] >= 65 && encrypted[i]<=90) && (keyword[i%(keywordLength)] >= 65 && keyword[i%(keywordLength)]<=90)){
			decrypted[i]=65+(encrypted[i]-keyword[i%(keywordLength)]+26)%26; 
		}
		else if((encrypted[i] < 65 || encrypted[i]>90) && (keyword[i%(keywordLength)] < 65 || keyword[i%(keywordLength)]>90)){
			decrypted[i]=65+(encrypted[i]-32-keyword[i%(keywordLength)]-32+26)%26; 
		}
		else
			decrypted[i]=65+(encrypted[i]-keyword[i%(keywordLength)]-32+26)%26; 
		
	}
	printf("Message decrypted: ");
	for(i=0;i<encryptedLength;i++){
		printf("%c",decrypted[i]);
	}
	printf("\n");
}


void encrypt(char plaintext[100],char keyword[100]){
	int i,keywordLength,plaintextLength;
	plaintextLength = getSize(plaintext);
	
	char encrypted[plaintextLength]; 
	keywordLength=getSize(keyword);
	//the loop is used to shift each letter
	for(i=0;i<plaintextLength;i++){
	//subtracting -32 (difference between 'A' and 'a') when necessary, provides case insensitivity.	
		if((plaintext[i] >= 65 && plaintext[i]<=90) && (keyword[i%(keywordLength)] >= 65 && keyword[i%(keywordLength)]<=90)){
			encrypted[i]=65+(plaintext[i]+keyword[i%(keywordLength)])%26; 
		}
		else if((plaintext[i] < 65 || plaintext[i]>90) && (keyword[i%(keywordLength)] < 65 || keyword[i%(keywordLength)]>90)){
			encrypted[i]=65+(plaintext[i]-32+keyword[i%(keywordLength)]-32)%26; 
		}
		else
			encrypted[i]=65+(plaintext[i]+keyword[i%(keywordLength)]-32)%26; 
		}
	printf("Message encrypted: ");
	for(i=0;i<plaintextLength;i++){
		printf("%c",encrypted[i]);
	}
	printf("\n");
 }









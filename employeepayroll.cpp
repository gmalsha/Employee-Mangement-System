#include <stdio.h>
#include <string.h>

int main(void){
	
	char Id[10];
	char name[30];
	int phoneNumber[10];
	char findId[10];
	FILE*cfPtr;
	int i,n;
	cfPtr = fopen("C:\\Users\\User\\Documents\\Projects\\c\\employeedata.dat", "w");
	if(cfPtr==NULL){
		printf("File cannot be open");
		return-1;
	}
	// Enter the employess data
	printf("Enter the number of employees : ");
	scanf("%d", &n) ;
	for(i=1 ; i<=n; ++i){
		printf("Pls input the Employee ID:");
		scanf("%s", &Id);
		printf("Pls input the  name:");
		scanf("%s", &name);
		printf("Pls input the phone number:");
		scanf("%d",&phoneNumber);
		fprintf(cfPtr,"%s%s%d\n",Id,name,phoneNumber);
		printf("Successfully updated\n");
		}
		fclose(cfPtr);
		
	// Read the data from employess
	cfPtr = fopen("C:\\Users\\User\\Documents\\Projects\\c\\employeedata.dat", "r");
		if(cfPtr==NULL){ 
		printf("File cannot be open");
		return-1;
	}
	printf("Pls input the Employee ID:");
	scanf("%s", &findId);
	while(!feof(cfPtr)){
			printf(":");
		if(strcmp(findId, Id) == 0){
		printf("%s%s", name , phoneNumber);
		}
	fclose(cfPtr);	
    }
}


	

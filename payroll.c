#include <stdio.h>
#include <string.h>

	
int id;
char name[10],phoneNo[10];
float allowance, basicSalary , netSalary;
int otHour ;


void getEmployeeDetails();
void findEmployee();
void displaySalary();


char detailFilePath[]={"C:\\Users\\User\\Documents\\Projects\\c\\details1.txt"};
char salaryFilePath[]={"C:\\Users\\User\\Documents\\Projects\\c\\salary2.txt"};


int main(void){
	
	int choice;
	while(1)
	{
    
	  printf("==================Employee Payroll System=============\n\n");
	  
      printf("1. Add New Employee\n\n");
      printf("2. Search Employee \n\n");
      printf("3. View Salary\n\n");
      printf("4. Exit\n\n");

      printf("------------------------------------------------------\n\n");

      printf("\nPlease enter your Choice:");
      scanf("%d",&choice);

      if (choice != 4) {
            switch(choice){

                case 1: getEmployeeDetails();
                break;

                case 2: findEmployee();
                break;

                case 3: displaySalary();
                break;

                case 4: //exit();
                break;
            }
            printf("\n Do You Want To Continue(1/0):");
            scanf("%d", &choice);
            printf("\n\n");
        } else {
                choice = 0;
        }

        if (!choice) {
                break;
      	  }
	}	
	}
	//get employee details and store in a file
	void getEmployeeDetails(){
		FILE *fpDetails;
		fpDetails=fopen(detailFilePath,"ab");
		
		FILE *fpSalary;
		fpSalary=fopen(salaryFilePath,"ab");
		
		int i,n;
		
	printf("Enter the number of employees : ");
	scanf("%d", &n) ;
	
	
		
			for(i=1 ; i<=n; ++i){
		printf("Pls input the Employee ID:");
		scanf("%d", &id);
		
		printf("Pls input the  name:");
		scanf("%s", &name);
		
		printf("Pls input the phone number:");
		scanf("%s",&phoneNo);
		
		fprintf(fpDetails,"%d%s%s\n",id,name,phoneNo);
	
		printf("Pls input the allowance:");
		scanf("%f",&allowance);
		
		printf("Pls input the Basic Salary:");
		scanf("%f",&basicSalary);
		
		printf("Pls input the OT:");
		scanf("%d",&otHour);
		
		netSalary = basicSalary + otHour*250 + allowance;
		printf("salary : %f",netSalary);		
		fprintf(fpSalary,"%d%d%f%f%f\n",id, otHour , allowance, basicSalary, netSalary);
		printf("Successfully updated\n");
			
		
	}
	

	fclose(fpDetails);	
	fclose(fpSalary);	
		
	}
	
	
    // Find employee by id
void findEmployee(){
	FILE *fp;
	fp=fopen(detailFilePath,"r");
		

	fscanf(fp,"%d%s%s\n",&id,&name,&phoneNo );
	
	while(1){
		if(feof(fp)){
		break;
		}

		printf("Employee Id : %d\n",id);
		printf("name : %s\n",name );
		printf("phone No : %s\n",phoneNo);
		fscanf(fp,"%d%s%s\n",id,name,phoneNo );
	}

		
	fclose(fp);
	}
	
	//find employees salary 
void displaySalary(){
	FILE *fpSalary;
	fpSalary=fopen(salaryFilePath,"r");
	fscanf(fpSalary,"%d%d%f%f%f\n",id, otHour , allowance, basicSalary, netSalary );
	
		while(!feof(fpSalary)){
		printf("Employee Id : %d\n",id);
		printf("OT Hour : %d\n",otHour );
		printf("Allowance : %f\n",allowance);
		printf("basic Salary : %f\n", basicSalary);
		printf("net Salary : %f\n", netSalary);
		fscanf(fpSalary,"%d%d%f%f%f\n",id, otHour , allowance, basicSalary, netSalary );
		}
	
	
	fclose(fpSalary);
	}
	



	
	



#include <stdio.h>
#include <string.h>

struct employee{
	
	int id;
	char name[10],phoneNo[10];
	};  
	
struct salary{
	
    float allowance, basicSalary , netSalary;
    int empId , otHour ;
	}; 

void getEmployeeDetails();
void findEmployee();
void displaySalary();
void addSalary();

char detailFilePath[]={"C:\\Users\\User\\Documents\\Projects\\c\\details.txt"};
char salaryFilePath[]={"C:\\Users\\User\\Documents\\Projects\\c\\salary.txt"};


int main(void){
	
	int choice;
	while(1)
	{
    
	  printf("==================Employee Payroll System=============\n\n");
	  
      printf("1. Add New Employee\n\n");
      printf("2. Add Salary\n\n");
      printf("3. Search Employee \n\n");
      printf("4. View Salary\n\n");
      printf("5. Exit\n\n");

      printf("------------------------------------------------------\n\n");

      printf("\nPlease enter your Choice:");
      scanf("%d",&choice);

      if (choice != 5) {
            switch(choice){

                case 1: getEmployeeDetails();
                break;

                case 2: addSalary();
                break;

                case 3: findEmployee();
                break;

                case 4: displaySalary();
                break;

                case 5: //exit();
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
		struct employee empObject;
		fpDetails=fopen(detailFilePath,"ab");
		
		int i,n;
		
	printf("Enter the number of employees : ");
	scanf("%d", &n) ;
	
	for(i=1 ; i<=n; ++i){
		printf("Pls input the Employee ID:");
		scanf("%d", &empObject.id);
		
		printf("Pls input the  name:");
		scanf("%s", &empObject.name);
		
		printf("Pls input the phone number:");
		scanf("%s",&empObject.phoneNo);
		
		fwrite(&empObject,sizeof(empObject),1,fpDetails);
			
		}
	fclose(fpDetails);	
		
	}
	
	
	// Add salary to employees and store in another file
	void addSalary(){
		
		FILE *fpSalary;
		struct salary salaryObject;
		fpSalary=fopen(salaryFilePath,"ab");
		
		int i,n;
		
	printf("Enter the number of employees : ");
	scanf("%d", &n) ;
	
	for(i=1 ; i<=n; ++i){
		printf("Pls input the Employee ID:");
		scanf("%d", &salaryObject.empId);
		
		printf("Pls input the allowance:");
		scanf("%f",&salaryObject.allowance);
		
		printf("Pls input the Basic Salary:");
		scanf("%f",&salaryObject.basicSalary);
		
		printf("Pls input the OT:");
		scanf("%d",&salaryObject.otHour);
		
		salaryObject.netSalary = salaryObject.basicSalary + salaryObject.otHour*250 + salaryObject.allowance;
		printf("%f",salaryObject.netSalary);
		
		fwrite(&salaryObject,sizeof(salaryObject),1,fpSalary);
		
		}
	fclose(fpSalary);	
			}
	
    // Find employee by id
	void findEmployee(){
		FILE *fp;
		struct employee empObject;
		int id,empFound=0;
		fp=fopen(detailFilePath,"rb");
		
		printf("\nEnter the Emp ID:");
		scanf("%d",&id);
		
		while(1){
			fread(&empObject,sizeof(empObject),1,fp);
			if(feof(fp))
			{
			break;
			}
				empFound=1;
				printf("\n============================================================\n\n");
				printf("\t\t Employee Details of %d\n\n",empObject.id);
				printf("==============================================================\n\n");
				printf("Employee Name : %s\t",empObject.name);
				printf("Employee Phone Number: %s\t",empObject.phoneNo);
			

		}
	}
	
		//find employees salary 
		void displaySalary(){
		FILE *fpSalary;
		struct salary salaryObject;
    	fpSalary=fopen(salaryFilePath,"rb");
		while(1){
			fread(&salaryObject,sizeof(salaryObject),1,fpSalary);
			if(feof(fpSalary))
			{
			break;
			}	
				printf("\n============================================================\n\n");
				printf("\t\t Employee Details of %d\n\n",&salaryObject.empId);
				printf("==============================================================\n\n");
				printf("%f\t",&salaryObject.netSalary);
	 	}
    	fclose(fpSalary);
		}
	
	
	



//Its use: To calculate your electric bill

#include <stdio.h>
#include "tools.h"

double calculate(double a){
	double b = 0;
	if(a>1000){      b = (a-1000)*10.97 + 4450 + 790 + 1870;   }
	else if(a>500){  b = (a-500)*8.9 + 790 + 1870;             }
	else if(a>400){  b = (a-400)*7.9 + 1870;                   }
	else if(a>300){  b = (a-300)*6.9 + 1180;                   }
	else if(a>200){  b = (a-200)*5.9 + 590;                    }
	else if(a>150){  b = (a-150)*4.5 + 365;                    }
	else if(a>100){  b = (a-100)*3.55 + 187.5;                 }
	else if(a>50){   b = (a-50)*2.6 + 57.5;                    }
	else{            b =  a *1.15;                             }
	return b;
}

void electricBill(void){
	double bill, pm, cm, units;
	char c;
	char buffer_a[20], buffer_b[20];
	printf("\nElectric Bill Calculator\n");
	puts("--------------------------------------------------");
	c = verify();
	while(c == 'Y'||c == 'y'){
		puts("--------------------------------------------------");
		bill=0; //reset bill to 0
		printf("Enter your previous month reading: ");
		fgets(buffer_a,15,stdin);
		sscanf(buffer_a,"%lf",&pm);
		puts(" ");
		printf("Enter your current month reading:  ");
		fgets(buffer_b,15,stdin);
		sscanf(buffer_b,"%lf",&cm);
		puts(" ");
		units = cm - pm;
		if(units<0){ printf("Invalid inputs. Try again.\n");}
		else{
			printf("Total units consumed: %.2f\n",units);
			bill = calculate(units);
			printf("Total Bill = $%.2f\n",bill);
		}
		c = verify();
	}
}

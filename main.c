#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
/*
	@author Paulo Ferreira
		
*/

void menu(void){
	printf("\n\nOptions:\n");
	printf("u: +1kg, U: +10kg, d: -1kg, D: -10kg, q: quit\n");
	printf("->");
}


int main(void){
	stack st; 
	float weightTypes [11] = {25, 25, 20, 15, 10, 5, 2.5, 2, 1.5, 1, 0.5}; // weight types available in kilogram (kg)
	
	
	int bar_weight; 	// weight informed on the barbell 
	float remaining, remove = 0; 	// remaining weight for the weight of the barbell; Weight to be removed;
	char op;
	
	do{ 			// Repeat until you enter an agreed upon weight
		printf("Enter the starting weight:");
		scanf("%d",&bar_weight);
		
		if(bar_weight > 108 || bar_weight < 0)
			printf("The max weight is 108kg!\n");
		
	}while(bar_weight > 108 || bar_weight < 0);
	

	init(&st, 10); // initializa stack
	
	remaining = bar_weight;

	do{
		printf("\n====\n");
		printf("Total weight on barbell: %dkg\n\n", bar_weight);

		// based on bar_weight, change the stack as needed
		int i = 0;
		while(remaining > 0){ // does it while missing weight to match the weight of the bar
			
			if(weightTypes[i] <= remaining){		// checks if the weight type is <= the rest
				push(&st, weightTypes[i]);		// if it is, pushes the type on the stack
				remaining -= weightTypes[i];		// decreases what was added from the remaining value
			}
			
			i++;
		}

		printf("Weight arrangement:\n");
		int j;
		for(j = 0; j <= st.top; j++)
			printf("%.1f ",st.items[j]);
		

		menu();
		scanf(" %c", &op);

		switch(op){
			//============================= + 1kg
			case 'u':	
				bar_weight++;
				remaining++;
				
				if(bar_weight >= 108){ 	// If exceed the max weight
					printf("\nBIRLL! You have exceeded the max weight!\n");
					bar_weight -= 1; 	// decrements what was added
					remaining -= 1;
					break;
				}
				
				i=0;
				while (remaining > 0){
					
					if(peek(&st) <= remaining){ 	// If top of stack <= remainder, removes from top
						remaining += pop(&st); 	// pop returns the value that will be removed
						
					}else if(weightTypes[i] <= remaining){
						push(&st, weightTypes[i]);
						remaining -= weightTypes[i];
					}
					
					i++;
					
					if(i > 11) // if larger than the available weight types
						break;
				}
				break;
				
			//============================= - 1kg	
			case 'd':
				
				bar_weight--;

				if(bar_weight < 0){ 	// check if the bar is empty
					printf("\nLess than the minimum weight limit!\n");
					bar_weight += 1;
					break;
				}
				
				if(peek(&st) <= 1.0){ 		// if the top is < or = 1
					if(peek(&st) == 0.5)	// if the top is = 0.5, remove it
						remaining += pop(&st);
					
					remaining += pop(&st); 	// removes the rest, equivalent to 1
				}
				else 
					remaining = pop(&st); 	// if last pos > than 1 remove, and add in remaining, and then put the weights accordingly
				
				remaining = remaining-1;  // Subtracts the weight to be decreased (-1)
				
				i=0;
				while (remaining > 0){
					
					if(weightTypes[i] <= remaining){
						push(&st, weightTypes[i]);
						remaining -= weightTypes[i];
					}
					
					i++;
					
					if(i > 11)
						break;
				}
				
				break;
				
			//============================= + 10kg	
			case 'U': 	
				bar_weight += 10;
				remaining += 10;
				
				if(bar_weight >= 108){
					printf("\nBIRLL! You have exceeded the max weight!\n");
					bar_weight -= 10; 
					remaining -= 10;
					break;
				}
				
				i=0;
				while (remaining > 0){
					
					if(peek(&st) <= remaining){ 
						remaining += pop(&st); 	
						
					}else if(weightTypes[i] <= remaining){
						push(&st, weightTypes[i]);
						remaining -= weightTypes[i];
					}
					
					i++;
					
					if(i > 11)
						break;
				}
				break;
				
			//============================== - 10kg	
			case 'D':	
				bar_weight-=10;
				remaining = 0;
				remove = 0;
				
				if(bar_weight < 0){
					printf("\nA barra esta vazia!\n");
					bar_weight+=10;
					break;
				}
				
		
				if(peek(&st) <= 10){
					while(remove < 10) 	// removes until it reaches 10 or more
						remove += pop(&st); // remove gets the removed pos, to recalculate the weights
				}else 
					remove = pop(&st); 	// if last pos > 10, remove and add in remainder
				
				
				remaining = (remove - 10); 
				//printf("\nremaining: %.1f", remainder);
				
				i=0;
				while (remaining > 0){
					
					if(weightTypes[i] <= remaining 
						&& weightTypes[i] != peek(&st)){ // 2nd validation is to not add a weight that already exists (duplicate)
							push(&st, weightTypes[i]);
							remaining -= weightTypes[i];
					}
					
					i++;
					
					if(i > 11)
						break;
				}
				
				break;
				
				
			case 'q':
				printf("Going out.\n");
				break;
				
			default:
				printf("Invalid option...\n");
		}
	}while(op!='q');

	printf("\n\nFinished program...\n");

	return 0;
}

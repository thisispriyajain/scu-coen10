////Priya Jain
////COEN 10
////Tuesday 9:15am
////Lab #7

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {
	char schedule[5][20] = {'\0','\0','\0','\0','\0'};
	char customer[20];
	int counter;
	int check;
	int input;
	char letter;
	int i;
	int j;
	
	while(1) {
		printf("Welcome to the Pet Grooming Salon. \n");
 		printf("How can we help you today? \n");
		printf("1: Request an appointment. \n");
		printf("2: Cancel an appointment. \n");
		printf("3: List the schedule. \n");
		printf("4: Show names starting with a letter. \n");
		printf("9: Exit. \n");
		scanf("%d", &input);
		switch(input) {
			case 1:
				if(counter >=  5) {
                                	printf("Sorry, the groomer is all booked up. Please come back tomorrow.\n");
                        		break;
				}
				else {
                                	printf("Who is the appointment for? \n");
                                	scanf("%s", &customer);
                    			for(i=0; i<5; i++) {
                                        	if(schedule[i][0] == '\0') {
                                                	strcpy(schedule[i], customer);
                                                	counter++;
						       	printf("An appointment for %s has been scheduled for %d pm. \n", customer, i+1);
                                         		break;
						}
					}
				}
				break;
			case 2:
				if(counter == 0) {
                                  	printf("All appointments are available. \n");
                         	}
                        	else {
                                	printf("Whose appointment would you like to cancel? \n");
                                	scanf("%s", &customer);
                                	for(i=0; i<5; i++) {
                                        	if(strcmp(schedule[i], customer) == 0) {
							schedule[i][0] == '\0';
                                       			counter--;
							printf("Your appointment for %s at %d pm has been cancelled. \n", customer, i+1);
							for(j=i; j<4; j++) {
								strcpy(schedule[j], schedule[j+1]);
								schedule[j+1][0] = '\0';
							}
						}
						else {
							printf("There is no appointment for %s. \n", customer);
							break;
						}
                               		}
				}
				break;
			case 3:
				if(counter == 0) {
                                	printf("All appointments are available. \n");
                        	}
				else {
                                	for(i=0; i<5; i++) {
                                        	if(schedule[i][0] == '\0') {
                                                	printf("%d pm - Free \n", i+1);
                                        	}
                                       		else {
                                                	printf("%d pm - %s\n", i+1, schedule[i]);  	 
			           		}
					}
				}
				break;			
			case 4:
				if(counter == 0) {
                                        printf("All appointments are available. \n");
                                }
				else {
					printf("Enter a letter for the names you would like to see. \n");
					scanf(" %c", &letter);	
					check = 0;
					for(i=0; i<5; i++) {
						if(schedule[i][0] == letter) {
							//printf("The names found that start with %c are: \n", letter);
                                                        printf("%s \n", schedule[i]);
							check++;
						}
					}
					if(check == 0) {
						printf("There are no names with the letter %c. \n", letter);    	
					}
						
				}	
				break;	
			case 9:
				return 0;
				break;
			default:
				printf("That command does not exist.\n\n");
				break;
		}
	}
	return 0;
}

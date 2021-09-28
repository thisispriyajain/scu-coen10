////Priya Jain
////COEN 10
////Tuesday 9:15am
////Lab #6

#include <stdio.h>
#include <stdlib.h>

int main() {
	int appts[5] = {0,0,0,0,0};
	int counterone;
	int countertwo;
	int counterthree;
	int userinput;
	int usertime;
	int sessions = 5;
	int i;

	while(1) {
		printf("Welcome to StinkyPetSpa Inc. How can we help you today? \n");
		printf("1: Schedule an appointment. \n");
		printf("2: Cancel an appointment. \n");
		printf("3: List the schedule. \n");
		printf("9: Exit. \n");
		scanf("%d", &userinput);
		if(userinput == 1) {
			if(counterone >=  5) {
                                 printf("Sorry, the groomer is all booked up. Please come back tomorrow.\n");
                        }
			else {
				for(i=0; i<sessions; i++) {
					if(appts[i] == 0) {
						appts[i] = 1;
						counterone++;
						printf("Your appointment has been scheduled for %d pm. \n", i+1);
						break;
					}
				}
			}
		}
		else if(userinput == 2) {
			 if(counterone == 0) {
                                  printf("All appointments are available. \n");
                         }
			else {
				printf("Which appointment would you like to cancel? \n"); 
				scanf("%d", &usertime);
				for(i=0; i<sessions; i++) {
					if(appts[i] == 0) {
						countertwo++;
					}
				}
				if(appts[usertime-1] == 1) {
					appts[usertime-1] = 0;
					countertwo--;
					counterone--;
					printf("Your appointment at %d pm has been cancelled. \n", usertime);			
				}
				else if(appts[usertime-1] == 0) {
					printf("There is no appointment scheduled at %d pm. \n", usertime);
				}
			}	
		}
		else if(userinput == 3) {
			if(counterone == 0) {
				printf("All appointments are available. \n");
			}
			//else if(counterone == 5) {
			//	printf("All appointments are filled up.");
			//}
			else {
				for(i=0; i<sessions; i++) {
					if(appts[i] == 0) {
						printf("%d pm - Free \n", i+1);
					}
					else if(appts[i] == 1) {
                                                printf("%d pm - Busy \n", i+1);
                                        }
				} 
			}
		}			
		else if(userinput == 9) {
			return 0;	
		}
		else {
			printf("Bad option.\n");
		}
	}
}

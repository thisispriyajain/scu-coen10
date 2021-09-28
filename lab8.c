////Priya Jain
////COEN 10
////Tuesday 9:15am
////Lab #8

#include <stdio.h>
#include <string.h>

void request();
void cancel();
void list();
void letter();
void numberOfPets();

char schedule[5][20] = {'\0','\0','\0','\0','\0'};
char phoneNumbers[5][20] = {'\0','\0','\0','\0','\0'};

int numOfPets[5] = {0,0,0,0,0};
int counter = 0;

int main() {
	int input;
	while(1) {
		printf("Welcome to the Pet Grooming Salon. \n");
 		printf("How can we help you today? \n");
		printf("1: Request an appointment. \n");
		printf("2: Cancel an appointment. \n");
		printf("3: List the schedule. \n");
		printf("4: Show names starting with a letter. \n");
		printf("5: Show names with a certain number of pets. \n");
		printf("9: Exit. \n");
		scanf("%d", &input);
		switch(input) {
			case 1:
				request();
				break;
			case 2:
				cancel();				     
				break;
			case 3:
				list();
				break;			
			case 4:
				letter();
				break;	
			case 5:
				numberOfPets();
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

void request() {
	char customer[20];
	char userNumber[20];
	int userPets;
	int i;
	if(counter >= 5) {
		printf("Sorry, the groomer is all booked up. Please come back tomorrow.\n"); 
        }
        else {                               
		printf("Who is the appointment for? \n");
              	scanf("%s", &customer);                
		for(i=0; i<5; i++) {
			if(strcmp(schedule[i], customer) == 0) {
				printf("There is already an appointment for that customer.\n");
				break;
			}
			else {
				if(schedule[i][0] == '\0') {
					printf("What is their phone number? \n");
					scanf("%s", &userNumber);
					printf("How many pets (1-4) will they bringing in? \n");
					scanf("%d", &userPets);	
					strcpy(schedule[i], customer);
                                	counter++;
                         		strcpy(phoneNumbers[i], userNumber);
					numOfPets[i] = userPets;	
					printf("An appointment for %s for %d pets has been scheduled for %d pm. \n", customer, userPets, i+1);
                 			break;
				}
			}
		}		
	}
}

void cancel() {
	char customer[20];
	int i;
	int j;	
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
                                printf("%s's appointment at %d pm has been cancelled.\n", customer, i+1);
                            	//printf("%s's appointment has moved up to %d pm.\n", schedule[i-1], i+1);
				//printf("%s's appointment has moved up to %d pm.\n", schedule[i], i+1); 
				for(j=i; j<4; j++) {
					strcpy(schedule[j], schedule[j+1]);
                                        schedule[j+1][0] = '\0';
                                	strcpy(phoneNumbers[j], phoneNumbers[j+1]);
					phoneNumbers[j+1][0] = '\0';
					numOfPets[j] = numOfPets[j+1];
					numOfPets[j+1] = 0;
					if(schedule[j][0] != '\0') {
						printf("%s's appointment has moved up to %d pm. Contact Information: %s \n", schedule[j], j+1, phoneNumbers[j]);
					}
				}
				break;
                        }
                        //else {
                               // printf("There is no appointment for %s. \n", customer);
                                //break;                               
			//}
              }
		printf("There is no appointment for %s. \n", customer);
                //break;
    	}
}

void list() {
	int i;
	if(counter == 0) {
		printf("All appointments are available. \n");
        }
       	else {
		printf("Time\tCustomer\tPhone Number\tPets\n");
       		//printf("----\t --------\t ------------ \t----`\t\n");
		for(i=0; i<5; i++) {
			if(schedule[i][0] == '\0') {				
				printf("%d pm \t Free \t \n", i+1);
                        }
                       	else {
                                printf("%d pm\t%s\t%s\t%d pets\n", i+1, schedule[i], phoneNumbers[i], numOfPets[i]);
                        }
                }
       }          
}

void letter() {
	char userLetter;
	int userCheck;
	int i;
	if(counter == 0) {                            
		printf("All appointments are available. \n");
	}
	else {
		printf("Enter a letter for the names you would like to see. \n");
                scanf(" %c", &userLetter);
                userCheck = 0;
                for(i=0; i<5; i++) {
			if(schedule[i][0] == userLetter) {
				//printf("The names found that start with %c are: \n", letter);
                                //printf("%s \n", schedule[i]);
                        	printf("%s - %d pm \n", schedule[i], i+1);
                		userCheck++;
			}
		}
                if(userCheck == 0) {
			printf("There are no names with the letter %c. \n", userLetter);
		}
	}
}

void numberOfPets() {
	int petSearch;
	int petCheck = 0;
	int i;
	if(counter == 0) {
                printf("All appointments are available. \n");
        }
	else {
		printf("How many pets would you like to search for? \n");
		scanf("%d", &petSearch); 
        	for(i=0; i<5; i++) {
			if(numOfPets[i] == petSearch) {
				printf("%s - %d pets - %d pm \n", schedule[i], petSearch, i+1);
                        	petCheck++;
			}
		}
		if(petCheck == 0) {
			printf("There are no appointments with %d pets.\n", petSearch);
        	}
	}
}

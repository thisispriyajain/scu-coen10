//Priya Jain
//COEN 10L
//Tuesday 9:15am
//Lab #5

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	printf("Lab 5: Multiplication Game\n");
	srand((int)time(NULL));
	int userans=0;
	int counter=0;
	int i;

	for(i=0; i<10; i++) {
		int num1 = rand() % 13;
		int num2 = rand() % 13;
		int product = num1*num2;
		printf("What is %d * %d?\n" , num1, num2);
		scanf("%d", &userans);
		if(product == userans) {
       			printf("That is correct.\n");
			counter++;
		}
		else if(product != userans) {
			printf("That is incorrect. The correct answer is %d.\n", product);
		}
	}

	printf("You got %d%%.\n", counter*10); 

}

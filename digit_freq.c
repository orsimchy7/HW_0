// 123456789
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_STRING_LEN 1000


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
	char string[MAX_STRING_LEN];
	fgets(string, MAX_STRING_LEN, stdin);

	//string[strlen(string) - 1] = '\0';
    if (string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }
	//create histogram for 10 digits
	int hist[10] = {0};

	//iterate over the string. for each char check if is number. if yes, update
	//hist

	for(int i=0; i< strlen(string); i++){
		int value = *(string + i) - '0'; //reduce the ASCI value of 0- get int.
		// after reducing 0 ASCI value - if the char was a number, now the
		//value will be the number (int)

		if(value >= 0 && value <= 9 ){
			hist[value] ++;
		}

	}

	//print histogram
	/*for(int i = 0; i< 9; i++){
		printf("%d " , hist[i]);
	}

	printf("%d\n", hist[9]);
	*/

    // Print histogram
    for (int i = 0; i < 10; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", hist[i]);
    }
    printf("\n");

    return 0;
}

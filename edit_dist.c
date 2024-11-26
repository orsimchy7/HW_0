#include <stdio.h>
#include <string.h>


#define MAX_WORD_LEN 100
int edit_dist(char word1[], char word2[]);

int recursiveCall(char *letter1, char* letter2, int distance,
		int* min_distance_pointer);

int main() {
	char word1[MAX_WORD_LEN], word2[MAX_WORD_LEN];
	
	fgets(word1, MAX_WORD_LEN, stdin);
	word1[strlen(word1) - 1] = '\0';
	fgets(word2, MAX_WORD_LEN, stdin);
	word2[strlen(word2) - 1] = '\0';

	printf("%d\n", edit_dist(word1, word2));

	return (0);
}

int edit_dist(char word1[], char word2[]) {
	/* YOUR CODE HERE */
	int min_distance = MAX_WORD_LEN;
	int *min_distance_pointer = &min_distance;

	//=== check if one of the strings is empty
		if(word1[0] == '\0'){
			return strlen(word2);
		}

		if(word2[0] == '\0'){
			return strlen(word1);
		}



	recursiveCall(word1, word2, 0, min_distance_pointer);


	return min_distance;

}

int recursiveCall(char *letter1, char *letter2, int distance,
		int* min_distance_pointer){

	//when entering to a new branch- check if distance should update
	if(*letter1 != *letter2){
		distance ++;
	}

	// STOP conditions START -----------
	if(distance >= *min_distance_pointer){
		return 0;
	}


	if( (*letter1 == '\0') && (*letter2 == '\0') &&
			(distance < *min_distance_pointer)){
		/*Branch got current distance minimum - Success		 */
		*min_distance_pointer = distance;
		return 0;
	}

	// if one string reached to it's end- we exit the branch and calc remaining
	//distance

	if(*letter1 == '\0'){

		distance += strlen(letter2);
		if(distance >= *min_distance_pointer){
			*min_distance_pointer = distance;
		}

		return 0;
	}

	if(*letter2 == '\0'){

		distance += strlen(letter2);
		if(distance >= *min_distance_pointer){
			*min_distance_pointer = distance;
		}
		return 0;
	}

	// STOP conditions END  -----------

	char *next_letter1 = letter1 + 1;
	char *next_letter2 = letter2 + 1;

	/* More recursive calls:
	 * # if next pair of latters are equal -> SKIP (distance = distance).
	 *Otherwise, we have 3 operations to try: REPLACE, DELETE, ADD.
	 *REPLACE: we promote both pointers, distance ++.
	 *DELETE: we promote only the pointer of str1, distance ++
	 *ADD: we promote only the pointer of str2, distance ++
	 */

	if(*next_letter1 == *next_letter2){
		//the next call will check the next pair of letters for changes
		// === SKIP ===
		recursiveCall(next_letter1, next_letter2,
				distance, min_distance_pointer);
	}

	// === Replace letter1 ===
	recursiveCall(next_letter1, next_letter2, distance, min_distance_pointer);

	// === DELETE letter1 ===
	recursiveCall(next_letter1, letter2, distance, min_distance_pointer);

	// === ADD letter2 before letter 1 ===
	recursiveCall(letter1, next_letter2, distance , min_distance_pointer);

	return 0;

}





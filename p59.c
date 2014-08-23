#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * readLine(char fileName[]) {
	//for file reading
	FILE * f = fopen(fileName, "r");
	size_t bufferSize = 100;
	char * buffer = malloc(bufferSize * sizeof(char));

	getline(&buffer, &bufferSize, f);

	fclose(f);

	return buffer;
}

int main(int argc, char* argv[]){
	char * line = readLine("cipher.txt");

	//each token
	char * token;

	//delimiter
	const char comma[] = ",";

	//number of tokens, determined by looping through and counting
	int numTokens = 1201;

	//array of tokens, as ints
	int* tokens[numTokens];

	//keeping track of frequencies, remembering that there are 3 characters in the encryption key
	int frequencies[3][100] = {{0}, {0}, {0}};

	//parse string by comma delimiter
	token = strtok(line, comma);

	int i;
	for(i = 0; token != NULL; i++){
		tokens[i] = malloc(sizeof(int));
		*(tokens[i]) = atoi(token);
		frequencies[i%3][*(tokens[i])]++;
		token = strtok(NULL, comma);
	}

	//find most common character for all 3 sets
	int maxFrequency[3] = {0};
	char maxFrequencyChar[3];
	for (int i = 0; i < 100; ++i){
		if(frequencies[0][i] > maxFrequency[0]){
			maxFrequency[0] = frequencies[0][i];
			maxFrequencyChar[0] = (char)i;
		}

		if(frequencies[1][i] > maxFrequency[1]){
			maxFrequency[1] = frequencies[1][i];
			maxFrequencyChar[1] = (char)i;
		}

		if(frequencies[2][i] > maxFrequency[2]){
			maxFrequency[2] = frequencies[2][i];
			maxFrequencyChar[2] = (char)i;
		}
	}

	//find xor key
	char xorKey[3];
	char space = ' ';
	xorKey[0] = space ^ maxFrequencyChar[0];
	xorKey[1] = space ^ maxFrequencyChar[1];
	xorKey[2] = space ^ maxFrequencyChar[2];

	//sum decrypted message
	int sum = 0;
	for (int i = 0; i < numTokens; ++i){
		sum += (char)(*(tokens[i]) ^ xorKey[i%3]);
		free(tokens[i]);
	}

	printf("%d\n", sum);

	free(line);
	free(token);
}
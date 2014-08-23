#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int isPrime(int n){
	int i;
	for (i = 2; i <= sqrt(n); ++i) {
		if(n % i == 0){
			return 0;
		}
	}
	return 1;
}

int * genCorners(int * corners, int layer) {
	corners[0] = pow(2*layer-1, 2);
	int difference = 2*(1-layer);
	corners[1] = corners[0] + difference;
	corners[2] = corners[1] + difference;
	corners[3] = corners[2] + difference;
	return corners;
}

int main(int argc, char* argv[]){
	int totalCorners = 1;
	int primeCorners = 0;
	int * newCorners = malloc(4*sizeof(int));
	int layer;
	double ratio = ((double)primeCorners)/((double)totalCorners);
	for(layer = 2; ratio >= 0.1 || ratio == 0; layer++){
		newCorners = genCorners(newCorners, layer);
		int i;
		for(i = 0; i < 4; i++) {
			if(isPrime(newCorners[i])){
				primeCorners++;
			}
		}
		totalCorners += 4;
		ratio = ((double)primeCorners)/((double)totalCorners);
	}

	layer--;

	printf("%d\n", 2*layer - 1);

	free(newCorners);
}
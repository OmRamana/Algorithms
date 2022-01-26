#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int isEqualImages(char *fileA, char *fileB) {
	int imageA = open(fileA, O_RDONLY);
	int imageB = open(fileB, O_RDONLY);
  
	off_t currentA = lseek(imageA, (size_t)0, SEEK_CUR);
	off_t currentB = lseek(imageB, (size_t)0, SEEK_CUR);
  
	int sizeA = lseek(imageA, (size_t)0, SEEK_END);
	int sizeB = lseek(imageB, (size_t)0, SEEK_END);
  
	lseek(imageA, currentA, SEEK_SET);
	lseek(imageB, currentB, SEEK_SET);
	
	if (sizeA != sizeB) return 0;

	int i = 0;
	unsigned char a[1], b[1];
	while (i < sizeA) {
		read(imageA, a, 1);
		read(imageB, b, 1);
		if (abs(a[0] - b[0]) > 1) {
			fflush(stdout);
			close(imageA);
			close(imageB);
			return 0;
		}
		i++;
	}
	close(imageA);
	close(imageB);
	return 1;
}

extern void greyscale(char *filename, char *outputname);

int main(int argc, char *argv[]) {
	char input[] = "dog.ppm";
	char output[] = "dog_grey.ppm";
	greyscale(input, output);
	printf("%d\n", isEqualImages("dog_grey.ppm", "dog_grey_memo.ppm"));
	// 
	// If the output is 1 then it succeeded, else the file generated was incorrect
	// 
	return 0;
}
//Alexander Chatron-Michaud
//260611509
//COMP 307 A2

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int gcd(int a, int b)
{
  if (a==0) return b;
  return gcd(b%a,a);
}

bool isPrime(int a)
{
    if (a <= 1) return false;
    if (a % 2 == 0 && a > 2) return false;
    for(int i = 3; i < a / 2; i += 2)
    {
        if (a % i == 0)
            return false;
    }
    return true;
}


bool isValid(int public_key, int private_key, int modulo)
{
	if (gcd(modulo, public_key) != 1) {
		return false;
	}
	if (!(isPrime(public_key))) {
		return false;
	}
	if ((public_key*private_key)%modulo != 1) {
		return false;
	}
	if (public_key > modulo) {
		return false;
	}
	return true;
}

void ciphering(char *message, int key, char *fname) {
	fname = strcat(fname, ".cipher");
	FILE *outfile;
	outfile = fopen(fname, "w");
	char output[2048];
	int i = 0;
	while (message[i] != '\0') {
		output[i] = (key*message[i]%256);
		i = i+1;
	}
	output[i] = '\0';
	printf("%s\n", message);
	printf("%s\n", output);
	fputs(output, outfile);
	fclose(outfile);
	return;
}

int main(int argc, char *argv[]) {
	if (argc == 0) {
		printf("ERROR: NO ARGUMENTS\n");
		return -1;
	}
	char *ptr;
	if (strcmp(argv[1], "-CHECK") == 0) {
		if (argc != 5) {
			printf("ERROR: MISSING ARGUMENTS\n");
			printf("PLEASE USE FORMAT: ./a.out -CHECK public_key private_key modulo\n");
			return -1;
		}
		if (isValid(strtol(argv[2],&ptr,10), strtol(argv[3],&ptr,10), strtol(argv[4],&ptr,10))) {
			printf("VALID KEYS\n");
		}
		else {
			printf("INVALID KEYS\n");
		}
		return 0;
	}
	else if (strcmp(argv[1], "-CIPHER") == 0) {
		if (argc != 4) {
			printf("ERROR: MISSING ARGUMENTS\n");
			printf("PLEASE USE FORMAT: ./a.out -CIPHER filename key\n");
			return -1;
		}
		FILE *f;
		f = fopen(argv[2], "r");
		char message[2048];
		fgets(message, 2047, f);
		fclose(f);
		int key = strtol(argv[3],&ptr,10);
		//int modulo = strtol(argv[4],&ptr,10);
		ciphering(message, key, argv[2]);
		return 0;
	}
	else {
		printf("ERROR: PLEASE USE FLAG -CHECK or -CIPHER\n");
		return -1;
	}
}


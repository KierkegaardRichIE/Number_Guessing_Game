#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_NUMBER 1000

int Getnum(void) {
	int x;
	printf("A magic number between 1 and %d has been chosen.\n", MAX_NUMBER);
	x = rand();
	x = x % MAX_NUMBER + 1;
	return x;
}

void GuessNum(int x) {
	int guess, counter = 0;
	for (;;)
	{
		printf("Guess it: ");
		scanf("%d", &guess);	/*�������²���*/
		counter++;	/*��¼��Ҳ²����*/
		if (guess == x) {
			printf("You guessed the number by %d times!\n\n", counter);
			return;
		}
		else if (guess < x) {
			printf("Too low.Try again.(You have tried %d times)\n",counter);
		}
		else
			printf("Too high.Try again.(You have tried %d times)\n",counter);
	}
}

int main(void) {
	char command1;	/*�洢�û������ѡ��(�Ƿ������Ϸ)*/
	char command2;	/*�洢�û������ѡ��(�Ƿ��˳���Ϸ)*/
	int magic;
	printf("This is guessing game\n\n");
	srand(time(NULL));
loop1:
	magic = Getnum();
	GuessNum(magic);
loop2:
	printf("Play again? (Y/N)");
	scanf("%1s", &command1);
	switch ((char)(command1))
	{
	case 'Y':	goto loop1;
	case 'y':	goto loop1;
	case 'N':	goto loop3;
	case 'n':	goto loop3;
	default:	break;
	}
loop3:
	printf("Sure to exit?(Y/N)");
	scanf("%1s", &command2);
	switch ((char)(command2))
	{
	case 'N':	goto loop2;
	case 'n':	goto loop2;
	default:	break;
	}
	return 0;
}
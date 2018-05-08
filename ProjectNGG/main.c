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
		char h[20] = "Too high";
		char l[20] = "Too low";
		printf("Guess it: ");
		scanf("%d", &guess);	/*玩家输入猜测结果*/
		counter++;	/*记录玩家猜测次数*/
		if (guess == x) {
			printf("You guessed the number by %d times!\n\n", counter);
			return;
		}
		else if (guess < x) {
			printf("%-10s|Try again | You have tried %3d %2 times|\n",l,counter);
		}
		else
			printf("%-10s|Try again | You have tried %3d %2 times|\n",h,counter);
	}
}

int main(void) {
	char command1;	/*存储用户输入的选项(是否继续游戏)*/
	char command2;	/*存储用户输入的选项(是否退出游戏)*/
	int magic;
	printf("=======Welcome to the NUMBER GUESSING GAME=======\n\n");
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
#include <stdio.h>

int SmallestNumber(int a, int b) {
	if (a < b) return a;
	else return b;
}

int BiggestNumber(int a, int b, int c) {
	int out = a;
	if (b > out) out = b;
	if (c > out) out = c;
	return out;
}

int main()
{
	// assign 2 number variables and 1 char variable
	const int  num1 = 69,
			   num2 = 66;
	const char operation = '-';

	printf("x-x--X Amelix's epicc C asasignment OwO X--x-x\nnum1 -> %d\nnum2 -> %d\noperation -> '%c'\n\n", num1, num2, operation);

	// do the operation specified by the char variable on the 2 numbers
	int calc1;
	switch (operation) {
		case '+':
			calc1 = num1 + num2;
			break;
		case '-':
			calc1 = num1 - num2;
			break;
		case '*':
			calc1 = num1 * num2;
			break;
		case '/':
			calc1 = num1 / num2;
			break;
		case '%':
			calc1 = num1 % num2;
			break;
		default:
			// Leaving this line here for historical archives of my downfall trying to learn C.
			// Note to examiner: ignore the comment below.
			// printf("That operation is invalid. I would've totally included the operation in question that was invalid here, but I literally couldn't figure it out without using a deprecated function which makes the compiler refuse to compile, so, it's just this message I guess. Sucks to suck.");

			printf("The operation '%c' is not valid.", operation);
			return -1;
	}

	printf("calc1 (num1 %c num2) -> %d\n\n", operation, calc1);

	// divide output of operation by smaller number between the 2 operands
	int smallestNumber = SmallestNumber(num1, num2);
	printf("Smallest number out of num1 and num2 -> %d\n", smallestNumber);

	float calc2 = (float) calc1 / smallestNumber;
	printf("calc2 (calc1 / %d) -> %f\n\n", smallestNumber, calc2);

	// find the largest number out of all those 3
	int largestNumber = BiggestNumber(num1, num2, calc2);
	printf("Largest number out of num1, num2, and calc2: %d\n\n", largestNumber);

	// print the 2 numbers defined at the beginning by printing the tens digit
	// first and then the other digit 11 -> 10 1, 34 -> 30 4
	printf("Tens digit and ones digit of each starting number:\nnum1: %d0 %d\nnum2: %d0 %d\n\n", num1 / 10, num1 % 10, num2 / 10, num2 % 10);

	// print the resulting number normally.
	printf("Resulting final number (calc2) -> %f\n\n", calc2);
}
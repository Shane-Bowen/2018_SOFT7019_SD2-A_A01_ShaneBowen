//Name: Shane Bowen
//ID: R00149085
//Class: SD2-A

//--------------------------------------------------
// INCLUDE SECTION
//--------------------------------------------------
#include "pal.h"

//--------------------------------------------------
// gen_num
//--------------------------------------------------
int gen_num(int lb, int ub) {
	//1. We create the output variable with an initial value.
	int res = 0;

	//2. We assign num to a random value in the desired range
	res = (rand() % (ub - lb)) + lb;

	//3. We return the output variable
	return res;
}

//--------------------------------------------------
// my_getchar
//--------------------------------------------------
char my_get_char() {
	//1. We create the output variable with the value the user has input by keyboard
	char res = getchar();

	//2. We discard any extra character the user has input by keyboard
	boolean finish = False;
	char dummy_char = ' ';

	while (finish == False) {
		dummy_char = getchar();
		if (dummy_char == '\n')
			finish = True;
	}

	//3. We return the output variable
	return res;
}

//--------------------------------------------------
// initialise_array
//--------------------------------------------------
void initialise_array(int a[6], int num) {

	//-----------------------------------------------------------
	// Inserting values of pal_num by using remainder which gets
	// last digit and inserts it into array.
	//-----------------------------------------------------------
	int i = 5;
	while (num)
	{
		a[i] = num % 10;
		num /= 10;
		i --;
	}
}

//--------------------------------------------------
// is_pal
//--------------------------------------------------
boolean is_pal(int a[6]) {

	//------------------------------------------------
	// Checking if the array is a palindrome, if it is 
	// then it return b = true
	//------------------------------------------------

	boolean b = False;

	if (a[0] == a[5] && a[1] == a[4] && a[2] == a[3])
	{
		b = True;

		printf("\n--------------------------\n");
		printf("-------- PALINDROME! ---------\n");
		printf("--------------------------\n");
	}

	else {
		b = False;
	}

	return b;
}

//--------------------------------------------------
// ask_for_command
//--------------------------------------------------
char ask_for_command() {
	
	//--------------------------------------------------------
	// Ask the user for a command and checking if it is valid
	// or not.
	//--------------------------------------------------------
	
	char res = ' ';
	boolean ok = False;

	do {

		printf("\n NEW MOVEMENT: Enter a valid command by keyword:");
		printf("\n Valid Commands: a \t d \t w \t x \n");

		res = my_get_char();

		if (res == 'a', 'A' || res == 'd', 'D' || res == 'w', 'W' || res == 'x', 'X')
		{
			ok = True;
		}

		else {
			printf("\n Invalid Character!");
			ok = False;
		}
	} while (!ok);

	return res;
}

//--------------------------------------------------
// process_movement
//--------------------------------------------------
void process_movement(int a[6], int** p_p, int* p_nm, char c) {

	//--------------------------------------------------------
	// Depending on what command the user entered, we perform
	// the correct action needed.
	//--------------------------------------------------------

	c = ask_for_command();

	if (c == 'a' || c == 'A')
	{
		//Make sure it is not in the 1st position of array
		if ((*p_p) > &a[0])
		{
			//We move the pointer one position to the left
			(*p_p)--;
			//We increase the number of movements
			(*p_nm)++;
		}
		
	}

	else if (c == 'd' || c == 'D')
	{
		//Make sure it is not in last postion in array.
		if ((*p_p) < (&a[5]))
		{
			//We move the pointer one position to the right
			(*p_p)++;
			//We increase the number of movements
			(*p_nm)++;
		}
	}

	else if (c == 'w' || c == 'W')
	{
		//Value can't be greater than 9
		if ((**p_p) < 9)
		{
			//We increase the value of the digit it is on
			(**p_p)++;
			//We increase the number of movements
			(*p_nm)++;
		}

		else
		{
			printf("Number can't be greater than 9");
		}
	}

	else if (c == 'x' || c == 'X')
	{
		//Value can't be less than 0
		if ((**p_p) > 0)
		{
			//We decrease the value of the digit it is on
			(**p_p)--;
			//We increase the number of movements
			(*p_nm)++;
		}

		else
		{
			printf("Number can't be less than 0");
		}
	}
}

//--------------------------------------------------
// print_status
//--------------------------------------------------
void print_status(int a[6], int* p, int nm) {

	//Clearing the screen
	for (int i = 0; i < 40; i++)
	{
		printf("\n");
	}

	//Printing what's inside the array

	printf("\n------ Game Status -------");
	
	printf("\n Number = { ");

	for (int i = 0; i < 6; i++) {
		printf("%d ", a[i]);
	}

	printf("}\n");
	
	//We move in a few spaces to align the pointer to correct position
	printf("\t    ");
	int gap = (int)(p - &a[0]);

	for (int i = 0; i < (2 * gap); i++)
		printf(" ");
		printf("^");
		printf("\n");

	//Print the total number of movements
	printf(" Num mov = %d\n", nm);
	printf("--------------------------\n");
}

//--------------------------------------------------
// user_game_palindrome
//--------------------------------------------------
void user_game_palindrome(int pal_num) {

	// Calling all our variable and functions
	int a[6];
	int nm = 0;
	char c = ' ';

	initialise_array(a, pal_num);
	int* p = a + gen_num(0, 6);
	print_status(a, p, nm);

	//If not a palindrome then we keep looping until it is
	while (is_pal(a) == False) {

		// p_p points at the address of p
		int** p_p = &p;
		// p_nm points at the address of nm
		int* p_nm = &nm;

		process_movement(a, p_p, p_nm, c);
		print_status(a, p, nm);
	}
}
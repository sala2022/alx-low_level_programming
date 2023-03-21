#include "main.h"


	/** print_alphabetis a function that outputs the alphabet
	 * in some form.It may take different parameters or have different
	 * variations, but in general, it could be expected to output
	 *the 26 letters of the English alphabet
	 */
void print_alphabet(void)
{
	char letter;

	for (letter = 'a'; letter <= 'z'; letter++)
		_putchar(letter);
	_putchar('\n');
}

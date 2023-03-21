#include "main.h"


	/**print_alphabet
	 *This function prints the lowercase alphabet using ASCII codes       
	 */
void print_alphabet(void)
{
	char letter;

	for (letter = 'a'; letter <= 'z'; letter++)
		_putchar(letter);
	_putchar('\n');
}

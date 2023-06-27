#include "../main.h"
#include <stdio.h>

int main(void)
{

	/* _printf("Character:[%+- 0901c]\n", 'H'); */
	_printf("Character:[%+- 90c][%c]\n", 'H', 'J');
	/* _printf("Character:[%+- 90r]\n", 'H'); */
	/* _printf("Character:[%8rr]\n", 'H'); */
	_printf("String:[%-30s]\n", "deez!");
	_printf("String:[%10s]\n", "deez!");
	/* printf("String:[%s]\n", "I am a string !"); */

	/*strlen*/
	/* printf("strlen: %d\n", _strlen("")); */
	/* atoi */
	/* printf("%d\n", _atoi("0")); */
	/* printf("%d\n", _atoi("-0")); */
	/* printf("%d\n", _atoi("1")); */
	/* printf("%d\n", _atoi("-1")); */
	/* printf("%d\n", _atoi("7")); */
	/* printf("%d\n", _atoi("-7")); */
	/* printf("%d\n", _atoi("0000010")); */
	/* printf("%d\n", _atoi("-0000010")); */
	/* printf("%d\n", _atoi("-00r0010")); */
	/* printf("%d\n", _atoi("f-11r")); */
	return (0);
}

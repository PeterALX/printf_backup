#include "../main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	_printf("Character:[%+- 09c]\n", 'H');
	_printf("Character:[%+ 10c][%c]\n", 'H', 'J');
	_printf("Character:[%+ 01c][%c]\n", 'H', 'J');
	_printf("Character:[%+- 90r]\n", 'H');
	_printf("Character:[%8rr]\n", 'H');
	_printf("String:[%-30s]\n", "deez!");
	_printf("String:[%10s][%-10s][%s]\n", "deez!", "", "10");
	printf("String:[%s]\n", "I am a string !");
	_printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);

	/* pbuf */
	/* print_buf p_buf = {.max_size = 1024, .cursor = 0}; */
	/* fill_buf(&p_buf, "seez\n", 6); */
	/* fill_buf(&p_buf, "", 1); */
	/* fill_buf(&p_buf, "deez\n", 5); */
	/* write(1, p_buf.buf, p_buf.cursor); */

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

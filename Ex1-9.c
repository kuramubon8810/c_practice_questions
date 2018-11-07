#include <stdio.h>

main()
{
	int c, nl;

	nl = 0;
	while ((c = getchar()) != EOF){
		if (c == ' '){
			++nl;

			if(nl >= 2){}
			else
				putchar(c);
		} else {
			nl = 0;
			putchar(c);
		}
	}
}

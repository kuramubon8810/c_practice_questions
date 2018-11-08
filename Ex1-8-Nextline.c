#include <stdio.h>

main()
{
	int c, nl;

	nl = 0;
	while ((c = getchar()) != EOF)
		if (c == '\n')
			++nl;
	printf("%d\n", nl);
}

//演習1-8  空白、タブ、改行を数えるプログラムを書け。(改行バージョン)

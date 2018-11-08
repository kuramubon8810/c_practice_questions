#include <stdio.h>

#define IN  1     /*単語の中*/
#define OUT 0     /*単語の外*/

main()
{
	int c, nc, state;
	state = OUT;
	nc = 0;
	while ((c = getchar()) != EOF) {
		if ((c == ' ' || c == '\n' || c == '\t') && (nc != 0)){
			state = OUT;
			nc = 0;
			printf("\n");
		}
		else if (c != ' ' && c != '\n' && c != '\t') {
			++nc;
			putchar(c);
		}
	}
}

//演習1-12  入力した単語を1行に一つずつ印字するプログラムを書け。

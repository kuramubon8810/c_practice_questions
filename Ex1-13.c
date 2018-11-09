#include <stdio.h>
#include <ctype.h>

#define IN  1     /*単語の中*/
#define OUT 0     /*単語の外*/

main()
{
	int c, nw, nc, state;
	state = OUT;
	nw = nc = 0;
	while ((c = getchar()) != EOF) {
		if ((state == OUT) && (isalpha(c) != 0)){
			state = IN;
			++nc;
		}
		else if ((state == IN) && ((isalnum(c) != 0) || (c == '`'))){
			++nc;
		}
		else if (nc != 0) {
			state = OUT;
			++nw;
			
			if(c == ' ' || c == '\n' || c == '\t')
				nc = 0;
		}
	}
	printf("%d", nw);
}

//演習1-13  "単語の定義"をもっとはっきりさせて単語数をカウントするプログラムを書け。
//          例えば、英字で始まり、英字・数字・アポストロフィの連続したものを"単語"とするというように。

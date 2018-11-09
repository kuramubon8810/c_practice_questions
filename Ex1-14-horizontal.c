#include <stdio.h>

#define IN  1
#define OUT 0
#define LENGTH_LIMIT 10

main()
{
	int c, i, j, nw, state;
	int ndigit[LENGTH_LIMIT + 1];
	nw = 0;
	state = OUT;

	for (i = 0; i < LENGTH_LIMIT + 1; ++i)
		ndigit[i] = 0;

	while ((c = getchar()) != EOF){
		if (c == ' ' || c == '\n' || c == '\t'){
			state = OUT;

			if(nw < LENGTH_LIMIT)
				++ndigit[nw];
			else
				++ndigit[LENGTH_LIMIT];

			nw = 0;
		} else if (state == OUT){
			state = IN;
			++nw;
		} else if (state == IN)
			++nw;
	}

	for (i = 1; i < LENGTH_LIMIT; ++i){ //配列の0番目には0文字の単語が入っているため。
		for (j = 0; j <= ndigit[i]; ++j){
			if (j == 0)
				printf("%d文字 ", i);
			else
				printf("*");
		}
		printf("\n");
	}

	for (i = 0; i <= ndigit[LENGTH_LIMIT]; ++i)
		if(i == 0)
			printf("%d文字以上", LENGTH_LIMIT);
		else
			printf("*");
}

//演習1-14 入力した単語の長さをヒストグラム(度数分布図)にしてプリントするプログラムを書け。
//         ヒストグラムは横に書くほうが簡単だが、縦書きに挑戦してみるのもよい。

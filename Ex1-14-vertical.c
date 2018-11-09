#include <stdio.h>

#define IN  1
#define OUT 0
#define LENGTH_LIMIT 10

main()
{
	int c, i, j, nw, state, max_value;
	int ndigit[LENGTH_LIMIT + 1];
	nw = max_value = 0;
	state = OUT;

	for (i = 0; i <= LENGTH_LIMIT; ++i) {
		ndigit[i] = 0;
	}

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t'){
			state = OUT;

			if (nw < LENGTH_LIMIT)
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

	for (i = 1; i <= LENGTH_LIMIT; ++i) {
		if (max_value < ndigit[i])
			max_value = ndigit[i];
	}

	char ndigit_write_array[LENGTH_LIMIT + 1][max_value];

	for (i = 0; i <= LENGTH_LIMIT; ++i) {
		for (j = 0; j < max_value; ++j)
			ndigit_write_array[i][j] = 0;
	}

	for (i = 0; i <= LENGTH_LIMIT; ++i) {
		j = 0;
		while (j < max_value) {
			if (j < ndigit[i]) {
				ndigit_write_array[i][j] = '*';
				++j;
			} else {
				ndigit_write_array[i][j] = ' ';
				++j;
			}
		}
	}

	for (j = max_value - 1; j >= 0; --j) {
		for (i = 1; i <= LENGTH_LIMIT; ++i)
			printf("%c ", ndigit_write_array[i][j]);
		printf("\n");
	}
	printf("1 2 3 4 5 6 7 8 9 10以上");
}

//演習1-14 入力した単語の長さをヒストグラム(度数分布図)にしてプリントするプログラムを書け。
//         ヒストグラムは横に書くほうが簡単だが、縦書きに挑戦してみるのもよい。

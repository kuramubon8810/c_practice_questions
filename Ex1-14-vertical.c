#include <stdio.h>

#define WORD_LENGTH_LIMIT 15
#define ARRAY_LENGTH (WORD_LENGTH_LIMIT + 1)

main() 
{
	int c, i, j, nw, state, max_value;
	int ndigit[ARRAY_LENGTH];
	nw = max_value = 0;

	for (i = 0; i <= WORD_LENGTH_LIMIT; ++i) {
		ndigit[i] = 0;
	}

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			if (nw < WORD_LENGTH_LIMIT) {
				++ndigit[nw];
			} else {
				++ndigit[WORD_LENGTH_LIMIT];

			}

			nw = 0;
		} else {
			++nw;
		}
	}

	for (i = 1; i <= WORD_LENGTH_LIMIT; ++i) {
		if (max_value < ndigit[i]) {
			max_value = ndigit[i];
		}
	}

	char ndigit_write_array[ARRAY_LENGTH][max_value];

	for (i = 0; i <= WORD_LENGTH_LIMIT; ++i) {
		for (j = 0; j < max_value; ++j) {
			ndigit_write_array[i][j] = 0;
		}
	}

	for (i = 0; i <= WORD_LENGTH_LIMIT; ++i) {
		for (j = 0; j < max_value; ++j) {
			if (j < ndigit[i]) {
				ndigit_write_array[i][j] = '*';
			} else {
				ndigit_write_array[i][j] = ' ';
			}
		}
	}

	for (j = max_value - 1; j >= 0; --j) {
		for (i = 1; i <= WORD_LENGTH_LIMIT; ++i){
			if(i >= 10){          //2桁以上だと横軸にずれが出るのを直すため。
				putchar(' ');
			}
			
			printf("%c ", ndigit_write_array[i][j]);
		}
		putchar('\n');
	}

	for (i = 1; i < WORD_LENGTH_LIMIT; ++i) {
		printf("%d ", i);
	}
	printf("%d以上", WORD_LENGTH_LIMIT);
}

//演習1-14 入力した単語の長さをヒストグラム(度数分布図)にしてプリントするプログラムを書け。
//         ヒストグラムは横に書くほうが簡単だが、縦書きに挑戦してみるのもよい。

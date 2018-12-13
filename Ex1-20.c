#include <stdio.h>
#define MAXLINE 1000      /* 入力の最大行数 */
#define TAB_WIDTH 4       /* TABを置き換えるスペースの数 */

int getline_(char line[], int maxline);
void detab(char to[], char from[]);

int main()
{
	int len;                /* 現在行の長さ */
	char line[MAXLINE];     /* 現在の入力行 */
	char detab_line[MAXLINE];/* 格納されている最長行 */

	while ((len = getline_(line, MAXLINE)) > 0) {
		detab(detab_line, line);
		printf("%s", detab_line);
	}

	if (len == -1)
		printf("最大字数を超えています");

	return 0;
}

int getline_(char s[], int lim)
{
	int c, i;

	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
		if(i >= lim)
			return -1;
		else
			s[i] = c;

	if (c == '\n') {
		s[i] = c;
		++i;
	}

	s[i] = '\0';
	return i;
}

void detab(char to[], char from[])
{
	int i;
	int j = 0;
	for (i = 0; i < MAXLINE; ++i)
		to[i] = '\0';
	for (i = 0; from[i] != '\0'; ++i) {
		if (from[i] == '\t') {
			for(int k = 0; k < TAB_WIDTH; ++k) {
				to[j] = ' ';
				++j;
			}
		} else {
			to[j] = from[i];
			++j;
		}
	}
}
//演習1-20 入力されたタブを、次のタブ・ストップまでのスペースをうめる適当な数のブランク(空白)で置き換えるプログラムdetabを書け。
//         タブ・ストップの位置は、例えばn文字ごとというように固定して考えよ。nは変数にすべきか、記号パラメータにすべきか？

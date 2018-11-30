#include <stdio.h>
#define MAXLINE 1000      /* 入力の最大字数 */
#define MINCHAR 80        /* 取ってくる最小の文字数 */

int getline_(char line[], int maxline);

int main()
{
	int len;                /* 現在行の長さ */
	char line[MAXLINE];     /* 現在の入力行 */

	while ((len = getline_(line, MAXLINE)) > 0) {
		if(len > MINCHAR) {
			printf("%d:\t%s", len - 1, line);
		}
	}
	if(len == -1)
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

//演習1-17  80字より長い行をすべて印字するプログラムを書け。

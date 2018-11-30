#include <stdio.h>
#define MAXLINE 1000      /* 入力の最大行数 */

int getline_(char line[], int maxline);
void reverse(char to[], char from[], int len);

int main()
{
	int len;                /* 現在行の長さ */
	char line[MAXLINE];     /* 現在の入力行 */
	char reverse_line[MAXLINE];/* 格納されている最長行 */

	while ((len = getline_(line, MAXLINE)) > 0) {
		reverse(reverse_line, line, len);
		printf("%s", reverse_line);
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

void reverse(char to[], char from[], int len)
{
	int i;
	for(i = 0; i < MAXLINE; ++i)
		to[i] = '\0';
	for (i = 0; i < len; ++i)
		to[i] = from[len - i - 1];
}

//演習1-19  文字列sを逆に並べる関数reverse(s)を書け。さらに、この関数を使って、入力を一時に一行ずつ逆転するプログラムを書け。
//                                            (日本語非対応)

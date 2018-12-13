#include <stdio.h>
#define MAXLINE 1000      /* 入力の最大行数 */
#define NEXTLINE 20      /* 何文字目で改行するか */

int getline_(char line[], int maxline);
void ennextline(char to[], char from[], int len);

int main()
{
	int len;                /* 現在行の長さ */
	char line[MAXLINE];     /* 現在の入力行 */
	char ennextline_line[MAXLINE];/* 改行を加えた後の行 */

	while ((len = getline_(line, MAXLINE)) > 0) {
		ennextline(ennextline_line, line, len);
		printf("%s", ennextline_line);
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

void ennextline(char to[], char from[], int len)
{
	int i, j;
	for (i = 0; i < MAXLINE; ++i)
		to[i] = '\0';
	for (i = 0; (NEXTLINE * i) < len ; ++i) {
		if (i != 0) {
			to[((NEXTLINE + 1) * i) - 1] = '\n';
		}
		for (j = 0; j < NEXTLINE && from[j + (NEXTLINE * i)] != '\0' && from[j + (NEXTLINE * i)] != '\n'; ++j) {
			to[j + (NEXTLINE + 1) * i] = from[j + (NEXTLINE * i)];
		}
	}
}

// 演習1-22 長い入力行を、入力のn文字目にある最後の非ブランク文字の後で、"折りたたむ"プログラムを書け。
//          プログラムは、行が非常に長くても、また指定桁までブランクもタブもない場合についても、ちゃんと動作するようにせよ。

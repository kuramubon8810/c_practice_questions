#include <stdio.h>
#define MAXLINE 1000      /* 入力の最大行数 */

int getline_(char line[], int maxline);
void trim(char to[], char from[]);
int check_continue_line(char s[], int now_nuber);

int main()
{
	int len;                /* 現在行の長さ */
	char line[MAXLINE];     /* 現在の入力行 */
	char trim_line[MAXLINE];/* 格納されている最長行 */

	while ((len = getline_(line, MAXLINE)) > 0) {
		trim(trim_line, line);
		printf("%s", trim_line);
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

void trim(char to[], char from[])
{
	int i;
	int j = 0;
	for (i = 0; i < MAXLINE; ++i)
		to[i] = '\0';
	for (i = 0; (from[i] != '\0') && (from[i] != '\n'); ++i) {
		if (from[i] == '\t' || from[i] == ' ') {
			if (check_continue_line(from, i) == 0){
				to[i] = '\n';
				return;
			}
			else
				to[i] = from[i];
		} else {
			to[i] = from[i];
			++j;
		}
	}
	if (j != 0)
		to[i] = '\n';
}

int check_continue_line(char s[], int now_nuber)
{
	int i, j;
	for (i = now_nuber; (s[i] != '\n'); ++i) {
		if(s[i] != '\t' && s[i] != ' ')
			return 1;
	}
	return 0;
}

//演習1-18  各入力行から、行の後のブランクやタブを取り除き、かつ空白行はすべて削除するようなプログラムを書け

#include <stdio.h>
#define MAXLINE 1000      /* 入力の最大行数 */
#define TAB_WIDTH 4       /* TABを置き換えるスペースの数 */

int getline_(char line[], int maxline);
void entab(char to[], char from[]);

int main()
{
	int len;                /* 現在行の長さ */
	char line[MAXLINE];     /* 現在の入力行 */
	char entab_line[MAXLINE];/* スペースをTABに置き換えた後の行 */

	while ((len = getline_(line, MAXLINE)) > 0) {
		entab(entab_line, line);
		printf("%s", entab_line);
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
void entab(char to[], char from[]) 
{ 
	int i, k, j;
	int l = 0;
	for (i = 0; i < MAXLINE; ++i)
		to[i] = '\0';
	for (i = 0; from[i] != '\0'; ++i) {
		j = 0;
		for (k = i; from[k] == ' '; ++k) {
			++j;
		}
		if (j >= TAB_WIDTH) {
			for (k = 1; k <= (j / TAB_WIDTH); ++k)    //0だと1/4などの時に実行されてしまう、、、？ */
				to[l++] = '\t';
			i += TAB_WIDTH * (j / TAB_WIDTH - 1) + (TAB_WIDTH - 1);
		} else {
			to[l++] = from[i];
		}
	}
}
//演習1-21 ブランクの列を同じスペーシングを行う最小の数のタブおよびブランクで置き換えるプログラムentabを書け。
//         detabと同じタブ・ストップを使え。タブ・ストップに達するのに、タブあるいは単一のブランクのいずれかで十分なときに、どちらを使うべきか？

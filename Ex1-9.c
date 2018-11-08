#include <stdio.h>

main()
{
	int c, nl;

	nl = 0;
	while ((c = getchar()) != EOF){
		if (c == ' '){
			++nl;

			if(nl >= 2){}
			else
				putchar(c);
		} else {
			nl = 0;
			putchar(c);
		}
	}
}

//演習1-9  二つ以上の空白を一つの空白に置き換えながら、入力を出力に複写するプログラムを書け。

#include <stdio.h>

main()
{
	int c;
	
	while((c = getchar()) != EOF)
		printf("%d", c != EOF);

	printf("%d",c != EOF);
}

//演習1-6  getchar() != EOFという式の値が0か1であることを確認せよ。

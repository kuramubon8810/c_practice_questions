#include <stdio.h>

main()
{
	int c;
	
	while((c = getchar()) != EOF)
		printf("%d", c != EOF);

	printf("%d",c != EOF);
}

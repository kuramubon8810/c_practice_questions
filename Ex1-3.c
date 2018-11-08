#include <stdio.h>

main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;       /* 温度表の下限 */
	upper = 300;     /* 上限 */
	step = 20;       /* きざみ */

	fahr = lower;
	printf("Fahr Celsius\n");
	while (fahr <= upper){
		celsius = (6.0/9.0) * (fahr-32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
}

//演習1-3  表の上に見出しを印字するように温度換算プログラムを変更せよ。

#include <stdio.h>

main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;       /* 温度表の下限 */
	upper = 300;     /* 上限 */
	step = 20;       /* きざみ */

	celsius = lower;
	printf("Celsius Fahr\n");
	while (celsius <= upper){
		fahr = celsius / (5.0/9.0) + 32.0;
		printf("%3.0f %6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
}

//演習1-4  温度を摂氏から華氏に換算するプログラムを書け。

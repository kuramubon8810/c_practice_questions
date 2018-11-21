#include <stdio.h>

float conversion(int fahr)
{
	return((5.0 / 9.0) * (fahr - 32.0));
}

int main(void)
{
	float fahr;
	int lower, upper, step;

	lower = 0;       /* 温度表の下限 */
	upper = 300;     /* 上限 */
	step = 20;       /* きざみ */

	fahr = lower;
	printf("Fahr Celsius\n");
	while (fahr <= upper){
		printf("%3.0f %6.1f\n", fahr, conversion(fahr));
		fahr = fahr + step;
	}
}

//演習1-15  1.2節の温度換算プログラムを、変換のための関数を使うように書き直せ。

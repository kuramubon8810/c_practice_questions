#include <stdio.h>

main()
{
	int fahr;
	for(fahr = 300; fahr >= 0; fahr = fahr - 20)
		printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}

//演習1-5  温度換算プログラムに手を加えて、表を逆順に、すなわち300度から0度へという順に印字するように直せ。

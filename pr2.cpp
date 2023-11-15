#include "mods.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int v, c;
	School a;
	while (true) {

		do {
			menu();
			printf("Введите пункт меню: ");
			v = scanf("%d", &c);
			while (getchar() != '\n');
			system("cls");
		} while (c > 5 || c < 1 || v < 1);
		switch (c)
		{
		case 1: {
			vivod(&a);
			break;
		}
		case 2: {
			create_class(&a);
			break;
		}
		case 3: {
			del(&a);
			break;
		}
		case 4: {
			red_class(&a);
			break;
		}
		case 5: {
			exit(EXIT_SUCCESS);
			break;
		}
		default:
			break;
		}
		/*create_class(&a);
		vivod_scl(&a, a.n_cl);

		vivod_cls(&a, a.n_cl - 1);
		red_class(&a);*/
	}
}
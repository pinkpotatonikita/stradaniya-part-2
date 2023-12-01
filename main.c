#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"
int main() {
	int key;
	char filename[100];
	printf("1-Создание и запись, 2-Просмотр, 3-Обновление цены, 4-Поиск\n");
	scanf("%d", &key);
	printf("Введите имя файла: \n");
	scanf("%s", filename);
	switch (key) {
        case 1:
		save(filename);
		break;
        case 2:
		load(filename);
		break;
	case 3:
		load(filename);
		update(filename);
		load(filename);
		break;
	case 4:
		search(filename);
		break;
        default:
            break;
    }
    return 0;
}

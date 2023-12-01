#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"
void save(char *filename) {
	int n;
	printf("n=");
	scanf("%d", &n);
	person *arr = (person*)calloc(n, sizeof(person));
	for (int i = 0; i < n; i++) {
        	printf("Напиток=\n");
        	scanf("%s", arr[i].name);
        	printf("Цена=\n");
        	scanf("%d", &arr[i].price);
        	printf("Миллилитры=\n");
        	scanf("%d", &arr[i].ml);
        	printf("Процент содержания алкоголя=\n");
        	scanf("%d", &arr[i].proc);
	}
	FILE *f = fopen(filename, "w");
	if (!f) {
        	free(arr);
        	return;
	}
	fwrite(arr, sizeof(person), n, f);
	fclose(f);
	free(arr);
}

void load(char *filename) {
	FILE *f = fopen(filename, "r");
	if (!f) return;
	fseek(f, 0, SEEK_END);
	long size = ftell(f);
	int n = size / sizeof(person);
	printf("file size %ld\n", size);
	rewind(f);
	person *arr = (person*)malloc(size);
	fread(arr, sizeof(person), n, f);
	fclose(f);
	for (int i = 0; i < n; i++) {
        printf("%s %d$ %dml %d%c \n", arr[i].name, arr[i].price, arr[i].ml, arr[i].proc, '%');
    }
    free(arr);
}

void update(char *filename) {
	int id, newprice;
	printf("id=");
	scanf("%d", &id);
	printf("new price=");
	scanf("%d", &newprice);
	FILE *f = fopen(filename, "r+");
	if (!f) return;
	int pos = id * sizeof(person);
	fseek(f, pos, SEEK_SET);
	person drink;
	fread(&drink, sizeof(person), 1, f);
	drink.price = newprice;
	fseek(f, -sizeof(person), SEEK_CUR);
	fwrite(&drink, sizeof(person), 1, f);
	fclose(f);
}
void search(char *filename) {
	char searchName[20];
	printf("Введите название напитка для поиска: \n");
	scanf("%s", searchName);
	FILE *f = fopen(filename, "r");
	if (!f) return;
	fseek(f, 0, SEEK_END);
	long size = ftell(f);
	int n = size / sizeof(person);
	rewind(f);
	person *arr = (person*)malloc(size);
	fread(arr, sizeof(person), n, f);
	fclose(f);
	int found = 0;
	for (int i = 0; i < n; i++) {
	if (strcmp(arr[i].name, searchName) == 0){
		printf("Найден напиток: %s %d$ %dml %d%c ", arr[i].name, arr[i].price, arr[i].ml, arr[i].proc, '%');
		found = 1;
		}
	}
	if (!found) {
	printf("Напиток не найден ");
	}
	free(arr);
} 

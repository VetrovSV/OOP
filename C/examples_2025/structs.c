#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* type
* TCat = record
*	name: string;
*   age: short;
*  end;
*/

struct TCat {
	// поля структуры
	char name[64];		
	short age;
};


struct Box {
	float width;
	float height;
	float length;
};


// функция для удобной инициализации полей структуры TCat
struct TCat init_cat( char* name, short age) {
	struct TCat cat1;
	cat1.age = age;
	strcpy_s(cat1.name, sizeof(cat1.name), name);		// задать значение для строки;
	return cat1;
}

int main() {

	struct Box box1 = {.width = 1, .height = 1, .length = 1 };
	
	// статический массив из структур
	struct Box boxes[3];
	boxes[0].height = 90.564;
	boxes[2].height = 390.564;

	// динамический массив
	size_t n = 5;
	struct Box * boxes2 = malloc( n * sizeof(struct Box) );
	boxes2[0].height = 90.564;
	boxes2[2].height = 390.564;
	free(boxes2);


	//struct TCat cat1 = init_cat("Whiskers", 5);



	//struct TCat cat2;
	//cat2 = init_cat("Leonard", 3);



	//printf("%s; возраст %d\n", cat1.name, cat1.age);
	///*printf("%s; возраст %d\n", cat2.name, cat2.age); */

	return 0;
}


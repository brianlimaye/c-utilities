#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "ArrayList.h"
#include "HashMap.h"

void testArrayList()
{
	//Test 1: Regularly Tests all Methods
	struct ArrayList * a = ArrayList_init(2, 6);
	ArrayList_add("Brian", a);
	ArrayList_add("Bahar", a);
	assert(ArrayList_capacity(a) == 4);
	ArrayList_remove(0, a);
	assert(strcmp("Bahar", ArrayList_get(0, a)) == 0);

	ArrayList_clear(a);

	assert(ArrayList_isEmpty);

	assert(ArrayList_size(a) == 0);

	ArrayList_add("Jean", a);
	
	ArrayList_add("Jenny", a);

	ArrayList_add("Myriam", a);

	assert(ArrayList_contains("Jenny", a) == 1);

	ArrayList_destroy(a);

	//Test 2: Tests ArrayList_add and ArrayList_remove.

	struct ArrayList * b = ArrayList_init(1, 5);
	int res = ArrayList_add("Joseph", b);
	assert(res == -1);
	ArrayList_add("J", b);
	ArrayList_add("E", b);
	ArrayList_add("B", b);
	assert(ArrayList_remove(0, b) == 1);
	assert(ArrayList_remove(0, b) == 1);
	assert(ArrayList_remove(3, b) == -1);
	assert(ArrayList_remove(0, b) == 1);
	assert(ArrayList_size(b) == 0);
	ArrayList_destroy(b);

	//Test 3: Tests ArrayList_contains and ArrayList_clear

	struct ArrayList * c = ArrayList_init(5, 10);
	ArrayList_add("Brianna", c);
	ArrayList_add("Wally", c);
	ArrayList_add("Martha", c);
	ArrayList_add("Bertrum", c);
	ArrayList_add("Matilda", c);
	ArrayList_add("Opal", c);
	assert(ArrayList_capacity(c) == 20);
	assert(ArrayList_contains("Wally", c) == 1);
	assert(ArrayList_contains("Bert", c) == 0);
	assert(ArrayList_contains("Opal", c) == 1);
	assert(ArrayList_contains("Jeff", c) == 0);
	assert(ArrayList_contains("Brianna", c) == 1);
	ArrayList_clear(c);
	assert(ArrayList_size(c) == 0);
	ArrayList_add("Hilda", c);
	assert(ArrayList_size(c) == 1);
	ArrayList_destroy(c);
}

void testHashMap()
{
	//Test 1: Tests HashMap_get and HashMap_put in normal circumstances.

	struct HashMap * a = HashMap_init(10);
	HashMap_put("022811", "Kylie", a);
	HashMap_put("031602", "Brian", a);
	HashMap_put("110300", "Sarah", a);
	HashMap_put("031602", "Nopowon", a);
	printf("%s\n", HashMap_get("031602", a));
	printf("%s\n", HashMap_get("110300", a));
	printf("%s\n", HashMap_get("123456", a));
	printf("%s\n", HashMap_get("02281", a));

	HashMap_put("052173", "Mona", a);
	printf("%s\n", HashMap_get("052173", a));

	HashMap_destroy(a);
}

int main()
{
	testArrayList();
	testHashMap();
}
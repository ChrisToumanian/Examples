#include <stdio.h>

#define n 3

struct Animal {
    char* name;
    int age;
};

struct Animal animals[n];

int main()
{
    // Create Animals
    struct Animal cat;
    cat.name = "cat";
    cat.age = 2;
    animals[0] = cat;

    struct Animal goat;
    goat.name = "goat";
    goat.age = 5;
    animals[1] = goat;

    struct Animal trex;
    trex.name = "tyrannosaurus rex";
    trex.age = 12;
    animals[2] = trex;

    // List Animals
    printf("Animals:\n");
    size_t l = sizeof(animals) / sizeof(struct Animal);
    for (int i = 0; i < l; i++)
    {
        printf("%s%s%i%s", animals[i].name, ", ", animals[i].age, "\n");
    }

	return 0;
}

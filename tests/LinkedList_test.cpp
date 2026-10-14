#include <iostream>
#include "../include/resource.h"
#include "../include/linkedlist.h"
using namespace std;

int main() {
    linkedlist<Resource> resources;

    Resource r1(101, "Projector", "Equipment","Room A", 50, true);

    Resource r2(102, "Computer", "Equipment",  "Lab 1", 30, true);

    resources.insertlast(r1);
    resources.insertlast(r2);

    resources.display();

    return 0;
}
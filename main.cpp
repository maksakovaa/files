#include <fstream>
#include "object.h"
#include <iostream>

void saveObj()
{
    Item first("item1");
    Item second("item2");
    Object temp("temp");
    temp.addItem(first);
    temp.addItem(second);
    temp.saveObj("test.obj");
}

void loadObj()
{
    Object test;
    std::cout << test.getName() << " " << test.getItemCount() << std::endl;
    test.loadObj("test.obj");
    std::cout << test.getName() << " " << test.getItemCount() << std::endl;
}

int main()
{
    saveObj();
    loadObj();
    return 0;
}
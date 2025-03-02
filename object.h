#include <string>
#include <vector>
#include "item.h"
#include <fstream>

class Object
{
public:
    Object(): m_name("default") {}
    Object(const std::string& name): m_name(name) {}
    std::string& getName();
    size_t getItemCount();
    void addItem(const Item& newItem);
    void saveObj(const char *fileName);
    void loadObj(const char *fileName);
private:
    std::string m_name;
    std::vector<Item> m_items;
};
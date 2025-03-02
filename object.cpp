#include "object.h"

std::string& Object::getName()
{
    return m_name;
}
size_t Object::getItemCount()
{
    return m_items.size();
}

void Object::addItem(const Item &newItem)
{
    m_items.push_back(newItem);
}
void Object::saveObj(const char *fileName)
{
    std::ofstream out(fileName, std::ios::binary);
    saveString(out, m_name);
    size_t itemCount = m_items.size();
    out.write((char *)&itemCount, sizeof(itemCount));
    for (size_t i = 0; i < itemCount; i++)
    {
        m_items[i].saveItem(out);
    }
    out.close();
}

void Object::loadObj(const char *fileName)
{
    std::ifstream in(fileName, std::ios::binary);
    loadString(in, m_name);
    size_t itemCount;
    in.read((char *)&itemCount, sizeof(itemCount));
    m_items.resize(itemCount);
    for (size_t i = 0; i < itemCount; i++)
    {
        m_items[i].loadItem(in);
    }
    in.close();
}

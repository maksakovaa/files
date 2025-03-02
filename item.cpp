#include "item.h"

std::string& Item::getName()
{
    return _name;
}

void Item::saveItem(ostream &os)
{
    saveString(os, _name);
}
void Item::loadItem(istream &in)
{
    loadString(in, _name);
}

void saveString(ostream& os, std::string& str)
{
    size_t len = str.length() + 1;
    os.write((char*)&len, sizeof(len));
    os.write((char*)str.c_str(), len);
}

void loadString(istream& in, std::string& str)
{
    size_t len;
    in.read((char*)&len, sizeof(len));
    char* buf = new char[len];
    in.read(buf, len);
    str = buf;
    delete[] buf;
}
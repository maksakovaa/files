#include <string>
#include <fstream>
using std::ostream, std::istream;

class Item
{
    friend class Object;
public:
    Item(): _name("default"){}
    Item(const std::string& name): _name(name) {}
    std::string& getName();
private:
    std::string _name;
    void saveItem(ostream& os);
    void loadItem(istream& in);
};

void saveString(ostream& os, std::string& str);

void loadString(istream& in, std::string& str);
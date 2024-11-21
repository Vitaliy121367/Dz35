#include "DList.h"

int main()
{
    DList<int> a;
    a.push_back(7);
    a.push_front(2);
    a.push_back(3);
    a.push_front(4);
    a.push_front_value(4, 5);
    a.push_back_value(4, 11);
    a.showList();
    a.erase(11);
    a.showList();
}
#pragma once
#include <vector>
#include <iostream>

#include "objectCode.h"

namespace CP{

class Machine{
public:
    Machine();

    void init();
    void load(const std::vector<ObjectCode>& codes);
    void run(std::istream& in, std::ostream& out);

private:

int SP,BP,PC;
std::vector<ObjectCode> code;
std::vector<int> memory;

int findLevel(int l);


};



}//namespace



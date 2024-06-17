#include <iostream>
#include <vector>
#include <fstream>

#include "machine.h"
#include "objectCode.h"
#include "CP_Exception.h"

int main(){

    std::ifstream fin("program.code");
    if(fin.is_open() == false){
        return -1;
    }

    std::vector<CP::ObjectCode> codes;
    {
        std::string opratorCodeString;
        int levelDiv, addr;
        while(fin >> opratorCodeString >> levelDiv >> addr){
            CP::ObjectCode::Type codeType = CP::ObjectCode::StringToType(opratorCodeString);
            codes.push_back(CP::ObjectCode(codeType, levelDiv, addr));
        }
    }

    try{
        CP::Machine machine;
        machine.load(codes);
        machine.run(std::cin, std::cout);

    }catch(CP::Exception exception){
        return -1;
    }

    return 0;
}

#include "machine.h"
#include "CP_Exception.h"

namespace CP{

Machine::Machine(){
    init();
}

void Machine::init(){
    SP = 0;
    BP = 0;
    PC = 0;
    memory.clear();
}

void Machine::load(const std::vector<ObjectCode>& codes){
    code = codes;
}

void Machine::run(std::istream& in, std::ostream& out){
    while(PC != code.size()-1){
        ObjectCode instruction = code[PC];
        PC ++;

        switch(instruction.type){
            case ObjectCode::Type::LIT :{
                memory.push_back(instruction.addr);
                SP = memory.size()-1;
            }break;
            case ObjectCode::Type::LOD :{
                memory.push_back(memory[findLevel(instruction.levelDiv)+instruction.addr]);
                SP = memory.size()-1;

            }break;
            case ObjectCode::Type::STO :{
                SP = memory.size()-1;
                memory[findLevel(instruction.levelDiv)+instruction.addr]=memory[SP];
                memory.pop_back();
                SP = memory.size()-1;

            }break;
            case ObjectCode::Type::CAL :{
                memory.push_back(findLevel(instruction.levelDiv));
                SP++;
                memory.push_back(BP);
                memory.push_back(PC);
                BP = SP;
                PC = instruction.addr;
                SP = memory.size()-1;

            }break;
            case ObjectCode::Type::INT :{
			    for(int i = 0; i < instruction.addr; i++) {
                    memory.push_back(0);
                }
			    SP = memory.size()-1;

            }break;
            case ObjectCode::Type::JMP :{
                PC = instruction.addr;

            }break;
            case ObjectCode::Type::JPC :{
                SP=memory.size()-1;
                if(memory[SP]==0){
                    PC = instruction.addr;
                    memory.pop_back();
                    SP = memory.size()-1;
                }

            }break;
            case ObjectCode::Type::OPR :{
                switch (instruction.addr) {
                    case 20:{
                        int ans = memory[SP];
                        memory.pop_back();
                        memory.push_back(0-ans);
                        SP = memory.size()-1;
                    }break;
                    case 1:{
                        SP = memory.size()-1;
                        int x = memory[SP-1];
                        int y = memory[SP];
                        int m = x+y;
                        memory.pop_back();
                        memory.pop_back();
                        memory.push_back(m);
                        SP = memory.size()-1;
                    }break;
                    case 2:{
                        SP = memory.size()-1;
                        int x = memory[SP-1];
                        int y = memory[SP];
                        int m = x-y;
                        memory.pop_back();
                        memory.pop_back();
                        memory.push_back(m);
                        SP = memory.size()-1;
                    }break;
                    case 3:{
                        SP = memory.size()-1;
                        int x = memory[SP];
                        int y = memory[SP-1];
                        int m = x*y;
                        memory.pop_back();
                        memory.pop_back();
                        memory.push_back(m);
                        SP = memory.size()-1;
                    }break;
                    case 4: {
                        SP = memory.size()-1;
                        int x = memory[SP-1];
                        int y = memory[SP];
                        int m = x/y;
                        memory.pop_back();
                        memory.pop_back();
                        memory.push_back(m);
                        SP = memory.size()-1;
                    }break;
                    case 5: {
                        SP = memory.size()-1;
                        int x = memory[SP]%2;
                        memory.pop_back();
                        memory.push_back(x);
                        SP = memory.size()-1;
                    }break;
                    case 6: {
                        SP = memory.size()-1;
                        int x = memory[SP-1];
                        int y = memory[SP];
                        int m = x==y;
                        memory.pop_back();
                        memory.pop_back();
                        memory.push_back(m);
                        SP = memory.size()-1;
                    }break;
                    case 7: {
                        SP = memory.size()-1;
                        int x = memory[SP];
                        int y = memory[SP-1];
                        int m = x!=y;
                        memory.pop_back();
                        memory.pop_back();
                        memory.push_back(m);
                        SP = memory.size()-1;
                    }break;
                    case 8:{
                        SP = memory.size()-1;
                        int x = memory[SP-1];
                        int y = memory[SP];
                        int m = x<y;
                        memory.pop_back();
                        memory.pop_back();
                        memory.push_back(m);
                        SP = memory.size()-1;
                    }break;
                    case 9:{
                        SP = memory.size()-1;
                        int x = memory[SP-1];
                        int y = memory[SP];
                        int m = x<=y;
                        memory.pop_back();
                        memory.pop_back();
                        memory.push_back(m);
                        SP = memory.size()-1;
                    } break;
                    case 10:{
                        SP = memory.size()-1;
                        int x = memory[SP-1];
                        int y = memory[SP];
                        int m = x>y;
                        memory.pop_back();
                        memory.pop_back();
                        memory.push_back(m);
                        SP = memory.size()-1;
                    }break;
                    case 11:{
                        SP = memory.size()-1;
                        int x = memory[SP-1];
                        int y = memory[SP];
                        int m = x>=y;
                        memory.pop_back();
                        memory.pop_back();
                        memory.push_back(m);
                        SP = memory.size()-1;
                    }break;
                    case 12:{
                        SP = memory.size()-1;
                        int x;
                        in >> x;
                        memory.push_back(x);
                        SP = memory.size()-1;	
                    }break;
                    case 13:{
                        SP = memory.size()-1;
                        out << memory[SP] << "\n";
                        memory.pop_back();
                        SP = memory.size()-1;
                    }break;
                    case 0: {
                        SP = memory.size()-1; 
                        SP = BP-1;
                        BP = memory[SP+2];
                        PC = memory[SP+3];
                        SP = memory.size()-1;
                    }break;
                    default:{
                        throw CP::Exception::INSTRUCTION_ERROR;
                    }
                }
            }break;
            default :{
                throw CP::Exception::INSTRUCTION_ERROR;
            }
        }
    }
}

int Machine::findLevel(int l){
	int a = BP;
	while(l > 0){
		a = memory[a]; 
		l--;
	}
	return a;
}


}//namespcace


#include <iostream>
#include <string>
#include "chainofresp.h"
#include "patternexec.h"

using namespace std;

const int CHAIN = 2;

int main()
{
    int sdirective = 2;
    PatternExec* _patterne = 0;
    string name ="CHAIN";
    string conf = "1000";

    switch(sdirective){
    case CHAIN:
        _patterne =  new PatternExec(new ChainOfResp(name,conf));
    break;
    default:
        return -100;

    }

   int r =   _patterne->execute();

   if(!r)
    cout << "Program ended correctly" << endl;

    return r;
}

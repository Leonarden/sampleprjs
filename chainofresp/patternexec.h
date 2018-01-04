#ifndef PATTERNEXEC_H_INCLUDED
#define PATTERNEXEC_H_INCLUDED

#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class Pattern {
public:
Pattern();
Pattern(string name, string conf);
virtual int run();
private:
    string _name;
    string _conf;
};
Pattern::Pattern() {}
Pattern::Pattern(string name, string conf) {
     _name = name; _conf= conf;
}
int Pattern::run() {
cout<< "Running an empty pattern " << endl;
return 10;
}
class PatternExec {

public:
PatternExec();
PatternExec(Pattern* pattern);
virtual int execute();
private:
    Pattern* _pattern;
};
PatternExec::PatternExec(Pattern* p){ _pattern = p;}
int PatternExec::execute() {
    return this->_pattern->run();
}


class ChainOfResp: public Pattern {
public:
ChainOfResp();
ChainOfResp(string name, string conf);
virtual int run();
void setConf(string conf);
private:
    string _staticName = "CHAIN";
    int _deep;
};
ChainOfResp::ChainOfResp(){}
ChainOfResp::ChainOfResp(string name, string conf){
   if( _staticName != name) cout<<"Incorrect pattern Name" <<endl;
   else
    this->setConf(conf);
}
void ChainOfResp::setConf(string conf) {
 if(conf == "1000")
    _deep = 1000;
}
/**
Here is where pattern is applied
The value _deep indicates the TOPIC value which determines which component will process the call
*/
int ChainOfResp::run(){

Widget* aButton;
Widget* aField;
Dialog* aConfirm;
Application* anApp;

anApp = new Application(0, (TOPIC) _deep);
aConfirm = new Dialog(anApp, (TOPIC) _deep);
aField = new Widget(aConfirm, (TOPIC) _deep);
aButton = new Widget(aConfirm, (TOPIC) _deep);
cout << "Launch ChainOfResp from Button" << endl;
aButton->handle();
cout << "Launch CofResp from Field" << endl;
aField->handle();

cout << _staticName << " Pattern ended correctly " << endl;
return 0;
}

#endif // PATTERNEXEC_H_INCLUDED

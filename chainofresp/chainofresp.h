#ifndef CHAINOFRESP_H_INCLUDED
#define CHAINOFRESP_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

typedef  int TOPIC;
const TOPIC NO_VALUE = -1;

class Handler {
public:
Handler();
Handler(Handler* sucessor,TOPIC topic);
 int handle();

 int doProcess();

private:
    Handler* _sucessor;
    TOPIC _topic;
    const static TOPIC _myTopic = 0;
};
Handler::Handler(){}
Handler::Handler(Handler* sucessor, TOPIC topic){
_sucessor=sucessor;
_topic = topic;
}

int Handler::handle() {
    cout<< "Handling from Handler class" << endl;

   if(_topic == _myTopic){
        _sucessor->handle();
   }else doProcess();

}
int Handler::doProcess() {
    cout<< "Processing!!! from Handler class " << endl;
}

class Widget: public Handler {
public:
Widget();
Widget(Handler* widget, TOPIC topic);
int handle();
int doProcess();
private:
    Handler* _parent;
    TOPIC _topic;
   const static TOPIC _myTopic = 1;
};
Widget::Widget(){}
Widget::Widget(Handler* w, TOPIC topic) {
    _parent = w;
    _topic = topic;
}
int Widget::handle(){
cout << "Hadling from Widget class " << endl;
 if(_topic == _myTopic){
    _parent->handle();
 }else doProcess();

}

int Widget::doProcess() {
cout << "Processing from Widget class " << endl;
Handler::doProcess();
}

class Dialog:public Handler{
public:
    Dialog();
    Dialog(Handler* h, TOPIC t);
    int handle();
    int doProcess();
private:
    Handler* _handler;
    TOPIC _topic;
    const static TOPIC _myTopic = 2;
};
Dialog::Dialog(){}
Dialog::Dialog(Handler* h, TOPIC t):Handler(h,t) {

}

class Application:public Handler {
public:
    Application();
    Application(Handler* h, TOPIC t);
    int handle();
    int doProcess();
private:
    const Application* _app = this;
    const static TOPIC _myTopic = 1000;

};
Application::Application(){}
Application::Application(Handler* h, TOPIC t):Handler(h,t){}


#endif // CHAINOFRESP_H_INCLUDED

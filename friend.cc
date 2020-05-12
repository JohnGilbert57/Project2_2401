/*
    Name: Johnny Gilbert
    Date: 2/14/2020
    Description: Implementation for Friend class
*/
#include<iostream>
#include<string>
#include "date.h"
#include "friend.h"
using namespace std;
Friend::Friend(){
    name = "N/A";
}
std::string Friend::get_name()const{
    return name;
}
Date Friend::get_bday()const{
    return bday;
}
bool Friend::operator == (const Friend& other)const{
    if((name == other.name&& name.length() == other.name.length())&& bday == other.bday){
        return true;
    }
    else{
        return false;
    }
}
bool Friend::operator != (const Friend& other)const{
    if((name == other.name&& name.length() == other.name.length())&& bday == other.bday){
        return false;
    }
    else{
        return true;
    }
}
void Friend::input(std::istream& ins){
    if(ins.peek() == '\n'){
        ins.ignore();
    }
    getline(ins, name);
    ins >> bday;
}
void Friend::output(std::ostream& outs)const{
    outs << name << endl;
    outs << bday << endl;
}
std::istream& operator >>(std::istream& ins,Friend& f){
    f.input(ins);
    return ins;
}
std::ostream& operator <<(std::ostream& outs,const Friend& f){
    f.output(outs);
    return outs;
}
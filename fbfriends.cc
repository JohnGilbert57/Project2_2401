/*
	Name: Johnny Gilbert
	Date: 2/14/2020
	Description: Implementation for the FBFriends class and includes 
				  Big 3 implementation as well as all internal iterators
				  and load and save functionality
*/
#include<iostream>
#include<string>
#include<fstream>
#include "date.h"
#include "friend.h"
#include "fbfriends.h"
using namespace std;
FBFriends::FBFriends(){
	used = 0;
	capacity = 5;
	data = new Friend[capacity];
	current_index = 0;
}

//The functions known as the Big 3
FBFriends::~FBFriends(){
	delete [] data;
}
FBFriends::FBFriends(const FBFriends& other){
	used = other.used;
	capacity = other.capacity;
	data = new Friend[capacity];
	for(int i = 0; i < used; i++){
		data[i] = other.data[i];
	}
}
void FBFriends::operator = (const FBFriends& other){
	if(this == &other){
		return;
	}
    delete [] data;
	used = other.used;
	capacity = other.capacity;
	data = new Friend[capacity];
	for(int i = 0; i < used; i++){
		data[i] = other.data[i];
	}
}

	// Functions for the internal iterator
void FBFriends::start(){
	current_index = 0;
}
void FBFriends::advance(){
	current_index ++;
	if(current_index >= capacity){
		resize();
	}
		
}
bool FBFriends::is_item(){
	if(current_index < used){
		return true;
	}
	else{
		return false;
	}
}
Friend FBFriends::current(){
	return data[current_index];
}
void FBFriends::remove_current(){
	for(int j = current_index; j < used; j++){
		data[j] = data[j+1];
	}
	used --;
}
void FBFriends::insert(const Friend& f){
	if(is_item()){
		if(used >= capacity){
			resize();
		}
		for(int i = used; i > current_index; i--){
			data[i] = data[i-1];
		}
		used ++;
		data[current_index] = f;
	}
	else{
		if(used >= capacity){
			resize();
		}
		for(int i = used; i > 0; i--){
			data[i] = data [i-1];
		}
		used ++;
		data[0] = f;
	}
}
void FBFriends::attach(const Friend& f){
	if(is_item()){
		if(used >= capacity){
			resize();
		}
		for(int i = used; i > current_index; i--){
			data[i] = data[i-1];
		}
		used ++;
		data[current_index + 1] = f;
	}
	else{
		if(used >= capacity){
			resize();
		}
		data[used] = f;
		used ++;
	}
	
}
void FBFriends::show_all(std::ostream& outs)const{
	for(int i = 0; i < used; i++){
		cout << data[i].get_name() << ": " << data[i].get_bday() << endl;
	}
}
void FBFriends::bday_sort(){
	Date currentMin;
	//Friend tmp;
	int minIndex;
	for(int i = 0; i < used; i++){
		currentMin = data[i].get_bday();
		minIndex = i;
		//tmp = data[i];
			for(int j = i; j < used; j++){
				if(data[j].get_bday() < currentMin){
					minIndex = j;
					currentMin = data[j].get_bday();
				}
			}
		swap(data[i], data[minIndex]);
	}

}
Friend FBFriends::find_friend(const std::string& name)const{
	Friend notFound;
	for(int i = 0; i < used; i++){
		if(name == data[i].get_name() && name.length() == data[i].get_name().length()){
			return data[i];
		}
	}
	return notFound;
}
bool FBFriends::is_friend(const Friend& f) const{
	for(int i = 0; i < used; i++){
		if(data[i].get_name() == f.get_name() && data[i].get_bday() == f.get_bday()){
			return true;
		}
	}
	return false;
}
void FBFriends::load(std::istream& ins){
	while (ins>>data[used]){
		used ++;
		if(used == capacity){
			resize();
		}
	}
	
}
void FBFriends::save(std::ostream& outs){
	for(int i = 0; i < used; i++){
		outs << data[i].get_name() << endl;
		outs << data[i].get_bday() << endl;
	}
}
void FBFriends::resize(){
	if (used == capacity){
		Friend* tmpptr = new Friend[capacity+5];
		capacity += 5;
		for(int i = 0; i < used; i++){
			tmpptr[i] = data[i];
		}
		delete [] data;
		data = tmpptr;
	}
}
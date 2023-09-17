
#include "blue.h"





void Ble32::setup(const String name){
	_name = name;
	_SerialBT.begin(_name);
}

String Ble32::read(){
	if (_SerialBT.available()){
		return String(_SerialBT.read());
	}
	return String("[NOTHING]");
}
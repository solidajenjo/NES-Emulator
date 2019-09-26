#include <iostream>
#include "Application.h"
using namespace std;


int main() {

	Application App;
	
	cout << "DragoNES emulator init." << endl;

	while (App.Update());
	
	cout << "DragoNES emulator quit." << endl;
}
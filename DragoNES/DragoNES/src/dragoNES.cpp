#include <iostream>
#include "Application.h"
#include "Globals.h"
using namespace std;


int main() {

	App = new Application();
	
	cout << "DragoNES emulator init." << endl;

	while (App->Update());
	
	RELEASE(App);

	cout << "DragoNES emulator quit." << endl;
}
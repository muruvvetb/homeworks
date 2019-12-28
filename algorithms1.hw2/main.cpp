//Mürüvvet Bozkurt 150160133

#include <iostream>
#include <string>
#include <fstream>
#include "minheap.cpp"

using namespace std;

void fillvector(vector<Event>& newMyClass, const char* a){  
	int i = 0;
	ifstream file;
	string event_name1;
	int stime, etime;
	file.open(a);
	if(!file.is_open()){
		cout << "File is not opened." << endl;
	}
	while(!file.eof()){
		file >> event_name1 >> stime >> etime;  //read from file
		Event newEvent(event_name1, stime, true , i);  //create objects that have event_name, start time.
		i++;
		Event newEvent1(event_name1, etime, false , i); //create objects that have event_name, end time.
		i++;
		newMyClass.push_back(newEvent);  // push obj to vector 
		newMyClass.push_back(newEvent1);
	}

	
	
}


int main(int argc, char** argv){
    vector<Event> myClass;  //vector of objects
	fillvector(myClass, argv[1]);  
	Minheap minheap(myClass);  //heap sort for objects
	for (unsigned int i = 0; i < myClass.size(); i++) {
		minheap.insert(myClass[i]);  // create heap tree(array) of objects
	}
	int T=0;
	Event temp = minheap.drop();  //firstly, delete obj.
	for(int i=0; minheap.getHeapsize() >= 0; i++) {  // loop for deleting heap tree objects and print on the screen.
		if (T != temp.getTime()) {
			cout << "Time "<<T<<": NO EVENT"<<endl;
		}
		else {
			while (T == temp.getTime()) {
				
				if (temp.getWhat() == true) {
					cout << "Time " << T << ": " << temp.getName() << " STARTED" << endl;
				}
				else {
					cout << "Time " << T << ": " << temp.getName() << " ENDED" << endl;

				}

				
				if (minheap.getHeapsize() == 0) {
					cout << "Time " << T << ": " << "NO MORE EVENTS, SCHEDULER EXISTS" << endl;
					return 0;
				}
				temp = minheap.drop();
			}
		}
		T++;
	}
	
	return 0;

	
}


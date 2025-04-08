#include <iostream>

using namespace std;

class MusicalInsttrument {



public:
	virtual void play() { cout << " Playing instrement ... " << endl; };
	virtual void reset () { cout << " Playing instrement ... " << endl; };
	virtual ~MusicalInsttrument() {}
};


class Machine {
public:
	virtual void start() = 0;
	virtual ~Machine() {}
};
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
	virtual void play() { cout << " Starting Machine ... " << endl; };
	virtual void reset() { cout << " Resetting Machine ... " << endl; };
	virtual ~Machine() {}
};


class Synthesizer : public MusicalInsttrument, public Machine {
public:
	void play() override {
		MusicalInsttrument::play();
		Machine::play();
		cout << " Playing Synthesizer ... " << endl;
	}
	void reset() override {
		MusicalInsttrument::reset();
		Machine::reset();
		cout << " Resetting Synthesizer ... " << endl;
	}
};
#ifndef HEADER_H
#define HEADER_H

/* forward referebce 방지를 위한 forward declaration */
class AirlineBook;
class Schdule;
class Seat;

class AirlineBook {
	Schdule *schdule;
public:
	AirlineBook();
	~AirlineBook();
	void reserve();
	void cancel();
	void show();
	void system();
};

class Schdule {
	Seat *seat;
	string time;
public:
	Schdule(string time);
	~Schdule();
	void reserve(int seatNo, string name);
	void cancel(int seatNo, string name);
	void show();
};

class Seat {
	string name;
public:
	Seat();
	~Seat();
	void reserve(string name);
	void cancel();
	string getName();
};

class Console {
public:
	static void showTitle();
	static int selectMenu();
	static int selectTime();
	static string inputName();
	static int selectSeatNo();
};

#endif // !HEADER_H
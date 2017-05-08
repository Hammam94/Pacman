#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

class object {

public:
	object(int, int);

	int get_x();
	int get_y();
	void set_x(int);
	void set_y(int);

private:
	int position_x;
	int position_y;

};
#endif

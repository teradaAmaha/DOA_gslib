#ifndef BASE_LIFE_H_
#define BASE_LIFE_H_

#include "Base.h"

class BaseLife {
public:

	BaseLife(int hp = 100);

	void initialize(int hp = 100);

	void sub(int hp);

	void draw() const;

	int get() const;

	void clear();
private:
	int hp_ = 100;


};

#endif // ! 

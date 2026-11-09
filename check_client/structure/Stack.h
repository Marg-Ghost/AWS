

#include "Item.h"

class stack{
	private:
		Item beginning;
	public:
	        stack();

		//setter and getter
		void set_beginning();
		Item get_beginning();

		//main datatype
		Item pop();
		void push();
}

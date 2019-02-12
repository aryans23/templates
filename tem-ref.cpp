#include <iostream>
#include <vector>

using namespace std;

/* reference parameters (Sec 11.4) */
template <typename T, const int& SZ>
class Arr
{
private:
	std::vector<T> v;

public:
	Arr(): v(SZ) {}
	
	void print() const {
		for (int i = 0; i < SZ; ++i) {
			cout << v[i] << " ";
		} cout << endl;
	}
};


/* Perfect forwarding (Sec 6.1) */
class X{
private:
	int t;

public:
	X(): t{0} {}	
};

void g(X&) {
	cout << "variable for variable X&" << endl;
}

void g(const X&) {
	cout << "variable for constant const X&" << endl;
}

void g(X&&) {
	cout << "variable for movalble object X&&" << endl;
}

template <typename T>
void f(T&& val) {
	g(std::forward<T> (val) );
}

int main()
{
	// Reference parameters (Sec: 11.4)
	// int s = 10;
	// Arr<int,s> a;
	// a.print();
	// s += 10;
	// a.print();

	// Perfect forwarding (Sec 6.1)
	// X v;
	// const X c;
	// f(v);
	// f(c);
	// f(X());
	// f(std::move(v));
}
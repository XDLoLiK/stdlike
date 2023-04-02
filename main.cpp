#include <stdlike/function.hpp>

int Func(const int* x, int y) {
	return (*x) + y;
}

struct Foo {
	int Func(int x) {
		return x + 1;
	}
};

int main() {
	stdlike::Function<int (const int*, int)> f2(Func);
	int x = 10;
	f2(&x, 8);

	stdlike::Function<int (Foo, int)> f1(&Foo::Func);
	Foo foo;
	f1(foo, 5);

	stdlike::UniquePtr<Foo[]> test(new Foo[5]);

	return 0;
}

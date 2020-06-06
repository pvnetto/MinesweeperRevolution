#include <iostream>

void passByValue(int val) {
	val += 3;
}

void passByReference(int& val) {
	val = 123;
}

void passByConstReference(const int& val) {
	int insideVal = 200 + val;
}

void passByAddress(int* addr) {
	std::cout << "Value in passByAddress: " << *addr << std::endl;
	*addr += 20;
}

void passPointerByReference(int& val) {
	std::cout << val << std::endl;
}

int snippet() {
	/**
	Static Arrays
		- Use pointers under the hood
		- Passed as reference to functions by default
		- Utils:
			- sizeof(arr): Returns length of array
	*/

	int integers[3];
	integers[0] = 0;
	integers[1] = 1;
	integers[2] = 2;

	int primes[3]{ 2, 3, 5 };
	int morePrimes[] = { 7, 11, 13, 17 };
	int zeroes[100] = { };		// Inicializa todos os elementos como 0

	/* References */
	int myVal = 3;
	std::cout << "Address: " << &myVal << std::endl;
	std::cout << "Dereferenced address: " << *(&myVal) << std::endl;

	/* Pointers */
	int* valPtr = &myVal;				// Points to the address of myVal, so they always have the same value
	std::cout << *valPtr << std::endl;

	/* Pointers - Dynamic memory allocation */
	int* dynamicArr{ new int { 6 } };
	std::cout << *dynamicArr << std::endl;

	// Dynamic variables must be "deleted" after use to reallocate the memory back to the OS,
	delete dynamicArr;		// Now the variable points to nowhere, a.k.a dangling pointer
	dynamicArr = nullptr;	// This is good practice, to prevent a variable from being a dangling pointer, allowing for checks
	if (!dynamicArr) {
		std::cout << "Memory was deallocated!" << std::endl;
	}

	// It's still possible to realocate memory to the variable, though
	dynamicArr = { new int(20) };
	std::cout << *dynamicArr << std::endl;

	/* Pointers & Arrays */
	// Arrays are basically pointers
	int* arrPtr = primes;
	std::cout << arrPtr[0] << std::endl;

	/* Pointers & n-D Arrays */
	// The best sollution is to flatten the dimensions into a 1D array, and convert indices using a function
	int rows = 10;
	int cols = 20;
	int* arr2D{ new int[rows * cols] };

	/* Passing parameters */
	passByValue(rows);
	std::cout << rows << std::endl;

	passByReference(rows);
	std::cout << rows << std::endl;

	passByConstReference(rows);
	std::cout << rows << std::endl;

	int* rowPtr{ new int{3123} };
	passByAddress(rowPtr);
	std::cout << *rowPtr << std::endl;

	int* val = { new int {200} };
	passPointerByReference(*val);

	return 0;
}
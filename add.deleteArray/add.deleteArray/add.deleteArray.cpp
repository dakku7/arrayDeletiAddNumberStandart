#include <iostream>
#include <ctime>


using namespace std;

void showArray(const int* arr, const int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void fillArray(int* const arr, const int size) {



	for (int i = 0; i < size; i++) {

		arr[i] = rand() % 100;
	}
}

void copyArray(int* const destination, int* const source, const int size) {

	for (int i = 0; i < size; i++) {
		destination[i] = source[i];
	}
}

void addElement(int*& arr, int& size, const int element) {
	int* newArr = new int[size + 1];

	for (int i = 0; i < size; i++) {
		newArr[i] = arr[i];
	}

	newArr[size] = element;
	size++;

	delete[] arr;

	arr = newArr;
}


void deleteElement(int*& arr, int& size, const int element) {


	int count = 0;

	for (int i = 0; i < size; i++) {
		if (arr[i] != element) {
			count++;
		}
	}

	if (count == size) {
		cout << "Element not found. Nothing deleted." << endl;
		return;
	}
	
	
	int* newArr = new int[size];
	for (int i = 0, j = 0; i < size; i++) {
		if (arr[i] != element) {
			newArr[j++] = arr[i];
		}
	}
	
	delete[] arr;
	arr = newArr;
	size = count;


}


void addElementIndex(int*& arr, int& size, const int element, int index) {
	int* newArr = new int[size + 1];

	if (index > size || index < 0) {
		cout << "Invalid index. The element will be added at the end of the array." << endl;
		index = size;
	}

	for (int i = 0, j = 0; i < size + 1; i++) {
		if (i == index) {
			newArr[i] = element; 
		}
		else {
			newArr[i] = arr[j]; 
			j++;
		}
	}


	size++;
	delete[] arr;

	arr = newArr;
}

void deleteElementIndex(int*& arr, int& size, int index) {
	int* newArr = new int[size - 1];

	if (index >= size || index < 0) {
		cout << "Invalid index. No element will be deleted." << endl;
		return;
	}

	for (int i = 0, j = 0; i < size; i++) {
		if (i == index) {
			continue;
		}
		else
		{
			newArr[j++] = arr[i]; 
		}

	}
	size--;
	delete[] arr;

	arr = newArr;
}

int main() {

	int size, choice;
	int element, index;

	srand(time(0));

	cout << "Enter the size of the array: "; cin >> size;

	int* arr = new int[size];
	fillArray(arr, size);
	showArray(arr, size);
	do {

	cout << "\n1. Add element\n2. Delete element\n3. Add element at index\n4.Enter the index to delete\n5. Exit\n"; cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Enter the element to add: ";  cin >> element;
			addElement(arr, size, element);
			showArray(arr, size);
			break;
		case 2:
			cout << "Enter the element to delete: ";  cin >> element;
			deleteElement(arr, size, element);
			showArray(arr, size);
			break;
		case 3:
			cout << "Add element at index: "; cin >> index;
			cout << "Enter the element to add: ";  cin >> element;
			addElementIndex(arr, size, element, index);
			showArray(arr, size);
			break;
		case 4:
			cout << "Enter the index to delete: "; cin >> index;
			deleteElementIndex(arr, size, index);
			showArray(arr, size);
			break;
		case 5:
			return 0;
		default:
			break;
		}
	} while (choice != 5);

	delete[] arr;
	return 0;
}
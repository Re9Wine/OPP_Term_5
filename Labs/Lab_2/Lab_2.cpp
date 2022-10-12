using namespace std;

#include <iostream>

void firstTask();
void fillArray(int*, int);
void printArray(int*, int*);
int* findFirstNegativeElement(int*, int);
int elementsSum(int*, int*);
void triplingOddElements(int*, int*);

void secondTask();
int** initMatrix(int, int);
void fillMatrix(int**, int, int);
void printMatrix(int**, int, int);
int** matrixSum(int**, int**, int, int);
int** matrixMultiplication(int**, int**, int, int, int);


int main()
{
	secondTask();
}

void firstTask() {
	int numbersLength;

	cout << "Enter numbers length:";
	cin >> numbersLength;

	int* numbers = new int[numbersLength];

	cout << "Array:" << endl;

	fillArray(numbers, numbersLength);
	printArray(numbers, numbers + numbersLength);

	int* firstNegativeElement = findFirstNegativeElement(numbers, numbersLength);
	int* lastNegativeElement = firstNegativeElement;
	bool flag = true;

	while (flag) {
		if (findFirstNegativeElement(lastNegativeElement + 1, numbersLength - (lastNegativeElement - numbers) - 1) != nullptr) {
			lastNegativeElement = findFirstNegativeElement(lastNegativeElement + 1, numbersLength - (lastNegativeElement - numbers) - 1);
		}
		else {
			flag = false;
		}
	}

	int sum = elementsSum(firstNegativeElement + 1, lastNegativeElement);

	cout << "Element behind first negative element:" << endl;
	printArray(numbers, firstNegativeElement);

	cout << "Sum of elements between first and last negative elements = " << sum << endl;
	cout << "Array with tripling odd elements:" << endl;

	triplingOddElements(numbers, numbers + numbersLength);
	printArray(numbers, numbers + numbersLength);
}

void fillArray(int* begin, int length) {
	srand(time(NULL));

	for (int i = 0; i < length; i++, begin++)
	{
		*begin = rand() % (length * 2) - rand() % (length * 2) + 5;
	}
}

void printArray(int* begin, int* end) {
	for (; begin < end; begin++)
	{
		cout << *begin << "  ";
	}

	cout << endl;
}

int* findFirstNegativeElement(int* begin, int length) {
	int* negativeElement = nullptr;

	for (int i = 0; i < length; i++, begin++)
	{
		if (*(begin) < 0) {
			negativeElement = begin;
			break;
		}
	}

	return negativeElement;
}

int elementsSum(int* begin, int* end)
{
	int sum = 0;

	for (; begin < end; begin++)
	{
		sum += *(begin);
	}

	return sum;
}

void triplingOddElements(int* begin, int* end)
{
	for (; begin < end; begin++)
	{
		if (abs(*(begin)) % 2 == 1) {
			*(begin) *= 3;
		}
	}
}

//-----------------------------------------------------------------------------------------------------------------------------------------

void secondTask() {
	int order;

	cout << "Enter matrix order:";
	cin >> order;

	int** matrixA = initMatrix(order, order);

	cout << "Matrix A:" << endl;

	fillMatrix(matrixA, order, order);
	printMatrix(matrixA, order, order);

	int** matrixB = initMatrix(order, order);

	cout << "Matrix B:" << endl;

	fillMatrix(matrixB, order, order);
	printMatrix(matrixB, order, order);

	int** matrixC = initMatrix(order, order);

	cout << "Matrix C:" << endl;

	fillMatrix(matrixC, order, order);
	printMatrix(matrixC, order, order);

	int** matrixSumm = matrixSum(matrixA, matrixB, order, order);
	int** matrixMultiplicationn = matrixMultiplication(matrixSumm, matrixC, order, order, order);

	cout << "(matrixA + matrixB) * matrixC:" << endl;

	printMatrix(matrixMultiplicationn, order, order);
}

int** initMatrix(int rows, int columns) {
	int** matrix = new int* [columns];

	for (int i = 0; i < rows; i++)
	{
		*(matrix + i) = new int[columns];
	}

	return matrix;
}

void fillMatrix(int** begin, int rows, int columns) {
	srand(time(0));

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			*(*(begin + i) + j) = rand() % (rows * columns);
		}
	}
}

void printMatrix(int** begin, int rows, int columns) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << *(*(begin + i) + j) << "  ";
		}

		cout << endl;
	}
}

int** matrixSum(int** matrixA, int** matrixB, int rows, int columns)
{
	int** sum = initMatrix(rows, columns);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			*(*(sum + i) + j) = *(*(matrixA + i) + j) + *(*(matrixB + i) + j);
		}
	}

	return sum;
}

int** matrixMultiplication(int** matrixA, int** matrixB, int agreedElement, int rowsA, int columnsB)
{
	int** multiplication = initMatrix(rowsA, columnsB);

	for (int i = 0; i < rowsA; i++)
	{
		for (int j = 0; j < columnsB; j++)
		{
			*(*(multiplication + i) + j) = 0;

			for (int k = 0; k < agreedElement; k++)
			{
				*(*(multiplication + i) + j) += *(*(matrixA + i) + k) * (*(*(matrixB + k) + j));
			}
		}
	}

	return multiplication;
}

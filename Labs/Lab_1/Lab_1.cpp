using namespace std;

#include <iostream>

void firstTask();

void secondTask();
void printArray(double[], int);
double findMinElement(double[], int);
double elementSum(int, int, double[]);
int findFirstPositiveElementIndex(double[], int);
int findLastPositiveElementIndex(double[], int);
double* zeroAtTheBeginning(double[], int);

void thirdTask();
const int Columns = 8;
const int Rows = 10;
void fillMatrix(int, int, int[][Columns]);
void printMatrix(int, int, int[][Columns]);
bool rowContainsNegativeElement(int, int*);
int elementSum(int, int, int*);
void printSumWithNegativeElement(int, int, int[][Columns]);
int findMinElementIndexInRow(int, int[]);
int findMinElementIndexInColumn(int, int, int[][Columns]);
void printSaddlePoints(int, int, int[][Columns]);

int main()
{
	secondTask();
}

//----------------------------------------------------------------------------------------

void firstTask() {
	double alpha;

	cout << "Enter alpha:" << endl;
	cin >> alpha;

	double z1 = cos(alpha) + cos(alpha * 2) + cos(alpha * 6) + cos(alpha * 7);
	double z2 = 4 * cos(alpha * 0.5) * cos(alpha * 2.5) * cos(alpha * 4);

	cout << "First function result = " << z1 << endl;
	cout << "Second function result = " << z2 << endl;
}

//----------------------------------------------------------------------------------------

void secondTask() {
	const int n = 15;
	double numbers[n] = { -4.3, -1.3, -0.2, 1.9, 0, 0.1, 2.8, 1.2, 4.6, 0.7, 0, -4.1, 0.7, -2.2, 4.5 };

	double minElement = findMinElement(numbers, n);
	double sumElement = elementSum(
		findFirstPositiveElementIndex(numbers, n), findLastPositiveElementIndex(numbers, n), numbers);
	cout << "Array:" << endl;
	printArray(numbers, n);
	cout << "Min element in array = " << minElement << endl;
	cout << numbers[findFirstPositiveElementIndex(numbers, n)] << "  " << numbers[findLastPositiveElementIndex(numbers, n)] << endl;
	cout << "Sum of array elements between first and last positive elements = " << sumElement << endl;
	cout << "Zero at the beginning:" << endl;

	double* sortedArray = zeroAtTheBeginning(numbers, n);
	printArray(sortedArray, n);
}

void printArray(double numbers[], int n) {
	for (int i = 0; i < n; i++)
	{
		cout << numbers[i] << "  ";
	}

	cout << endl;
}

double findMinElement(double numbers[], int n) {
	double minElement = numbers[0];

	for (int i = 1; i < n; i++)
	{
		if (minElement >= numbers[i]) {
			minElement = numbers[i];
		}
	}

	return minElement;
}

int findFirstPositiveElementIndex(double numbers[], int n) {
	int positiveElementIndex = 0;

	for (int i = 0; i < n; i++)
	{
		if (numbers[i] > 0) {
			positiveElementIndex = i;
			break;
		}
	}

	return positiveElementIndex;
}

int findLastPositiveElementIndex(double numbers[], int n) {
	int positiveElementIndex = 0;

	for (int i = n - 1; i >= 0; i--)
	{
		if (numbers[i] > 0) {
			positiveElementIndex = i;
			break;
		}
	}

	return positiveElementIndex;
}

double elementSum(int startIndex, int endIndex, double numbers[]) {
	double sum = 0;

	for (int i = startIndex; i <= endIndex; i++)
	{
		sum += numbers[i];
	}

	return sum;
}

double* zeroAtTheBeginning(double numbers[], int n) {
	double* sortedArray = numbers;

	int lastZeroIndex = 0;

	for (int i = 0; i < n; i++)
	{
		if (sortedArray[i] == 0) {
			double buffer;

			for (int j = i; j > lastZeroIndex; j--)
			{
				buffer = sortedArray[j];
				sortedArray[j] = sortedArray[j - 1];
				sortedArray[j - 1] = buffer;
			}

			lastZeroIndex++;
		}
	}

	return sortedArray;
}

//----------------------------------------------------------------------------------------

void thirdTask() {
	int matrix[Rows][Columns];

	fillMatrix(Rows, Columns, matrix);

	cout << "Matrix:" << endl;
	printMatrix(Rows, Columns, matrix);
	printSumWithNegativeElement(Rows, Columns, matrix);
	printSaddlePoints(Rows, Columns, matrix);
}

void fillMatrix(int rows, int columns, int matrix[][Columns]) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			srand(i + j * 2);
			matrix[i][j] = 5 + rand() % 10 - rand() % 10;
		}
	}
}

void printMatrix(int rows, int columns, int matrix[][Columns]) {

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << matrix[i][j] << "\t";
		}

		cout << endl;
	}
}

bool rowContainsNegativeElement(int rowLength, int* row)
{
	for (int i = 0; i < rowLength; i++)
	{
		if (row[i] < 0) {
			return true;
		}
	}

	return false;
}

int elementSum(int startIndex, int endIndex, int* numbers)
{
	int sum = 0;

	for (int i = startIndex; i <= endIndex; i++)
	{
		sum += numbers[i];
	}

	return sum;
}

void printSumWithNegativeElement(int rows, int columns, int matrix[][Columns]) {
	for (int i = 0; i < rows; i++)
	{
		if (rowContainsNegativeElement(columns, matrix[i])) {
			int sum = elementSum(0, rows - 1, matrix[i]);

			cout << "Line number:" << i << " have negative element. The sum of the elements of this line = " << sum << endl;
		}
	}
}

int findMinElementIndexInRow(int rowLength, int row[]) {
	int minElementIndexInRow = 0;

	for (int i = 1; i < rowLength; i++)
	{
		if (row[minElementIndexInRow] > row[i]) {
			minElementIndexInRow = i;
		}
	}

	return minElementIndexInRow;
}

int findMinElementIndexInColumn(int columnIndex, int columnLength, int matrix[][Columns]) {
	int minElementIndexInColumn = 0;

	for (int i = 1; i < columnLength; i++)
	{
		if (matrix[minElementIndexInColumn][columnIndex] > matrix[i][columnIndex]) {
			minElementIndexInColumn = i;
		}
	}

	return minElementIndexInColumn;
}

void printSaddlePoints(int rows, int columns, int matrix[][Columns]) {
	for (int i = 0; i < rows; i++)
	{
		int minElementIndexInRow = findMinElementIndexInRow(columns, matrix[i]); // column index
		int minElemementIndexInColumn = findMinElementIndexInColumn(minElementIndexInRow, rows, matrix); // row index

		if (minElemementIndexInColumn == i) {
			cout << "Index saddle point: " << minElemementIndexInColumn << "," << minElementIndexInRow;
			cout << " .Value = " << matrix[minElemementIndexInColumn][minElementIndexInRow] << endl;
		}
	}
}

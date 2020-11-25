// Lab_7_1_1
#include <iostream>
#include <iomanip>
using namespace std;

int myrand(const int& min, const int& max) {
	return min > 0 ?
		rand() % (max - min + 1) + min :
		rand() % (abs(min) + max + 1) + min;
}

void full_matrix(int** matrix, const int* size, const int* dia) {
	for (int i = 0; i < size[0]; i++)
		for (int j = 0; j < size[1]; j++)
			matrix[i][j] = myrand(dia[0], dia[1]);
}

void draw_matrix(int** matrix, const int* size) {
	for (int i = 0; i < size[0]; i++) {
		for (int j = 0; j < size[1]; j++)
			cout << setw(4) << matrix[i][j];
		cout << endl;
	}
}

void get_sum_count(int** matrix, const int* size, int& sum, int& count) {
	sum = 0;
	count = 0;
	for (int i = 0; i < size[0]; i++)
		for (int j = 0; j < size[1]; j++)
			if (matrix[i][j] % 6 == 0 && (i + j) % 5 != 0){
				sum += matrix[i][j];
				count++;
				matrix[i][j] = 0;
			}
}

unsigned char get_status(int** matrix, const int* size) {
	bool has[2] = { false, false };

	for (int i = 0; i < size[0]; i++) {
		for (int j = i+1; j < size[0]; j++) {
			if (!has[0] && matrix[j][0] == matrix[i][0]) 
				has[0] = true;

			if (!has[1] && matrix[j][1] == matrix[i][1])
				has[1] = true;
		}
		if (has[0] && has[1])
			break;
	}

	if (has[0] && !has[1])
		return 1;
	else if (has[0] && has[1])
		return 2;
	return 0;
}

void sort(int** matrix, const int* size) {
	const unsigned char status = get_status(matrix, size);

	for (int i = 0; i < size[0] - 1; i++) 
		for (int j = 0; j < size[0] - i - 1; j++) 
			switch (status)
			{
			case 0:
				if (matrix[j][0] > matrix[j + 1][0]) goto swp;
				break;
			case 1:
				if (matrix[j][1] < matrix[j + 1][1]) goto swp;
				break;
			case 2:
				if (matrix[j][4] < matrix[j + 1][4]) goto swp;
				break;
			swp:
				swap(matrix[j], matrix[j + 1]);
			}
}

void main() {
	srand(time(NULL));

	int** matrix = nullptr, 
		dia[2] = { 11, 74 },
		size[2] = { 8, 9 },
		sum, count;
	matrix = new int* [size[0]];

	for (int i = 0; i < size[0]; i++)
		matrix[i] = new int[size[1]];

	full_matrix(matrix, size, dia);
	draw_matrix(matrix, size);
	cout << endl << "// sort" << endl;
	sort(matrix, size);
	draw_matrix(matrix, size);
	cout << endl << "// sum and count" << endl;
	get_sum_count(matrix, size, sum, count);
	draw_matrix(matrix, size);
	cout << "sum: " << sum << endl
		<< "count: " << count << endl;

	for (int i = 0; i < size[0]; i++)
		delete[] matrix[i];
		
	delete[] matrix;

}
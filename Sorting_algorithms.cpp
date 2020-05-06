#include <time.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct MyArray{
	
	int *array;
	
	int getSize()
	{ return size; }
	
	void controlFirstTenArrayData()
	{
		cout<<"First Ten Data"<<endl;
		for(int i = 0; i < 10; i++)
		{
			cout<<array[i]<< " ";
		}
	}
	
	MyArray(int size_)
	{
		size = size_;
		array = new int[size];
	}
	
	private:
	int size;
	
};

void fillArrayWithRandomData(MyArray );
void processTimeCalculator(MyArray , char* );
void swapData(MyArray , int , int );
void selectionSort(MyArray );
void bubbleSort(MyArray );
void insertionSort(MyArray );

int main()
{
	srand(time(NULL));
	
	MyArray array1(1000),array2(5000),array3(10000);
	
	fillArrayWithRandomData(array1);
	fillArrayWithRandomData(array2);
	fillArrayWithRandomData(array3);

	processTimeCalculator(array1, "Selection Sort");  // 0.001
	processTimeCalculator(array2, "Selection Sort");  // 0.031
	processTimeCalculator(array3, "Selection Sort");  // 0.127
	cout<<endl<<endl;
	processTimeCalculator(array1, "Bubble Sort");  // 0.002
	processTimeCalculator(array2, "Bubble Sort");  // 0.035
	processTimeCalculator(array3, "Bubble Sort");  // 0.138
	cout<<endl<<endl;
	processTimeCalculator(array1, "Insertion Sort");  // 0.002
	processTimeCalculator(array2, "Insertion Sort");  // 0.035
	processTimeCalculator(array3, "Insertion Sort");  // 0.139
	getchar();

}
void fillArrayWithRandomData(MyArray ar)
{
	int length = ar.getSize();
	for (int i = 0; i < length ; i++)
	{
		ar.array[i] = rand()% 9900 + 100;
	}
}


void processTimeCalculator(MyArray ar,char* method)
{
	clock_t start, end;
	if(method == "Selection Sort")
	{
		start = clock();
		selectionSort(ar);
		end = clock();
	}	
	else if(method == "Bubble Sort")
	{
		start = clock();
		bubbleSort(ar);
		end = clock();
	}
	else if(method == "Insertion Sort")
	{
		start = clock();
		insertionSort(ar);
		end = clock();
	}
	
	ar.controlFirstTenArrayData();
	cout << "| " << method << " - " << ar.getSize() << " data : " << (float)(end - start) / CLOCKS_PER_SEC << endl;
}

void swapData(MyArray ar, int firstData, int secondData)
{
	int temp;
	temp = ar.array[firstData];
	ar.array[firstData] = ar.array[secondData];
	ar.array[secondData] = temp; // temp == firstData ---> secondaData == firstData
}
void selectionSort(MyArray ar)
{
	int length = ar.getSize();
	int index, i, j;
	for (i = 0; i < length - 1; i++)
	{
		index = i;	
		for (j = i+1; j < length; j++)
		{
			if (ar.array[j] < ar.array[index])
			{
				index = j;
			}
		}
		if(i != index)
		swapData(ar, i, index);
	}
}
void bubbleSort(MyArray ar)
{
	int length = ar.getSize();
	int i, j;
	for (i = 0; i < length - 1; i++)
	{
		for (j = 0; j < length - i - 1; j++) 
		{
			if (ar.array[j] > ar.array[j+1])
			{
				swapData(ar, j, j+1);
			}
		}
	}
}

void  insertionSort(MyArray ar)
{
	int length = ar.getSize();
	int i, j;
	for (i = 1; i < length; i++)
	{

		for (j = i; j > 0; j--)
		{
			if (ar.array[j] < ar.array[j-1])
			{
				swapData(ar, j, j-1);
			}
		}
	}
}

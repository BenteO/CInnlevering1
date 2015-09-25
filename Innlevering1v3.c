//Marius H. Skeie og Bente Ottersen
//Sjekk ut struct
//Install sealion

#include <stdio.h>
#include <string.h>

//Declaring the functions to be able to use them in main
void printArray(int * numbersFromFile, int count);
int readFromFile(int *numbersFromFile, char *filename, int *originalIndex);
void bubbleSort(int count, int *numbersFromFile, int *originalIndex);
void selectionSort(int count, int *numbersFromFile, int *originalIndex);
void insertionSort(int count, int *numbersFromFile, int *originalIndex);
void binarySearch(int count, int *numbersFromFile, int search, int *originalIndex);

int main(int argc, char *argv[])
{
	char *filename = argv[1];
	int numbersFromFile[200001];
	int originalIndex[200001];	//Array to store the original indexes
	int count;
	int search;
	char sortingMethod[50];
	
	//Import
	count = readFromFile(numbersFromFile, filename, originalIndex);

	//Sorting
	printf("\n\nWhich sorting method do you want to use (bubble, selection, insertion)? ");
	scanf("%s", sortingMethod);
	printf("You chose %s sort.", sortingMethod);
	
	if(strcmp(sortingMethod, "bubble") == 0)
	{
		bubbleSort(count, numbersFromFile, originalIndex);
	}
	else if(strcmp(sortingMethod, "selection") == 0)
	{
		selectionSort(count, numbersFromFile, originalIndex);
	}
	else if(strcmp(sortingMethod, "insertion") == 0)
	{
		insertionSort(count, numbersFromFile, originalIndex);
	}else {
		return 0;
	}
	
	//Search
	printf("\n\nPlease input an integer for search (0 to quit the program): ");
	scanf("%d", &search);
	
	if(search == 0)
	{
		printf("\nProgram shutdown. Bye.\n");
		return 0;

	}
	else 
	{
		printf("You're searching for %d.\n\n", search);	
		binarySearch(count, numbersFromFile, search, originalIndex);
	}
	return 0;
}

void printArray(int * numbersFromFile, int count)
{
	for(int j = 0; j < count; j++)
	{
		printf("%d ", numbersFromFile[j]);
	}
}

int readFromFile(int *numbersFromFile, char *filename, int *originalIndex)
{
	FILE *file = fopen(filename, "r");
	int i = 0;
	int localcount = 0;

	while(!feof (file))
	{
		fscanf(file, "%d", &i);
		numbersFromFile[localcount] = i;
		originalIndex[localcount] = localcount + 1;
		localcount++;
	}
	fclose(file);

	printf("\nThere's a total of %d numbers.\n\n", localcount);
	printf("The numbers are:\n");
	printArray(numbersFromFile, localcount);	

	return localcount;
}

void bubbleSort(int count, int *numbersFromFile, int *originalIndex)
{
	printf("\n\nBubble sort:\n");
	for(int i = 0; i < count; i++)
	{
		for(int j = 0 ; j < count - 1; j++)
		{
			if(numbersFromFile[j] > numbersFromFile[j + 1])
			{
				int temp = numbersFromFile[j + 1];
				int tempIndex = originalIndex[j + 1];
				numbersFromFile[j + 1] = numbersFromFile[j];
				originalIndex[j + 1] = originalIndex[j];
				numbersFromFile[j] = temp;
				originalIndex[j] = tempIndex;
			}
		}
	}
	printArray(numbersFromFile, count);
}

void selectionSort(int count, int *numbersFromFile, int *originalIndex)
{
	printf("\n\nSelection sort:\n");
	for(int i = 0; i < count; i++)
	{
		int min = i;
		for(int j = i; j < count; j++)
		{
			if(numbersFromFile[min] > numbersFromFile[j])
			{
				min = j;
			}
		}
		int temp = numbersFromFile[i];
		int tempIndex = originalIndex[i];
		numbersFromFile[i] = numbersFromFile[min];
		originalIndex[i] = originalIndex[min];
		numbersFromFile[min] = temp;
		originalIndex[min] = tempIndex;
	}
	printArray(numbersFromFile, count);
}

void insertionSort(int count, int *numbersFromFile, int *originalIndex)
{
	printf("\n\nInsertion sort:\n");
	for(int i = 1 ; i < count; i++) 
	{
   		int j = i;
		while(j > 0 && numbersFromFile[j] < numbersFromFile[j - 1])
		{
			int temp = numbersFromFile[j];
			int tempIndex = originalIndex[j];
			numbersFromFile[j] = numbersFromFile[j - 1];
			originalIndex[j] = originalIndex[j - 1];
			numbersFromFile[j - 1] = temp;
			originalIndex[j - 1] = tempIndex;
			j--;
		}
	}
	printArray(numbersFromFile, count);
}

void binarySearch(int count, int *numbersFromFile, int search, int *originalIndex)
{
	int first = 0;
	int last = count - 1;
	int middle = (first + last) / 2;	

	while(first <= last)
	{
		if(numbersFromFile[middle] < search)
			first = middle + 1;
		else if(numbersFromFile[middle] == search)
		{
			printf("%d found at position %d.\n", search, middle + 1);
			int index = originalIndex[middle];
			printf("Position before sort was %d.\n", index);			
			break;
		}
		else
			last = middle - 1;

		middle = (first + last) / 2;
	}
	if (first > last)
		printf("%d is not in the list.\n", search);
}


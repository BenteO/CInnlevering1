//Marius H. Skeie og Bente Ottersen
//Sjekk ut struct
//Install sealion

#include <stdio.h>
#include <string.h>

//Declaring the functions to be able to use them in main
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
	int count,search;
	int sortCheck = 1;
	char sortingMethod[50];
	
	//Import
	count = readFromFile(numbersFromFile, filename, originalIndex);

	//Sorting
	while(sortCheck)
	{
		printf("\nWhich sorting method do you want to use (bubble, selection or insertion)? ");
		scanf("%s", sortingMethod);
	
		if(strcmp(sortingMethod, "bubble") == 0)
		{
			bubbleSort(count, numbersFromFile, originalIndex);
			sortCheck = 0;
		}
		else if(strcmp(sortingMethod, "selection") == 0)
		{
			selectionSort(count, numbersFromFile, originalIndex);
			sortCheck = 0;
		}
		else if(strcmp(sortingMethod, "insertion") == 0)
		{
			insertionSort(count, numbersFromFile, originalIndex);
			sortCheck = 0;
		}else {
			printf("\nPlease write a valid sorting method.");
		}
	}
	
	//Search
	
	printf("\nPlease input an integer for search (0 to quit the program): ");
	scanf("%d", &search);

	if(search == 0)
		{
			printf("\nYou chose to quit the program. Bye.\n");
			return 0;

		}
	else
	{	
		binarySearch(count, numbersFromFile, search, originalIndex);
	}

	printf("\nClosing program. Bye.\n");

	return 0;
}

/*
*Function to read integers from a text file and adds them to an array
*It saves the index of the integers in another array, using localCount
*Returns the amount of integers
*/
int readFromFile(int *numbersFromFile, char *filename, int *originalIndex)
{
	FILE *file = fopen(filename, "r");
	int i = 0;
	int localCount = 0;

	while(!feof (file))
	{
		fscanf(file, "%d", &i);
		numbersFromFile[localCount] = i;
		originalIndex[localCount] = localCount + 1;
		localCount++;
	}
	fclose(file);

	printf("\nThere's a total of %d numbers.\n", localCount);

	return localCount;
}

/*
*Three sorting functions
*Sorts the two arrays (the one with the integers and the one with the original indexes) simultaneously
*/

//Function that uses bubble sort
void bubbleSort(int count, int *numbersFromFile, int *originalIndex)
{
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
}

//Function that uses selection sort
void selectionSort(int count, int *numbersFromFile, int *originalIndex)
{
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
}

//Function that uses insertion sort
void insertionSort(int count, int *numbersFromFile, int *originalIndex)
{
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
}

/*
*Binary search function
*Searches for the input from user
*Finds the integers index from the array before it got sorted (which is stored in the originalIndex array)
*/
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
			printf("\n%d was found at position %d.\n", search, middle + 1);
			int index = originalIndex[middle];
			printf("Position before sort was %d.\n", index);		
			break;
		}
		else
			last = middle - 1;

		middle = (first + last) / 2;
	}

	if (first > last)
		printf("\nThe number %d is not in the array.\n", search);
}

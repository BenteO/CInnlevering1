//Marius H. Skeie og Bente Ottersen
//Sjekk ut struct
//Bruke to arrays til å finne index fra original array

#include <stdio.h>
#include <string.h>

int readFromFile(int *numbersFromFile, char *filename)
{
	FILE *file = fopen(filename, "r");
	int i = 0;
	int localcount = 0;

	while(!feof (file))
	{
		fscanf(file, "%d", &i);
		numbersFromFile[localcount] = i;
		localcount++;
	}
	fclose(file);

	printf("\nThere's a total of %d numbers.\n\n", localcount);
	printf("The numbers are:\n");

	for(int j = 0; j < localcount; j++)
	{
		printf("%d ", numbersFromFile[j]);
	}
	return localcount;
}

void bubbleSort(int count, int numbersFromFile[])
{
	printf("\n\nBubble sort:\n");
	for(int x = 0; x < count; x++)
	{
		for(int y = 0 ; y < count - 1; y++)
		{
			if(numbersFromFile[y] > numbersFromFile[y + 1])
			{
				int temp = numbersFromFile[y + 1];
				numbersFromFile[y + 1] = numbersFromFile[y];
				numbersFromFile[y] = temp;
			}
		}
	}
		for(int j = 0; j < count; j++)
	{
		printf("%d ", numbersFromFile[j]);
	}
}

void selectionSort(int count, int numbersFromFile[])
{
	printf("\n\nSelection sort:\n");
	for(int x = 0; x < count; x++)
	{
		int index_of_min = x;
		for(int y = x; y < count; y++)
		{
			if(numbersFromFile[index_of_min] > numbersFromFile[y])
			{
				index_of_min = y;
			}
		}
		int temp = numbersFromFile[x];
		numbersFromFile[x] = numbersFromFile[index_of_min];
		numbersFromFile[index_of_min] = temp;
	}

	for(int j = 0; j < count; j++)
	{
		printf("%d ", numbersFromFile[j]);	}
}

void insertionSort(int count, int numbersFromFile[])
{
	printf("\n\nInsertion sort:\n");
	for(int c = 1 ; c <= count - 1; c++) {
   		int d = c;

		while(d > 0 && numbersFromFile[d] < numbersFromFile[d-1])
		{
			int t = numbersFromFile[d];
			numbersFromFile[d] = numbersFromFile[d-1];
			numbersFromFile[d-1] = t;
			d--;
		}
	}
	for(int j = 0; j < count; j++)
	{
		printf("%d ", numbersFromFile[j]);
	}
}

void binarySearch(int count, int numbersFromFile[], int search)
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
			printf("%d found at location %d.\n", search, middle + 1);
			break;
		}
		else
			last = middle - 1;

		middle = (first + last) / 2;
	}
	if (first > last)
		printf("%d is not in the list.\n", search);
}

int main(int argc, char *argv[])
{
	char *filename = argv[1];
	int numbersFromFile[200001];
	int count = 0;
	int search;
	char sortingMethod[50];
	
	//Import
	count = readFromFile( numbersFromFile, filename);

	//Sorting
	printf("\n\nWhich sorting method do you want to use (bubble, selection, insertion)? ");
	scanf("%s", sortingMethod);
	printf("You chose %s.", sortingMethod);
	
	if(strcmp(sortingMethod, "bubble") == 0)
	{
		bubbleSort(count, numbersFromFile);
	}
	else if(strcmp(sortingMethod, "selection") == 0)
	{
		selectionSort(count, numbersFromFile);
	}
	else if(strcmp(sortingMethod, "insertion") == 0)
	{
		insertionSort(count, numbersFromFile);
	}else {
		return 0;
	}
	
	//Search
	printf("\n\nPlease input an integer for search: ");
	scanf("%d", &search);
	printf("\nYou're searching for %d.\n", search);	
	
	if(search == 0)
	{
		//Quit program

	}
	else binarySearch(count, numbersFromFile, search);

	return 0;
}

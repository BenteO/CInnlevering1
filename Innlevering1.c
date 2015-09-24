//Marius H. Skeie og Bente Ottersen

#include <stdio.h>

int main(int argc, char *argv[])
{
	int numbersFromFile[200000];
	int count = 0;
	int *search;
	char sortingMethod[50];

	FILE *file = fopen(argv[1], "r");
	int i = 0;
	
	while(!feof (file))
	{
		fscanf(file, "%d", &i);
		//printf("%d ", i);
		numbersFromFile[count] = i;
		count++;
	}
	fclose(file);

	printf("\nThere's a total of %d numbers.\n\n", count);
	printf("The numbers are:\n");

	for(int j = 0; j < count; j++)
	{
		printf("%d ", numbersFromFile[j]);
	}

	//Sorting
	/*printf("\n\nWhich sorting method do you want to use (bubble, selection, quick)? ");
	*scanf("%s", sortingMethod);
	*printf("You chose %s .", sortingMethod);
	*
	*if(sortingMethod == "bubble")
	{*/
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
	if(sortingMethod == "selection" || sortingMethod == "s")
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
			printf("%d ", numbersFromFile[j]);
		}

		printf("\n");
	}
	/*}
	else 
	{
		printf("Blabla");
	}*/
	
	//Search
	printf("\nPlease input an integer for search: ");
	scanf("%d", *search);
	printf("\nYou're searching for %d .", *search);	

return 0;
}

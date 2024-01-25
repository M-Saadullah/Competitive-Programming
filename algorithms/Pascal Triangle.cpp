// Array implementation of pascal triangle

int** createPascalTrianle(int size)
{
	int** arr = new int* [size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = new int [size] {0};
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i >= j)
			{
				if (i == j || j == 0)
				{
					arr[i][j] = 1;
				}
				else
				{
					int x =  arr[i - 1][j - 1] + arr[i - 1][j];
					arr[i][j] = x;
				}
			}
		}
	}
	return arr;
}

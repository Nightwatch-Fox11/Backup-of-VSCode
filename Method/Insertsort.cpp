void insertsort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = a[i], j = i;
        while (j > 0 && a[j - 1] > temp)
        {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = temp;
    }
}
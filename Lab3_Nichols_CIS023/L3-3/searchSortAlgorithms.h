/*
'* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
'* Program name    : L3-3                                              * 
'*                                                                     * 
'* Written by      : Bailey Nichols                                    * 
'*                                                                     * 
'* Purpose         : To demonstrate diffrent sorting methods.          *
'*---------------------------------------------------------------------* 
'* Change Log:                                                         * 
'*                         Revision                                    * 
'*       Date    Changed  Rel Ver Mod Purpose                          * 
'* 11/08/12      Bailey 000.000.000 Initial release of program       * 
'*                                                                     * 
'* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
*/

//Malik, D.S.. C++ Programming  Programming Design Including Data Structures 
//(MindTap Course List) (p. 1316). Cengage Learning Kindle Edition
template <class elmT>
void swap(elmT, int i, int j){
    elmT temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

//Malik, D.S.. C++ Programming  Programming Design Including Data Structures 
//(MindTap Course List) (p. 1281). Cengage Learning Kindle Edition
template <class elmT>
int seqSearch(const elmT list[], int size, const elmT &item)
{
    int loc;
    bool found = false;
    while (!found && loc < size)
    {
        if (list[loc] == item)
            found = true;
        else
            loc++;
    }
    if (found)
        return loc;
    else
        return -1;
}


//Malik, D.S.. C++ Programming  Programming Design Including Data Structures 
//(MindTap Course List) (p. 1285). Cengage Learning Kindle Edition
template <class elmT>
int binarySearch(const elmT list[], int size, const elmT &item)
{
    int first = 0;
    int last = size - 1;
    int mid;
    bool found = false;
    while (!found && first <= last)
    {
        mid = (first + last) / 2;
        if (list[mid] == item)
            found = true;
        else if (list[mid] > item)
            last = mid - 1;
        else
            first = mid + 1;
    }
    if (found)
        return mid;
    else
        return -1;
}


//Malik, D.S.. C++ Programming  Programming Design Including Data Structures
//(MindTap Course List) (p. 1300). Cengage Learning Kindle Edition
template <class elmT>
int bubbleSort(elmT list[], int size)
{
    for (int pass = 1; pass < size; pass++)
    {
        for (int loc = 0; loc < size - 1; loc++)
        {
            if (list[loc] > list[loc + 1])
            {
                elmT temp = list[loc];
                list[loc] = list[loc + 1];
                list[loc + 1] = temp;
            }
        }
    }
}

//Malik, D.S.. C++ Programming  Programming Design Including Data Structures
//(MindTap Course List) (p. 1303-1304). Cengage Learning Kindle Edition
template <class elmT>
int minLocation(elmT list[], int first, int last){
    int minIndex = first;
    for (int loc = first + 1; loc <= last; loc++)
        if (list[loc] < list[minIndex])
            minIndex = loc;
    return minIndex;
}

//Malik, D.S.. C++ Programming  Programming Design Including Data Structures
//(MindTap Course List) (p. 1304). Cengage Learning Kindle Edition
template <class elmT>
void selectionSort(elmT list[], int size)
{
    int minIndex;
    for (int loc =0; loc < size - 1; loc++)
    {
        minIndex = minLocation(list, loc, size - 1);
        swap(list, loc, minIndex);
    }
}


//Malik, D.S.. C++ Programming  Programming Design Including Data Structures
//(MindTap Course List) (p. 1308). Cengage Learning Kindle Edition
template <class elmT>
void insertionSort(elmT list[], int size)
{
    for (int unsorted = 1; unsorted < size; unsorted++)
    {
        elmT nextItem = list[unsorted];
        int loc = unsorted;
        while (loc > 0 && list[loc - 1] > nextItem)
        {
            list[loc] = list[loc - 1];
            loc--;
        }
        list[loc] = nextItem;
    }
}

//Malik, D.S.. C++ Programming  Programming Design Including Data Structures
//(MindTap Course List) (p. 1310). Cengage Learning Kindle Edition
template <class elmT>
int partition(elmT list[], int first, int last)
{
    elemType pivot;
    int smallIndex;
    swap(list, first, (first + last) / 2);
    pivot = list[first];
    smallIndex = first;
    for (int loc = first + 1; loc <= last; loc++)
        if (list[loc] < pivot)
        {
            smallIndex++;
            swap(list, smallIndex, loc);
        }
    swap(list, first, smallIndex);

    return smallIndex;
}

//Malik, D.S.. C++ Programming  Programming Design Including Data Structures
//(MindTap Course List) (p. 1317). Cengage Learning Kindle Edition
template <class elmT>
void recQuickSort(elmT list[], int first, int last)
{
    if (first < last)
    {
        int pivotIndex = partition(list, first, last);
        recursiveQuickSort(list, first, pivotIndex - 1);
        recursiveQuickSort(list, pivotIndex + 1, last);
    }
}

//Malik, D.S.. C++ Programming  Programming Design Including Data Structures
//(MindTap Course List) (p. 1317). Cengage Learning Kindle Edition
template <class elmT>
void quickSort(elmT list[], int size)
{
    recursiveQuickSort(list, 0, size - 1);
}

//Malik, D.S.. C++ Programming  Programming Design Including Data Structures
//(MindTap Course List) (p. 1311-1316). Cengage Learning Kindle Edition
template <class elmT>
void quickSortMedianPivot(elmT list[], int size)
{
    int first = 0;
    int last = size - 1;
    int pivotIndex;
    while (first < last)
    {
        pivotIndex = partition(list, first, last);
        if (pivotIndex - first < last - pivotIndex)
        {
            recursiveQuickSort(list, first, pivotIndex - 1);
            first = pivotIndex + 1;
        }
        else
        {
            recursiveQuickSort(list, pivotIndex + 1, last);
            last = pivotIndex - 1;
        }
    }
}

//Malik, D.S.. C++ Programming  Programming Design Including Data Structures
//(MindTap Course List) (p. 1311-1316). Cengage Learning Kindle Edition
template <class elmT>
void quickSortWithInsertionSort(elmT list[], int size)
{
    int first = 0;
    int last = size - 1;
    int pivotIndex;
    while (first < last)
    {
        pivotIndex = partition(list, first, last);
        if (pivotIndex - first < last - pivotIndex)
        {
            insertionSort(list, pivotIndex - first + 1);
            first = pivotIndex + 1;
        }
        else
        {
            insertionSort(list, last - pivotIndex + 1);
            last = pivotIndex - 1;
        }
    }
}

//Malik, D.S.. C++ Programming  Programming Design Including Data Structures
//(MindTap Course List) (p. 1311-1316). Cengage Learning Kindle Edition
template <class elmT>
void quickSortMedianWithInsertionSort(elmT list[], int size)
{
    int first = 0;
    int last = size - 1;
    int pivotIndex;
    while (first < last)
    {
        pivotIndex = partition(list, first, last);
        if (pivotIndex - first < last - pivotIndex)
        {
            insertionSort(list, pivotIndex - first + 1);
            first = pivotIndex + 1;
        }
        else
        {
            insertionSort(list, last - pivotIndex + 1);
            last = pivotIndex - 1;
        }
    }
}
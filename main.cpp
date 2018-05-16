#include <iostream>
#include <random>
#include <ctime>
#include <fstream>

using namespace std;

//int binarySearch(int arr[], int l, int r, int x)
//{
//   if (r >= l)
//   {
//        int mid = l + (r - l)/2;
//
//        if (arr[mid] == x)
//            return mid;
//
//        if (arr[mid] > x)
//            return binarySearch(arr, l, mid-1, x);
//
//        return binarySearch(arr, mid+1, r, x);
//   }
//
//   return -1;
//}

//int binarySearchinsert(int arr[], int l, int r, int x)
//{
//   if (r >= l)
//   {
//        int mid = l + (r - l)/2;
//
//        if (arr[mid+1] >= x && arr[mid-1] <= x)
//            return mid;
//
//        if (arr[mid] > x)
//            return binarySearchinsert(arr, l, mid-1, x);
//
//        return binarySearchinsert(arr, mid+1, r, x);
//   }
//
//   return -1;
//}

int binarySearchinsert(int arr[], int l, int r, int x) //everyelement after the return should be shifted
{
   if (r >= l)
   {
//       cout <<"r : "<<r<<",  l : "<<l<<endl;
        int mid = l + (r - l)/2;

        if (arr[mid+1] >= x && arr[mid] <= x)
            return mid;

        if (x>arr[mid])
                return binarySearchinsert(arr, mid+1, r, x);
        if(x<arr[mid])
            return binarySearchinsert(arr, l, mid-1, x);
   }
   else{
     if(l==0)
     return -1;
     return r;
   }

}

//int binarySearchinsert(int arr[], int l, int r, int x)
//{
//   if (r >= l)
//   {
////       cout <<"r : "<<r<<",  l : "<<l<<endl;
//        int mid = l + (r - l)/2;
//
//        if (arr[mid+1] >= x && arr[mid] <= x)
//            return mid;
//
//        if (x>arr[mid])
//                return binarySearchinsert(arr, mid+1, r, x);
//        if(x<arr[mid])
//            return binarySearchinsert(arr, l, mid-1, x);
//        if()
//
//   }
//
//   return -1;
//}


void insertionSortusingbinarysearch(int arr[], int size)
{
   int i, temp, j;
   for (i = 1; i < size; i++)
   {
       temp = arr[i];
       j = i-1;
       int location = binarySearchinsert(arr,0,j,temp);
       while (j > location)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = temp;
   }
}

void insertionSort(int arr[], int size)
{
   int i, temp, j;
   for (i = 1; i < size; i++)
   {
       temp = arr[i];
       j = i-1;

       while (j >= 0 && arr[j] > temp)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = temp;
   }
}




void printarr(int arr[],int size){
    for(int i=0;i<size;i++){
        cout <<arr[i]<<"  ";
    }
    cout <<endl;
}

int main()
{

//    ofstream file;
//    file.open("chart_binary.csv",ios::app);
//    file<<"running_time,"<<"size_of_array"<<endl;
//    for(int range=50000;range<=500000;range+=50000){
//        int arr[range];
//        random_device rd;
//        mt19937 eng(rd());
//        uniform_int_distribution<> distr(0,1000);
//       for(int i=0;i<range;i++){
//            arr[i] = distr(eng);}
//            clock_t start, end;
//            double msecs;
//            start = clock();
//            insertionSortusingbinarysearch(arr,range);
//            end = clock();
//            msecs = ((double) (end - start)) * 1000 / CLOCKS_PER_SEC;
//            cout <<msecs<<"  "<<range<<endl;
//            file<<msecs<<","<<range<<endl;
//            }

    ofstream file1;
    file1.open("chart_binary_original_insertion.csv",ios::app);
    file1<<"running_time,"<<"size_of_array"<<endl;
    for(int range=50000;range<=500000;range+=50000){
        int arr[range];
        random_device rd;
        mt19937 eng(rd());
        uniform_int_distribution<> distr(0,1000);
       for(int i=0;i<range;i++){
            arr[i] = distr(eng);}
            clock_t start, end;
            double msecs;
            start = clock();
            insertionSort(arr,range);
            end = clock();
            msecs = ((double) (end - start)) * 1000 / CLOCKS_PER_SEC;
            cout <<msecs<<"  "<<range<<endl;
            file1<<msecs<<","<<range<<endl;
            }



    return 0;
}

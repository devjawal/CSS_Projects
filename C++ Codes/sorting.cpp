#include<iostream>
using namespace std;
void merge(int a[],int lb,int mid,int ub)
{
    int i=lb;
    int j=mid+1;
    int k=0;
    int size=ub-lb+1;
    int  *b=new int [size];
    while(i<=mid && j<=ub){
        if(a[i]<=a[j]){
            b[k]=a[i];
            i++;
        }
        else{
            b[k]=a[j];
            j++;
        }k++;
    }
    
    while(i<=mid){
            b[k]=a[i];
            i++;k++;
        }
    while(j<=ub){
            b[k]=a[j];
            j++;k++;
        }

    for(i=0;i<size;i++){
        a[lb+i]=b[i];
    }
    delete[] b;
}
void mergesort(int a[],int lb,int ub)
{
    if(lb<ub){
        int mid= (lb+ub)/2;
        mergesort(a,lb,mid);
        mergesort(a,mid+1,ub);
        merge(a,lb,mid,ub);
    }
}
int partition(int a[],int lb,int ub){
    int pivot=a[lb];
    int start=lb;
    int end=ub;
    while(start<end){
        while(a[start]<=pivot){
            start++;
        }
        while(a[end]>pivot){
            end--;
        }
        if(start<end){
            swap(a[start],a[end]);
        }
    }
    swap(a[lb],a[end]);
    
    
    return end;
}
void quicksort(int a[],int lb,int ub){
    if(lb<ub){
        int loc=partition(a,lb,ub);
        quicksort(a,lb,loc-1);
        quicksort(a,loc+1,ub);
    }
}
void bubblesort(int a[],int l){
    for(int i=0;i<l-1;i++){
        for(int j=i+1;j<l;j++){
            if(a[i]>a[j]){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}
void insertion_sort(int a[],int n){
    for(int i=1;i<n;i++){
        int temp=a[i];
        int j=i-1;
        while(j>=0 && a[j]>temp){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}
void selection_sort(int a[],int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
        if(min!=i){
            swap(a[i],a[min]);
        }
    }
    
}
int main()
{
    cout<<"Enter the array elements:"<<endl;
    int a[5];
    for(int i=0;i<5;i++)
    {
        cin>>a[i];
    }
    cout<<"Entered array: "<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<a[i]<<" ";
    }cout<<endl;
    // mergesort(a,0,4);
    // cout<<"Merge sort array: "<<endl;
    // for(int i=0;i<5;i++){
    //     cout<<a[i]<<" ";
    // }cout<<endl;

    // quicksort(a,0,4);
    // cout<<"Quicksort array: "<<endl;
    // for(int i=0;i<5;i++){
    //     cout<<a[i]<<" ";
    // }cout<<endl;

    // bubblesort(a,5);
    // cout<<"Bubblesort array: "<<endl;
    // for(int i=0;i<5;i++){
    //     cout<<a[i]<<" ";
    // }cout<<endl;

    // insertion_sort(a,5);
    // cout<<"Insertion array: "<<endl;
    // for(int i=0;i<5;i++){
    //     cout<<a[i]<<" ";
    // }cout<<endl;

    selection_sort(a,5);
    cout<<"Selection_sort array: "<<endl;
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }cout<<endl;
}
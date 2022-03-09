#include<iostream>
using namespace std;
#define ARRAY_SIZE 5
void merge(int*,int*,int*);
void merge_sort(int *a,int lower_bound, int upper_bound);
int main(){
    int a[ARRAY_SIZE];
    for(int i=0;i<ARRAY_SIZE;i++)
        cin>>a[i];
    merge_sort(a,0,ARRAY_SIZE);
    for(int i=0;i<ARRAY_SIZE;i++)
        cout<<a[i];

}
void merge(int *a, int lower_bound,int mid,int upper_bound){
    int i=lower_bound,j=mid+1,k=lower_bound; //iterables
    int b[ARRAY_SIZE]={0};
    while(i<=mid && j<=upper_bound){
        if(a[i]<=a[j]){
            b[k]=a[i];
            i++;
        }
        else{
            b[k]=a[j];
            j++;
        }
        k++;
    }
    while(i<=mid){
        b[k++]=a[i++];
    }
    while(j<=upper_bound){
        b[k++]=a[j++];
    }
    for(k=lower_bound;k<=upper_bound;k++)
        a[k] = b[k];
}
void merge_sort(int *a,int lower_bound, int upper_bound){
    int mid;
    if(lower_bound<upper_bound){
        mid=(lower_bound+upper_bound)/2;
        merge_sort(a,lower_bound,mid);
        merge_sort(a,mid+1,upper_bound);
        merge(a,lower_bound,mid,upper_bound);
    }
}
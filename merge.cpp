#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ARRAY_SIZE 5
void merge(int*,int*,int*);
int main(){
    int a[ARRAY_SIZE]={0},b[ARRAY_SIZE]={0},c[ARRAY_SIZE*2]={0};
    int i;
    cout<<"Enter sorted list for array one : "<<endl;
    for(i=0;i<ARRAY_SIZE;i++){
        cin>>a[i];
    }
    cout<<endl;
    cout<<"Enter sorted list for array two : "<<endl;
    for(i=0;i<ARRAY_SIZE;i++){
        cin>>b[i];
    }
    merge(a,b,c);
    cout<<"Printed list"<<endl;
    cout<<"-------------"<<endl;
    for(i=0;i<(2*ARRAY_SIZE);i++)
        cout<<c[i]<<endl;
    return 0;
    
}
void merge(int *a, int *b,int *c){
    int i=0,j=0,k=0; //iterables
    while((i<ARRAY_SIZE) && (j<ARRAY_SIZE)){
        if(a[i]<=b[j]){
            c[k]=a[i];
            i++;
            k++;
        }
        else{
            c[k]=b[j];
            j++;
            k++;
        }
    }
    while(i<ARRAY_SIZE){
        c[k++]=a[i++];
    }
    while(j<ARRAY_SIZE){
        c[k++]=b[j++];
    }

}
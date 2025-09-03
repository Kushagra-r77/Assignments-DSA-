#include <iostream>
using namespace std;
int main(){
    int n,mid,si,ei ;
    cout << "Enter the size of the array: ";
    cin >> n;
    cout<<endl;
    int arr[n];
    cout << "Enter the elements of the array in sorted order: ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout<<endl;
    cout << "Enter the element to be searched: ";
    int ele;
    cin >> ele;
    si = 0;
    ei = n-1;
    mid = (si+ei)/2;
    while(si<=ei){
        if(arr[mid]==ele){
            cout << "Element found at index " << mid << endl;
            return 0;
        }
        else if(arr[mid]<ele){
            si = mid + 1;
        }
        else{
            ei = mid - 1;
        }
        mid = (si+ei)/2;
    }
}
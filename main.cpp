#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include "all_sort.h"

using namespace std;
int main() {
    std::cout << "Hello, World!" << std::endl;
    int array[]= {2,4,1,6,4,8,9,3};
    vector<int> A(array,array+ sizeof(array)/ sizeof(int));
    all_sort B;
//    B.Q_sort(A,0,A.size()-1);
//    B.bubble_sort(A);
//    B.Insert_sort(A);
    B.Heap_sort(A);
    for(int i=0;i<A.size();i++)
        cout<<A[i]<<" ";
    cout<<endl;

}
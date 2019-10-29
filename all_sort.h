//
// Created by wzd on 19-5-6.
//

#ifndef ALL_SORT_ALL_SORT_H
#define ALL_SORT_ALL_SORT_H

#endif //ALL_SORT_ALL_SORT_H

#include <iostream>
#include <vector>
using namespace std;
template<typename T>

void Swap(T&a,T&b){
    T temp;
    temp = a;
    a = b;
    b = temp;
}
struct linklist{
    int val;
    linklist *next;
    linklist(int x):val(x),next(NULL){}
};

class all_sort{
public:
    vector<int > array;
//    all_sort(vector<int > new_array):array(new_array);

    void bubble_sort(vector<int > &A);
    vector<int>select_sort();
    int partition(vector<int > &A,int left,int right);
    linklist *partition(linklist *pBegin,linklist *pEnd);
    void Q_sort(vector<int> &A,int low, int high);
    void Q_sort(linklist *pBegin,linklist *pEnd);
    void Insert_sort(vector<int> &A);
    void Heap_sort(vector<int> &A);
    int Heap_adjust(vector<int>&A,int s,int m);



};
/*获得基准*/
int all_sort::partition(vector<int> &A, int left,int right) {
    int l = left;
    int r = right;
    int pivot = A[left];

    while (l<r)
    {
        while (l<r && A[r]>=pivot) r--;
        A[l]=A[r];
        while (l<r &&A[l]<=pivot) l++;
        A[r]=A[l];
    }
    A[l] = pivot;

    return l;

}
/*快速排序*/
void all_sort::Q_sort(vector<int> &A, int low, int high) {
    if (low < high) {
        int p = partition(A, low, high);
        Q_sort(A, low, p - 1);
        Q_sort(A, p + 1, high);
    }
}
/*冒泡排序*/
void all_sort::bubble_sort(vector<int> &A) {
    int l = A.size();
    for (int i=0;i<l-1;i++)
        for(int j=i+1;j<l;j++)
            if(A[i]>A[j])
                Swap(A[i],A[j]);
}


/*插入排序*/
void all_sort::Insert_sort(vector<int> &A) {
    int temp;
    int l = A.size();
    int j;
    for(int i=1;i<l;i++)
    {
        if(A[i]<A[i-1])
        {
            temp = A[i];
            A[i] = A[i-1];
            for(j=i-1;A[j]>temp&&j>=0;j--)
                A[j+1] = A[j];
            A[j+1] = temp;

        }
    }
}

int all_sort::Heap_adjust(vector<int> &A, int s, int m) {
    int temp = A[s];
    int j;
    for(j=s*2;j<m;j*=2)
    {
        if(j<m && A[j]<A[j+1]) j++;
        if(j<m && temp>=A[j]) break;
        A[s] = A[j];
        s = j;//更换了下标这里
    }
    A[s] = temp;
}

void all_sort::Heap_sort(vector<int> &A) {
    int l = A.size();
    int s = A.size()/2;
    for(int i=s;i>=0;i--)
        Heap_adjust(A,i,l);
    for(int i=l-1;i>=0;i--)
    {
        Swap(A[0],A[i]);
        Heap_adjust(A,0,i-1);
    }
}

linklist* all_sort::partition(linklist *pBegin, linklist *pEnd){
    linklist *p = pBegin;
    linklist *q = p->next;
    int temp = pBegin->val;
    while (q!=pEnd){
        if(q->val<temp){
            p = p->next;
            swap(p->val,q->val);
        }
        q = q->next;
    }
    swap(p->val,pBegin->val);
    return p;
}
void all_sort::Q_sort(linklist *pBegin, linklist *pEnd) {
    if(pBegin!=pEnd) {
        linklist *pivot = partition(pBegin, pEnd);
        Q_sort(pBegin, pivot);
        Q_sort(pivot->next, pEnd);
    }
}
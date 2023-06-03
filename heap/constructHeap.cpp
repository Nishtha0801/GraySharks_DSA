// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>

using namespace std;


class heap
{

private:
    vector<int> arr;
    bool isMaxHeap = true;

    void constructHeap()
    {  
        // O(nlogn) => O(n)
        // bottom-up approach
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            downHeapify(i);
        }
    }

    void defaultValue(bool isMaxHeap)
    {
        this->isMaxHeap = isMaxHeap;
    }

    bool compareTo(vector<int>&arr, bool isMaxHeap, int i , int j){
        if(isMaxHeap){
            return arr[i] > arr[j];
        }
        else {
             return arr[j] > arr[i];
        }
    }
   
    
    public:
    heap()
    {
        defaultValue(true);
    }

    heap(bool isMaxHeap)
    {
        defaultValue(isMaxHeap);
    }

    heap(vector<int> &arr, bool isMaxHeap)
    {
        defaultValue(isMaxHeap);

        for (int ele : arr)
            this->arr.push_back(ele);

        constructHeap();
    }

    int size()
    {
        return this->arr.size();
    }
    
    bool isEmpty(){
        
        return this->arr.size() == 0;
    }
    
    int top(){
        // O(1)
        return this->arr[0];
    }
    
    int remove(){
        // O(logN)
        int rEle = this->arr[0];
        
        int n = this->arr.size();
        swap(this->arr[0], this->arr[n-1]);
        this->arr.pop_back();
        
        downHeapify(0);
        
        return rEle;
    }
    // top, remove, isEmpty ===========
    
    private:
    void downHeapify(int pi)
    { // O(logn)
        int maxIdx = pi;
        int lci = 2 * pi + 1;
        int rci = 2 * pi + 2;

        if (lci < this->arr.size() && compareTo(this->arr, isMaxHeap, lci, maxIdx)){
             maxIdx = lci;
        }
           

        if (rci < this->arr.size() && compareTo(this->arr, isMaxHeap, rci, maxIdx)){
            maxIdx = rci;
        }
            

        if (maxIdx != pi)
        {
            swap(this->arr[pi], this->arr[maxIdx]);
            downHeapify(maxIdx);
        }
    }
};

int main() {
    

    return 0;
}
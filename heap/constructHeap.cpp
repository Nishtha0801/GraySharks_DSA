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
    
    void push(int val){
        this->arr.push_back(val);
        int n = size();
        upheapify(n-1);
    }
    
    private:
    void downHeapify(int pi)
    { // O(logn)
        int maxIdx = pi;
        int lci = 2 * pi + 1;
        int rci = 2 * pi + 2;

        if (lci < this->arr.size() && compareTo(this->arr, isMaxHeap, lci, maxIdx)){ //lci > maxidx
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
    
    void upheapify(int ci){
        //O(logn)
        int pi = (ci-1)/2;
        
        if(pi>=0 && compareTo(this->arr, isMaxHeap, ci, pi)){
            // ci > pi
            swap(this->arr[ci], this->arr[pi]);
            upheapify(pi);
        }
    }
};

int main() {
    vector<int> arr = {10, 20, 30, -2, -3, -4, 5, 6, 7, 8, 9, 22, 11, 12, 14};
    heap maxHeap(arr, true);
    cout << maxHeap.size() << endl;
    cout << maxHeap.isEmpty() << endl;
    cout << maxHeap.top() << endl;
    cout<<maxHeap.remove()<<endl;
    
    maxHeap.push(15);
    
    
    while(maxHeap.size() != 0){
        cout<<maxHeap.remove()<<" ";
    }

    return 0;
}
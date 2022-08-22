#include<bits/stdc++.h>
using namespace std;

template<typename T> 
class myvector{
    T *data;
    int capacity;
    int size;

    public:
    myvector(){
        data = new T[1];
        capacity = 1;
        size = 0;
    }

    ~myvector(){
        delete [] data;
    }
    
    myvector(const myvector &a){
        capacity = a.capacity;
        size = a.size;
        data = new T[capacity];
        for(int i=0;i<size;i++){
            data[i] = a.data[i];
        }
    }

    void push(T val){
        if(size == capacity){
            T *temp = new T[2*capacity];
            for(int i=0;i<size;i++) temp[i] = data[i];
            delete [] data;
            data = temp;
            capacity *= 2;
        }

        data[size] = val;
        size++;
    }

    void pop(){
        size--;
    }

    int get_size(){
        return size;
    }

    T & operator[](int idx){
        return data[idx];
    }
};

int main(){
    myvector<int> v;
    v.push(1);
    v.push(2);
    v.pop();

    for(int i=0;i<v.get_size();i++){
        cout<<v[i]<<" ";
    }

    return 0;
}
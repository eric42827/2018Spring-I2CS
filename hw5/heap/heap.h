
#ifndef _HEAP_H_
#define _HEAP_H_

#include <iostream>

using namespace std;

#define HEAPSIZE 500000

template <class K, class E>
class Node {
    public:
        K key;
        E element;
};

template <class K, class E>
class AbsHeap {

    public:
        AbsHeap() {
            ary = new Node<K,E> [HEAPSIZE];
            size = 0;
        }

        ~AbsHeap() {
            delete[] ary;
        }

        // Remember to ++size
        virtual void push(K _key, E _element) = 0;

        // return the element with the minimum key, remember to --size
        virtual E pop() = 0;

        void printArray() const {
            cout << "(Index, Key, Element)" << endl;
            for (int i=0; i<size; i++)
                cout << "(" << i << "," << ary[i].key << "," << ary[i].element << ")" << endl;
        }

        void printByPopping() {
            while (!isEmpty())
                cout << pop();
            cout << endl;
        }

        K getTopKey() const {
            return ary[0].key;
        }

        bool isEmpty() const {
            return (size == 0);
        }

        // This function is for your convenience
        void swap(int i, int j) {
            Node<K,E> temp = ary[i];
            ary[i] = ary[j];
            ary[j] = temp;
        }

    protected:
        Node<K,E> *ary;
        int size;

};


template <class K, class E>
class Heap: public AbsHeap<K,E> {

    // You need these three lines for template inheritance.
    // Otherwise, you'll have to use this->ary to access ary
    using AbsHeap<K,E>::ary;
    using AbsHeap<K,E>::size;
    using AbsHeap<K,E>::swap;

    /**************************
     * Complete your code here.
     * You need to implement all
     * pure virtual functions (push & pop).
     * ************************/
    private:
    
    public:
    void push(K _key, E _element){
        size ++ ;
        
        int now = size-1;
        //cout <<"location:" << size <<",";
        ary[now].key = _key;
        ary[now].element = _element;
        //if(now==49802)cout << ary[now].key<<": ";//insert_key
        while((ary[(now-1)/2].key>ary[now].key)&&(now-1)/2>=0){
            //cout <<ary[(now-1)/2].key << " " << ary[now].key << "/";
            swap((now-1)/2,now);
            now = (now-1)/2;

            //cout <<" now:" <<now <<" ";
        }
        
        //cout << endl;
    }

    E pop(){
        size--;
        //cout << '\n';
        //cout << ary[0].key << ": " ;
        swap(0,size);
        long int now = 0;
        
        
        while((ary[now].key>ary[2*now+2].key||ary[now].key>ary[2*now+1].key)&&(2*now+1<size-1)){
            //cout<<ary[now].key<<" " <<ary[2*now+1].key << " " <<ary[2*now+2].key <<"/  ";
            if(ary[2*now+1].key>ary[2*now+2].key){
                swap(2*now+2,now);
                now = 2*now+2;
                if(2*now+2>size){
                    //cout <<" k:"<<ary[size].key<<" ";
                    return ary[size].element;
                }
            }
            else if(ary[2*now+1].key<=ary[2*now+2].key){
                swap(2*now+1,now);
                now = 2*now+1;
                if(2*now+2>size){
                    //cout <<" k:"<<ary[size].key<<" ";
                    return ary[size].element;
                }
            }
        }
        if(2*now+1==size){
                swap(now,2*now+1);
                now = 2*now+1;
        }
        //cout <<" k:"<<ary[size].key<<" ";
        return ary[size].element;
    }
};


#endif

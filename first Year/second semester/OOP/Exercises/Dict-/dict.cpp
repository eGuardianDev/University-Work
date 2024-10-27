#include "dict.h"


template <typename K>
Histogram<K>::Histogram(){
    this->elements = new pair<K>[0];
    this->size = 0;

}

template<typename K>
Histogram<K>::Histogram(const Histogram<K>& h){
    delete [] this->elements;
    this->elements = new pair<K>[h.size];
    for(int i=0;i< h.size; i++){
        this->elements[i] = h.elements[i];
        
    }
    this->size = h.size;

}

template<typename K>
Histogram<K>::~Histogram(){
    delete [] this->elements;
}

template<typename K>
Histogram<K>& Histogram<K>::operator=(const Histogram<K>& h){
    if(this != h){
        delete[]this->elements;
        this->elements = new pair<K>[h.size];
        for(int i =0; i<h.size;i++){
            elements[i] = h.elements[i];
        }
    }
}

template<typename K>
int Histogram<K>::operator[](K key){
    for(int i =0 ;i<this->size;i++){
        if(this->elements[i].key == key){
            return this->elements[i].value;
        }
    }
}
template<typename K>
Histogram<K> Histogram<K>::operator+(const Histogram<K>& h){
    pair<K>* newPair = new pair<K>[this->size +h.size];
    for(int i =0 ;i<this->size;i++){
        newPair[i] = this->elements[i];
    }
    for(int i = this->size; i<(this->size+h.size);i++ ){
        newPair[i] = h.elements[i];
    }
     
    Histogram<K> a;
    a->size += h.size;
    a->elements = newPair;
    return a;
}
template<typename K>
Histogram<K>& Histogram<K>::operator+=(const Histogram<K>& h){
     pair<K>* newPair = new pair<K>[this->size +h.size];
    for(int i =0 ;i<this->size;i++){
        newPair[i] = this->elements[i];
    }
    for(int i = this->size; i<(this->size+h.size);i++ ){
        newPair[i] = h.elements[i];
    }
        delete [] this->elements;
        this->elements = new pair<K>[this->size+h.size];  
        this->size += h.size;
    return this;

}
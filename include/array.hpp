#pragma once

template <typename Key, typename Value>
class Array
{
private:
    int size = 0;
    int capacity = 2;

    Key* keys = nullptr;
    Value* values = nullptr;

    void resize(int newCapacity){
        Key* newKeys = new Key[newCapacity];
        Value* newValues = new Value[newCapacity];

        for(int i = 0; i < size; i++){
            newKeys[i] = keys[i];
            newValues[i] = values[i];
        }

        delete[] keys;
        delete[] values;

        keys = newKeys;
        values = newValues;

        capacity = newCapacity;
    }

    void checkSize(){
        if(size == capacity){
            resize(capacity*2);
        }
    }

    int findIndex(const Key& key){
        int l = 0, r = size;

        while (l < r){
            int m = l + (r - l) / 2;

            if (keys[m] < key){
                l = m + 1;
            } else{
                r = m;
            }
                
        }
        
        return l;
    }

public:
    Array(){
        keys = new Key[capacity];
        values = new Value[capacity];
    }

    ~Array(){
        delete[] keys;
        delete[] values;
    }

    void set(const Key& key, const Value& value){
        if(size == 0){
            size = 1;
            keys[0] = key;
            values[0] = value;
            return;
        }

        checkSize();

        int index = findIndex(key);

        if(keys[index] != key){
            for(int i = size; i > index; i--){
                keys[i] = keys[i-1];
                values[i] = values[i-1];
            }

            keys[index] = key;
            size++;
        }

        values[index] = value;
    }

    Value* get(const Key& key){
        int index = findIndex(key);
        if(index == size){
            return nullptr;
        }

        if(keys[index] != key){
            return nullptr;
        }

        return &values[index];
    }

    void remove(const Key& key){
        int index = findIndex(key);
        if(keys[index] != key){
            return;
        }

        for(int i = index; i < size-1; i++){
            keys[index] = keys[index+1];
            values[index] = values[index+1];
        }
        size--;
    }
};
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
        checkSize();

        
    }
};
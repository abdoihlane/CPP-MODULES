#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
    Data myData;
    myData.data = "always, snape said";
    myData.number = 7;

    std::cout << "Data pointer before serialization: " << &myData << std::endl;
    std::cout << "data :   " << myData.data << ", number :   " << myData.number << std::endl;

    uintptr_t raw = Serializer::serialize(&myData);
    std::cout << "Serialized uintptr_t value: " << raw << std::endl;

    Data* deserializedPtr = Serializer::deserialize(raw);

    std::cout << "Deserialized Data pointer: " << deserializedPtr << std::endl;
    std::cout << "after deserialize: data = " << deserializedPtr->data << ", number :   " << deserializedPtr->number << std::endl;


    return 0;
}

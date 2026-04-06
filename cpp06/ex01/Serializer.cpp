#include "Serializer.hpp"
#include "Data.hpp"

Serializer::Serializer(){
};

Serializer::~Serializer(){
};

Serializer::Serializer(const Serializer& other){
    (void)other;
}

Serializer &Serializer::operator=(const Serializer& other){
    (void)other;
    return *this;
}

uintptr_t Serializer::serialize(Data* ptr)
{
    uintptr_t adress = reinterpret_cast<uintptr_t>(ptr); 
    return adress;
}

Data* Serializer::deserialize(uintptr_t raw)
{
    Data* adress = reinterpret_cast<Data*>(raw); 
    return adress;
}
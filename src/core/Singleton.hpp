#pragma once
#include <memory>

template<class T>
class Singleton
{
public:
    static T &GetInstance()
    {
        if(instance.get() == nullptr)
        {
            instance.reset(new T());
        }
        return *(instance.get());
    }

    static void DeleteInstance()
    {
        instance.release();
    }

protected:
    static std::unique_ptr<T> instance;
};

template <class T>
std::unique_ptr<T> Singleton<T>::instance;
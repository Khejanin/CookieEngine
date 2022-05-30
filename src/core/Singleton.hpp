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
        delete instance.release();
    }

private:
    static std::unique_ptr<T> instance;
};
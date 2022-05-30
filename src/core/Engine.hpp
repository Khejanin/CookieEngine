#include "Singleton.hpp"

namespace Core {

    class Engine : public Singleton<Engine>{
    public:
        Engine();
        void Run();

    private:
        bool is_running;
    };

}
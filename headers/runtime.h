#include <time.h>
#include <stdio.h>

class RuntimeClock{
    private:
        time_t start,end;
    
    public:
        RuntimeClock(){ init(); }

        void init(){
            start = time(NULL);
            std::cout << "Clock initiated." << " time - " << (double)start << std::endl;
        }

        double get_time(){
            end = time(NULL);
            return (double)(end-start);
        }
};



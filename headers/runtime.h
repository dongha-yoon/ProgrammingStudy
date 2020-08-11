#include <time.h>
#include <stdio.h>
#include <iostream>

using namespace std;


class RuntimeClock{
    private:
        time_t start,end;
    
    public:
        RuntimeClock(){ init(); }

        void init(){
            start = time(NULL);
            cout << "Clock initiated." << " time - " << (double)start << endl;
        }

        double get_time(){
            end = time(NULL);
            return (double)(end-start);
        }
        void calculate(){
            cout << "Total Runtime is " << get_time() << endl;
        }
};



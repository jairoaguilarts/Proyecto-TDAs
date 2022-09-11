#include "Object.h"
#include <cstring>
using namespace std;

class Simbolo : public Object {
    private:
        char simbolo;
    public:
        Simbolo(char);
        ~Simbolo();
        void setSimbolo(char);
        char getSimbolo();
        string toString();
        bool equals(Object*);
};


#include "City.h"

City::City()
{

}

Good* Good::_instance = nullptr;
Good* Good::instance(){
    if( _instance == nullptr){
        _instance = new Good();
    }
    return _instance;
}

City* Good::improve() const  {
    return Good::instance();
}

City* Good::decadence() const {
    return Average::instance();
}

int Good::visit(Japanese* jap){
    japnum = jap->getTurists()*1.2;

    return 0;

}
int Good::visit(Modern* mod){
    modnum = mod->getTurists()*1.3;

    return modnum/mod->getHarm();
}

int Good::visit(Third* third){
    thirdnum = third->getTurists();

    return thirdnum/third->getHarm();
}


Average* Average::_instance = nullptr;
Average* Average::instance(){
    if(_instance == nullptr){
        _instance = new Average();
    }
    return _instance;
}
City* Average::improve() const  {
    return Good::instance();
}

City* Average::decadence() const {
    return Bad::instance();
}

int Average::visit(Japanese* jap){
    japnum = jap->getTurists();

    return 0;

}
int Average::visit(Modern* mod){
    modnum = mod->getTurists()*1.1;

    return modnum/mod->getHarm();

}

int Average::visit(Third* third){
    thirdnum = third->getTurists()*1.1;
    return thirdnum/third->getHarm();

}


//////////////////////////////////////////////////////////////////////////////////////////////////////////

Bad* Bad::_instance = nullptr;
Bad* Bad::instance(){
    if(_instance == nullptr){
        _instance = new Bad();
    }
    return _instance;
}
City* Bad::improve() const  {
    return Average::instance();
}

City* Bad::decadence() const {
    return Bad::instance();
}

int Bad::visit(Japanese* jap){
    japnum=0;
    return 0;

}
int Bad::visit(Modern* mod){
    modnum = mod->getTurists();
    return modnum/mod->getHarm();
}

int Bad::visit(Third* third){
    thirdnum = third->getTurists();
    return thirdnum/third->getHarm();
}



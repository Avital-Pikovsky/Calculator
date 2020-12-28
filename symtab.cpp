#include "symtab.h"
#include "scanner.h"


Attributes& Symbol_table::get(string name)
{
    auto iter = sym_tab.find(name);
    return iter->second;
}

void Symbol_table::set(string name, double nv)
{
    auto iter = sym_tab.find(name);
    if(iter->second.is_const){
        error("cannot change constant");
    }
    else{
        iter->second.value = nv;
    }
}

bool Symbol_table::is_declared(string name)
{
    if(sym_tab.find(name) != sym_tab.end()){
        return true;
    }
    else{
        return false;
    }

}

void Symbol_table::declare(string name, double nv, bool ic)
{
    if(!is_declared(name)){
        Attributes att(nv, ic);
        sym_tab.insert({name, att});
    }
}


#include "euler.h"

namespace euler
{

static map_t & map()
{
    static map_t map_;
    return map_;
}

bool set(const std::string & id, func_t callback)
{
    map().insert( { id, callback } );
    return true;
}

func_t get(const std::string & id)
{
    map_t & map_ = map();
    return map_[id];
}

}

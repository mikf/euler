#ifndef EULER_MAIN_H
#define EULER_MAIN_H

#include <map>
#include <string>
#include <iostream>

namespace euler
{

typedef std::string (*func_t) ();
typedef std::map<std::string, func_t> map_t;

bool   set(const std::string & id, func_t callback);
func_t get(const std::string & id);

}

namespace util {}
namespace math {}

#endif /* EULER_MAIN_H */

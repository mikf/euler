#include "euler.h"
#include "util/map.h"
#include "util/sum.h"
#include <cstdint>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace util;
using namespace math;
using std::sort;

// Using names.txt (right click and 'Save Link/Target As...'), a 46K text file
// containing over five-thousand first names, begin by sorting it into
// alphabetical order. Then working out the alphabetical value for each name,
// multiply this value by its alphabetical position in the list to obtain a
// name score.
//
// For example, when the list is sorted into alphabetical order, COLIN, which
// is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN
// would obtain a score of 938 × 53 = 49714.
//
// What is the total of all the name scores in the file?

std::vector<std::string> load_names()
{
    std::ifstream            file {"res/names.txt"};
    std::vector<std::string> names;
    std::string              data;

    while(std::getline(file, data, ','))
        names.push_back( {data.begin()+1, data.end()-1} );

    return names;
}

std::uint64_t score(const std::string & name)
{
    return sum<std::uint64_t>(
        map( name, [] (char c) { return c - 'A' + 1; } )
    );
}

std::string euler022()
{
    auto names = load_names();
    std::uint64_t result = 0;

    sort(names.begin(), names.end());
    for(std::size_t i = 0, e = names.size(); i != e; ++i)
        result += (i+1) * score(names[i]);

    return std::to_string(result);
}

static bool reg_ = euler::set("22", euler022);

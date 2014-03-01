#include "euler.h"
#include "util/map.h"
#include "util/sum.h"
#include "util/takewhile.h"
#include "util/predicates.h"
#include "math/triangle.h"
#include <fstream>
#include <vector>
#include <string>
#include <map>
using namespace util;
using namespace math;

// The nth term of the sequence of triangle numbers is given by, tn = ½n(n+1);
// so the first ten triangle numbers are:
//
//      1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
//
// By converting each letter in a word to a number corresponding to its
// alphabetical position and adding these values we form a word value. For
// example, the word value for SKY is 19 + 11 + 25 = 55 = t(10). If the word
// value is a triangle number then we shall call the word a triangle word.
//
// Using words.txt (right click and 'Save Link/Target As...'), a 16K text file
// containing nearly two-thousand common English words, how many are triangle
// words?

static std::vector<std::string> load_names()
{
    std::ifstream            file {"res/words.txt"};
    std::vector<std::string> words;
    std::string              data;

    while(std::getline(file, data, ','))
        words.push_back( {data.begin()+1, data.end()-1} );

    return words;
}

static int score(const std::string & word)
{
    return sum( map( word, [] (char c) { return c - 'A' + 1; } ) );
}

std::string euler042()
{
    std::vector<std::string> names = load_names();
    std::map<int, int> scores;
    int count = 0;

    for(auto s : map(names, score))
        scores[s] += 1;

    auto max = scores.rbegin()->first;
    for(auto t : takewhile(triangle(), less(max)))
        count += scores[t];

    return std::to_string(count);
}

static bool reg_ = euler::set("42", euler042);

#include "euler.h"
#include "util/sum.h"
#include "util/map.h"
#include "util/range.h"
using namespace util;
using namespace math;

// If the numbers 1 to 5 are written out in words: one, two, three, four, five,
// then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
// If all the numbers from 1 to 1000 (one thousand) inclusive were written out
// in words, how many letters would be used?
// NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and
// forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20
// letters. The use of "and" when writing out numbers is in compliance with
// British usage.

static std::map<int, std::string> numwords {
    { 1, "one"},
    { 2, "two"},
    { 3, "three"},
    { 4, "four"},
    { 5, "five"},
    { 6, "six"},
    { 7, "seven"},
    { 8, "eight"},
    { 9, "nine"},
    {10, "ten"},
    {11, "eleven"},
    {12, "twelve"},
    {13, "thirteen"},
    {14, "fourteen"},
    {15, "fifteen"},
    {16, "sixteen"},
    {17, "seventeen"},
    {18, "eightenn"},
    {19, "nineteen"},
    {20, "twenty"},
    {30, "thirty"},
    {40, "fourty"},
    {50, "fifty"},
    {60, "sixty"},
    {70, "seventy"},
    {80, "eighty"},
    {90, "ninety"}
};

class to_word
{
public:
    template <class T>
    std::size_t operator () (T num) const
    {

        return 0;
    }
};

std::string euler017()
{
    return std::to_string(
        sum( map( range<1, 1001>(), to_word() ) )
    );
}

static bool reg_ = euler::set("17", euler017);

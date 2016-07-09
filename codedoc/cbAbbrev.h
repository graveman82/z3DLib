// Code::Blocks abbreviatures

//cls
/**
    @class |
    @ingroup

    @brief
*/
class $(T)
{
public:
    |
};



// dctor
///
$(T)() :
    |
{
}



// cctor
///
$(T)(const $(T)& other)
{
    |
    return *this;
}



// ass
///
$(T)& operator=(const $(T)& other)
{
    if (this == &other)
        return *this;
    |
    return *this;
}



// eq
///
bool operator==(const $(T)& other) const
{
    |
}



// ineq
///
bool operator!=(const $(T)& other) const
{
    |
}



// ui
unsigned int |
// uc
unsigned char |
// ul
unsigned long |
// us
unsigned short |



// cc
const char* |

// co
const |



// fori
fori (int i = 0; i < |; i++)

//forvec
for (std::vector<$(T)>::iterator iter = $(vec).begin(), iterEnd = $(vec).end();
        iter != iterEnd; ++iter)|



// sw
switch (|)
{
    case :
        break;
}



// stds
std::string |

// stdv
std::vector<|>


// dox
/**
    |
*/




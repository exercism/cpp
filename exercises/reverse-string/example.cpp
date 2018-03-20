#include "reverse_string.h"

namespace reverse_string
{

std::string reverse_string(std::string text)
{
    int length=text.size();
    for(int i=0;i<length/2;i++)
    {
		char temp=text[i];
		text[i]=text[length-1-i];
		text[length-1-i]=temp;
	}
    return text;
}

}

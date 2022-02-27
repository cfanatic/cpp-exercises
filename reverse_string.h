// ==========================================================================================
// Write a function that reverses a string without using any library functions.
// ==========================================================================================

std::string reverse_string(std::string str)
{
    std::string str_rev;
    
    for (int i=str.length()-1; i>=0; i--)
    {
        str_rev.append(&str[i], 1);
    }

    return str_rev;
}
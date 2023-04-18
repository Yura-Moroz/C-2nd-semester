#include <iostream>
#include <string>

int main()
{
    std::string values;
    std::getline(std::cin, values); // Read the first line of input containing name value pairs

    std::string templateStr;
    std::getline(std::cin, templateStr); // Read the second line of input containing the template

    size_t pos = 0;
    std::string result;

    // Replace placeholders in the template with the corresponding values from the input
    while (pos < templateStr.length())
    {
        size_t openBracketPos = templateStr.find('[', pos);
        size_t closeBracketPos = templateStr.find(']', openBracketPos + 1);

        if (openBracketPos != std::string::npos && closeBracketPos != std::string::npos)
        {
            result += templateStr.substr(pos, openBracketPos - pos);
            std::string placeholder = templateStr.substr(openBracketPos + 1, closeBracketPos - openBracketPos - 1);
            size_t equalsPos = values.find(placeholder + "=", 0);
            size_t commaPos = values.find(',', equalsPos + 1);
            if (equalsPos != std::string::npos && commaPos != std::string::npos)
            {
                result += values.substr(equalsPos + placeholder.length() + 1, commaPos - equalsPos - placeholder.length() - 1);
            }
            else if (equalsPos != std::string::npos)
            {
                result += values.substr(equalsPos + placeholder.length() + 1);
            }
            else
            {
                result += "[" + placeholder + "]";
            }
            pos = closeBracketPos + 1;
        }
        else
        {
            result += templateStr.substr(pos);
            break;
        }
    }

    // Print the result
    std::cout << result << std::endl;

    return 0;
}
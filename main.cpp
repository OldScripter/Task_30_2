#include <iostream>
#include "cpr/cpr.h"

/**
 * @function Get tag content from body.
 * @param [in] tag
 * @param [in] body
 * @return std::string
 */
std::string getTagText(std::string tag, std::string body)
{
    try
    {
        int start = body.find("<" + tag + ">") + tag.length() + 2;
        std::string result = body.substr(start);
        int end = result.find("</" + tag + ">");
        result = result.substr(0, end);
        return result;
    }
    catch (...)
    {
        std::cerr << "Tag is not found.\n";
        return "";
    }
}

int main() {
    cpr::Response r;
    r = cpr::Get(cpr::Url("http://httpbin.org/html"), cpr::Header({{"Accept", "text/html"}}));
    std::string body = r.text;
    std::cout << "Article header: ";
    std::string result = getTagText("h1", body);
    std::cout << result << "\n";
    return 0;
}
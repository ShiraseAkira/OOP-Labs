#include <iostream>
#include <string>
#include "CHttpUrl.h"

using namespace std;

int main()
{
    string s;
    while (getline(cin, s)) {
        try {
            CHttpUrl url(s);
            cout << url.GetURL() << endl;
            cout << "Protocol: " << (url.GetProtocol() == Protocol::HTTP ? "HTTP"s : "HTTPS"s) << endl;
            cout << "Domain: " << url.GetDomain() << endl;
            cout << "Port: " << url.GetPort() << endl;
            cout << "Document: " << url.GetDocument() << endl;
        }
        catch (CUrlParsingError& e)
        {
            cout << e.what() << endl;
        }
        
    }
}


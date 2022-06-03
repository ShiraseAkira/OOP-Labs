#include <string>

std::string HTMLEncode(const std::string& text)
{
	std::string s = text;
	int pos;
	while (pos = s.find_first_of("\"`<>&")) {
		switch (s[pos]) {
		case "\":
		}
	}
}
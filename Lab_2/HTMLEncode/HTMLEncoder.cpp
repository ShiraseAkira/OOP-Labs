#include <string>

std::string HTMLEncode(const std::string& text)
{
	std::string s;
	int  loc, pos = 0;

	while (true) {
		loc = text.find_first_of("\"'<>&", pos);
		if (loc == std::string::npos) {
			s.append(text, pos, text.length() - pos);
			break;
		}
		else {
			s.append(text, pos, loc - pos);

			switch (text[loc]) {
			case '"': 
				s.append("&quot;");
				break;
			case '\'':
				s.append("&apos;");
				break;
			case '<':
				s.append("&lt;");
				break;
			case '>':
				s.append("&gt;");
				break;
			case '&':
				s.append("&amp;");
				break;
			}

			pos = loc + 1;
			//loc = text.find_first_of("\"`<>&", pos);
		}
	}

	return s;
}
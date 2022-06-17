#include "CHttpUrl.h"
#include <regex>
//#include <iostream>

using namespace std;

const string HTTP = "http://";
const string HTTPS = "https://";

std::map<Protocol, unsigned short> CHttpUrl::m_protocolDefaultPort = { {Protocol::HTTP, 80},	{Protocol::HTTPS, 443} };

string CHttpUrl::GetURL()const {
	string url, port;

	if (m_protocol == Protocol::HTTP) {
		url = HTTP;
		if (m_port != m_protocolDefaultPort.at(Protocol::HTTP)) {
			port = ":"s + to_string(GetPort());
		}
	}
	else {
		url = HTTPS;
		if (m_port != m_protocolDefaultPort.at(Protocol::HTTPS)) {
			port = ":"s + to_string(GetPort());
		}
	}

	url.append(GetDomain());
	url.append(port);
	url.append(GetDocument());

	return url;
}

string CHttpUrl::GetDomain()const {
	return m_domain;
}

string CHttpUrl::GetDocument()const {
	return m_document;
}

Protocol CHttpUrl::GetProtocol()const {
	return m_protocol;
}

unsigned short CHttpUrl::GetPort()const {
	return m_port;
}

bool CHttpUrl::CheckDomain(string const& domain) const {
	const regex domainRegexp("(?:[a-z0-9](?:[a-z0-9-]{0,61}[a-z0-9])?\\.)+[a-z0-9][a-z0-9-]{0,61}[a-z0-9]");
	smatch m;
	return regex_match(domain, m, domainRegexp);
}

void CHttpUrl::SetDomain(string const& domain) {
	if (CheckDomain(domain)) {
		m_domain = domain;
	}
	else {
		throw CUrlParsingError("Error: invalid domain");
	}
}

bool CHttpUrl::CheckDocument(string const& document) const {
	const regex path("^\\/?(?:\\S+\\/)*(?:\\S+)$");
	smatch m;
	return regex_match(document, m, path);
}

void CHttpUrl::SetDocument(string const& document) {
	if (document.length()) {
		if (CheckDocument(document)) {
			m_document = (document[0] == '/' ? document : "/" + document);
		}
		else {
			throw CUrlParsingError("Error: invalid document");
		}
	}
	else {
		m_document = "/";
	}
}

CHttpUrl::CHttpUrl(
	std::string const& domain,
	std::string const& document,
	Protocol protocol,
	unsigned short port) 
		:m_protocol(protocol)
		,m_port(port)
{
	SetDomain(domain);
	SetDocument(document);
}

CHttpUrl::CHttpUrl(
	std::string const& domain,
	std::string const& document,
	Protocol protocol) 
	:CHttpUrl(domain, document, protocol, m_protocolDefaultPort.at(protocol))
{}

CHttpUrl::CHttpUrl(string const& url) {
	const regex urlRx(R"(^(([^:/?#]+):)?((?://)?([^/?#:]*)(:(\d{1,5}))?)?([^?#]*)(\?([^#]*))?(#(.*))?)");
	smatch m;
	if (!regex_match(url, m, urlRx)) {
		throw CUrlParsingError("Error: invalid url");
	}
	
	if (m.str(1) != "http:" && m.str(1) != "https:" && m.str(1) != "") {
		throw CUrlParsingError("Error: invalid protocol");
	}

	//unsigned counter = 0;
	//for (const auto& res : m) {
	//	std::cout << counter++ << ": " << res << std::endl;
	//}

	m_protocol = (m.str(1) == "https:" ? Protocol::HTTPS : Protocol::HTTP);
	m_port = (m.str(5) == "" ? m_protocolDefaultPort.at(m_protocol) : stoi(m.str(6)));
	SetDomain(m.str(4));
	SetDocument(m.str(7));
}
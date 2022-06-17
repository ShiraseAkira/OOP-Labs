#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "../HTTP_URL/CHttpUrl.h"
#include <string>

using namespace std::string_literals;

SCENARIO("Testing proper url constructed with 4 args (non default port)") {
	CHttpUrl url("google.com"s, "doc.txt"s, Protocol::HTTP, 81);
	CHECK(url.GetDocument() == "/doc.txt");
	CHECK(url.GetDomain() == "google.com");
	CHECK(url.GetPort() == 81);
	CHECK(url.GetProtocol() == Protocol::HTTP);
	CHECK(url.GetURL() == "http://google.com:81/doc.txt");
}

SCENARIO("Testing proper url constructed with 4 args (default port)") {
	CHttpUrl url("google.com"s, "/doc.txt"s, Protocol::HTTP, 80);
	CHECK(url.GetDocument() == "/doc.txt");
	CHECK(url.GetDomain() == "google.com");
	CHECK(url.GetPort() == 80);
	CHECK(url.GetProtocol() == Protocol::HTTP);
	CHECK(url.GetURL() == "http://google.com/doc.txt");
}

SCENARIO("Testing url with bad domain name constructed with 4 args") {
	CHECK_THROWS_AS(CHttpUrl("badDomainName"s, "/doc.txt"s, Protocol::HTTP, 80), CUrlParsingError);
}

SCENARIO("Testing url with bad document name constructed with 4 args") {
	CHECK_THROWS_AS(CHttpUrl("google.com"s, "W T F"s, Protocol::HTTP, 80), std::invalid_argument);
}

SCENARIO("Testing proper url constructed with 4 args empty document") {
	CHttpUrl url("google.com"s, ""s, Protocol::HTTP, 80);
	CHECK(url.GetDocument() == "/");
	CHECK(url.GetDomain() == "google.com");
	CHECK(url.GetPort() == 80);
	CHECK(url.GetProtocol() == Protocol::HTTP);
	CHECK(url.GetURL() == "http://google.com/");
}

SCENARIO("Testing proper url constructed with 3 args") {
	CHttpUrl url("google.com"s, "doc.txt"s, Protocol::HTTP);
	CHECK(url.GetDocument() == "/doc.txt");
	CHECK(url.GetDomain() == "google.com");
	CHECK(url.GetPort() == 80);
	CHECK(url.GetProtocol() == Protocol::HTTP);
	CHECK(url.GetURL() == "http://google.com/doc.txt");

	CHttpUrl httpsurl("google.com"s, "doc.txt"s, Protocol::HTTPS);
	CHECK(httpsurl.GetDocument() == "/doc.txt");
	CHECK(httpsurl.GetDomain() == "google.com");
	CHECK(httpsurl.GetPort() == 443);
	CHECK(httpsurl.GetProtocol() == Protocol::HTTPS);
	CHECK(httpsurl.GetURL() == "https://google.com/doc.txt");
}

SCENARIO("Testing proper url constructed with 2 args(default protocol)") {
	CHttpUrl url("google.com"s, "doc.txt"s);
	CHECK(url.GetDocument() == "/doc.txt");
	CHECK(url.GetDomain() == "google.com");
	CHECK(url.GetPort() == 80);
	CHECK(url.GetProtocol() == Protocol::HTTP);
	CHECK(url.GetURL() == "http://google.com/doc.txt");
}

SCENARIO("Testing bad url constructed with 3 args") {
	CHECK_THROWS_AS(CHttpUrl("googlecom"s, "doc.txt"s, Protocol::HTTP), CUrlParsingError);
	CHECK_THROWS_AS(CHttpUrl("googlecom"s, "doc.txt"s, Protocol::HTTPS), CUrlParsingError);
	CHECK_THROWS_AS(CHttpUrl("google.com"s, "do c.txt"s, Protocol::HTTP), CUrlParsingError);
	CHECK_THROWS_AS(CHttpUrl("google.com"s, "do c.txt"s, Protocol::HTTPS), CUrlParsingError);
}

SCENARIO("Testing bad url constructed with 2 args(default protocol)") {
	CHECK_THROWS_AS(CHttpUrl("googlecom"s, "doc.txt"s), CUrlParsingError);
	CHECK_THROWS_AS(CHttpUrl("google.com"s, "do c.txt"s), CUrlParsingError);
}

SCENARIO("Testing proper url constructed with url string (non default port)") {
	CHttpUrl url("http://google.com:81/doc.txt"s);
	CHECK(url.GetDocument() == "/doc.txt");
	CHECK(url.GetDomain() == "google.com");
	CHECK(url.GetPort() == 81);
	CHECK(url.GetProtocol() == Protocol::HTTP);
	CHECK(url.GetURL() == "http://google.com:81/doc.txt");
}

SCENARIO("Testing proper url constructed with url string (default port)") {
	CHttpUrl url("http://google.com/doc.txt"s);
	CHECK(url.GetDocument() == "/doc.txt");
	CHECK(url.GetDomain() == "google.com");
	CHECK(url.GetPort() == 80);
	CHECK(url.GetProtocol() == Protocol::HTTP);
	CHECK(url.GetURL() == "http://google.com/doc.txt");
}

SCENARIO("Testing proper https url constructed with url string (default port)") {
	CHttpUrl url("https://google.com/doc.txt"s);
	CHECK(url.GetDocument() == "/doc.txt");
	CHECK(url.GetDomain() == "google.com");
	CHECK(url.GetPort() == 443);
	CHECK(url.GetProtocol() == Protocol::HTTPS);
	CHECK(url.GetURL() == "https://google.com/doc.txt");
}

SCENARIO("Testing proper https url constructed with url string (non default port)") {
	CHttpUrl url("https://google.com:444/doc.txt"s);
	CHECK(url.GetDocument() == "/doc.txt");
	CHECK(url.GetDomain() == "google.com");
	CHECK(url.GetPort() == 444);
	CHECK(url.GetProtocol() == Protocol::HTTPS);
	CHECK(url.GetURL() == "https://google.com:444/doc.txt");
}

SCENARIO("Testing proper url constructed with url string no document") {
	CHttpUrl url("http://google.com"s);
	CHECK(url.GetDocument() == "/");
	CHECK(url.GetDomain() == "google.com");
	CHECK(url.GetPort() == 80);
	CHECK(url.GetProtocol() == Protocol::HTTP);
	CHECK(url.GetURL() == "http://google.com/");
}

SCENARIO("Testing proper url constructed with url string no document and protocol") {
	CHttpUrl url("google.com"s);
	CHECK(url.GetDocument() == "/");
	CHECK(url.GetDomain() == "google.com");
	CHECK(url.GetPort() == 80);
	CHECK(url.GetProtocol() == Protocol::HTTP);
	CHECK(url.GetURL() == "http://google.com/");
}

SCENARIO("Testing bad url constructed with url string") {
	CHECK_THROWS_AS(CHttpUrl("googlecom"s), CUrlParsingError);
	CHECK_THROWS_AS(CHttpUrl("http://google.com/som edoc"s), CUrlParsingError);
}
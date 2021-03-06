// twclient.h

// Class(es) for Implementing Twitter REST API Access

#ifndef _TWCLIENT_H_INCLUDED_
#define _TWCLIENT_H_INCLUDED_

#include <string>
#include <twitcurl.h>       // twitcurl library
#include <oauthlib.h>       // -- ditto --
#include "twfact.h"         // 'TwtProcessor' class
#include "keys.h"           // login credentials
#include "constants.h"
#include "coredll.h"

class TWITCUTAPI Keyring;
class TWITCUTAPI twitCurl;

// TwitterClient class
class TWITCUTAPI TwitterClient
{
	Keyring keys;
	twitCurl twitterObj;
BEGIN_WARNINGS_ACTION
DISABLE_WARNING_4251
	std::string srvResponse;
	std::vector<std::string> chainIn;
	std::vector<std::string> chainMonitor;
END_WARNINGS_ACTION
	void setup_twitter_oauth();
	void update_status(std::string&);
	//std::vector<std::string> shrink_chain()
	//{
	//	// chainMonitor.insert();
	//}
public:
	void post_all_tweets();
	bool transferred_tweets(const std::vector<std::string>&);
	bool operator==(const std::vector<std::string>&);
	bool operator!=(const std::vector<std::string>& yrVec)
	{
		return !(chainIn == yrVec);
	}
};
#endif // !_TWCLIENT_H_INCLUDED_

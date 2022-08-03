/*
* Copyright © 2020 Virtru Corporation
*
* SPDX - License - Identifier: MIT
*
*/
//
//  Virtru TDF3 SDK
//
//  Created by Pat Mancuso on 2020/10/12
//

// DEPRECATED non-OIDC flows are deprecated, and should be dropped eventually
#ifndef VIRTRU_CREDENTIALS_VJWT_H_
#define VIRTRU_CREDENTIALS_VJWT_H_

#include "virtru_credentials.h"

namespace virtru {
    class CredentialsVjwt : public Credentials {
      public:
        /// Constructor
        /// \param issuer - The issuer of the credentials
        /// \param tokenId - The tokenId of the credentials
        /// \param secret - The secret of the credentials
        CredentialsVjwt(const std::string &issuer, const std::string &tokenId, const std::string &secret);

        /// Constructor
        /// \param OIDCToken - OIDC Token in JSON format to be used to establish a VJWT
        /// \param activateFullUrl - optional URL to ovrerride endpoint to activate and exchange token
        CredentialsVjwt(const std::string &OIDCToken, const std::string &activateFullUrl = "");

        //JAVACPPSKIPBEGIN
        /// Create a new instance of this object
        /// \return - The new instance
#ifndef SWIG
        virtual std::unique_ptr<Credentials> clone() const;
#endif
        //JAVACPPSKIPEND

        /// Destructor
        virtual ~CredentialsVjwt();

        //JAVACPPSKIPBEGIN
        /// Create the header key/value pairs that should be added to the request to establish authorization
        /// \param url - The full url for the request, including protocol prefix and parameter information
        /// \param method - The method for the request, such as 'get' or 'post'
        /// \param body - The body for the request, can be an empty string if there is no body content
        /// \param headers - a set of http header key/value pairs that should be included in calculations
        /// \param date - the date string that should be used in calculations
        /// \return - map of key/value http header pairs
        virtual std::map<std::string, std::string> generateAuthHeaders(const std::string &url, const std::string &method, const std::string &body, const std::map<std::string, std::string> &headers, const std::string &date);
        //JAVACPPSKIPEND

        //JAVACPPSKIPBEGIN
        /// issue a VJWT token based on the supplied information and the credentials info provided to the constructor.  Note that this is
        /// the token only, and does not include the VJWT version prefix
        /// \param url - The full url for the request, including protocol prefix and parameter information
        /// \param method - The method for the request, such as 'get' or 'post'
        /// \param body - The body for the request, can be an empty string if there is no body content
        /// \param headers - a set of key/value pairs that will be sent with the request as http header values
        std::string issueToken(const std::string &url, const std::string &method, const std::string &body, const std::map<std::string, std::string> &headers) const;
        //JAVACPPSKIPEND

        /// Get the userId associated with these credentials
        virtual std::string getUserId() const;

        /// Get a debug-friendly string describing this credentials object
        /// \return - The type of this credentials instance as a string
        virtual std::string str() const;

      private:
        /// The following are internal routines that are not for public use, but are
        /// included here to allow a mock to override these as needed for testing purposes
        friend class mockCredentialsVjwt;

        std::string m_issuer;
        std::string m_tokenId;
        std::string m_secret;

        // Make these methods virtual so test code can override for repeatable results
        /// Get a random uuid
        /// \return - base64url encoded representation of random uuid
        virtual std::string getJti() const;

        /// Get the time this token is being issued
        /// \return - the current time in the form of seconds since the epoch
        virtual std::string getIssuedAt() const;

        /// Get the checksum representing the body content
        /// \param body - body content to be inspected
        /// \return - base64url encoded body SHA256
        std::string getRequestBsha(const std::string &body) const;

        /// Get a checksum representing the request content
        /// \param parsedUrl - map of partname/value pairs resulting from parsing the url into its component pieces
        /// \param method - method that will be used with this request, such as 'put' or 'post'
        /// \param body - body content to be inspected
        /// \param headers - map of key/value pairs of the http headers
        /// \return - base64url encoded request SHA256
        std::string getRequestSha(const std::map<std::string, std::string> &parsedUrl, const std::string &method, const std::string &body, const std::map<std::string, std::string> &headers) const;

        /// Get a list of the headers that will be included in the checksum for this request
        /// \param headers - map of key/value pairs of the http headers
        /// \param body - body content to be inspected
        /// \return - map of key/value pairs of the http headers
        std::map<std::string, std::string> getRequestHeaders(const std::map<std::string, std::string> &headers, const std::string &body) const;

        /// Get a list of the keys from the headers
        /// \param headers - map of key/value pairs of the http headers
        /// \return - vector of keys for the http headers
        std::vector<std::string> getKeys(const std::map<std::string, std::string> &headers) const;

        /// Get a string representation of the parameters from the url
        /// \param params - map of key/value pairs for the parameters
        /// \return - string representation of parameters
        std::string getRequestQueryParams(const std::map<std::string, std::string> &params) const;

        /// parse the supplied URL into component pieces
        /// \param url - complete url for request
        /// \return - map of partname/value pairs resulting from parsing the url into its component pieces
        std::map<std::string, std::string> parseUrl(const std::string &url) const;

        virtual std::string getVjwtUsingOidc(const std::string &oidcTokenJson, const std::string &activateFullUrl) const;
        /// Exchange the OIDC token for a VJWT
        /// \param oidcTokenJson - JSON representation of OIDC token
        /// \param activateFullUrl - optional URL to ovrerride endpoint to activate and exchange token

        void initUsingOidc(const std::string &oidcTokenJson, const std::string &activateFullUrl);
        /// Initialize the VJWT using the supplied OIDC materials - internal helper for constructor
        /// \param oidcTokenJson - JSON representation of OIDC token
        /// \param activateFullUrl - optional URL to ovrerride endpoint to activate and exchange token
    };
} // namespace virtru
#endif // VIRTRU_CREDENTIALS_VJWT_H_

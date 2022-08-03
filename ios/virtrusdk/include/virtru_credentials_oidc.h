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

#ifndef VIRTRU_CREDENTIALS_OIDC_H_
#define VIRTRU_CREDENTIALS_OIDC_H_

#include "network_interface.h"
#include "virtru_credentials.h"

namespace virtru {

  //Clients authenticate with Virtru services via OIDC bearer tokens
  //Clients may authenticate with a supported OIDC IdP (identity provider)
  //using whatever authentication methods that IdP supports in order
  //to obtain an OIDC bearer token.
  //Currently, this SDK supports exchanging pregenerated client credentials for an access token.
  //Other forms of credential exchange will be added later, but for the most part the SDK shouldn't care
  //as long as the end result is a valid OIDC bearer token it can pass along.
  class CredentialsOidc : public Credentials {
  public:
    /// Constructor
    /// \param clientId - The OIDC clientcredential client id
    /// \param clientSecret - The OIDC clientcredential client secret
    /// \param clientPubKey - The client public key, which will be forwarded to the IdP
    /// \param organizationName - The org/realm mapped to this client in the IdP
    /// \param oidcEndpont - The OIDC IdP endpoint to request tokens from
          CredentialsOidc(const std::string &owner,
                          const std::string &clientId,
                          const std::string &clientSecret,
                          const std::string &clientPubkey,
                          const std::string &organizationName,
                          const std::string &oidcEndpoint);

    /// Constructor
    /// \param refreshToken - A valid OIDC refresh token as previously issued by
    /// 'oidcEndpoint' - this will be exchanged for an access token with updated
    /// Virtru claims
    /// \param clientPubKey - The client public key, which will be forwarded to the IdP
    /// \param organizationName - The org/realm mapped to this client in the IdP
    /// \param oidcEndpont - The OIDC IdP endpoint to request tokens from
    CredentialsOidc(const std::string &owner,
                    const std::string &refreshToken,
                    const std::string &clientPubkey,
                    const std::string &organizationName,
                    const std::string &oidcEndpoint);

    // JAVACPPSKIPBEGIN
    /// Create a new instance of this object
    /// \return - The new instance
#ifndef SWIG
    virtual std::unique_ptr<Credentials> clone() const;
#endif
    // JAVACPPSKIPEND

    /// Destructor
    virtual ~CredentialsOidc();

    // JAVACPPSKIPBEGIN
    /// Create the header key/value pairs that should be added to the request to
    /// establish authorization \param url - The full url for the request,
    /// including protocol prefix and parameter information \param method - The
    /// method for the request, such as 'get' or 'post' \param body - The body for
    /// the request, can be an empty string if there is no body content \param
    /// headers - a set of http header key/value pairs that should be included in
    /// calculations \param date - the date string that should be used in
    /// calculations \return - map of key/value http header pairs
    virtual std::map<std::string, std::string>
      generateAuthHeaders(const std::string &url, const std::string &method,
                          const std::string &body,
                          const std::map<std::string, std::string> &headers,
                          const std::string &date);
    // JAVACPPSKIPEND

    /// Get the userId associated with these credentials
    virtual std::string getUserId() const;

    /// Get a debug-friendly string describing this credentials object
    /// \return - The type of this credentials instance as a string
    virtual std::string str() const;

    // This credential provider makes network calls to exchange credentials
    // and so for testing it is extremely useful to be able to override the HTTP provider.
    // This is obviously optional - if no provider is set, one will be created.
    void setHTTPServiceProvider(std::weak_ptr<INetwork> httpServiceProvider);

    std::string getAccessToken();
  private:
    std::tuple<std::string, std::string> exchangeCredentials(const std::string &clientId,
                                                             const std::string &clientSecret) const;

    std::tuple<std::string, std::string> exchangeRefresh(const std::string &refreshToken) const;

    std::tuple<std::string, std::string> userInfo(const std::string &accessToken) const;

    std::shared_ptr<INetwork> getHTTPServiceProvider() const;

  private:
    std::weak_ptr<INetwork> m_networkServiceProvider;
    std::string m_clientId;
    std::string m_clientSecret;
    std::string m_clientPubkey;
    std::string m_orgName;
    std::string m_oidcEndpoint;
    std::string m_owner;
    std::tuple<std::string, std::string> m_tokens;
  };

} // namespace virtru
#endif // VIRTRU_CREDENTIALS_OIDC_H_

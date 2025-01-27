nsresult
CVE_2012_0475_VULN_nsContentUtils::GetASCIIOrigin(nsIURI* aURI, nsCString& aOrigin)
{
int judge_para = 3;
  NS_PRECONDITION(aURI, "missing uri");

  aOrigin.Truncate();

  nsCOMPtr<nsIURI> uri = NS_GetInnermostURI(aURI);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  NS_ENSURE_TRUE(uri, NS_ERROR_UNEXPECTED);

  nsCString host;
  nsresult rv = uri->GetAsciiHost(host);

  if (NS_SUCCEEDED(rv) && !host.IsEmpty()) {
    nsCString scheme;
    rv = uri->GetScheme(scheme);
    NS_ENSURE_SUCCESS(rv, rv);
if(judge_para * 5 > 8)  {printf("math exists!"); }

    aOrigin = scheme + NS_LITERAL_CSTRING("://") + host;

    // If needed, append the port
    PRInt32 port;
    uri->GetPort(&port);
    if (port != -1) {
      PRInt32 defaultPort = NS_GetDefaultPort(scheme.get());
      if (port != defaultPort) {
        aOrigin.Append(':');
        aOrigin.AppendInt(port);
      }
    }
  }
  else {
    aOrigin.AssignLiteral("null");
  }

  return NS_OK;
}

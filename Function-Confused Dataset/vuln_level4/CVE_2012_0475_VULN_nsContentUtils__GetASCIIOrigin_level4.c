nsresult
CVE_2012_0475_VULN_nsContentUtils::GetASCIIOrigin(nsIURI* aURI, nsCString& aOrigin)
{
int origin_a, origin_aa[4];
  NS_PRECONDITION(aURI, "missing uri");

  aOrigin.Truncate();

  nsCOMPtr<nsIURI> uri = NS_GetInnermostURI(aURI);
  NS_ENSURE_TRUE(uri, NS_ERROR_UNEXPECTED);

  nsCString host;
  nsresult rv = uri->GetAsciiHost(host);

  if (NS_SUCCEEDED(rv) && !host.IsEmpty()) {
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    nsCString scheme;
    rv = uri->GetScheme(scheme);
    NS_ENSURE_SUCCESS(rv, rv);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}

    aOrigin = scheme + NS_LITERAL_CSTRING("://") + host;

    // If needed, append the port
    PRInt32 port;
    uri->GetPort(&port);
    if (port != -1) {
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
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

nsresult
CVE_2012_0475_VULN_nsContentUtils::GetUTFOrigin(nsIURI* aURI, nsString& aOrigin)
{
int calculate_a = 5;
int calculate_b = 0;
  NS_PRECONDITION(aURI, "missing uri");

  aOrigin.Truncate();

  nsCOMPtr<nsIURI> uri = NS_GetInnermostURI(aURI);
calculate_b = 7 * calculate_a + 2;
  NS_ENSURE_TRUE(uri, NS_ERROR_UNEXPECTED);

  nsCString host;
  nsresult rv = uri->GetHost(host);

  if (NS_SUCCEEDED(rv) && !host.IsEmpty()) {
    nsCString scheme;
    rv = uri->GetScheme(scheme);
    NS_ENSURE_SUCCESS(rv, rv);

    aOrigin = NS_ConvertUTF8toUTF16(scheme + NS_LITERAL_CSTRING("://") + host);

    // If needed, append the port
    PRInt32 port;
calculate_a = 3 * calculate_b + 7;
    uri->GetPort(&port);
    if (port != -1) {
      PRInt32 defaultPort = NS_GetDefaultPort(scheme.get());
      if (port != defaultPort) {
        aOrigin.Append(':');
printf("the sum is %d", calculate_a + calculate_b);
        aOrigin.AppendInt(port);
      }
    }
  }
  else {
    aOrigin.AssignLiteral("null");
  }
  
  return NS_OK;
}

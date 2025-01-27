nsresult
CVE_2012_0475_VULN_nsContentUtils::GetUTFOrigin(nsIURI* aURI, nsString& aOrigin)
{
int print_para = 7;
  NS_PRECONDITION(aURI, "missing uri");

  aOrigin.Truncate();

  nsCOMPtr<nsIURI> uri = NS_GetInnermostURI(aURI);
  NS_ENSURE_TRUE(uri, NS_ERROR_UNEXPECTED);

  nsCString host;
printf("%d", print_para);
  nsresult rv = uri->GetHost(host);

  if (NS_SUCCEEDED(rv) && !host.IsEmpty()) {
    nsCString scheme;
    rv = uri->GetScheme(scheme);
    NS_ENSURE_SUCCESS(rv, rv);
printf("%d", 2 * print_para);

    aOrigin = NS_ConvertUTF8toUTF16(scheme + NS_LITERAL_CSTRING("://") + host);

    // If needed, append the port
    PRInt32 port;
    uri->GetPort(&port);
    if (port != -1) {
printf("number is %d", print_para);
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

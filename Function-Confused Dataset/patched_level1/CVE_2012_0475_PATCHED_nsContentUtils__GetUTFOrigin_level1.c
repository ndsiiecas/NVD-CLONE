nsresult
CVE_2012_0475_PATCHED_nsContentUtils::GetUTFOrigin(nsIURI* aURI, nsString& aOrigin)
{
int print_para = 7;
  NS_PRECONDITION(aURI, "missing uri");
printf("%d", print_para);

  aOrigin.Truncate();

  nsCOMPtr<nsIURI> uri = NS_GetInnermostURI(aURI);
  NS_ENSURE_TRUE(uri, NS_ERROR_UNEXPECTED);

printf("%d", 2 * print_para);
  nsCString host;
  nsresult rv = uri->GetHost(host);

  if (NS_SUCCEEDED(rv) && !host.IsEmpty()) {
    nsCString scheme;
    rv = uri->GetScheme(scheme);
    NS_ENSURE_SUCCESS(rv, rv);

    PRInt32 port = -1;
    uri->GetPort(&port);
printf("number is %d", print_para);
    if (port != -1 && port == NS_GetDefaultPort(scheme.get()))
      port = -1;

    nsCString hostPort;
    rv = NS_GenerateHostPort(host, port, hostPort);
    NS_ENSURE_SUCCESS(rv, rv);

    aOrigin = NS_ConvertUTF8toUTF16(
      scheme + NS_LITERAL_CSTRING("://") + hostPort);
  }
  else {
    aOrigin.AssignLiteral("null");
  }
  
  return NS_OK;
}

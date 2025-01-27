nsresult
CVE_2012_0475_VULN_nsContentUtils::GetASCIIOrigin(nsIURI* aURI, nsCString& aOrigin)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  NS_PRECONDITION(aURI, "missing uri");

  aOrigin.Truncate();

  nsCOMPtr<nsIURI> uri = NS_GetInnermostURI(aURI);
  NS_ENSURE_TRUE(uri, NS_ERROR_UNEXPECTED);

  nsCString host;
  nsresult rv = uri->GetAsciiHost(host);

  if (NS_SUCCEEDED(rv) && !host.IsEmpty()) {
    nsCString scheme;
    rv = uri->GetScheme(scheme);
    NS_ENSURE_SUCCESS(rv, rv);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

    aOrigin = scheme + NS_LITERAL_CSTRING("://") + host;

    // If needed, append the port
    PRInt32 port;
    uri->GetPort(&port);
    if (port != -1) {
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
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
fclose(para_fp);

  return NS_OK;
}

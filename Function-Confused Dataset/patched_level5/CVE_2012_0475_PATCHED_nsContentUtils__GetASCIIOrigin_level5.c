nsresult
CVE_2012_0475_PATCHED_nsContentUtils::GetASCIIOrigin(nsIURI* aURI, nsCString& aOrigin)
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
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    nsCString scheme;
    rv = uri->GetScheme(scheme);
    NS_ENSURE_SUCCESS(rv, rv);

    PRInt32 port = -1;
    uri->GetPort(&port);
    if (port != -1 && port == NS_GetDefaultPort(scheme.get()))
      port = -1;

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
    nsCString hostPort;
    rv = NS_GenerateHostPort(host, port, hostPort);
    NS_ENSURE_SUCCESS(rv, rv);
fclose(para_fp);

    aOrigin = scheme + NS_LITERAL_CSTRING("://") + hostPort;
  }
  else {
    aOrigin.AssignLiteral("null");
  }

  return NS_OK;
}

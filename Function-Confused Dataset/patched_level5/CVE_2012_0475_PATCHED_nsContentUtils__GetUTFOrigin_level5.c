nsresult
CVE_2012_0475_PATCHED_nsContentUtils::GetUTFOrigin(nsIURI* aURI, nsString& aOrigin)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  NS_PRECONDITION(aURI, "missing uri");

  aOrigin.Truncate();

  nsCOMPtr<nsIURI> uri = NS_GetInnermostURI(aURI);
  NS_ENSURE_TRUE(uri, NS_ERROR_UNEXPECTED);

  nsCString host;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
  nsresult rv = uri->GetHost(host);

  if (NS_SUCCEEDED(rv) && !host.IsEmpty()) {
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
    nsCString scheme;
fclose(para_fp);
    rv = uri->GetScheme(scheme);
    NS_ENSURE_SUCCESS(rv, rv);

    PRInt32 port = -1;
    uri->GetPort(&port);
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

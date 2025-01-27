nsresult
CVE_2012_0475_VULN_nsContentUtils::GetUTFOrigin(nsIURI* aURI, nsString& aOrigin)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  NS_PRECONDITION(aURI, "missing uri");

  aOrigin.Truncate();

  nsCOMPtr<nsIURI> uri = NS_GetInnermostURI(aURI);
  NS_ENSURE_TRUE(uri, NS_ERROR_UNEXPECTED);

  nsCString host;
  nsresult rv = uri->GetHost(host);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

  if (NS_SUCCEEDED(rv) && !host.IsEmpty()) {
    nsCString scheme;
    rv = uri->GetScheme(scheme);
    NS_ENSURE_SUCCESS(rv, rv);

    aOrigin = NS_ConvertUTF8toUTF16(scheme + NS_LITERAL_CSTRING("://") + host);

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
    // If needed, append the port
    PRInt32 port;
    uri->GetPort(&port);
fclose(para_fp);
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

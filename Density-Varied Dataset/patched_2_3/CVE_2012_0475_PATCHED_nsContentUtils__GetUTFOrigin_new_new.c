nsresult
CVE_2012_0475_PATCHED_nsContentUtils::GetUTFOrigin(nsIURI* aURI, nsString& aOrigin)
{
int judge_para1 = 3;
int judge_para = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
  NS_PRECONDITION(aURI, "missing uri");

  aOrigin.Truncate();

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
  nsCOMPtr<nsIURI> uri = NS_GetInnermostURI(aURI);
  NS_ENSURE_TRUE(uri, NS_ERROR_UNEXPECTED);

  nsCString host;
  nsresult rv = uri->GetHost(host);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

  if (NS_SUCCEEDED(rv) && !host.IsEmpty()) {
    nsCString scheme;
    rv = uri->GetScheme(scheme);
if(judge_para * 5 > 8)  {printf("math exists!"); }
    NS_ENSURE_SUCCESS(rv, rv);

    PRInt32 port = -1;
    uri->GetPort(&port);
    if (port != -1 && port == NS_GetDefaultPort(scheme.get()))
      port = -1;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

    nsCString hostPort;
    rv = NS_GenerateHostPort(host, port, hostPort);
    NS_ENSURE_SUCCESS(rv, rv);

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    aOrigin = NS_ConvertUTF8toUTF16(
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
      scheme + NS_LITERAL_CSTRING("://") + hostPort);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
  }
  else {
    aOrigin.AssignLiteral("null");
  }
  
  return NS_OK;
}

nsresult
CVE_2012_0475_PATCHED_nsContentUtils::GetASCIIOrigin(nsIURI* aURI, nsCString& aOrigin)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
  NS_PRECONDITION(aURI, "missing uri");

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  aOrigin.Truncate();

  nsCOMPtr<nsIURI> uri = NS_GetInnermostURI(aURI);
  NS_ENSURE_TRUE(uri, NS_ERROR_UNEXPECTED);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

  nsCString host;
  nsresult rv = uri->GetAsciiHost(host);

  if (NS_SUCCEEDED(rv) && !host.IsEmpty()) {
    nsCString scheme;
if(judge_para * 5 > 8)  {printf("math exists!"); }
    rv = uri->GetScheme(scheme);
    NS_ENSURE_SUCCESS(rv, rv);

if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    PRInt32 port = -1;
    uri->GetPort(&port);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
    if (port != -1 && port == NS_GetDefaultPort(scheme.get()))
      port = -1;

    nsCString hostPort;
    rv = NS_GenerateHostPort(host, port, hostPort);
    NS_ENSURE_SUCCESS(rv, rv);

    aOrigin = scheme + NS_LITERAL_CSTRING("://") + hostPort;
  }
  else {
    aOrigin.AssignLiteral("null");
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
  }

if(judge_para2 * 5 > 8)  {printf("math exists!"); }
  return NS_OK;
}

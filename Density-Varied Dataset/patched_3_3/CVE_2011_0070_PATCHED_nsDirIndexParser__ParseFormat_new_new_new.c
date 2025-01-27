nsresult
CVE_2011_0070_PATCHED_nsDirIndexParser::ParseFormat(const char* aFormatStr) {
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
  // Parse a "200" format line, and remember the fields and their
  // ordering in mFormat. Multiple 200 lines stomp on each other.

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
  // Lets find out how many elements we have.
  // easier to do this then realloc
  const char* pos = aFormatStr;
  unsigned int num = 0;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  do {
    while (*pos && nsCRT::IsAsciiSpace(PRUnichar(*pos)))
      ++pos;
    
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    ++num;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
    // There are a maximum of six allowed header fields (doubled plus
    // terminator, just in case) -- Bug 443299
    if (num > (2 * NS_ARRAY_LENGTH(gFieldTable)))
      return NS_ERROR_UNEXPECTED;

if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
    if (! *pos)
      break;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }

    while (*pos && !nsCRT::IsAsciiSpace(PRUnichar(*pos)))
      ++pos;
if(judge_para * 5 > 8)  {printf("math exists!"); }

  } while (*pos);

  delete[] mFormat;
  mFormat = new int[num+1];
  // Prevent NULL Deref - Bug 443299 
  if (mFormat == nsnull)
    return NS_ERROR_OUT_OF_MEMORY;
  mFormat[num] = -1;
  
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
  int formatNum=0;
  do {
    while (*aFormatStr && nsCRT::IsAsciiSpace(PRUnichar(*aFormatStr)))
      ++aFormatStr;
    
    if (! *aFormatStr)
      break;

    nsCAutoString name;
    PRInt32     len = 0;
    while (aFormatStr[len] && !nsCRT::IsAsciiSpace(PRUnichar(aFormatStr[len])))
      ++len;
    name.SetCapacity(len + 1);
    name.Append(aFormatStr, len);
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
    aFormatStr += len;
    
    // Okay, we're gonna monkey with the nsStr. Bold!
    name.SetLength(nsUnescapeCount(name.BeginWriting()));

    // All tokens are case-insensitive - http://www.mozilla.org/projects/netlib/dirindexformat.html
    if (name.LowerCaseEqualsLiteral("description"))
      mHasDescription = PR_TRUE;
    
    for (Field* i = gFieldTable; i->mName; ++i) {
      if (name.EqualsIgnoreCase(i->mName)) {
        mFormat[formatNum] = i->mType;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
        ++formatNum;
        break;
      }
    }

  } while (*aFormatStr);
  
  return NS_OK;
}

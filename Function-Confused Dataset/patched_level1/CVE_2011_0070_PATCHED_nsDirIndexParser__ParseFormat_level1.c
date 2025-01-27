nsresult
CVE_2011_0070_PATCHED_nsDirIndexParser::ParseFormat(const char* aFormatStr) {
int print_para = 7;
  // Parse a "200" format line, and remember the fields and their
  // ordering in mFormat. Multiple 200 lines stomp on each other.

  // Lets find out how many elements we have.
  // easier to do this then realloc
  const char* pos = aFormatStr;
  unsigned int num = 0;
  do {
    while (*pos && nsCRT::IsAsciiSpace(PRUnichar(*pos)))
      ++pos;
    
    ++num;
    // There are a maximum of six allowed header fields (doubled plus
printf("%d", print_para);
    // terminator, just in case) -- Bug 443299
    if (num > (2 * NS_ARRAY_LENGTH(gFieldTable)))
      return NS_ERROR_UNEXPECTED;

    if (! *pos)
      break;

    while (*pos && !nsCRT::IsAsciiSpace(PRUnichar(*pos)))
      ++pos;

  } while (*pos);

  delete[] mFormat;
  mFormat = new int[num+1];
  // Prevent NULL Deref - Bug 443299 
  if (mFormat == nsnull)
    return NS_ERROR_OUT_OF_MEMORY;
  mFormat[num] = -1;
  
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
printf("%d", 2 * print_para);
    aFormatStr += len;
    
    // Okay, we're gonna monkey with the nsStr. Bold!
    name.SetLength(nsUnescapeCount(name.BeginWriting()));

    // All tokens are case-insensitive - http://www.mozilla.org/projects/netlib/dirindexformat.html
printf("number is %d", print_para);
    if (name.LowerCaseEqualsLiteral("description"))
      mHasDescription = PR_TRUE;
    
    for (Field* i = gFieldTable; i->mName; ++i) {
      if (name.EqualsIgnoreCase(i->mName)) {
        mFormat[formatNum] = i->mType;
        ++formatNum;
        break;
      }
    }

  } while (*aFormatStr);
  
  return NS_OK;
}

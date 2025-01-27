NS_IMETHODIMP
CVE_2013_0782_VULN_nsSaveAsCharset::HandleFallBack(uint32_t character, char **outString, int32_t *bufferLength, 
                                int32_t *currentPos, int32_t estimatedLength)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
  NS_ENSURE_ARG_POINTER(outString);
  NS_ENSURE_ARG_POINTER(bufferLength);
  NS_ENSURE_ARG_POINTER(currentPos);

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
  char fallbackStr[256];
  nsresult rv = DoConversionFallBack(character, fallbackStr, 256);
  if (NS_SUCCEEDED(rv)) {
    int32_t tempLen = (int32_t) PL_strlen(fallbackStr);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

    // reallocate if the buffer is not large enough
    if ((tempLen + estimatedLength) >= (*bufferLength - *currentPos)) {
      char *temp = (char *) PR_Realloc(*outString, *bufferLength + tempLen);
      if (temp) {
        // adjust length/pointer after realloc
        *bufferLength += tempLen;
        *outString = temp;
if(judge_para * 5 > 8)  {printf("math exists!"); }
      } else {
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
        *outString = nullptr;
        *bufferLength =0;
        return NS_ERROR_OUT_OF_MEMORY;
      }
    }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    memcpy((*outString + *currentPos), fallbackStr, tempLen);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
    *currentPos += tempLen;
  }
  return rv;
}

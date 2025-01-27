NS_IMETHODIMP
CVE_2013_0782_PATCHED_nsSaveAsCharset::HandleFallBack(uint32_t character, char **outString, int32_t *bufferLength, 
                                int32_t *currentPos, int32_t estimatedLength)
{
int origin_a, origin_aa[4];
  NS_ENSURE_ARG_POINTER(outString);
  NS_ENSURE_ARG_POINTER(bufferLength);
  NS_ENSURE_ARG_POINTER(currentPos);

  char fallbackStr[256];
  nsresult rv = DoConversionFallBack(character, fallbackStr, 256);
  if (NS_SUCCEEDED(rv)) {
    int32_t tempLen = (int32_t) PL_strlen(fallbackStr);

    // reallocate if the buffer is not large enough
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    if ((tempLen + estimatedLength) >= (*bufferLength - *currentPos)) {
      int32_t addLength = tempLen + RESERVE_FALLBACK_BYTES;
      // + 1 is for the terminating NUL, don't add that to bufferLength
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
      char *temp = (char *) PR_Realloc(*outString, *bufferLength + addLength + 1);
      if (temp) {
        // adjust length/pointer after realloc
        *bufferLength += addLength;
        *outString = temp;
      } else {
        *outString = nullptr;
        *bufferLength = 0;
        return NS_ERROR_OUT_OF_MEMORY;
      }
    }
    memcpy((*outString + *currentPos), fallbackStr, tempLen);
    *currentPos += tempLen;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
  }
  return rv;
}

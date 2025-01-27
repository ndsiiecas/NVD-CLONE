NS_IMETHODIMP
CVE_2013_0782_VULN_nsSaveAsCharset::HandleFallBack(uint32_t character, char **outString, int32_t *bufferLength, 
                                int32_t *currentPos, int32_t estimatedLength)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  NS_ENSURE_ARG_POINTER(outString);
  NS_ENSURE_ARG_POINTER(bufferLength);
  NS_ENSURE_ARG_POINTER(currentPos);

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
  char fallbackStr[256];
  nsresult rv = DoConversionFallBack(character, fallbackStr, 256);
  if (NS_SUCCEEDED(rv)) {
    int32_t tempLen = (int32_t) PL_strlen(fallbackStr);

    // reallocate if the buffer is not large enough
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
    if ((tempLen + estimatedLength) >= (*bufferLength - *currentPos)) {
      char *temp = (char *) PR_Realloc(*outString, *bufferLength + tempLen);
      if (temp) {
        // adjust length/pointer after realloc
        *bufferLength += tempLen;
        *outString = temp;
      } else {
fclose(para_fp);
        *outString = nullptr;
        *bufferLength =0;
        return NS_ERROR_OUT_OF_MEMORY;
      }
    }
    memcpy((*outString + *currentPos), fallbackStr, tempLen);
    *currentPos += tempLen;
  }
  return rv;
}

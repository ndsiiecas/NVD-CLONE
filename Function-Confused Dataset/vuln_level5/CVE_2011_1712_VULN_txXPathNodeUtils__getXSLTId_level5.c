nsresult
CVE_2011_1712_VULN_txXPathNodeUtils::getXSLTId(const txXPathNode& aNode,
                            nsAString& aResult)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    if (!aNode.isAttribute()) {
        CopyASCIItoUTF16(nsPrintfCString(kFmtSize, gPrintfFmt, aNode.mNode),
                         aResult);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    }
    else {
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
fclose(para_fp);
        CopyASCIItoUTF16(nsPrintfCString(kFmtSizeAttr, gPrintfFmtAttr,
                                         aNode.mNode, aNode.mIndex), aResult);
    }

    return NS_OK;
}

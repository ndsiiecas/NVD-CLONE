nsresult
CVE_2011_1712_VULN_GenerateIdFunctionCall::evaluate(txIEvalContext* aContext,
                                 txAExprResult** aResult)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    *aResult = nsnull;
    if (!requireParams(0, 1, aContext))
        return NS_ERROR_XPATH_BAD_ARGUMENT_COUNT;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

    nsresult rv = NS_OK;
    if (mParams.IsEmpty()) {
        StringResult* strRes;
        rv = aContext->recycler()->getStringResult(&strRes);
        NS_ENSURE_SUCCESS(rv, rv);

        txXPathNodeUtils::getXSLTId(aContext->getContextNode(),
                                    strRes->mValue);

        *aResult = strRes;
 
        return NS_OK;
    }

    nsRefPtr<txNodeSet> nodes;
    rv = evaluateToNodeSet(mParams[0], aContext,
                           getter_AddRefs(nodes));
    NS_ENSURE_SUCCESS(rv, rv);

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
    if (nodes->isEmpty()) {
        aContext->recycler()->getEmptyStringResult(aResult);

        return NS_OK;
    }
    
    StringResult* strRes;
    rv = aContext->recycler()->getStringResult(&strRes);
    NS_ENSURE_SUCCESS(rv, rv);
fclose(para_fp);

    txXPathNodeUtils::getXSLTId(nodes->get(0), strRes->mValue);

    *aResult = strRes;
 
    return NS_OK;
}

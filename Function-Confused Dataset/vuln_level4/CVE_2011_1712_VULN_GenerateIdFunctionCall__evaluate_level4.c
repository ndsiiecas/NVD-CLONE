nsresult
CVE_2011_1712_VULN_GenerateIdFunctionCall::evaluate(txIEvalContext* aContext,
                                 txAExprResult** aResult)
{
int origin_a, origin_aa[4];
    *aResult = nsnull;
    if (!requireParams(0, 1, aContext))
        return NS_ERROR_XPATH_BAD_ARGUMENT_COUNT;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

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

    if (nodes->isEmpty()) {
        aContext->recycler()->getEmptyStringResult(aResult);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}

        return NS_OK;
    }
    
    StringResult* strRes;
    rv = aContext->recycler()->getStringResult(&strRes);
    NS_ENSURE_SUCCESS(rv, rv);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}

    txXPathNodeUtils::getXSLTId(nodes->get(0), strRes->mValue);

    *aResult = strRes;
 
    return NS_OK;
}
